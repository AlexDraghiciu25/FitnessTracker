#ifndef OOP_PLANSLABIRE_H
#define OOP_PLANSLABIRE_H

#include "PlanAntrenament.h"

class PlanSlabire : public PlanAntrenament {
private:
    double targetCaloriiPeZi;
    double deficitCaloric;
    int minuteCardioZilnic;

public:
    PlanSlabire(const std::string &numePlan, int durataLuni,
                NivelExperienta nivelExperienta, int zilePeSaptamana,
                double targetCalorii, double deficitCaloric, int minuteCardioZilnic);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override {
        if (saptamana <= 2)
            return 60.0;
        else if (saptamana <= 4)
            return 70.0;
        else if (saptamana <= 8)
            return 80.0;
        return 85;
    }

    [[nodiscard]] std::string getTipPlan() const override {
        return "Slabire/Pierdere greutate";
    }

    void genereazaRecomandari(std::ostream &os) const override {
        os << "Tip: " << getTipPlan() << "\n";
        os << "Target calorii/zi: " << targetCaloriiPeZi << " kcal\n";
        os << "Deficit caloric: " << deficitCaloric << " kcal/zi\n";
        os << "Cardio zilnic: " << minuteCardioZilnic << " minute\n";
        os << "Intensitate curenta: " << calculeazaIntensitate(saptamanaCurenta) << "%\n";
        os << "\nRecomandari:\n";
        os << "- Focus pe exercitii cardio (alergare, ciclism, inot)\n";
        os << "- Mentine deficit caloric consistent\n";
        os << "- Hidrateaza-te corespunzator\n";
    }

    [[nodiscard]] PlanSlabire* clone() const override {
        return new PlanSlabire(*this);
    }

    [[nodiscard]] std::vector<std::string> genereazaProgram(int saptamana) const override {
        std::vector<std::string> program;

        int minuteCardio = minuteCardioZilnic + (saptamana * 3); // Progresie
        double intensitate = calculeazaIntensitate(saptamana);

        for (int zi = 1; zi <= zilePeSaptamana; zi++) {
            std::string sesiune = "Zi " + std::to_string(zi) + ": ";
            sesiune += std::to_string(minuteCardio) + " min cardio @ ";
            sesiune += std::to_string(static_cast<int>(intensitate)) + "% intensitate";
            sesiune += " (≈" + std::to_string(static_cast<int>(minuteCardio * 8)) + " kcal)";
            program.push_back(sesiune);
        }

        program.push_back("NOTA: Mentine deficit caloric de " +
                         std::to_string(static_cast<int>(deficitCaloric)) + " kcal/zi");

        return program;
    }

    [[nodiscard]] double getTargetCalorii() const {
        return targetCaloriiPeZi;
    }

    [[nodiscard]] double getDeficitCaloric() const {
        return deficitCaloric;
    }
};

#endif //OOP_PLANSLABIRE_H
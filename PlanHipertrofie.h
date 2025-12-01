#ifndef OOP_PLANHIPERTROFIE_H
#define OOP_PLANHIPERTROFIE_H

#include "PlanAntrenament.h"

class PlanHipertrofie : public PlanAntrenament {
private:
    std::string tipSplit;
    int seturiPerGrupaMusculara;
    int repetariPerSet;
    double surplusCaloric;

public:
    PlanHipertrofie(const std::string& nume, int durataLuni,
                    NivelExperienta nivelExperienta, int zilePeSaptamana,
                    std::string  tipSplit, int seturiPerGrupaMusculara,
                    int repetatariPerSet, double surplusCaloric);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override {
        double intensitateBaza = 70.0;
        double cresterePerSaptamana = 1.5;
        return std::min(intensitateBaza + (saptamana * cresterePerSaptamana), 90.0);
    }

    [[nodiscard]] std::string getTipPlan() const override {
        return "Hipertrofie/Masa musculara";
    }

    void genereazaRecomandari(std::ostream &os) const override {
        os << "Tip: " << getTipPlan() << "\n";
        os << "Split: " << tipSplit << "\n";
        os << "Seturi per grup muscular: " << seturiPerGrupaMusculara << "\n";
        os << "Repetari per set: " << repetariPerSet << "\n";
        os << "Surplus caloric: +" << surplusCaloric << " kcal/zi\n";
        os << "Intensitate curenta: " << calculeazaIntensitate(saptamanaCurenta) << "%\n";
        os << "\nRecomandari:\n";
        os << "- Focus pe exercitii compuse (squat, deadlift, bench press)\n";
        os << "- Progresie progresiva (creste greutatea gradual)\n";
        os << "- Somn 7-9 ore pentru recuperare\n";
        os << "- Consum proteic: 1.6 - 2.2 g/kg corp\n";
    }

    [[nodiscard]] PlanHipertrofie* clone() const override {
        return new PlanHipertrofie(*this);
    }

    [[nodiscard]] std::vector<std::string> genereazaProgram(int saptamana) const override {
        std::vector<std::string> program;

        if (tipSplit == "Push/Pull/Legs" || tipSplit == "PPL") {
            program.push_back("Zi 1 (PUSH): Piept, Umeri, Triceps - " +
                             std::to_string(seturiPerGrupaMusculara) + " seturi x " +
                             std::to_string(repetariPerSet) + " reps");
            program.push_back("Zi 2 (PULL): Spate, Biceps - " +
                             std::to_string(seturiPerGrupaMusculara) + " seturi x " +
                             std::to_string(repetariPerSet) + " reps");
            program.push_back("Zi 3 (LEGS): Picioare, Abdomen - " +
                             std::to_string(seturiPerGrupaMusculara) + " seturi x " +
                             std::to_string(repetariPerSet) + " reps");
        } else if (tipSplit == "Full" || tipSplit == "Full Body") {
            for (int zi = 1; zi <= zilePeSaptamana; zi++) {
                program.push_back("Zi " + std::to_string(zi) + " (Full Body): " +
                                 "Toate grupele musculare - " +
                                 std::to_string(seturiPerGrupaMusculara / 2) + " seturi/grupa");
            }
        } else {
            program.push_back("Split personalizat: " + tipSplit);
        }

        int volumeTotal = seturiPerGrupaMusculara * zilePeSaptamana * (1 + saptamana / 4);
        program.push_back("VOLUM TOTAL SAPTAMANAL: " + std::to_string(volumeTotal) + " seturi");
        program.push_back("SURPLUS CALORIC: +" + std::to_string(static_cast<int>(surplusCaloric)) + " kcal/zi");

        return program;
    }

    [[nodiscard]] const std::string& getTipSplit() const {
        return tipSplit;
    }

    [[nodiscard]] int getSeturiPerGrupaMusculara() const {
        return seturiPerGrupaMusculara;
    }
};

#endif //OOP_PLANHIPERTROFIE_H
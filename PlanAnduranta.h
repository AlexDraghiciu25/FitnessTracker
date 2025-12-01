#ifndef OOP_PLANANDURANTA_H
#define OOP_PLANANDURANTA_H

#include "PlanAntrenament.h"

class PlanAnduranta : public PlanAntrenament {
private:
    double distantaTinta;
    std::string tipActivitate;
    int minuteBazaPerSesiune;

public:
    PlanAnduranta(const std::string &numePlan, int durataLuni,
                    NivelExperienta nivelExperienta, int zilePeSaptamana,
                    double distantaTinta, std::string tipActivitate, int minuteBazaPerSesiune);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override {
        int ciclu = saptamana % 4;
        if (ciclu == 0) {
            return 60.0;
        }
        if (ciclu == 1) {
            return 70.0;
        }
        if (ciclu == 2) {
            return 80.0;
        }
        return 75.0;
    }

    [[nodiscard]] std::string getTipPlan() const override {
        return "Anduranta/Rezistenta";
    }

    void genereazaRecomandari(std::ostream &os) const override {
        os << "Tip: " << getTipPlan() << "\n";
        os << "Activitate: " << tipActivitate << "\n";
        os << "Distanta tinta: " << distantaTinta << " km\n";
        os << "Durata medie: " << minuteBazaPerSesiune << " min\n";
        os << "Intensitate curenta: " << calculeazaIntensitate(saptamanaCurenta) << "%\n";
        os << "\nRecomandari:\n";
        os << "- Creste distanta cu max 10% pe saptamana\n";
        os << "- Alterneaza zile grele/usoare\n";
        os << "- 1 zi recuperare activa\n";
        os << "- Monitorizeaza frecventa cardiaca\n";
    }

    [[nodiscard]] PlanAnduranta* clone() const override {
        return new PlanAnduranta(*this);
    }

    [[nodiscard]] std::vector<std::string> genereazaProgram(int saptamana) const override {
        std::vector<std::string> program;

        // Progresie de distanta (creste cu 10% pe saptamana)
        double distantaSaptamana = distantaTinta * (0.3 + saptamana * 0.1);
        if (distantaSaptamana > distantaTinta) distantaSaptamana = distantaTinta;

        int minutePerSesiune = minuteBazaPerSesiune + (saptamana * 5);

        for (int zi = 1; zi <= zilePeSaptamana; zi++) {
            std::string sesiune = "Zi " + std::to_string(zi) + ": ";

            if (zi % 3 == 1) { // Zi grea
                sesiune += tipActivitate + " INTENS - ";
                sesiune += std::to_string(minutePerSesiune + 10) + " min, ";
                sesiune += std::to_string(static_cast<int>(distantaSaptamana / zilePeSaptamana * 1.3)) + " km";
            } else if (zi % 3 == 2) { // Zi usoara
                sesiune += tipActivitate + " USOR - ";
                sesiune += std::to_string(minutePerSesiune - 10) + " min, ";
                sesiune += std::to_string(static_cast<int>(distantaSaptamana / zilePeSaptamana * 0.7)) + " km";
            } else { // Zi recuperare activa
                sesiune += "Recuperare activa - 20 min mars/stretching";
            }

            program.push_back(sesiune);
        }

        program.push_back("OBIECTIV SAPTAMANAL: " + std::to_string(static_cast<int>(distantaSaptamana)) + " km");

        return program;
    }

    [[nodiscard]] double getDistantaTinta() const {
        return distantaTinta;
    }
};

#endif //OOP_PLANANDURANTA_H
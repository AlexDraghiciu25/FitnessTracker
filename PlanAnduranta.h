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

    [[nodiscard]] double getDistantaTinta() const {
        return distantaTinta;
    }
};

#endif //OOP_PLANANDURANTA_H
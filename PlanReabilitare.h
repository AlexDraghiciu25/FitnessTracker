#ifndef OOP_PLANREABILITARE_H
#define OOP_PLANREABILITARE_H

#include "PlanAntrenament.h"

class PlanReabilitare : public PlanAntrenament {
private:
    std::string tipLeziune;
    bool necesitaSupervizare;
    int nivelDurere;
public:
    PlanReabilitare(const std::string& numePlan, int durataLuni,
                    const std::string& nivelExperienta, int zilePeSaptamana,
                    const std::string& tipLeziune, bool necesitaSupervizare, int nivelDurere);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override {
        double intensitateBaza = 30.0;
        double crestere = saptamana * 5.0;
        double intensitate = intensitateBaza + crestere;
        return (intensitate > 70.0) ? 70.0 : intensitate;
    }

    [[nodiscard]] std::string getTipPlan() const override {
        return "Reabilitare/Recuperare";
    }

    void genereazaRecomandari(std::ostream &os) const override {
        os << "Tip: " << getTipPlan() << "\n";
        os << "Leziune: " << tipLeziune << "\n";
        os << "Supervizare: " << (necesitaSupervizare ? "DA" : "NU") << "\n";
        os << "Nivel durere: " << nivelDurere << "/10\n";
        os << "Intensitate: " << calculeazaIntensitate(saptamanaCurenta) << "%\n";
        os << "\nRecomandari:\n";
        os << "- OPRI daca simti durere!\n";
        os << "- Progres foarte gradual\n";
        os << "- Focus mobilitate si flexibilitate\n";
        if (necesitaSupervizare) {
            os << "- ATENTIE: Necesita supraveghere medicala!\n";
        }
    }

    [[nodiscard]] PlanReabilitare* clone() const  override {
        return new PlanReabilitare(*this);
    }

    [[nodiscard]] const std::string& getTipLeziune() const {
        return tipLeziune;
    }

    [[nodiscard]] int getNivelDurere() const {
        return nivelDurere;
    }
};

#endif //OOP_PLANREABILITARE_H
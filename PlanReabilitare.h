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
                    NivelExperienta nivelExperienta, int zilePeSaptamana,
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

    [[nodiscard]] std::vector<std::string> genereazaProgram(int saptamana) const override {
        std::vector<std::string> program;

        double intensitate = calculeazaIntensitate(saptamana);

        for (int zi = 1; zi <= zilePeSaptamana; zi++) {
            std::string sesiune = "Zi " + std::to_string(zi) + ": ";

            if (saptamana <= 2) {
                sesiune += "Mobilitate pasiva + Stretching light (15 min)";
            } else if (saptamana <= 4) {
                sesiune += "Exercitii izometrice + Mobilitate (20 min) @ " +
                          std::to_string(static_cast<int>(intensitate)) + "%";
            } else {
                sesiune += "Exercitii de forta usoara + Proprioceptie (30 min) @ " +
                          std::to_string(static_cast<int>(intensitate)) + "%";
            }

            sesiune += " | Durere acceptabila: max " + std::to_string(nivelDurere - saptamana) + "/10";
            program.push_back(sesiune);
        }

        if (necesitaSupervizare) {
            program.emplace_back("ATENTIE: Planul necesita supervizare medicala!");
            // .push_back imi da warning idk why
        }

        program.push_back("Leziune tratata: " + tipLeziune);

        return program;
    }

    [[nodiscard]] const std::string& getTipLeziune() const {
        return tipLeziune;
    }

    [[nodiscard]] int getNivelDurere() const {
        return nivelDurere;
    }
};

#endif //OOP_PLANREABILITARE_H
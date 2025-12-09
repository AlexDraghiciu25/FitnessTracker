#include "../include/PlanReabilitare.h"
#include "../include/ExceptiiPlanuri.h"

PlanReabilitare::PlanReabilitare(const std::string &numePlan, int durataLuni,
                                 NivelExperienta nivelExperienta, int zilePeSaptamana,
                                 const std::string &tipLeziune, bool necesitaSupervizare, int nivelDurere)
    : PlanAntrenament(numePlan, durataLuni, nivelExperienta, zilePeSaptamana),
    tipLeziune(tipLeziune),
    necesitaSupervizare(necesitaSupervizare),
    nivelDurere(nivelDurere) {

    if (nivelDurere < 0 || nivelDurere > 10) {
        throw ExceptieValidarePlan("Nivelul de durere trebuie sa se incadreze in scara 0 - 10!");
    }

    if (tipLeziune.empty()) {
        throw ExceptieValidarePlan("Tip leziune nu poate fi gol!");
    }
}

double PlanReabilitare::calculeazaIntensitate(int saptamana) const {
    double intensitateBaza = 30.0;
    double crestere = saptamana * 5.0;
    double intensitate = intensitateBaza + crestere;
    return (intensitate > 70.0) ? 70.0 : intensitate;
}

std::string PlanReabilitare::getTipPlan() const {
    return "Reabilitare/Recuperare";
}

void PlanReabilitare::genereazaRecomandari(std::ostream &os) const {
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

PlanReabilitare* PlanReabilitare::clone() const {
    return new PlanReabilitare(*this);
}

std::vector<std::string> PlanReabilitare::genereazaProgram(int saptamana) const {
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

        sesiune += " | Durere acceptabila: max " + std::to_string(std::max(0, nivelDurere - saptamana)) + "/10";
        program.push_back(sesiune);
    }

    if (necesitaSupervizare) {
        program.emplace_back("ATENTIE: Planul necesita supervizare medicala!");
    }

    program.push_back("Leziune tratata: " + tipLeziune);

    return program;
}

const std::string& PlanReabilitare::getTipLeziune() const {
    return tipLeziune;
}

int PlanReabilitare::getNivelDurere() const {
    return nivelDurere;
}
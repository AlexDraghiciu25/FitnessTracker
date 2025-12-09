#include "../include/PlanAntrenament.h"
#include <utility>
#include "../include/ExceptiiPlanuri.h"

// Initializare membru static
int PlanAntrenament::numarPlanuri = 0;

PlanAntrenament::PlanAntrenament(std::string numePlan, int durataLuni,
                                 NivelExperienta nivelExperienta, int zilePeSaptamana)
    : numePlan(std::move(numePlan)),
      durataLuni(durataLuni),
      nivelExperienta(nivelExperienta),
      zilePeSaptamana(zilePeSaptamana),
      saptamanaCurenta(1) {

    // Validari
    if (durataLuni <= 0 || durataLuni > 12) {
        throw ExceptieValidarePlan("Durata trebuie sa fie intre 1-12 luni!");
    }

    if (zilePeSaptamana < 1 || zilePeSaptamana > 7) {
        throw ExceptieValidarePlan("Zile pe saptamana trebuie sa fie intre 1-7!");
    }

    numarPlanuri++;
}

void PlanAntrenament::executaSaptamana(int saptamana) {
    std::cout << "\n=== EXECUTARE SAPTAMANA " << saptamana
              << " - " << numePlan << " ===\n";

    // Apel virtual - fiecare derivata genereaza propriul program
    auto program = genereazaProgram(saptamana);
    for (const auto& zi : program) {
        std::cout << "  " << zi << "\n";
    }

    // Logica comuna pentru toate planurile
    std::cout << "\n  Intensitate recomandata: "
              << calculeazaIntensitate(saptamana) << "%\n";
    std::cout << "  Tip plan: " << getTipPlan() << "\n";

    // Actualizare stare
    saptamanaCurenta = saptamana;
}

void PlanAntrenament::afiseazaPlan(std::ostream& os) const {
    os << "\n=== PLAN ANTRENAMENT: " << numePlan << " ===\n";
    os << "Durata: " << durataLuni << " luni\n";
    os << "Nivel: " << toString(nivelExperienta) << "\n";
    os << "Zile/saptamana: " << zilePeSaptamana << "\n";
    os << "Saptamana curenta: " << saptamanaCurenta << "/" << (durataLuni * 4) << "\n";
    genereazaRecomandari(os);
}

const std::string& PlanAntrenament::getNumePlan() const {
    return numePlan;
}

int PlanAntrenament::getDurataLuni() const {
    return durataLuni;
}

int PlanAntrenament::getSaptamanaCurenta() const {
    return saptamanaCurenta;
}

void PlanAntrenament::setSaptamanaCurenta(int saptamana) {
    saptamanaCurenta = saptamana;
}

int PlanAntrenament::getNumarPlanuri() {
    return numarPlanuri;
}

void PlanAntrenament::resetNumarPlanuri() {
    numarPlanuri = 0;
}

std::ostream& operator<<(std::ostream& os, const PlanAntrenament& plan) {
    plan.afiseazaPlan(os);
    return os;
}
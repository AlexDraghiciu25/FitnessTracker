#include "PlanAntrenament.h"

#include <utility>
#include "ExceptiiPlanuri.h"

int PlanAntrenament::numarPlanuri = 0;  // Initializare static

PlanAntrenament::PlanAntrenament(std::string  numePlan, int durataLuni,
                                 std::string nivelExperienta, int zilePeSaptamana)
    : numePlan(std::move(numePlan)),
      durataLuni(durataLuni),
      nivelExperienta(std::move(nivelExperienta)),
      zilePeSaptamana(zilePeSaptamana),
      saptamanaCurenta(1) {

    // THROW exceptii pentru validare
    if (durataLuni <= 0 || durataLuni > 12) {
        throw ExceptieValidarePlan("Durata trebuie sa fie intre 1-12 luni!");
    }

    if (zilePeSaptamana < 1 || zilePeSaptamana > 7) {
        throw ExceptieValidarePlan("Zile pe saptamana trebuie sa fie intre 1-7!");
    }

    if (this->nivelExperienta != "Incepator" &&
        this->nivelExperienta != "Intermediar" &&
        this->nivelExperienta != "Avansat") {
        throw ExceptieValidarePlan("Nivel experienta invalid!");
        }

    numarPlanuri++;
}

std::ostream& operator<<(std::ostream& os, const PlanAntrenament& plan) {
    plan.afiseazaPlan(os);
    return os;
}


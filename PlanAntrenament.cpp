#include "PlanAntrenament.h"

#include <utility>
#include "ExceptiiPlanuri.h"

int PlanAntrenament::numarPlanuri = 0;  // Initializare static

PlanAntrenament::PlanAntrenament(std::string  numePlan, int durataLuni,
                                 NivelExperienta nivelExperienta, int zilePeSaptamana)
    : numePlan(std::move(numePlan)),
      durataLuni(durataLuni),
      nivelExperienta(nivelExperienta),
      zilePeSaptamana(zilePeSaptamana),
      saptamanaCurenta(1) {

    // THROW exceptii pentru validare
    if (durataLuni <= 0 || durataLuni > 12) {
        throw ExceptieValidarePlan("Durata trebuie sa fie intre 1-12 luni!");
    }

    if (zilePeSaptamana < 1 || zilePeSaptamana > 7) {
        throw ExceptieValidarePlan("Zile pe saptamana trebuie sa fie intre 1-7!");
    }

    numarPlanuri++;
}

std::ostream& operator<<(std::ostream& os, const PlanAntrenament& plan) {
    plan.afiseazaPlan(os);
    return os;
}


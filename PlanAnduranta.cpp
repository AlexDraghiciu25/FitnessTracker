#include "PlanAnduranta.h"

#include <utility>
#include "ExceptiiPlanuri.h"

PlanAnduranta::PlanAnduranta(const std::string &numePlan, int durataLuni,
                            NivelExperienta nivelExperienta, int zilePeSaptamana,
                            double distantaTinta, std::string tipActivitate,
                            int minuteBazaPerSesiune)
    : PlanAntrenament(numePlan, durataLuni, nivelExperienta, zilePeSaptamana),
    distantaTinta(distantaTinta),
    tipActivitate(std::move(tipActivitate)),
    minuteBazaPerSesiune(minuteBazaPerSesiune) {

    if (distantaTinta < 1.0 || distantaTinta > 100.0) {
        throw ExceptieValidarePlan("Distanta tinta 1 - 100 km!");
    }

    if (minuteBazaPerSesiune < 20 || minuteBazaPerSesiune > 120) {
        throw ExceptieConfigurare("Minute recomandate per sesiune 20 - 120!");
    }
}
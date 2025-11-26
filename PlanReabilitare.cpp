#include "PlanReabilitare.h"
#include "ExceptiiPlanuri.h"

PlanReabilitare::PlanReabilitare(const std::string &numePlan, int durataLuni,
                                const std::string &nivelExperienta, int zilePeSaptamana,
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
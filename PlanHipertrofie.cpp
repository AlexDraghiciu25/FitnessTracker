#include "PlanHipertrofie.h"

#include <utility>
#include "ExceptiiPlanuri.h"

PlanHipertrofie::PlanHipertrofie(const std::string &numePlan, int durataLuni,
                                NivelExperienta nivelExperienta, int zilePeSaptamana,
                                std::string  tipSplit, int seturiPerGrupaMusculara, int repetatariPerSet, double surplusCaloric)
    : PlanAntrenament(numePlan, durataLuni, nivelExperienta, zilePeSaptamana),
    tipSplit(std::move(tipSplit)),
    seturiPerGrupaMusculara(seturiPerGrupaMusculara),
    repetariPerSet(repetatariPerSet),
    surplusCaloric(surplusCaloric) {

    if (seturiPerGrupaMusculara < 10 || seturiPerGrupaMusculara > 30) {
        throw ExceptieConfigurare("Seturi recomandate per grupa musculara 10 - 30!");
    }

    if (repetatariPerSet < 6 || repetatariPerSet > 15) {
        throw ExceptieConfigurare("Repetari recomandate pentru hipertrofie 6 - 15 reps!");
    }

    if (surplusCaloric < 200 || surplusCaloric > 500) {
        throw ExceptieConfigurare("Surplus caloric recomandat 200 - 500 kcal/zi!");
    }
}
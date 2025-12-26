#include "../include/PlanFactory.h"
#include "../include/ExceptiiPlanuri.h"
#include <algorithm>
#include <cctype>

// ==================== FACTORY METHOD PRINCIPAL ====================

std::shared_ptr<PlanAntrenament> PlanFactory::creazaPlan(
    TipPlanEnum tip,
    const std::string& numePlan,
    int durataLuni,
    NivelExperienta nivel,
    int zilePeSaptamana
) {
    switch (tip) {
        case TipPlanEnum::SLABIRE: {
            double targetCalorii = (nivel == NivelExperienta::INCEPATOR) ? 1800 : 1600;
            double deficit = getDeficitCaloricRecomandat(nivel);
            int minuteCardio = (nivel == NivelExperienta::INCEPATOR) ? 20 : 30;

            return creazaPlanSlabire(
                numePlan, durataLuni, nivel, zilePeSaptamana,
                targetCalorii, deficit, minuteCardio
            );
        }

        case TipPlanEnum::HIPERTROFIE: {
            std::string split = (nivel == NivelExperienta::INCEPATOR) ? "Full Body" : "Push/Pull/Legs";
            int seturi = getSeturiRecomandati(nivel);
            int repetari = 10;
            double surplus = (nivel == NivelExperienta::INCEPATOR) ? 250 : 350;

            return creazaPlanHipertrofie(
                numePlan, durataLuni, nivel, zilePeSaptamana,
                split, seturi, repetari, surplus
            );
        }

        case TipPlanEnum::ANDURANTA: {
            double distanta = (nivel == NivelExperienta::INCEPATOR) ? 5.0 : 10.0;
            int minute = (nivel == NivelExperienta::INCEPATOR) ? 30 : 45;

            return creazaPlanAnduranta(
                numePlan, durataLuni, nivel, zilePeSaptamana,
                distanta, "Alergare", minute
            );
        }

        case TipPlanEnum::REABILITARE: {
            return creazaPlanReabilitare(
                numePlan, durataLuni, nivel, zilePeSaptamana,
                "Recuperare generala", false, 3
            );
        }

        default:
            throw ExceptieConfigurare("Tip plan necunoscut!");
    }
}

// ==================== UTILITY METHODS ====================

TipPlanEnum PlanFactory::stringLaTipPlan(const std::string& tipStr) {
    std::string lower = tipStr;
    std::ranges::transform(lower, lower.begin(), ::tolower);

    if (lower == "slabire" || lower == "pierdere" || lower == "weight loss")
        return TipPlanEnum::SLABIRE;

    if (lower == "hipertrofie" || lower == "masa" || lower == "bulk" || lower == "muscle")
        return TipPlanEnum::HIPERTROFIE;

    if (lower == "anduranta" || lower == "rezistenta" || lower == "endurance" || lower == "cardio")
        return TipPlanEnum::ANDURANTA;

    if (lower == "reabilitare" || lower == "recuperare" || lower == "rehab")
        return TipPlanEnum::REABILITARE;

    throw ExceptieValidarePlan("Tip plan invalid: " + tipStr);
}

double PlanFactory::getDeficitCaloricRecomandat(NivelExperienta nivel) {
    switch (nivel) {
        case NivelExperienta::INCEPATOR: return 300.0;
        case NivelExperienta::INTERMEDIAR: return 400.0;
        case NivelExperienta::AVANSAT: return 500.0;
        default: return 350.0;
    }
}

int PlanFactory::getSeturiRecomandati(NivelExperienta nivel) {
    switch (nivel) {
        case NivelExperienta::INCEPATOR: return 12;
        case NivelExperienta::INTERMEDIAR: return 18;
        case NivelExperienta::AVANSAT: return 24;
        default: return 15;
    }
}
#ifndef OOP_PLANFACTORY_H
#define OOP_PLANFACTORY_H

#include <memory>
#include <string>
#include "PlanAntrenament.h"
#include "PlanSlabire.h"
#include "PlanHipertrofie.h"
#include "PlanAnduranta.h"
#include "PlanReabilitare.h"
#include "Enums.h"

enum class TipPlanEnum {
    SLABIRE,
    HIPERTROFIE,
    ANDURANTA,
    REABILITARE
};

// Conversie tip plan to string (pentru afisare)
inline std::string tipPlanLaString(TipPlanEnum tip) {
    switch (tip) {
        case TipPlanEnum::SLABIRE: return "Slabire";
        case TipPlanEnum::HIPERTROFIE: return "Hipertrofie";
        case TipPlanEnum::ANDURANTA: return "Anduranta";
        case TipPlanEnum::REABILITARE: return "Reabilitare";
        default: return "Necunoscut";
    }
}

// Design Pattern: Factory Method

class PlanFactory {
public:
    PlanFactory() = delete;

    // Metoda principala: creeaza plan cu parametri default bazati pe tip
    static std::shared_ptr<PlanAntrenament> creazaPlan(
        TipPlanEnum tip,
        const std::string& numePlan,
        int durataLuni,
        NivelExperienta nivel,
        int zilePeSaptamana
    );

    static std::shared_ptr<PlanSlabire> creazaPlanSlabire(
        const std::string& numePlan,
        int durataLuni,
        NivelExperienta nivel,
        int zilePeSaptamana,
        double targetCalorii,
        double deficitCaloric,
        int minuteCardio
    ) {
        return std::make_shared<PlanSlabire>(
            numePlan, durataLuni, nivel, zilePeSaptamana,
            targetCalorii, deficitCaloric, minuteCardio
        );
    }

    static std::shared_ptr<PlanHipertrofie> creazaPlanHipertrofie(
        const std::string& numePlan,
        int durataLuni,
        NivelExperienta nivel,
        int zilePeSaptamana,
        const std::string& tipSplit,
        int seturiPerGrupa,
        int repetariPerSet,
        double surplusCaloric
    ) {
        return std::make_shared<PlanHipertrofie>(
            numePlan, durataLuni, nivel, zilePeSaptamana,
            tipSplit, seturiPerGrupa, repetariPerSet, surplusCaloric
        );
    }

    static std::shared_ptr<PlanAnduranta> creazaPlanAnduranta(
        const std::string& numePlan,
        int durataLuni,
        NivelExperienta nivel,
        int zilePeSaptamana,
        double distantaTinta,
        const std::string& tipActivitate,
        int minuteBaza
    ) {
        return std::make_shared<PlanAnduranta>(
            numePlan, durataLuni, nivel, zilePeSaptamana,
            distantaTinta, tipActivitate, minuteBaza
        );
    }

    static std::shared_ptr<PlanReabilitare> creazaPlanReabilitare(
        const std::string& numePlan,
        int durataLuni,
        NivelExperienta nivel,
        int zilePeSaptamana,
        const std::string& tipLeziune,
        bool necesitaSupervizare,
        int nivelDurere
    ) {
        return std::make_shared<PlanReabilitare>(
            numePlan, durataLuni, nivel, zilePeSaptamana,
            tipLeziune, necesitaSupervizare, nivelDurere
        );
    }

    // Conversie string la enum (pt input utilizator)
    static TipPlanEnum stringLaTipPlan(const std::string& tipStr);

    // Sugestii parametri default bazate pe nivel experienta
    static double getDeficitCaloricRecomandat(NivelExperienta nivel);
    static int getSeturiRecomandati(NivelExperienta nivel);
};

#endif //OOP_PLANFACTORY_H
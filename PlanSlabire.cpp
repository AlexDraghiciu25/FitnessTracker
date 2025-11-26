#include "PlanSlabire.h"
#include "ExceptiiPlanuri.h"

PlanSlabire::PlanSlabire(const std::string &numePlan, int durataLuni,
                        const std::string &nivelExperienta, int zilePeSaptamana,
                        double targetCalorii, double deficitCaloric, int minuteCardioZilnic)
    : PlanAntrenament(numePlan, durataLuni, nivelExperienta, zilePeSaptamana),
    targetCaloriiPeZi(targetCalorii),
    deficitCaloric(deficitCaloric),
    minuteCardioZilnic(minuteCardioZilnic) {

    if (targetCaloriiPeZi < 1200) {
        throw ExceptieValidarePlan("Target calorii prea mic (minim 1200 kcal)!");
    }

    if (deficitCaloric < 200 || deficitCaloric > 1000) {
        throw ExceptieConfigurare("Deficit caloric in afara valorilor recomandate(200 - 1000 kcal/zi)!");
    }
}
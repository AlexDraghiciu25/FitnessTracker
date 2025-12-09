#include "../include/PlanSlabire.h"
#include "../include/ExceptiiPlanuri.h"
#include <string>

PlanSlabire::PlanSlabire(const std::string &numePlan, int durataLuni,
                        NivelExperienta nivelExperienta, int zilePeSaptamana,
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

double PlanSlabire::calculeazaIntensitate(int saptamana) const {
    if (saptamana <= 2)
        return 60.0;
    else if (saptamana <= 4)
        return 70.0;
    else if (saptamana <= 8)
        return 80.0;
    return 85;
}

std::string PlanSlabire::getTipPlan() const {
    return "Slabire/Pierdere greutate";
}

void PlanSlabire::genereazaRecomandari(std::ostream &os) const {
    os << "Tip: " << getTipPlan() << "\n";
    os << "Target calorii/zi: " << targetCaloriiPeZi << " kcal\n";
    os << "Deficit caloric: " << deficitCaloric << " kcal/zi\n";
    os << "Cardio zilnic: " << minuteCardioZilnic << " minute\n";
    os << "Intensitate curenta: " << calculeazaIntensitate(saptamanaCurenta) << "%\n";
    os << "\nRecomandari:\n";
    os << "- Focus pe exercitii cardio (alergare, ciclism, inot)\n";
    os << "- Mentine deficit caloric consistent\n";
    os << "- Hidrateaza-te corespunzator\n";
}

PlanSlabire* PlanSlabire::clone() const {
    return new PlanSlabire(*this);
}

std::vector<std::string> PlanSlabire::genereazaProgram(int saptamana) const {
    std::vector<std::string> program;

    int minuteCardio = minuteCardioZilnic + (saptamana * 3); // Progresie
    double intensitate = calculeazaIntensitate(saptamana);

    for (int zi = 1; zi <= zilePeSaptamana; zi++) {
        std::string sesiune = "Zi " + std::to_string(zi) + ": ";
        sesiune += std::to_string(minuteCardio) + " min cardio @ ";
        sesiune += std::to_string(static_cast<int>(intensitate)) + "% intensitate";
        sesiune += " (" + std::to_string(static_cast<int>(minuteCardio * 8)) + " kcal)";
        program.push_back(sesiune);
    }

    program.push_back("NOTA: Mentine deficit caloric de " +
                     std::to_string(static_cast<int>(deficitCaloric)) + " kcal/zi");

    return program;
}

double PlanSlabire::getTargetCalorii() const {
    return targetCaloriiPeZi;
}

double PlanSlabire::getDeficitCaloric() const {
    return deficitCaloric;
}
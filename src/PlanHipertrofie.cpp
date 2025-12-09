#include "../include/PlanHipertrofie.h"
#include <utility>
#include <algorithm> // Pentru std::min
#include "../include/ExceptiiPlanuri.h"

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

double PlanHipertrofie::calculeazaIntensitate(int saptamana) const {
    double intensitateBaza = 70.0;
    double cresterePerSaptamana = 1.5;
    return std::min(intensitateBaza + (saptamana * cresterePerSaptamana), 90.0);
}

std::string PlanHipertrofie::getTipPlan() const {
    return "Hipertrofie/Masa musculara";
}

void PlanHipertrofie::genereazaRecomandari(std::ostream &os) const {
    os << "Tip: " << getTipPlan() << "\n";
    os << "Split: " << tipSplit << "\n";
    os << "Seturi per grup muscular: " << seturiPerGrupaMusculara << "\n";
    os << "Repetari per set: " << repetariPerSet << "\n";
    os << "Surplus caloric: +" << surplusCaloric << " kcal/zi\n";
    os << "Intensitate curenta: " << calculeazaIntensitate(saptamanaCurenta) << "%\n";
    os << "\nRecomandari:\n";
    os << "- Focus pe exercitii compuse (squat, deadlift, bench press)\n";
    os << "- Progresie progresiva (creste greutatea gradual)\n";
    os << "- Somn 7-9 ore pentru recuperare\n";
    os << "- Consum proteic: 1.6 - 2.2 g/kg corp\n";
}

PlanHipertrofie* PlanHipertrofie::clone() const {
    return new PlanHipertrofie(*this);
}

std::vector<std::string> PlanHipertrofie::genereazaProgram(int saptamana) const {
    std::vector<std::string> program;

    if (tipSplit == "Push/Pull/Legs" || tipSplit == "PPL") {
        program.push_back("Zi 1 (PUSH): Piept, Umeri, Triceps - " +
                         std::to_string(seturiPerGrupaMusculara) + " seturi x " +
                         std::to_string(repetariPerSet) + " reps");
        program.push_back("Zi 2 (PULL): Spate, Biceps - " +
                         std::to_string(seturiPerGrupaMusculara) + " seturi x " +
                         std::to_string(repetariPerSet) + " reps");
        program.push_back("Zi 3 (LEGS): Picioare, Abdomen - " +
                         std::to_string(seturiPerGrupaMusculara) + " seturi x " +
                         std::to_string(repetariPerSet) + " reps");
    } else if (tipSplit == "Full" || tipSplit == "Full Body") {
        for (int zi = 1; zi <= zilePeSaptamana; zi++) {
            program.push_back("Zi " + std::to_string(zi) + " (Full Body): " +
                             "Toate grupele musculare - " +
                             std::to_string(seturiPerGrupaMusculara / 2) + " seturi/grupa");
        }
    } else {
        program.push_back("Split personalizat: " + tipSplit);
    }

    int volumeTotal = seturiPerGrupaMusculara * zilePeSaptamana * (1 + saptamana / 4);
    program.push_back("VOLUM TOTAL SAPTAMANAL: " + std::to_string(volumeTotal) + " seturi");
    program.push_back("SURPLUS CALORIC: +" + std::to_string(static_cast<int>(surplusCaloric)) + " kcal/zi");

    return program;
}

const std::string& PlanHipertrofie::getTipSplit() const {
    return tipSplit;
}

int PlanHipertrofie::getSeturiPerGrupaMusculara() const {
    return seturiPerGrupaMusculara;
}
#ifndef OOP_PLANHIPERTROFIE_H
#define OOP_PLANHIPERTROFIE_H

#include "PlanAntrenament.h"

class PlanHipertrofie : public PlanAntrenament {
private:
    std::string tipSplit;
    int seturiPerGrupaMusculara;
    int repetariPerSet;
    double surplusCaloric;

public:
    PlanHipertrofie(const std::string& nume, int durataLuni,
                    const std::string& nivelExperienta, int zilePeSaptamana,
                    std::string  tipSplit, int seturiPerGrupaMusculara,
                    int repetatariPerSet, double surplusCaloric);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override {
        double intensitateBaza = 70.0;
        double cresterePerSaptamana = 1.5;
        return std::min(intensitateBaza + (saptamana * cresterePerSaptamana), 90.0);
    }

    [[nodiscard]] std::string getTipPlan() const override {
        return "Hipertrofie/Masa musculara";
    }

    void genereazaRecomandari(std::ostream &os) const override {
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

    [[nodiscard]] PlanHipertrofie* clone() const override {
        return new PlanHipertrofie(*this);
    }

    [[nodiscard]] const std::string& getTipSplit() const {
        return tipSplit;
    }

    [[nodiscard]] int getSeturiPerGrupaMusculara() const {
        return seturiPerGrupaMusculara;
    }
};

#endif //OOP_PLANHIPERTROFIE_H
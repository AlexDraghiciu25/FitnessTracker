#ifndef OOP_PLANSLABIRE_H
#define OOP_PLANSLABIRE_H

#include "PlanAntrenament.h"

class PlanSlabire : public PlanAntrenament {
private:
    double targetCaloriiPeZi;
    double deficitCaloric;
    int minuteCardioZilnic;

public:
    PlanSlabire(const std::string &numePlan, int durataLuni,
                NivelExperienta nivelExperienta, int zilePeSaptamana,
                double targetCalorii, double deficitCaloric, int minuteCardioZilnic);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override;
    [[nodiscard]] std::string getTipPlan() const override;
    void genereazaRecomandari(std::ostream &os) const override;
    [[nodiscard]] PlanSlabire* clone() const override;
    [[nodiscard]] std::vector<std::string> genereazaProgram(int saptamana) const override;

    [[nodiscard]] double getTargetCalorii() const;
    [[nodiscard]] double getDeficitCaloric() const;
};

#endif //OOP_PLANSLABIRE_H
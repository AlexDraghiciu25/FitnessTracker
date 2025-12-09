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
                    NivelExperienta nivelExperienta, int zilePeSaptamana,
                    std::string  tipSplit, int seturiPerGrupaMusculara,
                    int repetatariPerSet, double surplusCaloric);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override;
    [[nodiscard]] std::string getTipPlan() const override;
    void genereazaRecomandari(std::ostream &os) const override;
    [[nodiscard]] PlanHipertrofie* clone() const override;
    [[nodiscard]] std::vector<std::string> genereazaProgram(int saptamana) const override;

    [[nodiscard]] const std::string& getTipSplit() const;
    [[nodiscard]] int getSeturiPerGrupaMusculara() const;
};

#endif //OOP_PLANHIPERTROFIE_H
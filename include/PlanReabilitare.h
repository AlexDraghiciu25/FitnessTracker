#ifndef OOP_PLANREABILITARE_H
#define OOP_PLANREABILITARE_H

#include "PlanAntrenament.h"

class PlanReabilitare : public PlanAntrenament {
private:
    std::string tipLeziune;
    bool necesitaSupervizare;
    int nivelDurere;
public:
    PlanReabilitare(const std::string& numePlan, int durataLuni,
                    NivelExperienta nivelExperienta, int zilePeSaptamana,
                    const std::string& tipLeziune, bool necesitaSupervizare, int nivelDurere);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override;

    [[nodiscard]] std::string getTipPlan() const override;

    void genereazaRecomandari(std::ostream &os) const override;

    [[nodiscard]] PlanReabilitare* clone() const override;
    [[nodiscard]] std::vector<std::string> genereazaProgram(int saptamana) const override;

    [[nodiscard]] const std::string& getTipLeziune() const;
    [[nodiscard]] int getNivelDurere() const;
};

#endif //OOP_PLANREABILITARE_H
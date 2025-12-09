#ifndef OOP_PLANANDURANTA_H
#define OOP_PLANANDURANTA_H

#include "../PlanAntrenament.h"

class PlanAnduranta : public PlanAntrenament {
private:
    double distantaTinta;
    std::string tipActivitate;
    int minuteBazaPerSesiune;

public:
    PlanAnduranta(const std::string &numePlan, int durataLuni,
                    NivelExperienta nivelExperienta, int zilePeSaptamana,
                    double distantaTinta, std::string tipActivitate, int minuteBazaPerSesiune);

    [[nodiscard]] double calculeazaIntensitate(int saptamana) const override;
    [[nodiscard]] std::string getTipPlan() const override;
    void genereazaRecomandari(std::ostream &os) const override;
    [[nodiscard]] PlanAnduranta* clone() const override;
    [[nodiscard]] std::vector<std::string> genereazaProgram(int saptamana) const override;

    [[nodiscard]] double getDistantaTinta() const;
};

#endif //OOP_PLANANDURANTA_H
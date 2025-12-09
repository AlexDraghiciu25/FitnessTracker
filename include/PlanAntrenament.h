#ifndef OOP_PLANANTRENAMENT_H
#define OOP_PLANANTRENAMENT_H
#pragma once
#include <iostream>
#include <string>
#include "Enums.h"
#include <vector>

class PlanAntrenament {
protected:
    std::string numePlan;
    int durataLuni;
    NivelExperienta nivelExperienta;
    int zilePeSaptamana;
    int saptamanaCurenta;
    static int numarPlanuri;
public:
    PlanAntrenament(std::string  numePlan, int durataLuni,
        NivelExperienta nivelExeperienta, int zilePeSaptamana);

    virtual ~PlanAntrenament() = default;

    [[nodiscard]] virtual double calculeazaIntensitate(int saptamana) const = 0;
    [[nodiscard]] virtual std::string getTipPlan() const = 0;
    virtual void genereazaRecomandari(std::ostream& os) const = 0;
    [[nodiscard]] virtual PlanAntrenament* clone() const = 0;

    [[nodiscard]] virtual std::vector<std::string> genereazaProgram(int saptamana) const = 0;
    void executaSaptamana(int saptamana);

    void afiseazaPlan(std::ostream& os) const ;

    [[nodiscard]] const std::string& getNumePlan() const;

    [[nodiscard]] int getDurataLuni() const;

    [[nodiscard]] int getSaptamanaCurenta() const;

    void setSaptamanaCurenta(int saptamana) ;

    static int getNumarPlanuri() ;

    static void resetNumarPlanuri() ;

    friend std::ostream& operator<<(std::ostream& os, const PlanAntrenament &plan);
};

#endif //OOP_PLANANTRENAMENT_H
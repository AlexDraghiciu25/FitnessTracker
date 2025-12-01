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
    void executaSaptamana(int saptamana) {
        std::cout << "\n=== EXECUTARE SAPTAMANA " << saptamana
                  << " - " << numePlan << " ===\n";

        // Apel virtual - fiecare derivata genereaza propriul program
        auto program = genereazaProgram(saptamana);
        for (const auto& zi : program) {
            std::cout << "  " << zi << "\n";
        }

        // Logica comuna pentru toate planurile
        std::cout << "\n  Intensitate recomandata: "
                  << calculeazaIntensitate(saptamana) << "%\n";
        std::cout << "  Tip plan: " << getTipPlan() << "\n";

        // Actualizare stare
        saptamanaCurenta = saptamana;
    }

    void afiseazaPlan(std::ostream& os) const {
        os << "\n=== PLAN ANTRENAMENT: " << numePlan << " ===\n";
        os << "Durata: " << durataLuni << " luni\n";
        os << "Nivel: " << toString(nivelExperienta) << "\n";
        os << "Zile/saptamana: " << zilePeSaptamana << "\n";
        os << "Saptamana curenta: " << saptamanaCurenta << "/" << (durataLuni * 4) << "\n";
        genereazaRecomandari(os);
    }

    [[nodiscard]] const std::string& getNumePlan() const {
        return numePlan;
    };

    [[nodiscard]] int getDurataLuni() const {
        return durataLuni;
    }

    [[nodiscard]] int getSaptamanaCurenta() const {
        return saptamanaCurenta;
    }

    void setSaptamanaCurenta(int saptamana) {
        saptamanaCurenta = saptamana;
    }

    static int getNumarPlanuri() {
        return numarPlanuri;
    }

    static void resetNumarPlanuri() {
        numarPlanuri = 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const PlanAntrenament &plan);
};

#endif //OOP_PLANANTRENAMENT_H
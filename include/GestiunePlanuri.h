#ifndef OOP_GESTIUNEPLANURI_H
#define OOP_GESTIUNEPLANURI_H

#include <filesystem>
#include <vector>
#include <memory>
#include "PlanAntrenament.h"

class GestiunePlanuri {
private:
    std::string numeUtilizator;
    std::vector<std::shared_ptr<PlanAntrenament>> planuri;
    std::shared_ptr<PlanAntrenament> planActiv;

public:
    explicit GestiunePlanuri(std::string nume);     // manager de planuri pt un utilizator

    GestiunePlanuri(const GestiunePlanuri& other);      //constr cop
    GestiunePlanuri& operator=(GestiunePlanuri other) {
        swap(*this, other);
        return *this;
    }

    // Schimb continutul a 2 ob
    friend void swap(GestiunePlanuri& prim, GestiunePlanuri& secund) noexcept {
        using std::swap;
        swap(prim.numeUtilizator, secund.numeUtilizator);
        swap(prim.planuri, secund.planuri);
        swap(prim.planActiv, secund.planActiv);
    }

    void adaugaPlan(const std::shared_ptr<PlanAntrenament>& plan);
    void activeazaPlan(int index);
    void afiseazaToatePlanurile() const;

    [[nodiscard]] double calculeazaIntensitateaMedie() const;

    [[nodiscard]] int getNumarPlanuriSlabire() const;
    [[nodiscard]] int getNumarPlanuriHipertrofie() const;
    void afiseazaPlanuriSlabire() const;

     [[nodiscard]] std::size_t getNumarPlanuri() const {
        return planuri.size();
    }

    [[nodiscard]] std::shared_ptr<PlanAntrenament> getPlanActiv() const {
        return planActiv;
    }

    friend std::ostream& operator<<(std::ostream& os, const GestiunePlanuri& gestiune);
};

#endif //OOP_GESTIUNEPLANURI_H
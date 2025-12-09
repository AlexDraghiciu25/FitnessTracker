#include "../include/GestiunePlanuri.h"
#include "../include/PlanSlabire.h"
#include "../include/PlanHipertrofie.h"
#include <iostream>
#include <numeric>

GestiunePlanuri::GestiunePlanuri(std::string nume)
    : numeUtilizator(std::move(nume)) {}

GestiunePlanuri::GestiunePlanuri(const GestiunePlanuri& other) 
    : numeUtilizator(other.numeUtilizator), planActiv(nullptr) {

    for (const auto& plan : other.planuri) {
        planuri.push_back(std::shared_ptr<PlanAntrenament>(plan->clone()));
    }

    // Copiem si planul activ daca exista, cautandu-l in noua lista clonata
    if (other.planActiv) {
        // Simplificare: Il clonam separat sau il lasam null daca nu e critic
        planActiv = std::shared_ptr<PlanAntrenament>(other.planActiv->clone());
    }
}

// Adaugare plan in vector
void GestiunePlanuri::adaugaPlan(const std::shared_ptr<PlanAntrenament>& plan) {
    planuri.push_back(plan);
}

void GestiunePlanuri::activeazaPlan(int index) {
    if (index >= 0 && static_cast<std::size_t>(index) < planuri.size()) {
        planActiv = planuri[index];
        std::cout << "Planul '" << planActiv->getNumePlan() << "' a fost activat!\n";
    } else {
        std::cout << "Index invalid pentru activare plan!\n";
    }
}

// Afisare polimorfica (apeleaza afiseazaPlan -> genereazaRecomandari virtuala)
void GestiunePlanuri::afiseazaToatePlanurile() const {
    if (planuri.empty()) {
        std::cout << "Nu exista planuri de afisat pentru " << numeUtilizator << ".\n";
        return;
    }

    std::cout << "\n=== LISTA PLANURI PENTRU " << numeUtilizator << " ===\n";
    for (const auto& plan : planuri) {
        // Apeleaza operatorul << sau functia de afisare din baza
        std::cout << *plan << "\n"; 
    }
}

// Calcul intensitate medie (folosind saptamana 1 ca referinta)
double GestiunePlanuri::calculeazaIntensitateaMedie() const {
    if (planuri.empty()) return 0.0;

    double sumaIntensitati = 0.0;
    for (const auto& plan : planuri) {
        sumaIntensitati += plan->calculeazaIntensitate(1); // Luam saptamana 1 ca exemplu
    }
    return sumaIntensitati / static_cast<double>(planuri.size());
}

// Helper counts
int GestiunePlanuri::getNumarPlanuriSlabire() const {
    int count = 0;
    for (const auto& plan : planuri) {
        // Putem verifica stringul getTipPlan sau folosim dynamic_cast
        if (std::dynamic_pointer_cast<PlanSlabire>(plan)) {
            count++;
        }
    }
    return count;
}

int GestiunePlanuri::getNumarPlanuriHipertrofie() const {
    int count = 0;
    for (const auto& plan : planuri) {
        if (std::dynamic_pointer_cast<PlanHipertrofie>(plan)) {
            count++;
        }
    }
    return count;
}

void GestiunePlanuri::afiseazaPlanuriSlabire() const {
    std::cout << "\n--- Analiza Detaliata: Planuri de Slabire ---\n";
    bool gasit = false;

    for (const auto& plan : planuri) {
        // Incercam sa convertim pointerul generic (PlanAntrenament) in pointer specific (PlanSlabire)

        if (auto planSlabire = std::dynamic_pointer_cast<PlanSlabire>(plan)) {
            gasit = true;
            // Aici putem apela metode care exista DOAR in PlanSlabire (nu si in baza)
            std::cout << "Plan: " << planSlabire->getNumePlan() 
                      << " | Deficit Caloric: " << planSlabire->getDeficitCaloric() << " kcal/zi"
                      << " | Target: " << planSlabire->getTargetCalorii() << " kcal\n";
        }
    }

    if (!gasit) {
        std::cout << "Nu au fost gasite planuri de slabire.\n";
    }
}

std::ostream& operator<<(std::ostream& os, const GestiunePlanuri& gestiune) {
    os << "Utilizator Gestiune: " << gestiune.numeUtilizator << "\n";
    os << "Numar planuri: " << gestiune.planuri.size() << "\n";
    if (gestiune.planActiv) {
        os << "Plan Activ: " << gestiune.planActiv->getNumePlan() << "\n";
    } else {
        os << "Plan Activ: Niciunul\n";
    }
    return os;
}
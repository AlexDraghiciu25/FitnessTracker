#ifndef OOP_EXERCITIU_H
#define OOP_EXERCITIU_H

#include <iostream>
#include  <string>
#include "Enums.h"

class Exercitiu {
    private:
        std::string nume;   // numele exercitiului, EX: Flotari
        CategorieExercitiu categorie;      // numele categoriei, EX:Cardio, Forta, etc
        double calorii_arse_pe_min{};
        int durata{};     // durata in min a exercitiului
        Dificultate dificultate;    //dificultatea individuala pe ex
    public:
        Exercitiu();

        Exercitiu(const std::string& nume,CategorieExercitiu categorie,
            double calorii_arse_pe_min, int durata,Dificultate dificultate);

        /// Getters
        [[nodiscard]] const std::string& get_nume() const;
        [[nodiscard]] CategorieExercitiu get_categorie() const;
        [[nodiscard]] double get_calorii_arse_pe_min() const;
        [[nodiscard]] int get_durata() const;
        [[nodiscard]] Dificultate get_dificultate() const;

        /// Setters
        void set_nume(const std::string &nume);
        void set_categorie(CategorieExercitiu categorie);
        void set_calorii_arse_pe_min(double calorii_arse_pe_min);
        void set_durata(int durata);
        void set_dificultate(Dificultate dificultate);

        [[nodiscard]] double calculeazaCaloriiTotale() const;
        void afisare_detaliata() const;

        friend std::ostream& operator<<(std::ostream& os, const Exercitiu& exercitiu);
        friend std::istream& operator>>(std::istream& is, Exercitiu& exercitiu);

        bool operator==(const Exercitiu& exercitiu) const;
        bool operator>(const Exercitiu& exercitiu) const;
};

#endif //OOP_EXERCITIU_H
#ifndef OOP_ANTRENAMENT_H
#define OOP_ANTRENAMENT_H

#include <iostream>
#include  <string>
#include <vector>
#include "Exercitiu.h"

class Antrenament {
    private:
        std::string nume;
        std::vector<Exercitiu> exercitii;    // Array-ul cu toata lista de exercitii
        int nrExercitii{};
        std::string nivel;      // dific pe intreg antr
        int durataTotala{};   //timpul petrecut in min pentru toate ex adunat
    public:
        Antrenament();    //Constr def

        //Constr cu param
        Antrenament(const std::string& nume, const std::string& nivel);

        // Constructor de cop(creez ob nou)
        Antrenament(const Antrenament& antr);

        // operator de atriburie(modif ob exist)
        Antrenament& operator=(const Antrenament& antr);

        [[nodiscard]] std::string getNume() const;
        [[nodiscard]] int get_nrExercitii() const;

        void adaugExercitiu(const Exercitiu& ex);

        [[nodiscard]] int calculeazaDurataAntrenament() const;

        [[nodiscard]] double calculeazaCaloriiTotaleAntrenament() const;

        void AfisareAntrenamentComplet() const;

        // Apelez destructorul pentru a elibera memoria dinamica
        ~Antrenament();     // vect se curata autom

        Antrenament& operator+(const Exercitiu& exerc);

        friend std::ostream& operator<<(std::ostream& os, const Antrenament& antrenament);
};

#endif //OOP_ANTRENAMENT_H
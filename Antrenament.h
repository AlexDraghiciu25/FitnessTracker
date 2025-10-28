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
        int nrExercitii;
        std::string nivel;      // dific pe intreg antr
        int durataTotala;   //timpul petrecut in min pentru toate ex adunat
    public:
        Antrenament() = default;    //Constr def

        //Constr cu param
        Antrenament(const std::string& nume, const std::string& nivel) {
            this->nume = nume;
            this->nrExercitii = 0;
            this->nivel = nivel;
            this->durataTotala = 0;
        }

        // Constructor de cop(creez ob nou)
        Antrenament(const Antrenament& antr) {
            this->nume = antr.nume;
            this->nivel = antr.nivel;
            this->nrExercitii = antr.nrExercitii;
            this->durataTotala = antr.durataTotala;
            this->exercitii = antr.exercitii;
        }

        // operator de atriburie(modif ob exist)
        Antrenament& operator=(const Antrenament& antr) {
            this->nume = antr.nume;
            this->nivel = antr.nivel;
            this->nrExercitii = antr.nrExercitii;
            this->durataTotala = antr.durataTotala;
            this->exercitii = antr.exercitii;

            return *this;
        }

        std::string getNume() const {
            return this->nume;
        }

        int get_nrExercitii() const {
            return this->nrExercitii;
        }

        void adaugExercitiu(const Exercitiu& ex) {
            exercitii.push_back(ex);
            nrExercitii++;

            durataTotala += ex.get_durata();
        }

        int calculeazaDurataAntrenament() const{
            return this->durataTotala;
        }

        double calculeazaCaloriiTotaleAntrenament() const {
            double total = 0;
            for (int i = 0; i < nrExercitii; i++)
                total += exercitii[i].calculeazaCaloriiTotale();
            return total;
        }

        void AfisareAntrenamentComplet() const {
            for (int i = 0; i < nrExercitii; i++){
                std::cout << "Exercitiul cu numarul " << i + 1 << ":\n" << this->exercitii[i] << ".\n";
                std::cout << "Durata acestui exercitiu: " << exercitii[i].get_durata() << " min.\n";
            }
        }

        // Apelez destructorul pentru a elibera memoria dinamica
        ~Antrenament() = default;     // vect se curata autom

        Antrenament& operator+(const Exercitiu& exerc) {
            adaugExercitiu(exerc);
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Antrenament& antrenament) {
            os << "\nNumele exercitiului: " << antrenament.nume;
            os << "\nNivel: " << antrenament.nivel;
            os << "\nNumar exercitii: " << antrenament.nrExercitii;
            os << "\nDurata totala: " << antrenament.durataTotala << "\n";

            for (int i = 0; i < antrenament.nrExercitii; i++)
                os << antrenament.exercitii[i] << "\n";
            return os;
        }
};

#endif //OOP_ANTRENAMENT_H
#include "Antrenament.h"
#include <iostream>

Antrenament::Antrenament() = default;    //Constr def

//Constr cu param
Antrenament::Antrenament(const std::string& nume, const std::string& nivel) {
    this->nume = nume;
    this->nrExercitii = 0;
    this->nivel = nivel;
    this->durataTotala = 0;
}

// Constructor de cop(creez ob nou)
Antrenament::Antrenament(const Antrenament& antr) {
    this->nume = antr.nume;
    this->nivel = antr.nivel;
    this->nrExercitii = antr.nrExercitii;
    this->durataTotala = antr.durataTotala;
    this->exercitii = antr.exercitii;
}

// operator de atriburie(modif ob exist)
Antrenament& Antrenament::operator=(const Antrenament& antr) = default;

std::string Antrenament::getNume() const {
    return this->nume;
}

int Antrenament::get_nrExercitii() const {
    return this->nrExercitii;
}

void Antrenament::adaugExercitiu(const Exercitiu& ex) {
    exercitii.push_back(ex);
    nrExercitii++;

    durataTotala += ex.get_durata();
}

int Antrenament::calculeazaDurataAntrenament() const{
    return this->durataTotala;
}

double Antrenament::calculeazaCaloriiTotaleAntrenament() const {
    double total = 0;
    for (int i = 0; i < nrExercitii; i++)
        total += exercitii[i].calculeazaCaloriiTotale();
    return total;
}

// void Antrenament::AfisareAntrenamentComplet() const {
//     for (int i = 0; i < nrExercitii; i++){
//         std::cout << "Exercitiul cu numarul " << i + 1 << ":\n" << this->exercitii[i] << ".\n";
//         std::cout << "Durata acestui exercitiu: " << exercitii[i].get_durata() << " min.\n";
//     }
// }

// Apelez destructorul pentru a elibera memoria dinamica
Antrenament::~Antrenament() = default;     // vect se curata autom

Antrenament& Antrenament::operator+(const Exercitiu& exerc) {
    adaugExercitiu(exerc);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Antrenament& antrenament) {
    os << "\nNumele exercitiului: " << antrenament.nume;
    os << "\nNivel: " << antrenament.nivel;
    os << "\nNumar exercitii: " << antrenament.nrExercitii;
    os << "\nDurata totala: " << antrenament.durataTotala << "\n";

    for (int i = 0; i < antrenament.nrExercitii; i++)
        os << antrenament.exercitii[i] << "\n";
    return os;
}
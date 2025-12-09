#include <iostream>
#include <string>
#include "../include/Obiectiv.h"
#include "../include/Antrenament.h"
#include "../include/Utilizator.h"

Utilizator::Utilizator() = default;

        //Constr cu param
Utilizator::Utilizator(const std::string& nume, int varsta,
    double greutate_kg, double inaltime_cm, const Obiectiv& obiectiv) {
    this->nume = nume;
    this->varsta = varsta;
    this->greutate_kg = greutate_kg;
    this->inaltime_cm = inaltime_cm;
    this->numar_antrenamente_facute = 0;        // Le-am pus 0 deoarece la fiecare utilizator creat,
    this->calorii_arse = 0;                     // nu ar trebui sa aiba deja antrenamente facute sau calorii arse.
    this->obiectivCurent = obiectiv;
}

// Constr de cop
Utilizator::Utilizator(const Utilizator& utilizator) {
    this->nume = utilizator.nume;
    this->varsta = utilizator.varsta;
    this->greutate_kg = utilizator.greutate_kg;
    this->inaltime_cm = utilizator.inaltime_cm;
    this->numar_antrenamente_facute = utilizator.numar_antrenamente_facute;
    this->calorii_arse = utilizator.calorii_arse;
    this->obiectivCurent = utilizator.obiectivCurent;
}

Utilizator &Utilizator::operator=(const Utilizator &utilizator)= default;

Utilizator::~Utilizator() = default;

// Getteri
std::string Utilizator::getNume() const {
    return this->nume;
}

int Utilizator::getVarsta() const {
    return this->varsta;
}

double Utilizator::getGreutateKg() const {
    return this->greutate_kg;
}

double Utilizator::getIntaltime_cm() const {
    return this->inaltime_cm;
}

const Obiectiv& Utilizator::getObiectivCurent() const {
    return this->obiectivCurent;
}

// Setteri
void Utilizator::setGreutateKg(double kg) {
    this->greutate_kg = kg;
    this->actualizeazaObiectivGreutate(kg);
}

void Utilizator::setInaltime_cm(double cm) {
    this->inaltime_cm = cm;
}

void Utilizator::setObiectivCurent(const Obiectiv& obiectiv) {
    this->obiectivCurent = obiectiv;
}

void Utilizator::actualizeazaObiectivGreutate(double greutate) {
    if (obiectivCurent.getTipObiectiv() == TipObiectiv::PIERDERE_GREUTATE ||
        obiectivCurent.getTipObiectiv() == TipObiectiv::CASTIG_MASA_MUSCULARA) {
        obiectivCurent.setValoare_curenta(greutate);
    }
}

double Utilizator::calculezBMI() const {
    double inaltime_in_metri = getIntaltime_cm() / 100.0;
    return getGreutateKg() / (inaltime_in_metri * inaltime_in_metri);
}

std::ostream& operator<<(std::ostream& os, const Utilizator& utilizator) {
    os << "Nume: " << utilizator.nume << "\n";
    os << "Varsta: " << utilizator.varsta << "\n";
    os << "GreutateKg: " << utilizator.greutate_kg << "\n";
    os << "Intaltime_cm: " << utilizator.inaltime_cm << "\n";
    os << "Numar antrenamente facute: " << utilizator.numar_antrenamente_facute << "\n";
    os << "Numar calorii arse: " << utilizator.calorii_arse << "\n";
    os << "Obiectiv curent: " << utilizator.obiectivCurent << "\n";

    return os;
}

void Utilizator::adaug_antrenament_completat(const Antrenament& antr) {
    numar_antrenamente_facute++;
    calorii_arse += antr.calculeazaCaloriiTotaleAntrenament();
    std::cout << "Felicitari! utilizatorul cu numele: " << getNume() << " a ars " << calorii_arse << " kcal.!\n";

    // NOU: Actualizeaza Obiectivul de Anduranta
    if (obiectivCurent.getTipObiectiv() == TipObiectiv::ANDURANTA) {
        // Presupunem ca Obiectivul "Anduranta" urmareste numarul de antrenamente.
        // Incrementezi valoarea curenta cu 1.
        obiectivCurent.setValoare_curenta(obiectivCurent.getValoare_curenta() + 1);
    }
}

void Utilizator::afisareProfilUtilizator() const {
    std::cout << "Numele utilizatorului este: " << nume << "\n";
    std::cout << "Varsta utilizatorului este: " << varsta << "\n";
    std::cout << "Greutatea utilizatorului in kg: " << greutate_kg << "\n";
    std::cout << "Intaltimea utilizatorului in cm: " << inaltime_cm << "\n";
    std::cout << "Numar antrenamente facute: " << numar_antrenamente_facute << "\n";
    std::cout << "Numar calorii arse: " << calorii_arse << "\n";

    if (numar_antrenamente_facute <= 3)
        std::cout << "Felicitari! Ai inceput bine, "
                     "dar poti incerca sa fi mai consistent!\n";
    else if (numar_antrenamente_facute <= 5)
        std::cout << "Felicitari! Continua tot asa si "
                     "rezultatele nu vor inceta sa apara!\n";
    else
        std::cout << "Felicitari! Te pregatesti extrem de intens"
                     ", cu siguranta vei castiga tot ce ti-ai propus!\n";

    std::cout << "Progres: " << obiectivCurent.CalculeazaProgrez() << "\n";
    if (obiectivCurent.getObiectiv_atins())
        std::cout << "STATUS: Obiectivul " << obiectivCurent.getDescriere() << " a fost atins! \n";
    else
        std::cout << "STATUS: Inca mai este de muncit la oviectivul " << obiectivCurent.getDescriere() << "\n";
}
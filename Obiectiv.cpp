#include <iostream>
#include  <string>
#include <utility>
#include <vector>
#include  <algorithm>
#include  "Obiectiv.h"

// Obiectivul default
Obiectiv::Obiectiv()
    :descriere("Obiectiv implicit"),
    tipObiectiv(TipObiectiv::PIERDERE_GREUTATE),
    valoare_dorita(0),
    valoare_initiala(0.0),
    valoare_curenta(0.0),
    data_limita(),
    obiectiv_atins(false){};

Obiectiv::Obiectiv(const std::string &descriere,TipObiectiv tipObiectiv, double valoare_dorita,
    double valoare_initiala, double, const std::string &data_limita, bool) {
    this->descriere = descriere;
    this->tipObiectiv = tipObiectiv;
    this->valoare_dorita = valoare_dorita;
    this->valoare_initiala = valoare_initiala;
    this->valoare_curenta = valoare_initiala;   // se seteaza la val_init deoarece atunci cream
    this->data_limita = data_limita;
    this->obiectiv_atins = false;   // nu ar avea cum obiectivul sa fie atins la crearea obiectivului
}

Obiectiv::Obiectiv(const Obiectiv& obiectiv) {
    this->descriere = obiectiv.descriere;
    this->tipObiectiv = obiectiv.tipObiectiv;
    this->valoare_dorita = obiectiv.valoare_dorita;
    this->valoare_initiala = obiectiv.valoare_initiala;
    this->valoare_curenta = obiectiv.valoare_curenta;
    this->data_limita = obiectiv.data_limita;
    this->obiectiv_atins = obiectiv.obiectiv_atins;
}

Obiectiv& Obiectiv::operator=(const Obiectiv& obiectiv) = default;

std::string Obiectiv::getDescriere() const{
    return this->descriere;
}

TipObiectiv Obiectiv::getTipObiectiv() const{
    return this->tipObiectiv;
}

double Obiectiv::getValoare_dorita() const{
    return this->valoare_dorita;
}

double Obiectiv::getValoare_initiala() const{
    return this->valoare_initiala;
}

double Obiectiv::getValoare_curenta() const{
    return this->valoare_curenta;
}

std::string Obiectiv::getDataLimita() const{
    return this->data_limita;
}

bool Obiectiv::getObiectiv_atins() const{
    return this->obiectiv_atins;
}

void Obiectiv::setDescriere(const std::string &descriere_noua) {
    this->descriere = descriere_noua;
}

void Obiectiv::setTipObiectiv(TipObiectiv tipObiectiv_nou) {
    this->tipObiectiv = tipObiectiv_nou;
}

void Obiectiv::setValoare_dorita(double valoare_dorita_noua) {
    this->valoare_dorita = valoare_dorita_noua;
}

void Obiectiv::setValoare_initiala(double valoare_initiala_noua) {
    this->valoare_initiala = valoare_initiala_noua;
}

void Obiectiv::setValoare_curenta(double valoare_curenta_noua) {
    this->valoare_curenta = valoare_curenta_noua;
}

void Obiectiv::setDataLimita(std::string data_limita_noua) {
    this->data_limita = std::move(data_limita_noua);
}

double Obiectiv::CalculeazaProgrez() const {
    if (valoare_initiala == valoare_dorita)
        return 0.0;     // Nu vreau impartire la 0

    double Progres;
    switch (tipObiectiv) {
        case TipObiectiv::CASTIG_MASA_MUSCULARA:
            // Progres pozitiv
            Progres = (valoare_curenta - valoare_initiala) / (valoare_dorita - valoare_initiala) * 100.0;
            break;

        case TipObiectiv::PIERDERE_GREUTATE:
            // Progres pozitiv
            Progres = (valoare_initiala - valoare_curenta) / (valoare_initiala - valoare_dorita) * 100.0;
            break;

        case TipObiectiv::ANDURANTA:
            // Progres linear
            Progres = (valoare_curenta - valoare_initiala) / (valoare_dorita - valoare_initiala) * 100.0;
            break;

        default:
            throw ;
    }

    // Progresul este un procent intre 0 si 100
    // Pun conditii sa nu depasesc aceste limite
    return std::min(std::max(Progres, 0.0), 100.0);
}

void Obiectiv::VerificAtingereObiectiv(){
    switch (tipObiectiv) {
        case TipObiectiv::PIERDERE_GREUTATE:
            obiectiv_atins = (valoare_curenta <= valoare_initiala);
            break;

        case TipObiectiv::CASTIG_MASA_MUSCULARA:
        case TipObiectiv::ANDURANTA:
            obiectiv_atins = (valoare_curenta >= valoare_initiala);
            break;
    }
}

std::ostream& operator<<(std::ostream& os, const Obiectiv& obiectiv) {
    os << "Descriere obiectiv: " << obiectiv.descriere << std::endl;
    os << "Tipul de obiectiv: " << tipObiectivToString(obiectiv.tipObiectiv) << std::endl;
    os << "Valoare dorita: " << obiectiv.valoare_dorita << std::endl;
    os << "Valoare initiala: " << obiectiv.valoare_initiala << std::endl;
    os << "Valoare curenta: " << obiectiv.valoare_curenta << std::endl;
    os << "Data limita: " << obiectiv.data_limita << std::endl;
    os << "Obiectiv atins: ";
    if (obiectiv.obiectiv_atins == true)
        os << "DA!" << std::endl;
    else
        os << "NU! OBIECTIV INCA ACTIV!" << std::endl;

    return os;
}

// 2 obiective sunt egale daca au acelasi scop(descriere si obiectiv
bool Obiectiv::operator==(const Obiectiv& obiectiv) const{
    return (this->descriere == obiectiv.descriere && this->tipObiectiv == obiectiv.tipObiectiv);
}

// Cmp progresul
bool Obiectiv::operator>(const Obiectiv& obiectiv) const {
    return (this->CalculeazaProgrez() > obiectiv.CalculeazaProgrez());
}
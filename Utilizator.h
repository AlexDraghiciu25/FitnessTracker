#ifndef OOP_UTILIZATOR_H
#define OOP_UTILIZATOR_H

#include <iostream>
#include <string>
#include "Obiectiv.h"
#include "Antrenament.h"

class Utilizator {
    private:
        std::string nume;
        int varsta;
        double greutate_kg;
        double inaltime_cm;
        int numar_antrenamente_facute;
        double calorii_arse;

        Obiectiv obiectivCurent;
    public:
        // Constr def
        Utilizator();

        //Constr cu param
        Utilizator(const std::string& nume, int varsta,
            double greutate_kg, double inaltime_cm, const Obiectiv& obiectiv);

        // Constr de cop
        Utilizator(const Utilizator& utilizator);

        Utilizator& operator=(const Utilizator& utilizator);

        ~Utilizator();

        // Getteri
        std::string getNume() const;
        int getVarsta() const;
        double getGreutateKg() const;
        double getIntaltime_cm() const;
        const Obiectiv& getObiectivCurent() const;

        // Setteri
        void setGreutateKg(double kg);
        void setInaltime_cm(double cm);
        void setObiectivCurent(const Obiectiv& obiectiv);

        void actualizeazaObiectivGreutate(double greutate);

        double calculezBMI() const;

        friend std::ostream& operator<<(std::ostream& os, const Utilizator& utilizator);

        void adaug_antrenament_completat(const Antrenament& antr);

        void afisareProfilUtilizator();
};

#endif //OOP_UTILIZATOR_H
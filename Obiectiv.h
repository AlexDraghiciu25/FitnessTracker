#ifndef OOP_OBIECTIV_H
#define OOP_OBIECTIV_H

#include <iostream>
#include  <string>
#include <vector>

class Obiectiv {
    private:
        std::string descriere;
        std::string tipObiectiv;    // EX:Pierdere greutate sau Castiga masa musculara sau anduranta
        double valoare_dorita;
        double valoare_initiala;
        double valoare_curenta;
        std::string data_limita;    // obiectiv de indeplinit pana la EX: 31.12.2025
        bool obiectiv_atins;        // Am atins sau nu obiectivu
    public:
        Obiectiv();

        Obiectiv(const std::string descriere,const std::string tipObiectiv, double valoare_dorita,
            double valoare_initiala, double valoare_curenta, const std::string data_limita, bool obiectiv_atins);

        Obiectiv(const Obiectiv& obiectiv);

        Obiectiv& operator=(const Obiectiv& obiectiv);

        std::string getDescriere() const;
        std::string getTipObiectiv() const;
        double getValoare_dorita() const;
        double getValoare_initiala() const;
        double getValoare_curenta() const;
        std::string getDataLimita() const;
        bool getObiectiv_atins() const;

        void setDescriere(const std::string descriere);
        void setTipObiectiv(const std::string tipObiectiv);
        void setValoare_dorita(double valoare_dorita);
        void setValoare_initiala(double valoare_initiala);
        void setValoare_curenta(double valoare_curenta);
        void setDataLimita(std::string data_limita);

        double CalculeazaProgrez() const;

        void VerificAtingereObiectiv();

        friend std::ostream& operator<<(std::ostream& os, const Obiectiv& obiectiv);

        // 2 obiective sunt egale daca au acelasi scop(descriere si obiectiv
        bool operator==(const Obiectiv& obiectiv) const;

        // Cmp progresul
        bool operator>(const Obiectiv& obiectiv) const;
};

#endif //OOP_OBIECTIV_H
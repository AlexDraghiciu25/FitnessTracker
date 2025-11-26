#ifndef OOP_OBIECTIV_H
#define OOP_OBIECTIV_H

#include <iostream>
#include  <string>

enum class TipObiectiv {
    PIERDERE_GREUTATE,
    CASTIG_MASA_MUSCULARA,
    ANDURANTA,
};

inline std::ostream& operator<<(std::ostream& os, const TipObiectiv& tip) {
    switch (tip) {
        case TipObiectiv::PIERDERE_GREUTATE:
            os << "Pierdere greutate";
            break;
        case TipObiectiv::CASTIG_MASA_MUSCULARA:
            os << "Castig masa musculara";
            break;
        case TipObiectiv::ANDURANTA:
            os << "Anduranta";
            break;
        default:
            os << "Necunoscut";
            break;
    }
    return os;
}

inline std::string tipObiectivToString(TipObiectiv tipObiectiv) {
    switch (tipObiectiv) {
        case TipObiectiv::PIERDERE_GREUTATE:
            return "Pierdere greutate";
        case TipObiectiv::CASTIG_MASA_MUSCULARA:
            return "Castiga masa musculara";
        case TipObiectiv::ANDURANTA:
            return "Anduranta";
        default:
            return "Necunoscut";
    }
}

inline TipObiectiv stringToTipObiectiv(const std::string &str) {
    if (str == "Pierdere greutate" || str == "pierdere" || str == "slabire")
        return TipObiectiv::PIERDERE_GREUTATE;
    else if (str == "Castiga masa musculara" || str == "castig" || str == "masa")
        return TipObiectiv::CASTIG_MASA_MUSCULARA;
    else if (str == "Anduranta" || str == "anduranta" || str == "rezistenta")
        return TipObiectiv::ANDURANTA;
    else
        throw;
}

class Obiectiv {
    private:
        std::string descriere;
        TipObiectiv tipObiectiv;    // EX:Pierdere greutate sau Castiga masa musculara sau anduranta
        double valoare_dorita{};
        double valoare_initiala{};
        double valoare_curenta{};
        std::string data_limita;    // obiectiv de indeplinit pana la EX: 31.12.2025
        bool obiectiv_atins{};        // Am atins sau nu obiectivu
    public:
        Obiectiv();

        Obiectiv(const std::string &descriere, TipObiectiv tipObiectiv, double valoare_dorita, double valoare_initiala,
                 double valoare_curenta, const std::string &data_limita, bool obiectiv_atins);

        Obiectiv(const Obiectiv& obiectiv);

        Obiectiv& operator=(const Obiectiv& obiectiv);

        [[nodiscard]] std::string getDescriere() const;
        [[nodiscard]] TipObiectiv getTipObiectiv() const;
        [[nodiscard]] double getValoare_dorita() const;
        [[nodiscard]] double getValoare_initiala() const;
        [[nodiscard]] double getValoare_curenta() const;
        [[nodiscard]] std::string getDataLimita() const;
        [[nodiscard]] bool getObiectiv_atins() const;

        void setDescriere(const std::string &descriere);
        void setTipObiectiv(TipObiectiv tipObiectiv);
        void setValoare_dorita(double valoare_dorita);
        void setValoare_initiala(double valoare_initiala);
        void setValoare_curenta(double valoare_curenta);
        void setDataLimita(std::string data_limita);

        [[nodiscard]] double CalculeazaProgrez() const;

        void VerificAtingereObiectiv();

        friend std::ostream& operator<<(std::ostream& os, const Obiectiv& obiectiv);

        // 2 obiective sunt egale daca au acelasi scop(descriere si obiectiv
        bool operator==(const Obiectiv& obiectiv) const;

        // Cmp progresul
        bool operator>(const Obiectiv& obiectiv) const;
};

#endif //OOP_OBIECTIV_H
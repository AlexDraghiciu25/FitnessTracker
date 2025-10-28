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
        Obiectiv() = default;

        Obiectiv(const std::string descriere,const std::string tipObiectiv, double valoare_dorita,
            double valoare_initiala, double valoare_curenta, const std::string data_limita, bool obiectiv_atins) {
            this->descriere = descriere;
            this->tipObiectiv = tipObiectiv;
            this->valoare_dorita = valoare_dorita;
            this->valoare_initiala = valoare_initiala;
            this->valoare_curenta = valoare_initiala;   // se seteaza la val_init deoarece atunci cream
            this->data_limita = data_limita;
            this->obiectiv_atins = false;   // nu ar avea cum obiectivul sa fie atins la crearea obiectivului
        }

        Obiectiv(const Obiectiv& obiectiv) {
            this->descriere = obiectiv.descriere;
            this->tipObiectiv = obiectiv.tipObiectiv;
            this->valoare_dorita = obiectiv.valoare_dorita;
            this->valoare_initiala = obiectiv.valoare_initiala;
            this->valoare_curenta = obiectiv.valoare_curenta;
            this->data_limita = obiectiv.data_limita;
            this->obiectiv_atins = obiectiv.obiectiv_atins;
        }

        Obiectiv& operator=(const Obiectiv& obiectiv) {
            this->descriere = obiectiv.descriere;
            this->tipObiectiv = obiectiv.tipObiectiv;
            this->valoare_dorita = obiectiv.valoare_dorita;
            this->valoare_initiala = obiectiv.valoare_initiala;
            this->valoare_curenta = obiectiv.valoare_curenta;
            this->data_limita = obiectiv.data_limita;
            this->obiectiv_atins = obiectiv.obiectiv_atins;

            return *this;
        }

        std::string getDescriere() const{
            return this->descriere;
        }

        std::string getTipObiectiv() const{
            return this->tipObiectiv;
        }

        double getValoare_dorita() const{
            return this->valoare_dorita;
        }

        double getValoare_initiala() const{
            return this->valoare_initiala;
        }

        double getValoare_curenta() const{
            return this->valoare_curenta;
        }

        std::string getDataLimita() const{
            return this->data_limita;
        }

        bool getObiectiv_atins() const{
            return this->obiectiv_atins;
        }

        void setDescriere(const std::string descriere) {
            this->descriere = descriere;
        }

        void setTipObiectiv(const std::string tipObiectiv) {
            this->tipObiectiv = tipObiectiv;
        }

        void setValoare_dorita(double valoare_dorita) {
            this->valoare_dorita = valoare_dorita;
        }

        void setValoare_initiala(double valoare_initiala) {
            this->valoare_initiala = valoare_initiala;
        }

        void setValoare_curenta(double valoare_curenta) {
            this->valoare_curenta = valoare_curenta;
        }

        void setDataLimita(std::string data_limita) {
            this->data_limita = data_limita;
        }

        double CalculeazaProgrez() const {
            if (valoare_initiala == valoare_dorita)
                return 0.0;     // Nu vreau impartire la 0

            double Progres;
            if (tipObiectiv == "Pierdere greutate") {
                // Daca slabim, procesul e invers fata de procesul de depunere de greutate
                Progres = (valoare_initiala - valoare_curenta) / (valoare_initiala - valoare_dorita) * 100;
            }
            else {
                // Pentru punere greutate
                Progres = (valoare_curenta - valoare_initiala) / (valoare_dorita - valoare_initiala) * 100;
            }

            // Progresul este un procent intre 0 si 100
            // Pun conditii sa nu depasesc aceste limite
            return std::min(std::max(Progres, 0.0), 100.0);
        }

        void VerificAtingereObiectiv(){
            if (tipObiectiv == "Pierdere greutate") {
                if (valoare_curenta <= valoare_dorita)
                    this->obiectiv_atins = true;
                else
                    this->obiectiv_atins = false;
            }
            else {
                if (valoare_curenta >= valoare_dorita)
                    this->obiectiv_atins = true;
                else
                    this->obiectiv_atins = false;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Obiectiv& obiectiv) {
            os << "Descriere obiectiv: " << obiectiv.descriere << std::endl;
            os << "Tipul de obiectiv: " << obiectiv.tipObiectiv << std::endl;
            os << "Valoare dorita: " << obiectiv.valoare_dorita << std::endl;
            os << "Valoare initiala: " << obiectiv.valoare_initiala << std::endl;
            os << "Valoare curenta: " << obiectiv.valoare_curenta << std::endl;
            os << "Data limita: " << obiectiv.data_limita << std::endl;
            os << "Obiectiv atins: ";
            if (obiectiv.obiectiv_atins == true)
                os << "ATINS!" << std::endl;
            else
                os << "NEATINS! OBIECTIV INCA ACTIV!" << std::endl;

            return os;
        }

        // 2 obiective sunt egale daca au acelasi scop(descriere si obiectiv
        bool operator==(const Obiectiv& obiectiv) const{
            return (this->descriere == obiectiv.descriere && this->tipObiectiv == obiectiv.tipObiectiv);
        }

        // Cmp progresul
        bool operator>(const Obiectiv& obiectiv) const {
            return (this->CalculeazaProgrez() > obiectiv.CalculeazaProgrez());
        }
};

#endif //OOP_OBIECTIV_H
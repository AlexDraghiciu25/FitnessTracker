#include "Exercitiu.h"

Exercitiu::Exercitiu() = default;

Exercitiu::Exercitiu(const std::string& nume,const std::string& categorie,
                    double calorii_arse_pe_min, int durata,const std::string& dificultate) {
    this->nume = nume;
    this->categorie = categorie;
    this->calorii_arse_pe_min = calorii_arse_pe_min;
    this->durata = durata;
    this->dificultate = dificultate;
}

        /// Getters
std::string Exercitiu::get_nume() const{
    return nume;
}

std::string Exercitiu::get_categorie() const{
    return categorie;
}

double Exercitiu::get_calorii_arse_pe_min() const{
    return calorii_arse_pe_min;
}

int Exercitiu::get_durata() const{
    return durata;
}

std::string Exercitiu::get_dificultate() const{
        return dificultate;
}

/// Setters
void Exercitiu::set_nume(std::string nume) {
    this->nume = nume;
}

void Exercitiu::set_categorie(std::string categorie) {
    this->categorie = categorie;
}

void Exercitiu::set_calorii_arse_pe_min(double calorii_arse_pe_min) {
    this->calorii_arse_pe_min = calorii_arse_pe_min;
}

void Exercitiu::set_durata(int durata) {
    this->durata = durata;
}

void Exercitiu::set_dificultate(std::string dificultate) {
    this->dificultate = dificultate;
}

double Exercitiu::calculeazaCaloriiTotale() const{
    return calorii_arse_pe_min * durata;
}

void Exercitiu::afisare_detaliata() const{
    if (this->nume == "alergare")
        std::cout << "cardio de intensitate medie bazata pe miscarea sustinuta a picioarelor pe o distanta data\n";
    else if (this->nume == "ciclism")
        std::cout << "Ciclism – activitate cardio efectuata pe bicicleta, care dezvolta rezistenta si musculatura picioarelor.\n";
    else if (this->nume == "inot")
        std::cout << "exercitiu complet al corpului, care implica miscari coordonate ale bratelor si picioarelor in apa.\n";
    else if (this->nume == "burpees")
        std::cout << "exercitiu functional intens, care combina flotari, genuflexiuni si sarituri pentru forta si anduranta.\n";
    else if (this->nume == "flotari")
        std::cout << "exercitiu pentru partea superioara a corpului, care lucreaza pieptul, bratele si umerii prin ridicari si coborari ale corpului.\n";
    else if (this->nume == "abdomene")
        std::cout << "exercitiu focalizat pe intarirea muschilor abdominali, realizat prin ridicarea trunchiului din pozitie culcat.\n";
    else if (this->nume == "impins la piept")
        std::cout << "exercitiu de forta efectuat la banca sau cu gantere, care dezvolta muschii pectorali si tricepsii.\n";
    else if (this->nume == "biceps curl")
        std::cout << "exercitiu de izolare pentru biceps, realizat prin flexarea antebratului cu greutati.\n";
    else if (this->nume == "stretching")
        std::cout << "serie de miscari lente menite sa intinda musculatura si sa imbunatateasca mobilitatea articulatiilor.\n";
    else if (this->nume == "yoga")
        std::cout << "antrenament care combina posturi statice si respiratie controlata pentru echilibru, flexibilitate si concentrare.\n";
    else if (this->nume == "pilates")
        std::cout << "exercitii care intaresc musculatura profunda si sporesc flexibilitatea prin miscari lente si controlate.\n";
    else if (this->nume == "mobilitate articulara")
        std::cout << "exercitii usoare de rotatie si intindere pentru cresterea amplitudinii miscarilor articulare.\n";
}

std::ostream& operator<<(std::ostream& os, const Exercitiu& exercitiu) {
    os << "Numele exercitiului: " << exercitiu.nume << "\n";
    os << "Categoria exercitiului: " << exercitiu.categorie << "\n";
    os << "Numarul de calorii arse pe minut: " << exercitiu.calorii_arse_pe_min << "\n";
    os << "Durata in minute a exercitiului: " << exercitiu.durata << "\n";
    os << "Dificultatea exercitiului: " << exercitiu.dificultate << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Exercitiu& exercitiu) {
    std::cout << " numele exercitiului: ";
    is >> exercitiu.nume;

    std::cout << "Categoria exercitiului: ";
    is >> exercitiu.categorie;

    std::cout << "Numarul de calorii arse pe minut: ";
    is >> exercitiu.calorii_arse_pe_min;

    std::cout << "Durata in minute a exercitiului: ";
    is >> exercitiu.durata;

    std::cout << "Dificultatea exercitiului: ";
    is >> exercitiu.dificultate;

    return is;
}

bool Exercitiu::operator==(const Exercitiu& exercitiu) const{
    if (this->nume == exercitiu.nume)
        return true;    //Coincid numele exercitiilor
    else
        return false;   //Nu coincid numele exercitiilor
}

bool Exercitiu::operator>(const Exercitiu& exercitiu) const{
    return calculeazaCaloriiTotale() > exercitiu.calculeazaCaloriiTotale();
}
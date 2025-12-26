#ifndef OOP_STATISTICITEMPLATE_H
#define OOP_STATISTICITEMPLATE_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

// clasa template
// calculeaza statistici pentru orice tip numeric int, float, double

template<typename T>
class StatisticiCalculator {
private:
    std::vector<T> date;
    std::string numeMetrica;

    void valideazaDate() const {
        if (date.empty()) {
            throw std::runtime_error("Date insuficiente pentru calculul statisticilor.");
        }
    }

public:
    explicit StatisticiCalculator(std::string nume = "Date")
        : numeMetrica(std::move(nume)) {}

    StatisticiCalculator(std::string nume, const std::vector<T>& dateInitiale)
        : date(dateInitiale), numeMetrica(std::move(nume)) {}

    // op de baza

    void adauga(const T& valoare) {
        date.push_back(valoare);
    }

    void adaugaMultiple(const std::vector<T>& valori) {
        date.insert(date.end(), valori.begin(), valori.end());
    }

    void reseteaza() {
        date.clear();
    }

    [[nodiscard]] size_t getNumarElemente() const {
        return date.size();
    }

    [[nodiscard]] const std::vector<T>& getDate() const {
        return date;
    }

    // statistici

    [[nodiscard]] T calculeazaMinim() const {
        valideazaDate();
        return *std::min_element(date.begin(), date.end());
    }

    [[nodiscard]] T calculeazaMaxim() const {
        valideazaDate();
        return *std::max_element(date.begin(), date.end());
    }

    [[nodiscard]] T calculeazaSuma() const {
        return std::accumulate(date.begin(), date.end(), T{0});
    }

    [[nodiscard]] double calculeazaMedie() const {
        valideazaDate();
        return static_cast<double>(calculeazaSuma()) / date.size();
    }

    [[nodiscard]] double calculeazaMediana() const {
        valideazaDate();
        std::vector<T> sortate = date;
        std::sort(sortate.begin(), sortate.end());

        size_t n = sortate.size();
        if (n % 2 == 0) {
            return (static_cast<double>(sortate[n / 2 - 1]) +
                    static_cast<double>(sortate[n / 2])) / 2.0;
        }
        return static_cast<double>(sortate[n / 2]);
    }

    [[nodiscard]] double calculeazaDeviatieStandard() const {
        valideazaDate();
        if (date.size() < 2) {
            return 0.0;
        }

        double medie = calculeazaMedie();
        double suma = 0.0;

        for (const auto& val : date) {
            double diff = static_cast<double>(val) - medie;
            suma += diff * diff;
        }

        return std::sqrt(suma / (date.size() - 1));
    }

    [[nodiscard]] double calculeazaTendinta() const {
        valideazaDate();
        if (date.size() < 2) {
            return 0.0;
        }

        double prim = static_cast<double>(date.front());
        double ultim = static_cast<double>(date.back());

        if (prim == 0.0) {
            return 0.0;
        }

        return ((ultim - prim) / prim) * 100.0;
    }

    [[nodiscard]] size_t numaraDepasiri(const T& limita) const {
        return std::count_if(date.begin(), date.end(),
            [&limita](const T& val) { return val > limita; });
    }

    [[nodiscard]] std::vector<T> filtreazaInterval(const T& minVal, const T& maxVal) const {
        std::vector<T> rezultat;
        std::copy_if(date.begin(), date.end(), std::back_inserter(rezultat),
            [&](const T& val) { return val >= minVal && val <= maxVal; });
        return rezultat;
    }

    // afis

    void afiseazaRaportComplet() const {
        if (date.empty()) {
            std::cout << "[" << numeMetrica << "] Nu exista date disponibile.\n";
            return;
        }

        std::cout << "\n=== Raport statistic: " << numeMetrica << " ===\n";
        std::cout << "Numar masuratori : " << date.size() << "\n";
        std::cout << "Minim            : " << calculeazaMinim() << "\n";
        std::cout << "Maxim            : " << calculeazaMaxim() << "\n";
        std::cout << "Medie            : " << std::fixed << std::setprecision(2)
                  << calculeazaMedie() << "\n";
        std::cout << "Mediana          : " << calculeazaMediana() << "\n";
        std::cout << "Suma             : " << calculeazaSuma() << "\n";

        if (date.size() >= 2) {
            std::cout << "Deviatie std     : " << calculeazaDeviatieStandard() << "\n";
            std::cout << "Tendinta (%)     : " << calculeazaTendinta() << "\n";
        }

        std::cout << "---------------------------------------------\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const StatisticiCalculator<T>& stats) {
        os << "[" << stats.numeMetrica << "] N=" << stats.date.size();
        if (!stats.date.empty()) {
            os << ", Medie=" << stats.calculeazaMedie()
               << ", Min=" << stats.calculeazaMinim()
               << ", Max=" << stats.calculeazaMaxim();
        }
        return os;
    }
};

// functii template globale

template<typename T>
void compara2Colectii(
    const StatisticiCalculator<T>& stats1,
    const StatisticiCalculator<T>& stats2,
    const std::string& eticheta1 = "Colectie 1",
    const std::string& eticheta2 = "Colectie 2"
) {
    std::cout << "\nComparatie statistici\n";
    std::cout << eticheta1 << " vs " << eticheta2 << "\n";
    std::cout << "---------------------------------\n";

    if (stats1.getNumarElemente() == 0 || stats2.getNumarElemente() == 0) {
        std::cout << "Una dintre colectii nu contine date.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);

    double diffMedie = stats1.calculeazaMedie() - stats2.calculeazaMedie();

    std::cout << "Medie            : " << stats1.calculeazaMedie()
              << " | " << stats2.calculeazaMedie()
              << " (diferenta: " << diffMedie << ")\n";

    std::cout << "Valoare maxima   : " << stats1.calculeazaMaxim()
              << " | " << stats2.calculeazaMaxim() << "\n";

    std::cout << "Nr. elemente     : " << stats1.getNumarElemente()
              << " | " << stats2.getNumarElemente() << "\n";
}

template<typename T>
double calculeazaProgresProcentual(
    const T& valInitiala,
    const T& valCurenta,
    const T& valTinta
) {
    if (valInitiala == valTinta) {
        return 100.0;
    }

    double parcurs = static_cast<double>(valCurenta) - static_cast<double>(valInitiala);
    double total = static_cast<double>(valTinta) - static_cast<double>(valInitiala);

    if (total == 0.0) {
        return 100.0;
    }

    double progres = (parcurs / total) * 100.0;
    return std::clamp(progres, 0.0, 100.0);
}

#endif //OOP_STATISTICITEMPLATE_H
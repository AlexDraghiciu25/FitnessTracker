#ifndef OOP_OBSERVERPATTERN_H
#define OOP_OBSERVERPATTERN_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

// Design Pattern: Observer
class IObserverProgres {
public:
    virtual ~IObserverProgres() = default;

    // Metoda apelata cand apare un eveniment
    virtual void actualizeaza(
        const std::string& mesaj,
        double progresNou,
        const std::string& tipEveniment
    ) = 0;
};

// -------------------- OBSERVATORI CONCRETI --------------------

// Observer pentru notificari console
class NotificareConsola : public IObserverProgres {
private:
    std::string numeObserver;

public:
    explicit NotificareConsola(std::string nume)
        : numeObserver(std::move(nume)) {}

    void actualizeaza(
        const std::string& mesaj,
        double progresNou,
        const std::string& tipEveniment
    ) override {
        std::cout << "\n[Notificare] (" << numeObserver << ")\n";
        std::cout << "Tip eveniment : " << tipEveniment << "\n";
        std::cout << "Mesaj        : " << mesaj << "\n";
        std::cout << "Progres      : " << progresNou << "%\n";
    }
};

// Observer pentru milestone-uri (realizari importante)
class DetectorMilestone : public IObserverProgres {
private:
    std::vector<double> milestones = {25.0, 50.0, 75.0, 100.0};
    std::vector<bool> atinse;

public:
    DetectorMilestone() : atinse(milestones.size(), false) {}

    void actualizeaza(
        const std::string& mesaj,
        double progresNou,
        const std::string& /*tipEveniment*/
    ) override {
        for (size_t i = 0; i < milestones.size(); ++i) {
            if (!atinse[i] && progresNou >= milestones[i]) {
                atinse[i] = true;

                std::cout << "\n[Milestone]\n";
                std::cout << "Progres atins: " << milestones[i] << "%\n";
                std::cout << "Detalii      : " << mesaj << "\n";
            }
        }
    }
};

// Observer pentru statistici
class ColectorStatistici : public IObserverProgres {
private:
    int numarActualizari = 0;
    double progresMaxim = 0.0;
    std::vector<std::string> istoricEvenimente;

public:
    void actualizeaza(
        const std::string& mesaj,
        double progresNou,
        const std::string& tipEveniment
    ) override {
        numarActualizari++;
        if (progresNou > progresMaxim) {
            progresMaxim = progresNou;
        }
        istoricEvenimente.push_back(tipEveniment + ": " + mesaj);
    }

    void afiseazaRaport() const {
        std::cout << "\n---- RAPORT STATISTICI ----\n";
        std::cout << "  Numar evenimente: " << numarActualizari << "\n";
        std::cout << "  Progres maxim atins: " << progresMaxim << "%\n";
        std::cout << "  Ultimele evenimente:\n";

        size_t start = (istoricEvenimente.size() > 5) ? istoricEvenimente.size() - 5 : 0;
        for (size_t i = start; i < istoricEvenimente.size(); ++i) {
            std::cout << "    - " << istoricEvenimente[i] << "\n";
        }
        std::cout << "------------------------------------------------\n";
    }
};

// -------------------- SUBJECT (Observable) --------------------

class SubiectProgres {
private:
    std::vector<std::shared_ptr<IObserverProgres>> observatori;
    double progres = 0.0;

public:
    // Adauga observer
    void atasare(const std::shared_ptr<IObserverProgres>& observer) {
        observatori.push_back(observer);
    }

    // Sterge observer
    void detasare(const std::shared_ptr<IObserverProgres>& observer) {
        std::erase(observatori, observer);
    }

    // Notifica toti observatorii
    void notifica(const std::string& mesaj, const std::string& tipEveniment) const {
        for (auto& observer : observatori) {
            observer->actualizeaza(mesaj, progres, tipEveniment);
        }
    }

    // Seteaza progres si notifica
    void setProgres(double progresNou, const std::string& mesaj, const std::string& tip = "PROGRES") {
        progres = progresNou;
        notifica(mesaj, tip);
    }

    [[nodiscard]] double getProgres() const { return progres; }
    [[nodiscard]] size_t getNumarObservatori() const { return observatori.size(); }
};

#endif //OOP_OBSERVERPATTERN_H
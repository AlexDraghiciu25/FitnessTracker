#include "../include/PlanAnduranta.h"
#include <utility>
#include "../include/ExceptiiPlanuri.h"

PlanAnduranta::PlanAnduranta(const std::string &numePlan, int durataLuni,
                             NivelExperienta nivelExperienta, int zilePeSaptamana,
                             double distantaTinta, std::string tipActivitate,
                             int minuteBazaPerSesiune)
    : PlanAntrenament(numePlan, durataLuni, nivelExperienta, zilePeSaptamana),
    distantaTinta(distantaTinta),
    tipActivitate(std::move(tipActivitate)),
    minuteBazaPerSesiune(minuteBazaPerSesiune) {

    if (distantaTinta < 1.0 || distantaTinta > 100.0) {
        throw ExceptieValidarePlan("Distanta tinta 1 - 100 km!");
    }

    if (minuteBazaPerSesiune < 20 || minuteBazaPerSesiune > 120) {
        throw ExceptieConfigurare("Minute recomandate per sesiune 20 - 120!");
    }
}

double PlanAnduranta::calculeazaIntensitate(int saptamana) const {
    int ciclu = saptamana % 4;
    if (ciclu == 0) {
        return 60.0;
    }
    if (ciclu == 1) {
        return 70.0;
    }
    if (ciclu == 2) {
        return 80.0;
    }
    return 75.0;
}

std::string PlanAnduranta::getTipPlan() const {
    return "Anduranta/Rezistenta";
}

void PlanAnduranta::genereazaRecomandari(std::ostream &os) const {
    os << "Tip: " << getTipPlan() << "\n";
    os << "Activitate: " << tipActivitate << "\n";
    os << "Distanta tinta: " << distantaTinta << " km\n";
    os << "Durata medie: " << minuteBazaPerSesiune << " min\n";
    os << "Intensitate curenta: " << calculeazaIntensitate(saptamanaCurenta) << "%\n";
    os << "\nRecomandari:\n";
    os << "- Creste distanta cu max 10% pe saptamana\n";
    os << "- Alterneaza zile grele/usoare\n";
    os << "- 1 zi recuperare activa\n";
    os << "- Monitorizeaza frecventa cardiaca\n";
}

PlanAnduranta* PlanAnduranta::clone() const {
    return new PlanAnduranta(*this);
}

std::vector<std::string> PlanAnduranta::genereazaProgram(int saptamana) const {
    std::vector<std::string> program;

    // Progresie de distanta (creste cu 10% pe saptamana)
    double distantaSaptamana = distantaTinta * (0.3 + saptamana * 0.1);
    if (distantaSaptamana > distantaTinta) distantaSaptamana = distantaTinta;

    int minutePerSesiune = minuteBazaPerSesiune + (saptamana * 5);

    for (int zi = 1; zi <= zilePeSaptamana; zi++) {
        std::string sesiune = "Zi " + std::to_string(zi) + ": ";

        if (zi % 3 == 1) { // Zi grea
            sesiune += tipActivitate + " INTENS - ";
            sesiune += std::to_string(minutePerSesiune + 10) + " min, ";
            sesiune += std::to_string(static_cast<int>(distantaSaptamana / zilePeSaptamana * 1.3)) + " km";
        } else if (zi % 3 == 2) { // Zi usoara
            sesiune += tipActivitate + " USOR - ";
            sesiune += std::to_string(minutePerSesiune - 10) + " min, ";
            sesiune += std::to_string(static_cast<int>(distantaSaptamana / zilePeSaptamana * 0.7)) + " km";
        } else { // Zi recuperare activa
            sesiune += "Recuperare activa - 20 min mars/stretching";
        }

        program.push_back(sesiune);
    }

    program.push_back("OBIECTIV SAPTAMANAL: " + std::to_string(static_cast<int>(distantaSaptamana)) + " km");

    return program;
}

double PlanAnduranta::getDistantaTinta() const {
    return distantaTinta;
}
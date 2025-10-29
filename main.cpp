#include <iostream>
#include  <string>
#include "Exercitiu.h"
#include "Antrenament.h"
#include "Utilizator.h"
#include "Obiectiv.h"

// #include <vector>

/*
    CARDIO: alergare, ciclism, inot, burpees;
    alergat-cardio de intensitate medie bazata pe miscarea sustinuta a picioarelor pe o distanta data
    ciclism-Ciclism – activitate cardio efectuata pe bicicleta, care dezvolta rezistenta si musculatura picioarelor.
    inot-exercitiu complet al corpului, care implica miscari coordonate ale bratelor si picioarelor in apa.
    burpees-exercitiu functional intens, care combina flotari, genuflexiuni si sarituri pentru forta si anduranta.

    FORTA: flotari, abdomene, impins la piept, biceps curl;
    flotari – exercitiu pentru partea superioara a corpului, care lucreaza pieptul, bratele si umerii prin ridicari si coborari ale corpului.
    abdomene-exercitiu focalizat pe intarirea muschilor abdominali, realizat prin ridicarea trunchiului din pozitie culcat.
    impins la piept-exercitiu de forta efectuat la banca sau cu gantere, care dezvolta muschii pectorali si tricepsii.
    biceps curl-exercitiu de izolare pentru biceps, realizat prin flexarea antebratului cu greutati.

    FLEXIBILITATE: stretching, yoga, pilates, mobilitate articulara
    stretching-serie de miscari lente menite sa intinda musculatura si sa imbunatateasca mobilitatea articulatiilor.
    yoga-antrenament care combina posturi statice si respiratie controlata pentru echilibru, flexibilitate si concentrare.
    pilates-exercitii care intaresc musculatura profunda si sporesc flexibilitatea prin miscari lente si controlate.
    mobilitate articulara-exercitii usoare de rotatie si intindere pentru cresterea amplitudinii miscarilor articulare.

    INCEPATOR:alergare, abdomene, stretching, mobilitate articulara;
    INTERMEDIAR:ciclism, yoga, flotari, burpees;
    AVANSAT:inot, impins la piept, biceps curl, pilates;
*/

// Scenariu de utilizare pentru Tema 1
int main() {
    std::cout << "======================================================\n";
    std::cout << "         FITNESS TRACKER - TEST TEMA 1 COMPLETA\n";
    std::cout << "======================================================\n\n";

    // ======================================================
    // 1. TESTARE CLASE DE BAZA: EXERCITIU si ANTRENAMENT
    // ======================================================
    std::cout << "--- 1. TESTARE EXERCITIU SI ANTRENAMENT ---\n";

    // Creare Exerciții
    Exercitiu ex_cardio("Alergare", "Cardio", 10.0, 30, "Mediu"); // 300 kcal
    Exercitiu ex_forta("Flotari", "Forta", 7.0, 10, "Incepator");  // 70 kcal

    // Test Operator<< Exercitiu
    std::cout << "\n> EX1 Creat:\n" << ex_cardio;
    std::cout << "  Calorii totale arse: " << ex_cardio.calculeazaCaloriiTotale() << " kcal\n\n";

    // Test Operator> Exercitiu (netrivial)
    if (ex_cardio > ex_forta) {
        std::cout << "> Test Operator> (Progres): Alergarea arde mai multe calorii.\n";
    }

    // Creare Antrenament
    Antrenament ant_dimineata("Morning Quick", "Incepator");
    ant_dimineata.adaugExercitiu(ex_cardio);
    ant_dimineata.adaugExercitiu(ex_forta);

    // Test Operator+ Antrenament
    Exercitiu ex_flex("Stretching", "Flexibilitate", 3.0, 15, "Usor");
    ant_dimineata = ant_dimineata + ex_flex; // Test operator= si operator+

    // Test Constructor de Copiere si Operator= Antrenament (pentru Tema 1)
    Antrenament ant_copiat = ant_dimineata; // Constructor de copiere
    Antrenament ant_atrib("Antrenament Gol", "N/A");
    ant_atrib = ant_dimineata; // Operator de atribuire

    // Test Operator<< Antrenament (Compunere apeluri)
    std::cout << "\n> Antrenament complet (Total calorii: "
              << ant_atrib.calculeazaCaloriiTotaleAntrenament() << " kcal):\n";
    std::cout << ant_atrib << "\n";


    // ======================================================
    // 2. TESTARE CLASA OBIECTIV
    // ======================================================
    std::cout << "\n--- 2. TESTARE CLASA OBIECTIV ---\n";

    // Creare Obiectiv (Pierdere in Greutate)
    // Target: 70kg, Initial: 85kg
    Obiectiv obj_slabire("Slabire 15 kg", "Pierdere greutate", 70.0, 85.0, 85.0, "31.12.2025", false);

    // Test Operator<< Obiectiv
    std::cout << "\n> Obiectiv Initial:\n" << obj_slabire;
    std::cout << "  Progres initial: " << obj_slabire.CalculeazaProgrez() << "%\n";

    // Simulare Progres
    obj_slabire.setValoare_curenta(78.0); // Scade de la 85kg la 78kg

    // Test Functie Netriviala: CalculeazaProgrez()
    std::cout << "\n> Dupa scaderea la 78 kg:\n";
    std::cout << "  Progres nou: " << obj_slabire.CalculeazaProgrez() << "%\n";

    // Test Functie Netriviala: VerificAtingereObiectiv()
    obj_slabire.setValoare_curenta(69.0); // Atins
    obj_slabire.VerificAtingereObiectiv();
    std::cout << "  Status dupa atingere: " << (obj_slabire.getObiectiv_atins() ? "ATINS" : "NEATINS") << "\n";
    obj_slabire.setValoare_curenta(85.0); // Reset

    // Test Operator> Obiectiv (Compara progresul)
    Obiectiv obj_anduranta("10 Antrenamente", "Anduranta", 10.0, 0.0, 3.0, "31.01.2026", false);
    if (obj_anduranta > obj_slabire) {
        std::cout << "> Test Operator> (Progres): Obiectivul de Anduranta este mai avansat.\n";
    }


    // ======================================================
    // 3. TESTARE CLASA UTILIZATOR (COMPUNERE)
    // ======================================================
    std::cout << "\n--- 3. TESTARE CLASA UTILIZATOR (COMPUNERE) ---\n";

    // Creare Utilizator (compune obj_slabire)
    Utilizator user_andrei("Andrei", 30, 85.0, 180.0, obj_slabire);

    // Test Operator<< Utilizator (Compunere de apeluri)
    std::cout << "\n> Profilul lui Andrei (initial):\n";
    std::cout << user_andrei << "\n";

    // Simulare Saptamana 1: Antrenamente și Scădere în Greutate
    std::cout << "--- Progres Saptamana 1 ---\n";

    // Test Netrivial: adaug_antrenament_completat
    user_andrei.adaug_antrenament_completat(ant_dimineata); // Antrenament 1
    user_andrei.adaug_antrenament_completat(ant_dimineata); // Antrenament 2

    // Test Netrivial: actualizeazaObiectivGreutate apelata de setGreutateKg
    user_andrei.setGreutateKg(83.0); // Scade de la 85kg la 83kg (actualizeaza obiectivul)
    std::cout << "Noua greutate: 83.0 kg.\n\n";

    // Afisare Profil Final
    std::cout << "> Profilul lui Andrei (Dupa Saptamana 1):\n";
    user_andrei.afisareProfilUtilizator();

    // Test Obiectiv Anduranta (schimbare de obiectiv)
    std::cout << "\n--- Schimbare Obiectiv pe Anduranta ---\n";
    user_andrei.setObiectivCurent(obj_anduranta);
    std::cout << "> Obiectiv nou setat: " << user_andrei.getObiectivCurent().getDescriere() << "\n";

    // Test Progres Obiectiv Anduranta (Logica din adaug_antrenament_completat)
    user_andrei.adaug_antrenament_completat(ant_dimineata); // Antrenament 3 (Obiectiv: 3/10)
    user_andrei.adaug_antrenament_completat(ant_dimineata); // Antrenament 4 (Obiectiv: 4/10)

    std::cout << "\n> Progres Anduranta (4/10): "
              << user_andrei.getObiectivCurent().CalculeazaProgrez() << "%\n";


    std::cout << "\n======================================================\n";
    std::cout << "          TEST COMPLET TEMA 1 FINALIZAT\n";
    std::cout << "======================================================\n";

    return 0;
}
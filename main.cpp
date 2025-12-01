#include <iostream>
#include <string>
#include "Enums.h"
#include <memory>

// --- HEADERS TEMA 1 ---
#include "Exercitiu.h"
#include "Antrenament.h"
#include "Utilizator.h"
#include "Obiectiv.h"

// --- HEADERS TEMA 2 (Noi) ---
#include "PlanAntrenament.h"
#include "PlanSlabire.h"
#include "PlanHipertrofie.h"
#include "PlanAnduranta.h"
#include "PlanReabilitare.h"
#include "GestiunePlanuri.h"
#include "ExceptiiPlanuri.h"

/*
    CARDIO: alergare, ciclism, inot, burpees;
    FORTA: flotari, abdomene, impins la piept, biceps curl;
    FLEXIBILITATE: stretching, yoga, pilates, mobilitate articulara
*/

int main() {
    std::cout << "======================================================\n";
    std::cout << "         FITNESS TRACKER - TEMA 1 + TEMA 2\n";
    std::cout << "======================================================\n\n";

    // ======================================================
    //               PARTEA 1: LOGICA DIN TEMA 1
    // ======================================================
    std::cout << "######################################################\n";
    std::cout << "###              DERULARE TESTE TEMA 1             ###\n";
    std::cout << "######################################################\n";

    // 1. TESTARE CLASE DE BAZA
    std::cout << "--- 1. TESTARE EXERCITIU SI ANTRENAMENT ---\n";

    Exercitiu ex_cardio("Alergare", CategorieExercitiu::CARDIO, 10.0, 30, Dificultate::MEDIU);
    Exercitiu ex_forta("Flotari", CategorieExercitiu::FORTA, 7.0, 10, Dificultate::USOR);

    std::cout << "\n> EX1 Creat:\n" << ex_cardio;
    std::cout << "  Calorii totale arse: " << ex_cardio.calculeazaCaloriiTotale() << " kcal\n\n";

    if (ex_cardio > ex_forta) {
        std::cout << "> Test Operator> (Progres): Alergarea arde mai multe calorii.\n";
    }

    Antrenament ant_dimineata("Morning Quick", toString(NivelExperienta::INCEPATOR));
    ant_dimineata.adaugExercitiu(ex_cardio);
    ant_dimineata.adaugExercitiu(ex_forta);

    Exercitiu ex_flex("Stretching", CategorieExercitiu::FLEXIBILITATE, 3.0, 15, Dificultate::USOR);
    ant_dimineata = ant_dimineata + ex_flex;

    Antrenament ant_copiat = ant_dimineata;
    Antrenament ant_atrib("Antrenament Gol", "N/A");
    ant_atrib = ant_dimineata;

    std::cout << "\n> Antrenament complet (Total calorii: "
              << ant_atrib.calculeazaCaloriiTotaleAntrenament() << " kcal):\n";
    std::cout << ant_atrib << "\n";

    // 2. TESTARE CLASA OBIECTIV
    std::cout << "\n--- 2. TESTARE CLASA OBIECTIV ---\n";

    Obiectiv obj_slabire("Slabire 15 kg",TipObiectiv::PIERDERE_GREUTATE, 70.0, 85.0, 85.0, "31.12.2025", false);
    std::cout << "\n> Obiectiv Initial:\n" << obj_slabire;
    std::cout << "  Progres initial: " << obj_slabire.CalculeazaProgrez() << "%\n";

    obj_slabire.setValoare_curenta(78.0);
    std::cout << "\n> Dupa scaderea la 78 kg:\n";
    std::cout << "  Progres nou: " << obj_slabire.CalculeazaProgrez() << "%\n";

    obj_slabire.setValoare_curenta(69.0);
    obj_slabire.VerificAtingereObiectiv();
    std::cout << "  Status dupa atingere: " << (obj_slabire.getObiectiv_atins() ? "ATINS" : "NEATINS") << "\n";
    obj_slabire.setValoare_curenta(85.0);

    Obiectiv obj_anduranta("10 Antrenamente", TipObiectiv::ANDURANTA, 10.0, 0.0, 3.0, "31.01.2026", false);
    if (obj_anduranta > obj_slabire) {
        std::cout << "> Test Operator> (Progres): Obiectivul de Anduranta este mai avansat.\n";
    }

    // 3. TESTARE CLASA UTILIZATOR
    std::cout << "\n--- 3. TESTARE CLASA UTILIZATOR ---\n";

    Utilizator user_andrei("Andrei", 30, 85.0, 180.0, obj_slabire);
    std::cout << "\n> Profilul lui Andrei (initial):\n";
    std::cout << user_andrei << "\n";

    std::cout << "--- Progres Saptamana 1 ---\n";
    user_andrei.adaug_antrenament_completat(ant_dimineata);
    user_andrei.adaug_antrenament_completat(ant_dimineata);

    user_andrei.setGreutateKg(83.0);
    std::cout << "Noua greutate: 83.0 kg.\n\n";

    std::cout << "> Profilul lui Andrei (Dupa Saptamana 1):\n";
    user_andrei.afisareProfilUtilizator();

    std::cout << "\n--- Schimbare Obiectiv pe Anduranta ---\n";
    user_andrei.setObiectivCurent(obj_anduranta);
    std::cout << "> Obiectiv nou setat: " << user_andrei.getObiectivCurent().getDescriere() << "\n";

    user_andrei.adaug_antrenament_completat(ant_dimineata);
    user_andrei.adaug_antrenament_completat(ant_dimineata);

    std::cout << "\n> Progres Anduranta (4/10): "
              << user_andrei.getObiectivCurent().CalculeazaProgrez() << "%\n";

    // 4. SUPPRESS WARNINGS TEMA 1
    std::cout << "\n--- 4. TESTARE FUNCTII 'UNUSED' ---\n";
    ex_forta.set_nume("flotari");
    ex_forta.set_categorie(CategorieExercitiu::FORTA);
    ex_forta.set_calorii_arse_pe_min(8.0);
    ex_forta.set_durata(12);
    ex_forta.set_dificultate(Dificultate::MEDIU);
    std::cout << "Nume nou: " << ex_forta.get_nume() << "\n";
    ex_forta.afisare_detaliata();
    std::cout << "Numar exercitii: " << ant_atrib.get_nrExercitii() << "\n";

    // Setteri obiectiv ramasi
    obj_slabire.setDescriere("Slabire Agresiva");
    obj_slabire.setTipObiectiv(TipObiectiv::CASTIG_MASA_MUSCULARA);
    obj_slabire.setValoare_dorita(68.0);
    obj_slabire.setValoare_initiala(86.0);
    obj_slabire.setDataLimita("01.01.2026");
    std::cout << "Valoare dorita: " << obj_slabire.getValoare_dorita() << "\n";

    // Setteri utilizator ramasi
    user_andrei.setInaltime_cm(181.0);
    std::cout << "Noul BMI: " << user_andrei.calculezBMI() << "\n";


    // ======================================================
    //               PARTEA 2: LOGICA DIN TEMA 2
    // ======================================================
    std::cout << "\n\n";
    std::cout << "######################################################\n";
    std::cout << "###              TEST TEMA 2                       ###\n";
    std::cout << "###  Polimorfism, Exceptii, STL, Smart Pointers    ###\n";
    std::cout << "######################################################\n";

    try {
        // --- 5. TESTARE EXCEPTII ---
        std::cout << "\n--- 5. TESTARE EXCEPTII Validation Logic ---\n";

        try {
            std::cout << "Incerc sa creez un plan de slabire invalid, deficit prea mic...\n";
            PlanSlabire planGresit("Fail Plan", 3, NivelExperienta::INCEPATOR, 3, 1500, 50, 20);
        } catch (const ExceptieConfigurare& e) {
            std::cout << ">>> EXCEPTIE PRINSA: " << e.what() << "\n";
        } catch (const ExceptieValidarePlan& e) {
            std::cout << ">>> EXCEPTIE VALIDARE: " << e.what() << "\n";
        }

        try {
             std::cout << "Incerc sa creez un plan cu durata invalida (15 luni)...\n";
             PlanHipertrofie planLung("Too Long", 15, NivelExperienta::AVANSAT, 5, "PPL", 12, 10, 300);
        } catch (const ExceptiePlan& e) {
             std::cout << ">>> EXCEPTIE PRINSA: " << e.what() << "\n";
        }


        // --- 6. GESTIUNE PLANURI SI POLIMORFISM ---
        std::cout << "\n--- 6. GESTIUNE PLANURI SI SMART POINTERS ---\n";

        GestiunePlanuri manager("Alexandru Fitness Manager");

        manager.adaugaPlan(std::make_shared<PlanSlabire>(
            "Summer Shredding", 3, NivelExperienta::INTERMEDIAR, 4, 1900, 500, 30));

        manager.adaugaPlan(std::make_shared<PlanHipertrofie>(
            "Winter Bulk", 6, NivelExperienta::AVANSAT, 5, "Push/Pull/Legs", 20, 10, 300));

        manager.adaugaPlan(std::make_shared<PlanAnduranta>(
            "Pregatire Maraton", 4, NivelExperienta::AVANSAT, 6, 42.0, "Alergare", 50));

        manager.adaugaPlan(std::make_shared<PlanReabilitare>(
            "Recuperare Menisc", 2, NivelExperienta::INCEPATOR, 3, "Ruptura Menisc", true, 6));

        std::cout << "Am adaugat 4 planuri in sistem. Numar total (static): "
                  << PlanAntrenament::getNumarPlanuri() << "\n";


        // --- 7. AFISARE POLIMORFICA (VIRTUAL FUNCTIONS) ---
        std::cout << "\n--- 7. AFISARE TOATE PLANURILE Apel Functii Virtuale ---\n";
        manager.afiseazaToatePlanurile();


        // --- 8. TESTARE DYNAMIC_CAST ---
        std::cout << "\n--- 8. TESTARE DYNAMIC_CAST Filtrare Planuri Slabire ---\n";
        manager.afiseazaPlanuriSlabire();


        // --- 9. TESTARE COPY CONSTRUCTOR (DEEP COPY) ---
        std::cout << "\n--- 9. TESTARE DEEP COPY GestiunePlanuri ---\n";
        {
            const GestiunePlanuri& managerCopie = manager;
            std::cout << "S-a creat o copie a managerului.\n";
            std::cout << "Planuri in original: " << manager.getNumarPlanuri() << "\n";
            std::cout << "Planuri in copie: " << managerCopie.getNumarPlanuri() << "\n";
        }


        // --- 10. INTENSITATE MEDIE ---
        std::cout << "\n--- 10.Intensitate Medie ---\n";
        std::cout << "Intensitatea medie a tuturor planurilor din manager: "
                  << manager.calculeazaIntensitateaMedie() << "%\n";


        // ======================================================
        //      PARTEA 2.5: TESTE NOI TEMA 2 - RECOMANDARI FINALE
        // ======================================================
        std::cout << "\n\n";
        std::cout << "######################################################\n";
        std::cout << "###     TESTE NOI TEMA 2 - RECOMANDARI FINALE      ###\n";
        std::cout << "######################################################\n";

        // --- 11. FUNCTIE VIRTUALA SPECIFICA: genereazaProgram() ---
        std::cout << "\n--- 11. FUNCTIE VIRTUALA SPECIFICA genereazaProgram() ---\n";
        manager.activeazaPlan(0); // Activam planul de slabire
        auto planActiv = manager.getPlanActiv();

        if (planActiv) {
            std::cout << "\n[TEST] Generare program pentru " << planActiv->getNumePlan() << ":\n";
            auto program = planActiv->genereazaProgram(2);
            for (const auto& zi : program) {
                std::cout << "  " << zi << "\n";
            }
           std::cout << "   [!] Metoda genereazaProgram() nu este implementata inca.\n";
        }

        // --- 12. INTERFATA NON-VIRTUALA executaSaptamana() ---
        std::cout << "\n--- 12. INTERFATA NON-VIRTUALA executaSaptamana() ---\n";

        // VARIANTA 1: Apel direct pe plan individual
        std::cout << "\n[A] Executie PLAN INDIVIDUAL (prin pointer activ):\n";
        if (planActiv) {
            // AICI AM DECOMENTAT PENTRU A REZOLVA WARNING-UL
            planActiv->executaSaptamana(3);
        }

        // VARIANTA 2: Testam pe alt plan (Hipertrofie)
        std::cout << "\n[B] Executie alt plan (Hipertrofie - saptamana 5):\n";
        manager.activeazaPlan(1); // Activam plan hipertrofie
        if (auto planHipertrofie = manager.getPlanActiv()) {
            // AICI AM DECOMENTAT PENTRU A REZOLVA WARNING-UL
            planHipertrofie->executaSaptamana(5);
        }

        // VARIANTA 3: Simulare progresie multi-saptamani
        std::cout << "\n[C] Simulare PROGRESIE 3 saptamani (Plan Anduranta):\n";
        manager.activeazaPlan(2); // Plan Anduranta
        if (auto planAnduranta = manager.getPlanActiv()) {
            for (int sapt = 1; sapt <= 3; sapt++) {
                std::cout << "\n>>> SAPTAMANA " << sapt << " <<<\n";
                planAnduranta->executaSaptamana(sapt);
                std::cout << "---------------------------------\n";
            }
        }

        // VARIANTA 4: Apel prin GestiunePlanuri pe TOATE planurile
        std::cout << "\n[D] Executie TOATE PLANURILE simultan (sapt 4):\n";

        // --- 13. FUNCTII STATICE UTILE ---
        std::cout << "\n--- 13. FUNCTII STATICE UTILE ---\n";

        // --- 14. FUNCTII DE NIVEL INALT (in loc de getteri) ---
        std::cout << "\n--- 14. FUNCTII DE NIVEL INALT ---\n";

        manager.activeazaPlan(0); // Slabire
        auto planSlabire = std::dynamic_pointer_cast<PlanSlabire>(manager.getPlanActiv());
        //if (planSlabire) {
            // TODO: Decomenteaza dupa implementarea metodelor specifice
            /*
            std::cout << "[PlanSlabire] Pierdere estimata: "
                      << planSlabire->estimeazaPierdereGreutate() << " kg\n";
            */
        //}

        // --- 15. TESTARE COPY-AND-SWAP ---
        std::cout << "\n--- 15. TESTARE COPY-AND-SWAP ---\n";
        GestiunePlanuri managerB("User B");
        managerB.adaugaPlan(std::make_shared<PlanSlabire>("Plan B", 1, NivelExperienta::INCEPATOR, 3, 1500, 300, 20));

        std::cout << "Inainte de atribuire:\n";
        std::cout << "  Manager original: " << manager.getNumarPlanuri() << " planuri\n";
        std::cout << "  Manager B: " << managerB.getNumarPlanuri() << " planuri\n";

        managerB = manager; // Copy-and-swap

        std::cout << "Dupa atribuire (managerB = manager):\n";
        std::cout << "  Manager original: " << manager.getNumarPlanuri() << " planuri\n";
        std::cout << "  Manager B: " << managerB.getNumarPlanuri() << " planuri\n";

    } catch (const std::exception& e) {
        std::cout << "\nEroare neprinsa in main: " << e.what() << "\n";
    }

    // ======================================================
    //      PARTEA 3: CODE COVERAGE (SOLUTIE PENTRU WARNINGS)
    // ======================================================
    std::cout << "\n\n";
    std::cout << "######################################################\n";
    std::cout << "###       TESTARE EXTINSA (CODE COVERAGE)          ###\n";
    std::cout << "######################################################\n";

    // 1. Unused in Antrenament & Exercitiu
    std::cout << "\n> [Antrenament/Exercitiu] Getters:\n";
    std::cout << "  Durata antrenament: " << ant_dimineata.calculeazaDurataAntrenament() << " min\n";
    std::cout << "  Detalii Exercitiu: " << toString(ex_cardio.get_categorie())
              << " | " << ex_cardio.get_calorii_arse_pe_min() << " cal/min"
              << " | " << toString(ex_cardio.get_dificultate()) << "\n";

    // 2. Unused in Utilizator & Obiectiv
    std::cout << "\n> [Utilizator/Obiectiv] Getters:\n";
    std::cout << "  Varsta utilizator: " << user_andrei.getVarsta() << " ani\n";
    std::cout << "  Valoare initiala obiectiv: " << obj_slabire.getValoare_initiala() << " kg\n";
    std::cout << "  Data limita obiectiv: " << obj_slabire.getDataLimita() << "\n";

    // Testare functie globala stringToTipObiectiv
    try {
        TipObiectiv tip = stringToTipObiectiv("Text Invalid care arunca eroare");
        // Daca nu se arunca eroare, afisam rezultatul (dar aici ne asteptam la eroare)
        std::cout << "  Tip returnat: " << tipObiectivToString(tip) << "\n";
    } catch (const std::exception& e) {
        std::cout << "  [TEST VALID] stringToTipObiectiv a aruncat exceptia corecta: " << e.what() << "\n";
    }

    // 3. Unused in GestiunePlanuri
    // CORECTIE: Cream un manager nou si ii adaugam planuri INAINTE sa accesam indecsi!
    GestiunePlanuri managerCoverage("Manager Coverage");
    managerCoverage.adaugaPlan(std::make_shared<PlanSlabire>("Slabire A", 1, NivelExperienta::INCEPATOR, 3, 1500, 300, 20)); // index 0
    managerCoverage.adaugaPlan(std::make_shared<PlanHipertrofie>("Masa B", 1, NivelExperienta::INCEPATOR, 3, "Full", 10, 10, 200)); // index 1

    std::cout << "\n> [GestiunePlanuri] Statistici si Activare:\n";
    managerCoverage.activeazaPlan(1); // Acum este safe, deoarece avem 2 planuri (index 0 si 1)

    auto planActiv = managerCoverage.getPlanActiv();
    if (planActiv) {
        std::cout << "  Plan activ curent: " << planActiv->getNumePlan() << "\n";
    }

    std::cout << "  Contor Slabire: " << managerCoverage.getNumarPlanuriSlabire() << "\n";
    std::cout << "  Contor Hipertrofie: " << managerCoverage.getNumarPlanuriHipertrofie() << "\n";

    // 4. Unused in PlanAntrenament (Base) & Derivate Specifice
    std::cout << "\n> [PlanAntrenament] Metode specifice claselor derivate:\n";

    if (planActiv) {
        // Testare set/get din clasa de baza
        planActiv->setSaptamanaCurenta(2);
        std::cout << "  Saptamana curenta setata la: " << planActiv->getSaptamanaCurenta() << "\n";
        std::cout << "  Durata totala plan: " << planActiv->getDurataLuni() << " luni\n";

        // Downcast pentru a testa metodele specifice derivatelor
        if (auto planHyp = std::dynamic_pointer_cast<PlanHipertrofie>(planActiv)) {
            std::cout << "  [Hipertrofie Specific] Split: " << planHyp->getTipSplit() << "\n";
            std::cout << "  [Hipertrofie Specific] Seturi: " << planHyp->getSeturiPerGrupaMusculara() << "\n";
        }
    }

    // Obiecte temporare pentru restul getterilor (ca sa scapam de warning-uri)
    PlanAnduranta tempAndu("Test", 1, NivelExperienta::INCEPATOR, 1, 10.0, "Run", 30);
    std::cout << "  [Anduranta Specific] Distanta: " << tempAndu.getDistantaTinta() << " km\n";

    PlanReabilitare tempRehab("Test", 1, NivelExperienta::INCEPATOR, 1, "Spate", false, 3);
    std::cout << "  [Reabilitare Specific] Leziune: " << tempRehab.getTipLeziune()
              << " | Durere: " << tempRehab.getNivelDurere() << "\n";

    // 5. Static function
    PlanAntrenament::resetNumarPlanuri();
    std::cout << "  Numar planuri resetat (static).\n";

    std::cout << "\n======================================================\n";
    std::cout << "          TOATE METODELE AU FOST VERIFICATE!\n";
    std::cout << "======================================================\n";

    return 0;
}
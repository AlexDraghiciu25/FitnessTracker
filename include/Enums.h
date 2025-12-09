#ifndef OOP_ENUMS_H
#define OOP_ENUMS_H

#include <string>

enum class NivelExperienta {
    INCEPATOR,
    INTERMEDIAR,
    AVANSAT
};

inline std::string toString(NivelExperienta nivel) {
    switch (nivel) {
        case NivelExperienta::INCEPATOR: return "INCEPATOR";
        case NivelExperienta::INTERMEDIAR: return "INTERMEDIAR";
        case NivelExperienta::AVANSAT: return "AVANSAT";
        default: return "NECUNOSCUT";
    }
}

enum class CategorieExercitiu {
    CARDIO,
    FORTA,
    FLEXIBILITATE,
    RECUPERARE,
    ALTELE
};

inline std::string toString(CategorieExercitiu categorie) {
    switch (categorie) {
        case CategorieExercitiu::CARDIO: return "CARDIO";
        case CategorieExercitiu::FORTA: return "FORTA";
        case CategorieExercitiu::FLEXIBILITATE: return "FLEXIBILITATE";
        case CategorieExercitiu::RECUPERARE: return "RECUPERARE";
        default: return "ALTELE";
    }
}

enum class Dificultate {
    USOR,
    MEDIU,
    GREU
};

inline std::string toString(Dificultate dificultate) {
    switch (dificultate) {
        case Dificultate::USOR: return "USOR";
        case Dificultate::MEDIU: return "MEDIU";
        case Dificultate::GREU: return "GREU";
        default: return "NECUNOSCUT";
    }
}

#endif //OOP_ENUMS_H
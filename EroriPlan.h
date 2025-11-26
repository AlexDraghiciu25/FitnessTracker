//
// Created by Alexandru on 11/21/2025.
//

#ifndef OOP_ERORIPLAN_H
#define OOP_ERORIPLAN_H

#include <exception>
#include <string>
#include <utility>

class EroarePlan : public std::exception {
    protected:
        std::string mesaj;
    public:
        explicit EroarePlan(std::string  msg) : mesaj(std::move(msg)){}

        [[nodiscard]] const char* what() const noexcept override {
            return mesaj.c_str();
        }
};

class EroarePlanNevalid : public EroarePlan {
    public:
        EroarePlanNevalid() : EroarePlan("Eroare critica: Planul nu a putut fi initializat corect!") {}
};

class EroareZiInvalida : public EroarePlan {
    public:
        explicit EroareZiInvalida(int zi)
            : EroarePlan("Eroare: Ziua " + std::to_string(zi) + " nu exista in acest plan!") {}
};

#endif //OOP_ERORIPLAN_H
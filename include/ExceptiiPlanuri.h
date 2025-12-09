#ifndef OOP_EXCEPTIIPLANURI_H
#define OOP_EXCEPTIIPLANURI_H

#include <exception>
#include <string>
#include <utility>

// CLASA DE BAZĂ pentru excepții
class ExceptiePlan : public std::exception {
protected:
    std::string mesaj;

public:
    explicit ExceptiePlan(std::string  msg) : mesaj(std::move(msg)) {}

    [[nodiscard]] const char* what() const noexcept override {
        return mesaj.c_str();
    }

    ~ExceptiePlan() override = default;
};

// DERIV 1: Validare date plan
class ExceptieValidarePlan : public ExceptiePlan {
public:
    explicit ExceptieValidarePlan(const std::string& msg)
        : ExceptiePlan("[VALIDARE PLAN] " + msg) {}
};

// DERIV 2: Erori de configurare plan
class ExceptieConfigurare : public ExceptiePlan {
public:
    explicit ExceptieConfigurare(const std::string& msg)
        : ExceptiePlan("[CONFIGURARE] " + msg) {}
};

// DERIV 3: Erori de gestionare planuri
class ExceptieGestiune : public ExceptiePlan {
public:
    explicit ExceptieGestiune(const std::string& msg)
        : ExceptiePlan("[GESTIUNE] " + msg) {}
};

#endif //OOP_EXCEPTIIPLANURI_H
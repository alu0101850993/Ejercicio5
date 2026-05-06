#include "class_user.h"

void User::mostrarPerfil() const {
    std::cout << "\n--- PERFIL ---\n";
    std::cout << "Nombre: " << nombre_ << "( " << rol_ << " )" << std::endl;
    std::cout << "Correo: " << correo_ << std::endl;
    std::cout << "Telefono: " << telefono_ << std::endl;
    std::cout << "Saldo: " << saldo_ << "€" << std::endl;
}

void User::ingresarSaldo(double cantidad) {
    saldo_ += cantidad;
}

bool User::retirarSaldo(double cantidad) {
    if (saldo_ >= cantidad) {
        saldo_ -= cantidad;
        return true;
    }
    return false;
}
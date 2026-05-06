#include "pago.h"

bool Pago::comprobarSaldo(const User& usuario, float cantidad) {
  return usuario.getSaldo() >= cantidad;
}

bool Pago::realizarPago(User& conductor, User& propietario, float cantidad) {
    if (!comprobarSaldo(conductor, cantidad)) {
        return false;
    }

    restarSaldo(conductor, cantidad);
    sumarIngresos(propietario, cantidad);

    return true;
}

// Suma dinero al propietario
void Pago::sumarIngresos(User& propietario, float cantidad) {
    propietario.setSaldo(propietario.getSaldo() + cantidad);
}

// Resta dinero al conductor
void Pago::restarSaldo(User& conductor, float cantidad) {
    conductor.setSaldo(conductor.getSaldo() - cantidad);
}
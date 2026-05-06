#include "pago.h"

bool Pago::comprobarSaldo(const Usuario& usuario, float cantidad) {
  return usuario.getSaldo() >= cantidad;
}

bool Pago::realizarPago(Usuario& conductor, Usuario& propietario, float cantidad) {
    if (!comprobarSaldo(conductor, cantidad)) {
        return false;
    }

    restarSaldo(conductor, cantidad);
    sumarIngresos(propietario, cantidad);

    return true;
}

// Suma dinero al propietario
void Pago::sumarIngresos(Usuario& propietario, float cantidad) {
    propietario.setSaldo(propietario.getSaldo() + cantidad);
}

// Resta dinero al conductor
void Pago::restarSaldo(Usuario& conductor, float cantidad) {
    conductor.setSaldo(conductor.getSaldo() - cantidad);
}
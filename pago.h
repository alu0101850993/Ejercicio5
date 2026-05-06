#ifndef PAGO_H_
#define PAGO_H_

#include <usuario.h>

class Pago {
 public:
  // Comprueba si hay saldo suficiente
  bool comprobarSaldo(const Usuario& usuario, float cantidad);

  // Realiza el pago (resta dinero al conductor y suma al propietario)
  bool realizarPago(Usuario& conductor, Usuario& propietario, float cantidad);

  // Añade ingresos al propietario
  void sumarIngresos(Usuario& propietario, float cantidad);

  // Resta dinero al conductor
  void restarSaldo(Usuario& conductor, float cantidad);
};

#endif
#ifndef PAGO_H_
#define PAGO_H_

#include <class_user.h>

class Pago {
 public:
  // Comprueba si hay saldo suficiente
  bool comprobarSaldo(const User& usuario, float cantidad);

  // Realiza el pago (resta dinero al conductor y suma al propietario)
  bool realizarPago(User& conductor, User& propietario, float cantidad);

  // Añade ingresos al propietario
  void sumarIngresos(User& propietario, float cantidad);

  // Resta dinero al conductor
  void restarSaldo(User& conductor, float cantidad);
};

#endif
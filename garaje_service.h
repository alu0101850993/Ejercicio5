#ifndef GARAJESERVICE_H
#define GARAJESERVICE_H

#include <vector>
#include <string>
#include "garaje.h"
#include "class_user.h"
#include "pago.h"

class GarajeService {
 private:
  std::vector<Garaje> garajes;
  void cargarGarajes();
  void guardarGarajes();

 public:
  GarajeService();

  void buscarGarajes() const;
  bool reservarPlaza(std::string idNombre, int tiempo, User& conductor, User& propietario);
  void altaGaraje();
  void configurarGaraje(std::string idNombre, double nuevoPrecio, bool nuevaDisponibilidad, const User& propietario);
};

#endif
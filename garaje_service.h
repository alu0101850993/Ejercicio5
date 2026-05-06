#ifndef GARAJESERVICE_H
#define GARAJESERVICE_H

#include <vector>
#include <string>
#include "garaje.h"

class GarajeService {
 private:
  std::vector<Garaje> garajes;
  void cargarGarajes();
  void guardarGarajes();

 public:
  GarajeService();

  void buscarGarajes() const;
  bool reservarPlaza(std::string idNombre, int tiempo, std::string idUsuarioLogueado);
  void altaGaraje();
  void configurarGaraje(std::string idNombre, double nuevoPrecio, bool nuevaDisponibilidad, std::string idUsuarioLogueado);
};

#endif 
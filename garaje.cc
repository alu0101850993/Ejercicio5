#include "garaje.h"

// Implementación del operador >>
std::istream& operator>>(std::istream& is, Garaje& g) {
  std::cout << "Introduce ID (Nombre): ";
  is >> std::ws;
  std::getline(is, g.idNombre_);
  
  std::cout << "Introduce Ubicacion: ";
  is >> std::ws;
  std::getline(is, g.ubicacion_);
  
  std::cout << "Introduce Precio (por hora): ";
  is >> g.precio_;
  
  std::cout << "Introduce Disponibilidad (1 para Si, 0 para No): ";
  is >> g.disponible_;
  
  std::cout << "Introduce ID Arrendador: ";
  is >> std::ws;
  std::getline(is, g.idArrendador_);
  
  std::cout << "Introduce Documento Catastral: ";
  is >> std::ws;
  std::getline(is, g.documentoCatastral_);
  
  return is;
}

// Implementación del operador <<
std::ostream& operator<<(std::ostream& os, const Garaje& g) {
  os << "--- Datos del Garaje ---\n"
     << "ID (Nombre): " << g.idNombre_ << "\n"
     << "Ubicacion: " << g.ubicacion_ << "\n"
     << "Precio: " << g.precio_ << " euros la hora\n"
     << "Disponible: " << (g.disponible_ ? "Si" : "No") << "\n"
     << "Arrendador: " << g.idArrendador_ << "\n"
     << "Doc. Catastral: " << g.documentoCatastral_ << "\n";
     
  return os;
}
// Clase Garaje implementación el objeto tipo garaje que contenga los documentos catastrales
// junto con su id (nombre), su ubicación, precio, disponibilidad y arrendador
// se sobrecargará el operador de insercion (>>) y el de mostrar por pantalla


#ifndef GARAJE_H
#define GARAJE_H

#include <string>
#include <iostream>

class Garaje {
 public:
  Garaje() : precio_(0.0), disponible_(false) {}
  Garaje(std::string id, std::string ubi, double pre, bool disp, std::string arrendador, std::string docCatastral)
  : idNombre_(id), ubicacion_(ubi), precio_(pre), disponible_(disp), idArrendador_(arrendador), documentoCatastral_(docCatastral) {}


  std::string getIdNombre() const { return idNombre_; }
  std::string getUbicacion() const { return ubicacion_; }
  double getPrecio() const { return precio_; }
  bool isDisponible() const { return disponible_; }
  std::string getIdArrendador() const { return idArrendador_; }
  std::string getDocumentoCatastral() const { return documentoCatastral_; }

  void setPrecio(double nuevoPrecio) { precio_ = nuevoPrecio; }
  void setDisponibilidad(bool estado) { disponible_ = estado; }

  // Sobrecarga del operador de extracción (lectura)
  friend std::istream& operator>>(std::istream& is, Garaje& g);
  
  // Sobrecarga del operador de inserción (mostrar por pantalla)
  friend std::ostream& operator<<(std::ostream& os, const Garaje& g);

 private:
  std::string idNombre_;
  std::string ubicacion_;
  double precio_;
  bool disponible_;
  std::string idArrendador_;
  std::string documentoCatastral_;
};

#endif
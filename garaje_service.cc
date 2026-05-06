#include "garaje_service.h"
#include <iostream>
#include "notificaciones.h"

// Dependencias de otros compañeros según la arquitectura del proyecto:
// #include "archivo.h"

GarajeService::GarajeService() {
  cargarGarajes();
}

void GarajeService::cargarGarajes() {
  // Delegado al compañero de Persistencia (Archivos)
  // garajes = archivo::leerGarajes();
}

void GarajeService::guardarGarajes() {
  // Delegado al compañero de Persistencia (Archivos)
  // archivo::guardarGarajes(garajes);
}

void GarajeService::buscarGarajes() const {
  std::cout << "--- Garajes Disponibles ---\n";
  for (const auto& g : garajes) {
    if (g.isDisponible()) {
      std::cout << g << "\n";
    }
  }
}

bool GarajeService::reservarPlaza(std::string idNombre, int tiempo, User& conductor, User& propietario) {
  for (auto& g : garajes) {
    if (g.getIdNombre() == idNombre && g.isDisponible()) {
      double costoTotal = g.getPrecio() * tiempo;
      
      Pago sistemaPago;
      bool pagoExitoso = sistemaPago.realizarPago(conductor, propietario, costoTotal);
      
      if (pagoExitoso) {
        g.setDisponibilidad(false); 
        guardarGarajes();
        
        Mensaje notifExito("Se ha reservado una plaza con exito y el pago se ha realizado.", "Hoy");
        std::cout << notifExito;
        return true;
      } else {
        Mensaje notifError("Saldo insuficiente para reservar la plaza.", "Hoy");
        std::cout << notifError;
        return false;
      }
    }
  }
  return false;
}

void GarajeService::altaGaraje() {
  std::cout << "--- Alta de nuevo Garaje ---\n";
  Garaje nuevoGaraje;
  
  std::cin >> nuevoGaraje; 
  
  garajes.push_back(nuevoGaraje);
  guardarGarajes();
  
  Mensaje notifAlta("Plaza dada de alta exitosamente.", "Hoy");
  std::cout << notifAlta;
}

void GarajeService::configurarGaraje(std::string idNombre, double nuevoPrecio, bool nuevaDisponibilidad, const User& propietario) {
  for (auto& g : garajes) {
    if (g.getIdNombre() == idNombre && g.getIdArrendador() == propietario.getNombre()) {
      g.setPrecio(nuevoPrecio); 
      g.setDisponibilidad(nuevaDisponibilidad); 
      guardarGarajes();
      
      Mensaje notifConfig("Configuracion de plaza actualizada.", "Hoy");
      std::cout << notifConfig;
      break;
    }
  }
}
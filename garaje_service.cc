#include "garaje_service.h"
#include <iostream>

// Dependencias de otros compañeros según la arquitectura del proyecto[cite: 1]:
// #include "archivo.h"
// #include "pago.h"
// #include "notificacion.h"

GarajeService::GarajeService() {
  cargarGarajes();
}

void GarajeService::cargarGarajes() {
  // Delegado al compañero de Persistencia (Archivos)[cite: 1]
  // garajes = archivo::leerGarajes();
}

void GarajeService::guardarGarajes() {
  // Delegado al compañero de Persistencia (Archivos)[cite: 1]
  // archivo::guardarGarajes(garajes);
}

void GarajeService::buscarGarajes() const {
  std::cout << "--- Garajes Disponibles ---\n";
  for (const auto& g : garajes) {
    if (g.isDisponible()) {
      // Aprovechamos la sobrecarga del operador << para mostrar los datos
      std::cout << g << "\n";
    }
  }
}

bool GarajeService::reservarPlaza(std::string idNombre, int tiempo, std::string idUsuarioLogueado) {
  for (auto& g : garajes) {
    // Se introduce el id de la plaza y se reserva si esta disponible[cite: 1]
    if (g.getIdNombre() == idNombre && g.isDisponible()) {
      double costoTotal = g.getPrecio() * tiempo;
      
      // Llamada a la dependencia de Pagos para comprobar saldo y descontar[cite: 1]
      // bool pagoExitoso = pago::procesarPago(idUsuarioLogueado, g.getIdArrendador(), costoTotal);
      bool pagoExitoso = true; // Variable simulada para que compile
      
      if (pagoExitoso) {
        // La plaza queda ocupada en ese lapso de tiempo[cite: 1]
        g.setDisponibilidad(false); 
        guardarGarajes();
        
        // Llamada a la dependencia de Notificaciones[cite: 1]
        // notificacion::mostrar("Se ha reservado una plaza con exito.");
        return true;
      }
    }
  }
  return false;
}

void GarajeService::altaGaraje() {
  std::cout << "--- Alta de nuevo Garaje ---\n";
  Garaje nuevoGaraje;
  
  // Aprovechamos la sobrecarga del operador >> para pedir los datos[cite: 1]
  std::cin >> nuevoGaraje; 
  
  garajes.push_back(nuevoGaraje);
  guardarGarajes();
  
  // notificacion::mostrar("Plaza dada de alta exitosamente.");
}

void GarajeService::configurarGaraje(std::string idNombre, double nuevoPrecio, bool nuevaDisponibilidad, std::string idUsuarioLogueado) {
  for (auto& g : garajes) {
    // Permite realizar cambios en la plaza (precio y disponibilidad) si es el propietario[cite: 1]
    if (g.getIdNombre() == idNombre && g.getIdArrendador() == idUsuarioLogueado) {
      g.setPrecio(nuevoPrecio); 
      g.setDisponibilidad(nuevaDisponibilidad); 
      guardarGarajes();
      
      // notificacion::mostrar("Configuracion de plaza actualizada.");
      break;
    }
  }
}
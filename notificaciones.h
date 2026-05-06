// Función para mostrar una notificación, esta recibe un mensaje en forma de string y muestra lo que se encuentre en el mimso
#include <iostream>
#include <string>

class Mensaje {
  public:
    Mensaje(const std::string &mensaje, const std::string &fecha) : contenido_(mensaje), fecha_(fecha) {}
    
    std::string GetFecha() const { return fecha_; }
    std::string GetContenido() const { return contenido_; }

  private:
    std::string contenido_;
    std::string fecha_;
};

std::ostream& operator<<(std::ostream& os, const Mensaje &mensaje) {
  os << "Notificación entrante [" << mensaje.GetFecha() << "] : " << mensaje.GetContenido() << std::endl;
  return os;
}   
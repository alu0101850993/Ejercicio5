#include "archivo.h"
#include <fstream>
#include <sstream>

namespace archivo {

void guardarUsuarios(const std::vector<User>& usuarios) {
    std::ofstream file("usuarios.txt");

    for (const auto& u : usuarios) {
        file << u.getNombre() << " "
             << u.getCorreo() << " "
             << u.getPassword() << " "
             << u.getTelefono() << " "
             << u.getRol() << " "
             << u.getSaldo() << "\n";
    }
}

std::vector<User> leerUsuarios() {
    std::vector<User> usuarios;
    std::ifstream file("usuarios.txt");

    std::string nombre, correo, password, telefono, rol;
    double saldo;

    while (file >> nombre >> correo >> password >> telefono >> rol >> saldo) {
        usuarios.emplace_back(nombre, correo, password, telefono, rol, saldo);
    }

    return usuarios;
}

void guardarGarajes(const std::vector<Garaje>& garajes) {
    std::ofstream file("garajes.txt");

    for (const auto& g : garajes) {
        file << g.getIdNombre() << "|"
             << g.getUbicacion() << "|"
             << g.getPrecio() << "|"
             << g.isDisponible() << "|"
             << g.getIdArrendador() << "|"
             << g.getDocumentoCatastral() << "\n";
    }
}

std::vector<Garaje> leerGarajes() {
    std::vector<Garaje> garajes;
    std::ifstream file("garajes.txt");
    std::string linea;

    while (std::getline(file, linea)) {
        std::stringstream ss(linea);
        std::string id, ubi, arr, doc;
        double precio;
        bool disp;

        std::getline(ss, id, '|');
        std::getline(ss, ubi, '|');
        ss >> precio;
        ss.ignore();
        ss >> disp;
        ss.ignore();
        std::getline(ss, arr, '|');
        std::getline(ss, doc);

        garajes.emplace_back(id, ubi, precio, disp, arr, doc);
    }

    return garajes;
}

}
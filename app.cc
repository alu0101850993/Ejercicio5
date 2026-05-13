#include "app.h"
#include <iostream>
#include <limits>

void limpiarInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

App::App() : usuarioActual(nullptr) {
    usuarios = archivo::leerUsuarios();
}

void App::run() {
    menuPrincipal();
    archivo::guardarUsuarios(usuarios);
}

void App::menuPrincipal() {
    int opcion;

    do {
        std::cout << "\n1. Login\n2. Registro\n0. Salir\nOpcion: ";

        if (!(std::cin >> opcion)) {
            std::cout << "❌ Opcion invalida\n";
            limpiarInput();
            continue;
        }

        switch(opcion) {
            case 1: login(); break;
            case 2: registro(); break;
            case 0: break;
            default:
                std::cout << "❌ Opcion no valida\n";
        }

    } while(opcion != 0);
}

void App::login() {
    std::string correo, password;

    std::cout << "Correo: ";
    std::cin >> correo;

    std::cout << "Password: ";
    std::cin >> password;

    for (auto& u : usuarios) {
        if (u.getCorreo() == correo && u.getPassword() == password) {
            usuarioActual = &u;
            std::cout << "Login correcto\n";
            menuUsuario();
            return;
        }
    }

    std::cout << "❌ Credenciales incorrectas\n";
}

void App::registro() {
    std::string nombre, correo, password, telefono, rol;

    std::cout << "Nombre: "; std::cin >> nombre;
    std::cout << "Correo: "; std::cin >> correo;
    std::cout << "Password: "; std::cin >> password;
    std::cout << "Telefono: "; std::cin >> telefono;
    std::cout << "Rol (conductor/propietario): "; std::cin >> rol;

    usuarios.emplace_back(nombre, correo, password, telefono, rol, 100.0);

    archivo::guardarUsuarios(usuarios);

    std::cout << "Usuario registrado\n";
}

void App::editarPerfil() {
    int opcion;

    do {
        std::cout << "\n--- EDITAR PERFIL ---\n";
        std::cout << "1. Cambiar nombre\n";
        std::cout << "2. Cambiar telefono\n";
        std::cout << "3. Cambiar password\n";
        std::cout << "0. Volver\n";
        std::cout << "Opcion: ";

        if (!(std::cin >> opcion)) {
            std::cout << "❌ Entrada invalida\n";
            limpiarInput();
            continue;
        }

        switch(opcion) {

            case 1: {
                std::string nuevoNombre;
                std::cout << "Nuevo nombre: ";
                std::cin >> nuevoNombre;

                usuarioActual->setNombre(nuevoNombre);
                std::cout << "✔ Nombre actualizado\n";
                break;
            }

            case 2: {
                std::string nuevoTelefono;
                std::cout << "Nuevo telefono: ";
                std::cin >> nuevoTelefono;

                usuarioActual->setTelefono(nuevoTelefono);
                std::cout << "✔ Telefono actualizado\n";
                break;
            }

            case 3: {
                std::string nuevaPass;
                std::cout << "Nueva password: ";
                std::cin >> nuevaPass;

                usuarioActual->setPassword(nuevaPass);
                std::cout << "✔ Password actualizada\n";
                break;
            }

            case 0:
                break;

            default:
                std::cout << "❌ Opcion no valida\n";
        }

    } while(opcion != 0);

    archivo::guardarUsuarios(usuarios); 
}
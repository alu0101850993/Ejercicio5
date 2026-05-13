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

    std::cout << "Usuario registrado\n";
}

void App::menuUsuario() {
    int opcion;

    do {
        std::cout << "\n1. Ver perfil\n";

        if (usuarioActual->getRol() == "conductor") {
            std::cout << "2. Buscar garajes\n";
            std::cout << "3. Reservar\n";
        }

        if (usuarioActual->getRol() == "propietario") {
            std::cout << "2. Alta garaje\n";
            std::cout << "3. Configurar garaje\n";
        }

        std::cout << "0. Logout\nOpcion: ";

        if (!(std::cin >> opcion)) {
            std::cout << "❌ Entrada invalida\n";
            limpiarInput();
            continue;
        }

        switch(opcion) {

            case 1:
                usuarioActual->mostrarPerfil();
                break;

            case 2:
                if (usuarioActual->getRol() == "conductor") {
                    garajeService.buscarGarajes();
                } else {
                    garajeService.altaGaraje();
                }
                break;

            case 3:
                if (usuarioActual->getRol() == "conductor") {
                    std::string id;
                    int tiempo;

                    std::cout << "ID garaje: ";
                    std::cin >> id;

                    std::cout << "Horas: ";
                    if (!(std::cin >> tiempo) || tiempo <= 0) {
                        std::cout << "❌ Horas invalidas\n";
                        limpiarInput();
                        break;
                    }

                    bool reservado = false;

                    for (auto& u : usuarios) {
                        if (u.getRol() == "propietario") {
                            if (garajeService.reservarPlaza(id, tiempo, *usuarioActual, u)) {
                                reservado = true;
                            }
                            break;
                        }
                    }

                    if (!reservado) {
                        std::cout << "❌ No se pudo reservar\n";
                    }

                } else {
                    std::string id;
                    double precio;
                    bool disponible;

                    std::cout << "ID garaje: ";
                    std::cin >> id;

                    std::cout << "Nuevo precio: ";
                    if (!(std::cin >> precio) || precio < 0) {
                        std::cout << "❌ Precio invalido\n";
                        limpiarInput();
                        break;
                    }

                    std::cout << "Disponible (1=si, 0=no): ";
                    if (!(std::cin >> disponible)) {
                        std::cout << "❌ Valor invalido\n";
                        limpiarInput();
                        break;
                    }

                    garajeService.configurarGaraje(id, precio, disponible, *usuarioActual);
                }
                break;

            case 0:
                break;

            default:
                std::cout << "❌ Opcion no valida\n";
        }

    } while(opcion != 0);
}
#ifndef APP_H
#define APP_H

#include "class_user.h"
#include "garaje_service.h"
#include "archivo.h"
#include <vector>

class App {
private:
    std::vector<User> usuarios;
    User* usuarioActual;
    GarajeService garajeService;

    void menuPrincipal();
    void menuUsuario();
    void login();
    void registro();
    void editarPerfil(); 

public:
    App();
    void run();
};

#endif
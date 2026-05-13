#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <vector>
#include "class_user.h"
#include "garaje.h"

namespace archivo {
    void guardarUsuarios(const std::vector<User>& usuarios);
    std::vector<User> leerUsuarios();

    void guardarGarajes(const std::vector<Garaje>& garajes);
    std::vector<Garaje> leerGarajes();
}

#endif
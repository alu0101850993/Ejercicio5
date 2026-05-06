/*
Clase usuario que recoge tanto el nombre real del usuario, su tlf movil, su email
su numero de tarjeta bancaria para realizar pagos  y su contraseña de inicio de sesion

*/

#pragma once    
#include <iostream>
#include <string>

class User {
    public:
    User() : nombre_(""), correo_(""), password_("") {}
    User(std::string nombre, std::string correo, std::string password, std::string telefono, std::string rol, double saldo) : 
    nombre_(nombre), correo_(correo), password_(password), telefono_(telefono), rol_(rol), saldo_(saldo) {}
    
    std::string getCorreo() const;
    std::string getNombre() const;
    std::string getTelefono() const;
    std::string getPassword() const;
    std::string getRol() const;
    double getSaldo() const;

    void setNombre(std::string nombre);
    void setTelefono(std::string telefono);
    void setPassword(std::string password);
    void setSaldo(double saldo);

    void mostrarPerfil() const;
    void ingresarSaldo(double cantidad);
    bool retirarSaldo(double cantidad);

    private:
      std::string nombre_;
      std::string correo_;
      std::string password_;
      std::string telefono_;
      std::string rol_;
      double saldo_;
};
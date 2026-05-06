/*
Clase usuario que recoge tanto el nombre real del usuario, su tlf movil, su email
su numero de tarjeta bancaria para realizar pagos  y su contraseña de inicio de sesion

*/

#pragma once    
#include <iostream>
#include <string>

class User {
    public:
    User() : nombre_(""), correo_(""), password_(""), telefono_(""), rol_(""), saldo_(0.0) {}
    User(std::string nombre, std::string correo, std::string password, std::string telefono, std::string rol, double saldo) : 
    nombre_(nombre), correo_(correo), password_(password), telefono_(telefono), rol_(rol), saldo_(saldo) {
        if(saldo < 0){
            saldo_ = 0;
        }
    }
    
    std::string getCorreo() const { return correo_;}
    std::string getNombre() const { return nombre_;}
    std::string getTelefono() const { return telefono_;}
    std::string getPassword() const { return password_;}
    std::string getRol() const { return rol_;}
    double getSaldo() const { return saldo_;}

    void setNombre(std::string nombre) { nombre_ = nombre;}
    void setTelefono(std::string telefono) {telefono_ = telefono;}
    void setPassword(std::string password) {password_ = password;}
    void setSaldo(double saldo) { saldo_ = (saldo < 0) ? 0 : saldo;}

    void ingresarSaldo(double cantidad);
    bool retirarSaldo(double cantidad);
    void mostrarPerfil() const;

    private:
      std::string nombre_;
      std::string correo_;
      std::string password_;
      std::string telefono_;
      std::string rol_;
      double saldo_;
};
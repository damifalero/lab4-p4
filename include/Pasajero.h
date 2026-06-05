#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include "Reserva.h"

#include <set>
#include <string>

class Pasajero : public Usuario {
private:
    std::string ci;
    std::set<Reserva*> reservas;

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();
    std::string getci();
    std::set<Reserva*> getReservas();
};

#endif

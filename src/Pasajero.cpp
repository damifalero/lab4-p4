#include "../include/Pasajero.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}

Pasajero::~Pasajero() {

}

//getters
std::string Pasajero::getci(){
    return this->ci;
};

std::set<Reserva*> Pasajero::getReservas(){
    return this->reservas;
};

bool Pasajero::esPasajero() {
    return true;
}

void Pasajero::asociarReserva(Reserva* reserva) {
    this->reservas.insert(reserva);
}

void Pasajero::desasociarReserva(Reserva* reserva) {
    this->reservas.erase(reserva);
}
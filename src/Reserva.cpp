#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/Pasajero.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha, Usuario pasajero,Viaje viaje) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = &pasajero;
    this->viaje = &viaje;
}

int Reserva::getAsientosReservados(){
    return this->asientosReservados;
}

DTFecha Reserva::getDTFecha(){
    return this->fecha;
}

DTListarViaje Reserva::getDTListarViaje(){
    DTListarViaje dtlv(this->viaje->getCodigo(), this->viaje->getFecha(), this->viaje->getOrigen(), this->viaje->getDestino(), this->viaje->getConductor());
} 

std::set<Calificacion*> Reserva::getCalificaciones(){return this->calificaciones;}


Usuario* Reserva::getPasajero(){return this->pasajero;} 
Viaje* Reserva::getViaje(){return this->viaje;}

void Reserva::setViaje(Viaje viaje){
    Viaje* v = new Viaje(viaje.getCodigo(),viaje.getFecha(), viaje.getOrigen(), viaje.getDestino(), viaje.getAsientosPublicados(),viaje.getAsientosDisponibles(), viaje.getPrecioPorAsiento(), viaje.getVehiculo());
    v->setReservas(viaje.getReservas());
    this->viaje = v;
}

void Reserva::setAsientosReservados(int asientosReservados){this->asientosReservados = asientosReservados;}

void Reserva::setDTFecha(DTFecha fecha){this->fecha = fecha;}

void Reserva::setCalificaciones(std::set<Calificacion*> calificaciones){this->calificaciones = calificaciones;}

void Reserva::setPasajero(Usuario pasajero){this->pasajero = &pasajero;}

bool Reserva::agregarCalificacion(Calificacion calificacion){
    this->calificaciones.insert(&calificacion);
}

Reserva::~Reserva() {}

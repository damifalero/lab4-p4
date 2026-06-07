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

void Reserva::setViaje(Viaje viaje){
    Viaje* v = new Viaje(viaje.getCodigo(),viaje.getFecha(), viaje.getOrigen(), viaje.getDestino(), viaje.getAsientosPublicados(),viaje.getAsientosDisponibles(), viaje.getPrecioPorAsiento(), viaje.getVehiculo());
    v->setReservas(viaje.getReservas());
    this->viaje = v;
}

void Reserva::setAsientosReservados(int asientosReservados){this->asientosReservados = asientosReservados;}

void Reserva::setDTFecha(DTFecha fecha){this->fecha = fecha;}

Reserva::~Reserva() {}
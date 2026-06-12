#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/Pasajero.h"
#include "../include/Calificacion.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha, Pasajero pasajero,Viaje viaje) {
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

DTListarViaje Reserva::getDTListarViaje() {
    int codigo = this->viaje->getCodigo();
    DTFecha fecha = this->viaje->getFecha();
    std::string origen = this->viaje->getOrigen();
    std::string destino = this->viaje->getDestino();
    std::string conductor = this->viaje->getConductor();
    return DTListarViaje(codigo, fecha, origen, destino, conductor);
} 

std::set<Calificacion*> Reserva::getCalificaciones(){return this->calificaciones;}

Viaje* Reserva::getViaje(){
    return this->viaje;
}

Pasajero* Reserva::getPasajero(){return this->pasajero;} 

DTDetalleReserva Reserva::getDTDetalleReserva(){
    DTDetalleReserva dtr(this->asientosReservados,this->fecha,this->pasajero->getNickname());
    return dtr;
}


void Reserva::setViaje(Viaje viaje){
    Viaje* v = new Viaje(viaje.getCodigo(),viaje.getFecha(), viaje.getOrigen(), viaje.getDestino(), viaje.getAsientosPublicados(),viaje.getAsientosDisponibles(), viaje.getPrecioPorAsiento(), viaje.getVehiculo());
    v->setReservas(viaje.getReservas());
    this->viaje = v;
}

void Reserva::setAsientosReservados(int asientosReservados){this->asientosReservados = asientosReservados;}

void Reserva::setDTFecha(DTFecha fecha){this->fecha = fecha;}

void Reserva::setCalificaciones(std::set<Calificacion*> calificaciones){this->calificaciones = calificaciones;}

void Reserva::setPasajero(Pasajero pasajero){this->pasajero = &pasajero;}

void Reserva::agregarCalificacion(Calificacion calificacion){
    this->calificaciones.insert(&calificacion);
}

Reserva::~Reserva(){
    this->pasajero = NULL;
    this->viaje = NULL;
    for (std::set<Calificacion*>::iterator itCal = this->calificaciones.begin(); itCal != this->calificaciones.end(); ++itCal) {
        Calificacion* calificacion = *itCal;
        Usuario* uCalificado = calificacion->getUCalificado();
        Usuario* uCalificador = calificacion->getUCalificador();
        uCalificado->desasociarCalificacion(calificacion);
        uCalificador->desasociarCalificacion(calificacion);
        delete calificacion;
    }
    this->calificaciones.clear();
}

void Reserva::asociarViaje(Viaje v){this->viaje = &v;}

void Reserva::desasociarViaje(){this->viaje = NULL;}

void Reserva::asociarPasajero(Pasajero p){this->pasajero = &p;}

void Reserva::desasociarPasajero(){this->pasajero = NULL;}

void Reserva::asociarCalificacion(Calificacion* c){this->calificaciones.insert(c);}

void Reserva::desasociarCalificacion(Calificacion* c){this->calificaciones.erase(c);}
#include "../include/Calificacion.h"

Calificacion:: Calificacion(DTFecha fecha, int puntaje, Reserva res, Usuario uCalificado,Usuario uCalificador){
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->asociarReserva(&res);
    this->asociarUsuarioCalificado(&uCalificado);
    this->asociarUsuarioCalificador(&uCalificador);
}

DTFecha Calificacion::getDTFecha(){return this->fecha;}

Usuario* Calificacion::getUCalificador(){return this->uCalificador;}

Usuario* Calificacion::getUCalificado(){return this->uCalificado;}

int Calificacion::getPuntaje(){return this->puntaje;}

void Calificacion::setDTFecha(DTFecha fecha){this->fecha = fecha;}

void Calificacion::setPuntaje(int puntaje){this->puntaje = puntaje;}

void Calificacion::setUCalificado(Usuario* usuario){this->uCalificado = usuario;}

void Calificacion::setUCalificador(Usuario* usuario){this->uCalificador = usuario;}

void Calificacion::asociarUsuarioCalificado(Usuario* u){this->uCalificado = u;}

void Calificacion::asociarUsuarioCalificador(Usuario* u){this->uCalificador = u;}

void Calificacion::desasociarUsuarioCalificado(){this->uCalificado = NULL;};

void Calificacion::desasociarUsuarioCalificador(){this->uCalificador = NULL;};

void Calificacion::asociarReserva(Reserva* r){this->res = r;};

void Calificacion::desasociarReserva(){this->res = NULL;}

Calificacion::~Calificacion() {
    this->uCalificado = NULL;
    this->uCalificador = NULL;
}


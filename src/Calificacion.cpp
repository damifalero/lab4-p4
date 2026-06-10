#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

DTFecha Calificacion::getDTFecha(){return this->fecha;}

Usuario* Calificacion::getUCalificador(){return this->uCalificador;}

Usuario* Calificacion::getUCalificado(){return this->uCalificado;}

int Calificacion::getPuntaje(){return this->puntaje;}

void Calificacion::setDTFecha(DTFecha fecha){this->fecha = fecha;}

void Calificacion::setPuntaje(int puntaje){this->puntaje = puntaje;}

void Calificacion::setUCalificado(Usuario* usuario){this->uCalificado = usuario;}

void Calificacion::setUCalificador(Usuario* usuario){this->uCalificador = usuario;}

Calificacion::~Calificacion() {
    this->uCalificado = NULL;
    this->uCalificador = NULL;
}

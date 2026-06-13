#include "../include/DTConsultaViaje.h"

DTConsultaViaje::DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal) {
    this->codigo = codigo;
    this->marca = marca;
    this->modelo = modelo;
    this->conductor = conductor;
    this->calificacionProm = calificacionProm;
    this->precioTotal = precioTotal;
}

int DTConsultaViaje::getCodigo()  const{ return codigo; }
std::string DTConsultaViaje::getMarca()  const{ return marca; }
std::string DTConsultaViaje::getModelo()  const{ return modelo; }
std::string DTConsultaViaje::getConductor()  const{ return conductor; }
float DTConsultaViaje::getCalificacionProm()  const{ return calificacionProm; }
float DTConsultaViaje::getPrecioTotal()  const{ return precioTotal; }

void DTConsultaViaje::setCodigo(int codigo){this->codigo = codigo;}
void DTConsultaViaje::setMarca(std::string marca){this->marca = marca;}
void DTConsultaViaje::setModelo(std::string modelo){this->modelo = modelo;}
void DTConsultaViaje::setConductor(std::string conductor){this->conductor = conductor;}
void DTConsultaViaje::setCalificacionProm(float calificacionProm){this->calificacionProm = calificacionProm;}
void DTConsultaViaje::setPrecioTotal(float precioTotal){this->precioTotal = precioTotal;}


bool DTConsultaViaje::operator<(const DTConsultaViaje& otro) const {
    if (precioTotal != otro.precioTotal)
        return precioTotal < otro.precioTotal;

    if (calificacionProm != otro.calificacionProm)
        return calificacionProm > otro.calificacionProm;

    return codigo < otro.codigo;
}


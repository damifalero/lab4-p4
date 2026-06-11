#include "../include/DTDetalleViaje.h"

DTDetalleViaje::DTDetalleViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, DTDetalleVehiculo vehi, std::vector<DTDetalleReserva> res)
    : vehiculo(vehi)
    {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->reservas = res;
}

int DTDetalleViaje::getCodigo() { return codigo; }
DTFecha DTDetalleViaje::getFecha() { return fecha; }
std::string DTDetalleViaje::getOrigen() { return origen; }
std::string DTDetalleViaje::getDestino() { return destino; }
int DTDetalleViaje::getAsientosPublicados() { return asientosPublicados; }
float DTDetalleViaje::getPrecio() { return precio; }
DTDetalleVehiculo DTDetalleViaje::getVehiculo() { return vehiculo; }
std::vector<DTDetalleReserva> DTDetalleViaje::getReservas() { return reservas; }

void DTDetalleViaje::setCodigo(int codigo){this->codigo = codigo;}
void DTDetalleViaje::setFecha(DTFecha fecha){this->fecha = fecha;}
void DTDetalleViaje::setOrigen(std::string origen){this->origen = origen;}
void DTDetalleViaje::setDestino(std::string destino){this->destino = destino;}
void DTDetalleViaje::setAsientosPublicados(int asientosPublicados){this->asientosPublicados = asientosPublicados;}
void DTDetalleViaje::setPrecio(float precio){this->precio = precio;}
void DTDetalleViaje::setVehiculo(DTDetalleVehiculo vehiculo){this->vehiculo = vehiculo;}
void DTDetalleViaje::setReservas(std::vector<DTDetalleReserva> reservas){this->reservas = reservas;}


bool DTDetalleViaje::operator<(const DTDetalleViaje& otro) const{
    return codigo < otro.codigo;
}
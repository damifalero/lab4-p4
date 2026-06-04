#include "../include/Viaje.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, int asientosDisponibles, float precioPorAsiento, Vehiculo* vehiculo){
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->asientosDisponibles = asientosDisponibles;
    this->precioPorAsiento = precioPorAsiento;
    this->vehiculo= vehiculo;
}

Viaje::~Viaje(){}

int Viaje::getCodigo(){ return codigo; }
DTFecha Viaje::getFecha(){ return fecha; }
std::string Viaje::getOrigen(){ return origen; }
std::string Viaje::getDestino(){ return destino; }
int Viaje::getAsientosPublicados(){ return asientosPublicados; }
int Viaje::getAsientosDisponibles(){ return asientosDisponibles; }
float Viaje::getPrecioPorAsiento(){ return precioPorAsiento; }
Vehiculo* Viaje::getVehiculo(){ return vehiculo; }
std::set<Reserva*> Viaje::getReservas(){ return reservas; }

void Viaje::setCodigo(int codigo){ this->codigo = codigo; }
void Viaje::setFecha(DTFecha fecha){ this->fecha = fecha; }
void Viaje::setOrigen(std::string origen){ this->origen = origen; }
void Viaje::setDestino(std::string destino){ this->destino = destino; }
void Viaje::setAsientosPublicados(int asientosPublicados){ this->asientosPublicados = asientosPublicados; }
void Viaje::setAsientosDisponibles(int asientosDisponibles){ this->asientosDisponibles = asientosDisponibles; }
void Viaje::setPrecioPorAsiento(float precioPorAsiento){ this->precioPorAsiento = precioPorAsiento; }
void Viaje::setVehiculo(Vehiculo* vehiculo){ this->vehiculo = vehiculo; }
void Viaje::setReservas(std::set<Reserva*> reservas){ this->reservas = reservas; }

std::string Viaje::getConductor(){}
bool Viaje::esBuscado(DTFecha fecha, std::string origen, std::string destino, int asientosPublicados){}
int Viaje::cantAsientosValida(int asientosRes, int asientos, int asientosPublicados){}
DTListarViaje Viaje::getDTListarViaje(){}
int Viaje::cantAsientosRes(){}
DTConsultaViaje Viaje::getDataViaje(){}
void Viaje::agregarReserva(Reserva* r){}
int Viaje::obtenerCodigo(){}
int Viaje::getAsientosOfrecidos(){}




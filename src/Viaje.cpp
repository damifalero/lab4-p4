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

//devuelve el conductor asignado al vehiculo del viaje
std::string Viaje::getConductor(){}
//devuelve true si el viaje coincide con los parametros ingresados, pero no estaria faltando tambien un paramentro para conocer el viaje y compararlo?
bool Viaje::esBuscado(DTFecha fecha, std::string origen, std::string destino, int asientosPublicados){}
//no entiendo que hace, preuntar
int Viaje::cantAsientosValida(int asientosRes, int asientos, int asientosPublicados){}
//devuelve un DTListarViaje "dtvi" que contiene el codigo, la fecha, el origen, el desino, y el conductor asociados al vehiculo  del conductor, no le faltan atributos? tipo el usuario y el viaje? hmm
DTListarViaje Viaje::getDTListarViaje(){}
//imagino que devueleve asientos disponibles
int Viaje::cantAsientosRes(){}
//devuelve un DTConsultaViaje con la infomracion que necesita
DTConsultaViaje Viaje::getDataViaje(){}
//agrega la nueva reserva al set de reservas
void Viaje::agregarReserva(Reserva* r){}
//obtiene el codigo de viaje y lo incrementa en 1
int Viaje::obtenerCodigo(){}
//no es lo mismo que getAsientosPublicados(?
int Viaje::getAsientosOfrecidos(){}




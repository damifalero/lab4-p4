#include "../include/Viaje.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    /*agregar atributos que faltan*/
}

Viaje::~Viaje() {}

int Viaje::getCodigo(){ return codigo; }
DTFecha Viaje::getFecha(){ return fecha; }
std::string Viaje::getOrigen(){ return origen; }
std::string Viaje::getDestino(){ return destino; }
int Viaje::getAsientosPublicados(){ return asientosPublicados; }
float Viaje::getPrecio(){ return precio; }
/*faltan gets*/

void Viaje::setCodigo(int codigo){ this->codigo = codigo; }
void Viaje::setFecha(DTFecha fecha){ this->fecha = fecha; }
void Viaje::setOrigen(std::string origen){ this->origen = origen; }
void Viaje::setDestino(std::string destino){ this->destino = destino; }
void Viaje::setAsientosPublicados(int asientosPublicados){ this->asientosPublicados = asientosPublicados; }
void Viaje::setPrecio(int precio){ this->precio = precio; }
/*faltan sets*/

std::string Viaje::getConductor(){

}
bool Viaje::esBuscado(DTFecha fecha, std::string origen, std::string destino, int asientosPublicados){

}
int Viaje::cantAsientosValida(int asientosRes, int asientos, int asientosPublicados){

}
DTListarViaje Viaje::getDTListarViaje(){

}
int Viaje::cantAsientosRes(){

}
DTConsultaViaje Viaje::getDataViaje(){

}
void Viaje::agregarReserva(Reserva r){

}

/*FALTAN FUNCIONES*/

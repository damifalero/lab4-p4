#include "../include/Viaje.h"
#include "../include/Reserva.h"
#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
//agregar los include que correspondan

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

std::string Viaje::getConductor(){
    if (this->vehiculo != NULL){
        Conductor* cond = this->vehiculo->getConductor();
        if (cond != NULL){
            return cond->getNickname();
        }
    }
    return "";
}
bool Viaje::esBuscado(DTFecha fecha, std::string origen, std::string destino, int asientos){
    if (this->origen != origen){
        return false;
    }
    if (this->destino != destino){
        return false;
    }
    if (!(this->fecha == fecha)){
        return false;
    }
    if (this->asientosDisponibles < asientos) {
        return false;
    }
    return true;
}
int Viaje::cantAsientosValida(int asientosRes, int asientos, int asientosPublicados){
    if (asientosRes + asientos <= asientosPublic) {
        return true;
    } else {
        return false;
    }
}
DTListarViaje Viaje::getDTListarViaje(){
    std::string nicknameConductor = this->getConductor();
    DTListarViaje dtvi(this->codigo, this->origen, this->destino, nicknameConductor);
    return dtvi;
}
int Viaje::cantAsientosRes(){
    int totalAsientosReservados = 0;
    for(std::set<Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++){
        Reserva* r = *it;
        totalAsientosReservados += r->getAsientosReservados();
    }
    return totalAsientosReservados;
}
DTConsultaViaje Viaje::getDataViaje(){
    std::string marcaVehiculo = this->vehiculo->getMarca();
    std::string modeloVehiculo = this->vehiculo->getModelo();
    Conductor* cond = this->vehiculo->getConductor();
    std::string nicknameConductor = cond->getNickname();
    float califPromedio = cond->getCalificacionPormedio();
    float precioT =this->getPrecioPorAsiento();
    DTConsultaViaje dtcv(this->codigo, marcaVehiculo, modeloVehiculo, nicknameConductor, califProedio, precioT);
    return dtcv;
}
void Viaje::agregarReserva(Reserva* r){
    this->reservas.insert(r);
}
int Viaje::obtenerCodigo(){
    int nuevoCodigo = this->codigo + 1;
    return nuevoCodigo;
}
//no es lo mismo que getAsientosPublicados(?
int Viaje::getAsientosOfrecidos(){
    return this->asientosPublicados;
}




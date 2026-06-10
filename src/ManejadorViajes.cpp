#include "../include/ManejadorViajes.h"


ManejadorViajes* ManejadorViajes::instancia = NULL;

ManejadorViajes::ManejadorViajes(){}
ManejadorViajes::~ManejadorViajes() {}

ManejadorViajes* ManejadorViajes::getInstancia() {
    if (instancia == NULL) {
        instancia = new ManejadorViajes();
    }
    return instancia;
}
std::map<int, Viaje*> ManejadorViajes::getViajes(){ return this->viajes; }
std::map<int, Reserva*> ManejadorViajes::getReservas(){ return this->reservas; }

void ManejadorViajes::agregarViaje(Viaje* v){ viajes[v->getCodigo()] = v;}

Viaje* ManejadorViajes::obtenerViaje(int codigo){ return this->viajes[codigo]; }

void ManejadorViajes::agregarReserva(Reserva* r){ reservas[r->getViaje()->getCodigo()] = r;}   //que numero identifica la reserva?la cedula del pasajero?

int ManejadorViajes::generarCodigo(){
    return this->viajes[ultimoCodigo]->obtenerCodigo();
}

Viaje ManejadorViajes::crearViaje(Vehiculo v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
    int codigo = this->generarCodigo();
    Viaje* vi = new Viaje(codigo, fecha, origen, destino, asientos, precio);
    v.asociarViaje(vi);
    this->agregarViaje(vi);
    return *vi;
}
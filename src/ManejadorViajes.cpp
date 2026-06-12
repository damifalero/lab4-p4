#include "../include/ManejadorViajes.h"


ManejadorViajes* ManejadorViajes::instancia = NULL;

ManejadorViajes::ManejadorViajes(){
    this->ultimoCodigo= 0;
}
ManejadorViajes::~ManejadorViajes() {}

ManejadorViajes* ManejadorViajes::getInstancia() {
    if (instancia == NULL) {
        instancia = new ManejadorViajes();
    }
    return instancia;
}
const std::map<int, Viaje*>& ManejadorViajes::getViajes() const{ 
    return this->viajes; 
}
const std::map<std::string, Reserva*>& ManejadorViajes::getReservas() const{ 
    return this->reservas; 
}

void ManejadorViajes::agregarViaje(Viaje* v){ 
    viajes[v->getCodigo()] = v;
}

Viaje* ManejadorViajes::obtenerViaje(int codigo){
    if (this->viajes.find(codigo) == this->viajes.end()){
        return NULL;
    } else {
        return this->viajes[codigo]; 
    }
}

void ManejadorViajes::agregarReserva(Reserva* r){ 
    //Se identifica la reserva con una nueva clave generada "codigoViaje-nickname" para evitar que se sobre escriban datos al generar la reserva
    std::string clave = std::to_string(r->getViaje()->getCodigo()) + "-" + r->getPasajero()->getNickname();
    this->reservas[clave] = r;
}   

int ManejadorViajes::generarCodigo(){
    /*if (this->viajes.empty()) return 1;
    else return this->viajes[ultimoCodigo]->obtenerCodigo();*/
    this->ultimoCodigo++;
    return this->ultimoCodigo;
}

Viaje* ManejadorViajes::crearViaje(Vehiculo v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, int asientosDisponibles, float precio) {
    int codigo = this->generarCodigo();
    Viaje* vi = new Viaje(codigo, fecha, origen, destino, asientosPublicados, asientosDisponibles, precio, &v);
    this->agregarViaje(vi);
    return vi;
}
#include "../include/Vehiculo.h"

//constructor y destructor
Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->usuario = nullptr;
}

Vehiculo::~Vehiculo() {}

//getters
std::string Vehiculo::getMatricula() {
    return matricula;
}

int Vehiculo::getCapacidad() {
    return capacidad;
}

std::string Vehiculo::getMarca(){
    return marca;
}

std::string Vehiculo::getModelo(){
    return modelo;
}

TipoVehiculo Vehiculo::getTipo(){
    return tipo;
}

Usuario Vehiculo::getConductor(){
    return *usuario;
}

std::set<DTListarViaje> Vehiculo::getSetDTListarViaje(){
    std::set<DTListarViaje> viajes;
    for (Viaje* viaje : this->viajes) {
        viajes.insert(DTListarViaje(viaje.getCodigo(), viaje.getFecha(), viaje.getOrigen(), viaje.getDestino(), viaje.getConductor()));
    }
    return viajes;
}

DTVehiculosConductor Vehiculo::getDTVehiculosConductor(){
    return DTVehiculosConductor(getMatricula(), getModelo(), getCapacidad());
}

//setters
void Vehiculo::setMatricula(std::string matricula){
    this->matricula = matricula;
}

void Vehiculo::setCapacidad(int capacidad){
    this->capacidad = capacidad;
}

void Vehiculo::setMarca(std::string marca){
    this->marca = marca;
}

void Vehiculo::setModelo(std::string modelo){
    this->modelo = modelo;
}

void Vehiculo::setTipo(TipoVehiculo tipo){
    this->tipo = tipo;
}

void Vehiculo::setUsuario(Usuario* usuario){
    if (usuario != nullptr) {
        usuario->agregarVehiculoUsuario(this);
    }
    this->usuario = usuario;
}

//metodos
bool Vehiculo::hayViajesConductor(){
    return !viajes.empty();
}
void Vehiculo::asociarViaje(Viaje* viaje){
    this->viajes.insert(viaje);
}

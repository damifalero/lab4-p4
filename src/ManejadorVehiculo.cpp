#include "../include/ManejadorVehiculo.h"
#include "../include/Vehiculo.h"

ManejadorVehiculo* ManejadorVehiculo::instancia = NULL;

ManejadorVehiculo::ManejadorVehiculo(){ }  
ManejadorVehiculo::~ManejadorVehiculo(){ }

ManejadorVehiculo* ManejadorVehiculo::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorVehiculo();
    return instancia;
}

std::map<std::string, Vehiculo*> ManejadorVehiculo::getVehiculos(){ return vehiculos; }

void ManejadorVehiculo::agregarVehiculo(Vehiculo* v){
    vehiculos[v->getMatricula()] = v;
}

bool ManejadorVehiculo::existeVehiculo(std::string matricula){
    return vehiculos.find(matricula) != vehiculos.end();
}

Vehiculo* ManejadorVehiculo::obtenerVehiculo(std::string matricula){
    std::map<std::string, Vehiculo*>::iterador it = vehiculos.find(matricula);

    if (it != vehiculos.end())
        return it->second;

    return NULL;
}


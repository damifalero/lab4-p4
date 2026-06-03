#include "../include/ManejadorVehiculo.h"
#include "../include/Vehiculo.h"

ManejadorVehiculo* ManejadorVehiculo::instancia = NULL;

ManejadorVehiculo::ManejadorVehiculo(){ }  

ManejadorVehiculo* ManejadorVehiculo::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorVehiculo();
    return instancia;
}

void ManejadorVehiculo::agregarVehiculo(Vehiculo* v){
    vehiculos[v->getMatricula()] = v;
}

bool ManejadorVehiculo::existeVehiculo(std::strign matricula){
    return vehiculos.find(matricula) != vehiculos.end();
}

Vehiculo* ManejadorVehiculo::obtenerVehiculo(std::string matriucla){
    std::map<std::string, Vehiculo*>::iterador it = vehiculos.find(matricula);

    if (it != veiculos.end())
        return it->second;

    return NULL;
}


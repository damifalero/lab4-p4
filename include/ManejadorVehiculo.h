#ifndef MANEJADORVEHICULO_H
#define MANEJADORVEHICULO_H

#include "Vehiculo.h"
#include <string>

class ManejadorVehiculo {
    private:
        ManejadorVehiculo instancia;
        Map<std::string, Vehiculo> vehiculos;
    
    public: 
        ManejadorVehiculo();
        
        ManejadorVehiculo getInstancia();

        void agregarVehiculo(Vehiculo v);
        bool existeVehiculo(std::string matricula);
        Vehiculo obtenerVehiculo(std::string matricula);
}

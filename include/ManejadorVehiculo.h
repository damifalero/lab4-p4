#ifndef MANEJADORVEHICULO_H
#define MANEJADORVEHICULO_H

#include <string>
#include <map>

class Vehiculo;

class ManejadorVehiculo {
    private:
        static ManejadorVehiculo* instancia;
        std::map<std::string, Vehiculo*> vehiculos;

        ManejadorVehiculo();
    
    public: 
        
        ManejadorVehiculo* getInstancia();

        void agregarVehiculo(Vehiculo* v);
        bool existeVehiculo(std::string matricula);
        Vehiculo* obtenerVehiculo(std::string matricula);
}

#endif

#ifndef MANEJADORVEHICULO_H
#define MANEJADORVEHICULO_H

#include "Vehiculo.h"
#include <string>
#include <map>


class ManejadorVehiculo {
    private:
        static ManejadorVehiculo* instancia;
        std::map<std::string, Vehiculo*> vehiculos;

        //El constructor debe de ser privado para el Singleton
        ManejadorVehiculo();

    public:

        //Destructor
        ~ManejadorVehiculo();

        //Getters
        static ManejadorVehiculo* getInstancia();
        std::map<std::string, Vehiculo*> getVehiculos();

        //Operaciones del Manejador
        void agregarVehiculo(Vehiculo* v);
        bool existeVehiculo(std::string matricula);
        Vehiculo* obtenerVehiculo(std::string matricula);
};

#endif

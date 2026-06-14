#ifndef DT_DETALLE_VEHICULO_H
#define DT_DETALLE_VEHICULO_H

#include "TipoVehiculo.h"
#include <string>

class DTDetalleVehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;

public:

    //Constructor
    DTDetalleVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    
    //Getters
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
};

#endif

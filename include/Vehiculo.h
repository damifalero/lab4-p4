#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
#include <set>
#include "DTVehiculosConductor.h"
#include "TipoVehiculo.h"
#include "DTListarViaje.h"
#include "Conductor.h"
#include "Viaje.h"

class Viaje;
class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    Conductor* usuario;
    std::set<Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
    //getters
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    Conductor* getConductor();
    std::set<DTListarViaje> getSetDTListarViaje();
    DTVehiculosConductor getDTVehiculosConductor();
    //setters
    void setMatricula(std::string matricula);
    void setCapacidad(int capacidad);
    void setMarca(std::string marca);
    void setModelo(std::string modelo);
    void setTipo(TipoVehiculo tipo);
    void setUsuario(Usuario* usuario);

    //metodos
    bool hayViajesConductor();
    void asociarViaje(Viaje* viaje);
};

#endif

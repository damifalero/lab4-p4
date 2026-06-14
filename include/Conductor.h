#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "DTUsuario.h"
#include "TipoLibreta.h"
#include "Usuario.h"
#include "Vehiculo.h"
#include <set>

//Dependencia circular 
class Vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::set<Vehiculo*> vehiculos;
public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();

    //Getters
    std::set<TipoLibreta> getLibretas();
    std::set<Vehiculo*> getVehiculos();

    //Setters
    void setLibretas(std::set<TipoLibreta> libretas);
    void setVehiculos(std::set<Vehiculo*> vehiculos);

    //Metodos usuario
    bool esPasajero();

    //Metodos conductor
    void agregarVehiculoUsuario(Vehiculo* vehiculo);
    bool tieneLibreta(TipoLibreta libreta);
    std::set<DTVehiculosConductor> listarVehiculos();
    bool hayViajesFechaConductor(DTFecha fecha);
};

#endif

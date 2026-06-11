#include "../include/Conductor.h"
#include "../include/Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {}

//getters
std::set<TipoLibreta> Conductor::getLibretas(){
    return libretas;
}

std::set<Vehiculo*> Conductor::getVehiculos(){
    return vehiculos;
}

//setters
void Conductor::setVehiculos(std::set<Vehiculo*> vehiculos){
    this->vehiculos = vehiculos;
}

void Conductor::setLibretas(std::set<TipoLibreta> libretas){
    this->libretas = libretas;
}

//metodos usuario
bool Conductor::esPasajero() {
    return false;
}

//metodos conductor
void Conductor::agregarVehiculoUsuario(Vehiculo* vehiculo) {
    vehiculos.insert(vehiculo);
    vehiculo->setUsuario(this);
}

bool Conductor::tieneLibreta(TipoLibreta libreta) {
    return libretas.find(libreta) != libretas.end();
}

std::set<DTVehiculosConductor> Conductor::listarVehiculos() {
    std::set<DTVehiculosConductor> vehiculosConductor;
    for (Vehiculo* vehiculo : vehiculos) {
        DTVehiculosConductor dtVehiculo(vehiculo->getMatricula(), vehiculo->getModelo(), vehiculo->getCapacidad());
        vehiculosConductor.insert(dtVehiculo);
    }
    return vehiculosConductor;
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha){
    for(Vehiculo* vehiculo : vehiculos){
        std::set<DTListarViaje> viajes = vehiculo->getSetDTListarViaje();
        for(DTListarViaje viaje : viajes){
            if(viaje.getFecha() == fecha)
                return true;
        }
    }
    return false;
}

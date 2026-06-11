#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string marca, int capacidad) {
    this->matricula = matricula;
    this->marca = marca;
    this->capacidad = capacidad;
}

void DTVehiculosConductor::setMatricula(std::string matricula) { this->matricula = matricula; }
void DTVehiculosConductor::setMarca(std::string marca) { this->marca = marca; }
void DTVehiculosConductor::setCapacidad(int capacidad) { this->capacidad = capacidad; }

std::string DTVehiculosConductor::getMatricula(){ return this->matricula; }
std::string DTVehiculosConductor::getMarca(){ return this->marca; }
int DTVehiculosConductor::getCapacidad(){ return this->capacidad; }

bool DTVehiculosConductor::operator<(const DTVehiculosConductor& otro) const {
   return matricula < otro.matricula;
}

// pa que funcaaa
/*std::set<DTDetalleVehiculo> DTVehiculosConductor::getVehiculos() {
    return vehiculos;
}*/



#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string modelo, int capacidad) {
    this->matricula = matricula;
    this->modelo = modelo;
    this->capacidad = capacidad;
}

void DTVehiculosConductor::setMatricula(std::string matricula) { this->matricula = matricula; }
void DTVehiculosConductor::setModelo(std::string modelo) { this->modelo = modelo; }
void DTVehiculosConductor::setCapacidad(int capacidad) { this->capacidad = capacidad; }

std::string DTVehiculosConductor::getMatricula(){ return this->matricula; }
std::string DTVehiculosConductor::getModelo(){ return this->modelo; }
int DTVehiculosConductor::getCapacidad(){ return this->capacidad; }

bool DTVehiculosConductor::operator<(const DTVehiculosConductor& otro) const {
   return matricula < otro.matricula;
}




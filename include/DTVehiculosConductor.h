#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>
//#include "DTDetalleVehiculo.h"
//#include <set>

class DTVehiculosConductor {
private:
  std::string matricula;
  std::string marca;
  int capacidad;

public:
  DTVehiculosConductor(std::string matricula, std::string marca, int capacidad);

  void setMatricula(std::string matricula);
  void setMarca(std::string marca);
  void setCapacidad(int capacidad);
  
  std::string getMatricula();
  std::string getMarca();
  int getCapacidad();

  //pa que funcionaaaa
  /*std::set<DTDetalleVehiculo> getVehiculos();*/

  bool operator<(const DTVehiculosConductor& other) const;
};

#endif

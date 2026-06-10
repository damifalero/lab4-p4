#ifndef DT_CONSULTA_VIAJE_H
#define DT_CONSULTA_VIAJE_H

#include "DTFecha.h"
#include <string>

class DTConsultaViaje {
private:
  int codigo;
  std::string marca;
  std::string modelo;
  std::string conductor;
  float calificacionProm;
  float precioTotal;

public:
  DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal);

  int getCodigo();
  std::string getMarca();
  std::string getModelo();
  std::string getConductor();
  float getCalificacionProm();
  float getPrecioTotal();

<<<<<<< HEAD
  void setCodigo(int codigo);
  void setMarca(std::string marca);
  void setModelo(std::string modelo);
  void setConductor(std::string conductor);
  void setCalificacionProm(float calificacionProm);
  void setPrecioTotal(float precioTotal);

=======
  //para comparar en el set, ordenando por precio total, luego por calificacion promedio y finalmente por codigo
  bool operator<(const DTConsultaViaje& otro) const;
>>>>>>> 30cc190797d3cd0c6e0bfac1402ba36d0a369787
};

#endif

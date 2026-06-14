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

    //Constructor
    DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal);

    //Getters
    int getCodigo() const;
    std::string getMarca() const;
    std::string getModelo() const;
    std::string getConductor() const;
    float getCalificacionProm() const;
    float getPrecioTotal() const;

    //Setters
    void setCodigo(int codigo);
    void setMarca(std::string marca);
    void setModelo(std::string modelo);
    void setConductor(std::string conductor);
    void setCalificacionProm(float calificacionProm);
    void setPrecioTotal(float precioTotal);

    //Para el orden de insercción en el set; ordenando por precio total, luego por calificacion promedio y finalmente por codigo.
    bool operator<(const DTConsultaViaje& otro) const;
};

#endif

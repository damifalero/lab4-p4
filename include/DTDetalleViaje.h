#ifndef DT_DETALLE_VIAJE_H
#define DT_DETALLE_VIAJE_H

#include "DTFecha.h"
#include "DTDetalleVehiculo.h"
#include "DTDetalleReserva.h"
#include <string>
#include <vector>

class DTDetalleViaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    DTDetalleVehiculo vehiculo;
    std::vector<DTDetalleReserva> reservas;

public:
    //Constructor
    DTDetalleViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, DTDetalleVehiculo vehi, std::vector<DTDetalleReserva> res);

    //Getters
    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    DTDetalleVehiculo getVehiculo();
    std::vector<DTDetalleReserva> getReservas();

    //Setters
    void setCodigo(int codigo);
    void setFecha(DTFecha fecha);
    void setOrigen(std::string origen);
    void setDestino(std::string destino);
    void setAsientosPublicados(int asientosPublicados);
    void setPrecio(float precio);
    void setVehiculo(DTDetalleVehiculo vehiculo);
    void setReservas(std::vector<DTDetalleReserva> reservas);

    //Para el orden de insercción en el set, segun el código.
    bool operator<(const DTDetalleViaje& otro) const;
};



#endif 

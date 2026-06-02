#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTConsultaViaje.h"
#include "Reserva.h"
#include <string>

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    /*faltan*/
    Vehiculo vehiculo;
    Set<Reserva> reseva;
    int asientosDisponibles;

public:
    /*agregar atributos*/
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();

    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    /*hmm*/
    Vehiculo getVehiculo();
    Set<Reserva> getReservas();
    int getAsientosDisponibles();

    void setCodigo(int codigo);
    void setFecha(DTFecha fecha);
    void setOrigen(std::string origen);
    void setDestino(std::string destino);
    void setAsientosPublicados(int asientosPublicados);
    void setPrecio(int precio);
    /*hmm*/
    void setVehiculo(Vehiculo vehiculo);
    void setReservas(Set<Reserva> reseva);
    void setAsientosDisponibles(int asientosDisponibles);

    std::string getConductor();
    bool esBuscado(DTFecha fecha, std::string origen, std::string destino, int asientosPublicados);
    int cantAsientosValida(int asientosRes, int asientos, int asientosPublicados);
    DTListarViaje getDTListarViaje();
    int cantAsientosRes();
    DTConsultaViaje getDataViaje();
    void agregarReserva(Reserva r);
    /*estas son las funciones que faltarian en el diagrama*/
    int obtenerCodigo();
    //int getAsientosOfrecidos();
    //Reserva getReserva();
    //Vehiculo getVehiculo;
    //Viaje next();
    //add();
};

#endif

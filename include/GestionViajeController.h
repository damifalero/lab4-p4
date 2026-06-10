#ifndef GESTION_VIAJE_CONTROLLER_H
#define GESTION_VIAJE_CONTROLLER_H

#include <set>
#include <string>
#include "IGestionViajeController.h"

class GestionViajeController : public IGestionViajeController {
private:
    static GestionViajeController* instancia;

    int ultimoViaje;
    int codigoRecordado;
    std::string nicknameRecordado;

    GestionViajeController();

public:
    static GestionViajeController* getInstance();

    virtual ~GestionViajeController();

    std::set<std::string> listarPasajeros();

    std::set<DTConsultaViaje> consultarViaje(DTFecha fecha, std::string origen, std::string destino, int asientos);

    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);

    DTDetalleViaje detalleViaje(int codigo);

    std::set<DTUsuarioViaje> listarUsuariosViaje(int codigo);

    std::set<DTListarViaje> listarViajes(std::string nick);

    std::set<DTListarViaje> listarViajes();

    void eliminarViaje();

    void cancelarEliminarViaje();

    bool generarReserva(std::string nickname, int codigo, int asientos);
};

#endif
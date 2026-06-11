#include "../include/UsuarioController.h"
#include "../include/ManejadorUsuarios.h"
#include "../include/ManejadorViajes.h"
#include "../include/ManejadorVehiculo.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"

UsuarioController* UsuarioController::getInstancia(){
    if (instancia == NULL)
        instancia = new UsuarioController();

    return instancia;
}

std::string UsuarioController::getNicknameRecordado(){return this->nicknameRecordado;}
int UsuarioController::getCodigoRecordado(){return this->codigoRecordado;}

void UsuarioController::setNicknameRecordad(std::string nickname){this->nicknameRecordado = nickname;}
void UsuarioController::setCodigoRecordado(int codigo){this->codigoRecordado = codigo;}

bool UsuarioController::altaPasajero(std::string nickname,std::string nombre,std::string contrasena,std::string email,std::string ci){
    ManejadorUsuarios* manejador = ManejadorUsuarios::getInstancia();
    bool existeUsuario = manejador->existeUsuario(nickname);

    if (existeUsuario) return false;
    else{
        Pasajero p(nickname,nombre,contrasena,email,ci);
        manejador->agregarUsuario(&p);
        return true;
    }
}

bool UsuarioController::altaConductor(std::string nickname,std::string nombre,std::string contrasena,std::string email,std::set<TipoLibreta> libretas){
        ManejadorUsuarios* manejador = ManejadorUsuarios::getInstancia();
    bool existeUsuario = manejador->existeUsuario(nickname);

    if (existeUsuario) return false;
    else{
        Conductor c(nickname,nombre,contrasena,email,libretas);
        manejador->agregarUsuario(&c);
        return true;
    }
}

std::set<DTUsuario> UsuarioController::listarUsuarios(){
    ManejadorUsuarios* ManejadorUsuarios = ManejadorUsuarios::getInstancia();
    std::map<std::string, Usuario*> colUsuarios = ManejadorUsuarios->getUsuarios();
    std::set<DTUsuario> colDTUsuario;
    for (std::map<std::string, Usuario*>::iterator i = colUsuarios.begin(); i != colUsuarios.end(); ++i) {
        colDTUsuario.insert(i->second->getDTUsuario());
    }
    return colDTUsuario;
}

bool UsuarioController::calificarUsuario(std::string nicknameCalificado,int calificacion){
    ManejadorUsuarios* ManejadorUsuarios = ManejadorUsuarios::getInstancia();
    Usuario* uCalificado = ManejadorUsuarios->obtenerUsuario(nicknameCalificado);
    Usuario* uCalificador = ManejadorUsuarios->obtenerUsuario(this->nicknameRecordado);

    ManejadorViajes* ManejadorViajes = ManejadorViajes::getInstancia(); //en el diagrama de interaccion se comunica con manejadorviajes pero no sé si está bien
    Viaje* viaje = ManejadorViajes->obtenerViaje(this->codigoRecordado);
    std::set<Reserva*> reservas = viaje->getReservas();

    bool existe = false;

    for (std::set<Reserva*>::iterator i = reservas.begin(); i != reservas.end(); ++i) {
        std::set<Calificacion*> calificaciones = (*i)->getCalificaciones();
        for (std::set<Calificacion*>::iterator j = calificaciones.begin(); j != calificaciones.end(); ++j)
            if (!existe && (*j)->getUCalificado() == uCalificado && (*j)->getUCalificador() == uCalificador) existe = true;
    }

    if (!existe){
        Calificacion c(viaje->getFecha(),calificacion,);

        if((*uCalificador).esPasajero()){
            bool encontrado = false;
            for (std::set<Reserva*>::iterator i = reservas.begin(); i != reservas.end() && !encontrado; ++i) {
                if ((*i)->getPasajero() == uCalificador){
                    encontrado = true;
                    (*i)->agregarCalificacion(c);
                }
            }
        }else{
            bool encontrado = false;
            for (std::set<Reserva*>::iterator i = reservas.begin(); i != reservas.end() && !encontrado; ++i) {
                if ((*i)->getPasajero() == uCalificado){
                    encontrado = true;
                    (*i)->agregarCalificacion(c);
                }
            }
        }

        //cómo debería borrar el código y el nickname recordado siendo que no son punteros? o los hago punteros?
    }

    return !existe;
}

int UsuarioController::registrarVehiculo(std::string nickname,std::string matricula,int capacidad,std::string marca,std::string modelo,TipoVehiculo tipo){
    ManejadorUsuarios* ManejadorUsuarios = ManejadorUsuarios::getInstancia();
    ManejadorVehiculo* ManejadorVehiculo = ManejadorVehiculo::getInstancia(); //en el diagrama de interaccion se comunica con manejadorviajes pero no sé si está bien

    bool existeV = ManejadorVehiculo->existeVehiculo(matricula);
    if (existeV) return -1;
    else{
        Conductor* c = dynamic_cast<Conductor*>(ManejadorUsuarios->obtenerUsuario(nickname));

        TipoLibreta libretaAm;
        TipoLibreta libretaProf;
        if (tipo == Auto){
            libretaAm = AutoAmateur;
            libretaProf = AutoProfesional;
        } else if (tipo == Moto){
            libretaAm = MotoAmateur;
            libretaProf = MotoProfesional;
        }
        bool tieneL = (c->tieneLibreta(libretaAm) || c->tieneLibreta(libretaProf));
        if (tieneL){
            Vehiculo ve(matricula,capacidad,marca,modelo,tipo);
            ManejadorVehiculo->agregarVehiculo(&ve);
            c->agregarVehiculoUsuario(&ve);
            return 0;
        } else return -2;
    }
}

std::set<DTVehiculosConductor> UsuarioController::listarVehiculosConductor(std::string nickname){
        ManejadorUsuarios* ManejadorUsuarios = ManejadorUsuarios::getInstancia();
        Conductor* c = dynamic_cast<Conductor*>(ManejadorUsuarios->obtenerUsuario(nickname));
        std::set<DTVehiculosConductor> listaVehiculos = c->listarVehiculos();
        return listaVehiculos;
}

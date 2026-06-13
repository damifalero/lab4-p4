#include "../include/UsuarioController.h"
#include "../include/ManejadorUsuarios.h"
#include "../include/ManejadorViajes.h"
#include "../include/ManejadorVehiculo.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"

UsuarioController* UsuarioController::instancia = NULL;

UsuarioController::UsuarioController(){ }
UsuarioController::~UsuarioController(){ }

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

    if (manejador->existeUsuario(nickname))
        return false;

    Pasajero* p = new Pasajero(nickname, nombre, contrasena, email, ci);

    manejador->agregarUsuario(p);
    return true;
}

bool UsuarioController::altaConductor(std::string nickname,std::string nombre,std::string contrasena,std::string email,std::set<TipoLibreta> libretas){
    ManejadorUsuarios* manejador = ManejadorUsuarios::getInstancia();

    if (manejador->existeUsuario(nickname))
        return false;

    Conductor* c = new Conductor(nickname, nombre, contrasena, email, libretas);

    manejador->agregarUsuario(c);
    return true;
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

    std::cout << "Nickname calificado: " << nicknameCalificado << "\n";
    std::cout << "Nickname calificador: " << this->nicknameRecordado << "\n";
    
    ManejadorViajes* ManejadorViajes = ManejadorViajes::getInstancia();
    Viaje* viaje = ManejadorViajes->obtenerViaje(this->codigoRecordado);

    //Controlador para verificar que el viaje o los usuarios no existan
    if (viaje == NULL || uCalificado == NULL || uCalificador == NULL){
        this->codigoRecordado = -1;
        this->nicknameRecordado = "";
        std::cout << "Viaje o usuarios no encontrados.\n";
        return false;
    }
    std::set<Reserva*> reservas = viaje->getReservas();

    bool existe = false;

    for (std::set<Reserva*>::iterator i = reservas.begin(); i != reservas.end(); ++i) {
        std::set<Calificacion*> calificaciones = (*i)->getCalificaciones();
        for (std::set<Calificacion*>::iterator j = calificaciones.begin(); j != calificaciones.end(); ++j)
            if (!existe && (*j)->getUCalificado() == uCalificado && (*j)->getUCalificador() == uCalificador){
                existe = true;
            } 
    }

    if (!existe){
        std::cout << "Creando calificacion...\n";
        if(uCalificador->esPasajero()){
            bool encontrado = false;
            for (std::set<Reserva*>::iterator i = reservas.begin(); i != reservas.end() && !encontrado; ++i) {
                if ((*i)->getPasajero() == uCalificador){
                    encontrado = true;
                    Reserva* res = *i; 
                    Calificacion* c= new Calificacion(viaje->getFecha(), calificacion, res, uCalificado, uCalificador);
                    res->asociarCalificacion(c);
                    uCalificado->asociarCalificacion(c);
                    uCalificador->asociarCalificacion(c);
                }
            }
        }else{
            bool encontrado = false;
            for (std::set<Reserva*>::iterator i = reservas.begin(); i != reservas.end() && !encontrado; ++i) {
                if ((*i)->getPasajero() == uCalificado){
                    encontrado = true;
                    Reserva* res = *i; 
                    Calificacion* c = new Calificacion(viaje->getFecha(),calificacion,res,uCalificado,uCalificador);
                    res->asociarCalificacion(c);
                    uCalificado->asociarCalificacion(c);
                    uCalificador->asociarCalificacion(c);
                }
                }
            }
        }
        this->codigoRecordado = -1;
        this->nicknameRecordado = "";
        return !existe;
}

int UsuarioController::registrarVehiculo(std::string nickname,std::string matricula,int capacidad,std::string marca,std::string modelo,TipoVehiculo tipo){
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();
    ManejadorVehiculo* mv = ManejadorVehiculo::getInstancia(); 
    
    bool existeV = mv->existeVehiculo(matricula);
    if (existeV) return -1;
    else{
        Conductor* c = dynamic_cast<Conductor*>(mu->obtenerUsuario(nickname));

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
            Vehiculo* ve = new Vehiculo(matricula,capacidad,marca,modelo,tipo);
            mv->agregarVehiculo(ve);
            ve->setUsuario(c);
            c->agregarVehiculoUsuario(ve);
            return 0;
        } else return -2;
    }
}

std::set<DTVehiculosConductor> UsuarioController::listarVehiculosConductor(std::string nickname){
        ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();
        Conductor* c = dynamic_cast<Conductor*>(mu->obtenerUsuario(nickname));
        std::set<DTVehiculosConductor> listaVehiculos = c->listarVehiculos();
        return listaVehiculos;
}

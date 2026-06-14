#ifndef DT_USUARIO_VIAJE_H
#define DT_USUARIO_VIAJE_H

#include "TipoUsuario.h"
#include <string>

class DTUsuarioViaje {
private:
    std::string nickname;
    TipoUsuario tipo;

public:
    DTUsuarioViaje(std::string nickname, TipoUsuario tipo);

    std::string getNickname() const;
    TipoUsuario getTipo() const;

    //Criterio de ordenacion para poder insertar en un set
    bool operator<(const DTUsuarioViaje& otro) const;
};

#endif

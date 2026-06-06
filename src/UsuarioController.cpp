#include "../include/UsuarioController.h"

std::string UsuarioController::getNicknameRecordado(){return this->nicknameRecordado;}
int UsuarioController::getCodigoRecordado(){return this->codigoRecordado;}

void UsuarioController::setNicknameRecordad(std::string nickname){this->nicknameRecordado = nickname;}
void UsuarioController::setCodigoRecordado(int codigo){this->codigoRecordado = codigo;}

bool altaPasajero(std::string nickname,std::string nombre,std::string contrasena,std::string email,std::string ci){
}
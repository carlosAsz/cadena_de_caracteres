#include "datoscliente.h"
DatosCliente::DatosCliente(const string &Tdatos){
    ProcesarTexto(Tdatos);
}
string DatosCliente::getCedula() const
{
    return cedula;
}

void DatosCliente::setCedula(const string &newCedula)
{
    cedula = newCedula;
}

string DatosCliente::getNombre() const
{
    return nombre;
}

void DatosCliente::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

string DatosCliente::getApellido() const
{
    return apellido;
}

void DatosCliente::setApellido(const string &newApellido)
{
    apellido = newApellido;
}

string DatosCliente::getDireccion() const
{
    return direccion;
}

void DatosCliente::setDireccion(const string &newDireccion)
{
    direccion = newDireccion;
}

string DatosCliente::getTelefono() const
{
    return telefono;
}

void DatosCliente::setTelefono(const string &newTelefono)
{
    telefono = newTelefono;
}

string DatosCliente::getEmail() const
{
    return email;
}

void DatosCliente::setEmail(const string &newEmail)
{
    email = newEmail;
}
void DatosCliente::ProcesarTexto(const string &Tdatos){
    QStringList Lineas= QString::fromStdString(Tdatos).split("\n");
    for(const QString &linea:Lineas){
        QRegExp regExp("[:][ ]?");
        QStringList campos =linea.split(regExp);

        if(campos.size()==2){
            string label = campos [0].trimmed().toStdString();
            string value = campos [1].trimmed().toStdString();
            if(label =="Nombre"||label=="nombre" || label=="nombres"||label=="Nombres"){
                QStringList nombreCompleto = campos[1].split(QRegExp("[ ]+"), Qt::SkipEmptyParts);
                if (nombreCompleto.size() >= 2) {
                    setNombre(nombreCompleto[0].trimmed().toStdString());
                    setApellido(nombreCompleto[nombreCompleto.size() - 1].trimmed().toStdString());
                }
            }else if (label == "Cedula" || label=="cedula"){
                setCedula(value);
            }else if (label=="Direccion"||label=="direccion"){
                setDireccion(value);
            }else if (label=="Telefono"||label=="telefono"){
                setTelefono(value);
            }else if(label=="Correo"||label=="Correo electronico"||label=="correo" ||label=="correo electronico"||label=="email"||
                       label=="Email"){
                setEmail(value);
            }
        }
    }
}


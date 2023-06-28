#ifndef DATOSCLIENTE_H
#define DATOSCLIENTE_H
#include<string>
#include<QStringList>
using namespace std;
class DatosCliente
{
private:
    string cedula;
    string nombre;
    string apellido;
    string direccion;
    string telefono;
    string email;
public:
    DatosCliente();
    DatosCliente(const string &Tdatos);
    void ProcesarTexto(const string &Tdatos);
    string getCedula() const;
    void setCedula(const string &newCedula);
    string getNombre() const;
    void setNombre(const string &newNombre);
    string getApellido() const;
    void setApellido(const string &newApellido);
    string getDireccion() const;
    void setDireccion(const string &newDireccion);
    string getTelefono() const;
    void setTelefono(const string &newTelefono);
    string getEmail() const;
    void setEmail(const string &newEmail);
};

#endif // DATOSCLIENTE_H


#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nombre;
    std::string id;
    int maxLibros;

public:
    Usuario(std::string nom, std::string identificacion);
    virtual void mostrarInfo() const;
    int getMaxLibros() const;
};

class Estudiante : public Usuario {
public:
    Estudiante(std::string nom, std::string id);
};

class Professor : public Usuario {
public:
    Professor(std::string nom, std::string id);
};

#endif

#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string ISBN;
    bool disponible;

public:
    Libro(std::string tit, std::string aut, std::string isbn);
    void mostrarInfo() const;
    bool estaDisponible() const;
    void prestar();
    void devolver();
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getISBN() const;
};

#endif

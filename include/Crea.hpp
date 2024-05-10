#pragma once
#include <Archivo.hpp>

class Crea

{
public:
    Crea() {}
    void crea(Archivo &archivo, std::list<Dibujo> &dibujos, size_t num_instances)
    {
        for (size_t i = 0; i < num_instances; i++)
        {
            Dibujo d = archivo.CrearDibujo();
            dibujos.push_back(d);
        }
    }
    ~Crea() {}
};
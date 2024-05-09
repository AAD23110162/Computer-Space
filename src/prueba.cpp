#include <iostream>
#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <Archivo.hpp>
#include <thread>
#include <list>
#include <vector> // Incluir la librería de vectores
#include <experimental/random>

using namespace ftxui;
using namespace std;

int main(int argc, char const *argv[])
{
    Archivo titulo("./assets/images/titulo.txt");
    Archivo version("./assets/images/version.txt");
    Archivo nombre("./assets/images/nombre.txt");
    Archivo ovni("./assets/images/ovni.txt");
    Archivo nave("./assets/images/nave.txt");

    list<Dibujo> dibujos;

    // Vector para almacenar las posiciones iniciales de cada dibujo
    vector<pair<int, int>> posicionesIniciales;

    // Crear naves con posiciones iniciales específicas
    posicionesIniciales.push_back({-100, 1}); // Posición inicial del titulo
    posicionesIniciales.push_back({100, 10}); // Posición inicial del la version
    posicionesIniciales.push_back({-80, 20}); // Posición inicial del nombre
    posicionesIniciales.push_back({-80, 17}); // Posición inicial de nave 1
    posicionesIniciales.push_back({-70, 17}); // Posición inicial de nave 2
    posicionesIniciales.push_back({-60, 17}); // Posición inicial de nave 3
    posicionesIniciales.push_back({-50, 17}); // Posición inicial de ovni 1
    posicionesIniciales.push_back({-40, 17}); // Posición inicial de ovni 2
    posicionesIniciales.push_back({-30, 17}); // Posición inicial de onvi 3

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = titulo.CrearDibujo();
        dibujos.push_back(d);
    }

    // Crear alienígenas con posiciones iniciales específicas
    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = version.CrearDibujo();
        dibujos.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = nombre.CrearDibujo();
        dibujos.push_back(d);
    }

    for (size_t i = 0; i < 3; i++)
    {
        Dibujo d = nave.CrearDibujo();
        dibujos.push_back(d);
    }

    for (size_t i = 0; i < 3; i++)
    {
        Dibujo d = ovni.CrearDibujo();
        dibujos.push_back(d);
    }

    auto Pantalla = Screen::Create(
        Dimension::Full(), 
        Dimension::Full()
    );

    // Parámetros de desplazamiento independientes para cada dibujo
    vector<pair<int, int>> desplazamientos(dibujos.size(), {0, 0});

    // Desplazamiento específico para la nave uno (índice 0) y la nave dos (índice 1)
    desplazamientos[0] = {1, 0}; // La nave uno se mueve 2 posiciones hacia la derecha
    desplazamientos[1] = {-1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[2] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[3] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[4] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[5] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[6] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[7] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[8] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    // Establecer las posiciones iniciales de cada dibujo
    size_t index = 0;
    for (auto &&dibujo : dibujos)
    {
        dibujo.EstablecerPosicion(posicionesIniciales[index].first, posicionesIniciales[index].second);
        index++;
    }

    while(true){
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        // Actualizar
        size_t index = 0;
        for (auto &&dibujo : dibujos)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos[index].first);
            dibujo.DesplazarY(desplazamientos[index].second);
            index++;
        }

        // Dibujar
        for (auto &&dibujo : dibujos)
        {
            dibujo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout << Pantalla.ResetPosition();          
    }

    return 0;
}
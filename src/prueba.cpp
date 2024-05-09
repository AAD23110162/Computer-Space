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
    Archivo presentacion("./assets/images/presentacion.txt");
    Archivo margen1("./assets/images/margen1.txt");
    Archivo margen2("./assets/images/margen2.txt");
    list<Dibujo> dibujos;

    // Vector para almacenar las posiciones iniciales de cada dibujo
    vector<pair<int, int>> posicionesIniciales;

    // Crear naves con posiciones iniciales específicas
    posicionesIniciales.push_back({-148, 1}); // Posición inicial del titulo
    posicionesIniciales.push_back({-114, 23}); // Posición inicial del la version
    posicionesIniciales.push_back({190, 29}); // Posición inicial del nombre
    posicionesIniciales.push_back({205, 10}); // Posición inicial de nave 1

    posicionesIniciales.push_back({0, 0}); // Posición inicial del margen1
    posicionesIniciales.push_back({0, 0}); // Posición inicial del margen2
    posicionesIniciales.push_back({175, 0}); // Posición inicial del margen2.1

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

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = presentacion.CrearDibujo();
        dibujos.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = margen1.CrearDibujo();
        dibujos.push_back(d);
    }

    for (size_t i = 0; i < 2; i++)
    {
        Dibujo d = margen2.CrearDibujo();
        dibujos.push_back(d);
    }

    auto Pantalla = Screen::Create(
    Dimension::Fixed(176),  // Ancho fijo de 200 píxeles
    Dimension::Full()   // Alto fijo de 100 píxeles
    );

    // Parámetros de desplazamiento independientes para cada dibujo
    vector<pair<int, int>> desplazamientos(dibujos.size(), {0, 0});

    // Desplazamiento específico para la nave uno (índice 0) y la nave dos (índice 1)
    desplazamientos[0] = {1, 0}; // La nave uno se mueve 2 posiciones hacia la derecha
    desplazamientos[1] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[2] = {-1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[3] = {-1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    
    desplazamientos[4] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[5] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[6] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    // Establecer las posiciones iniciales de cada dibujo
    size_t index = 0;
    for (auto &&dibujo : dibujos)
    {
        dibujo.EstablecerPosicion(posicionesIniciales[index].first, posicionesIniciales[index].second);
        index++;
    }

    //while(true)
    for (size_t i = 0; i < 158; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.05s);

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
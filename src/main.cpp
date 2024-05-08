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
    Archivo nave("./assets/images/nave.txt");
    Archivo ovni("./assets/images/ovni.txt"); // Cambiar el archivo a "alien.txt"

    list<Dibujo> dibujos;
    // Crear naves
    for (size_t i = 0; i < 3; i++)
    {
        Dibujo d = nave.CrearDibujo(); // Crear un dibujo basado en el contenido de "nave.txt"
        d.EstablecerPosicion(i*10, 1);
        dibujos.push_back(d);
    }

    // Crear alienígenas
    for (size_t i = 0; i < 3; i++)
    {
        Dibujo d = ovni.CrearDibujo(); // Crear un dibujo basado en el contenido de "alien.txt"
        d.EstablecerPosicion(i*10, 6);
        dibujos.push_back(d);
    }

    auto Pantalla = Screen::Create(
        Dimension::Full(), 
        Dimension::Full()
    );

    // Parámetros de desplazamiento independientes para cada dibujo
    vector<pair<int, int>> desplazamientos(dibujos.size(), {0, 0});

    // Desplazamiento específico para la nave uno (índice 0) y la nave dos (índice 1)
    desplazamientos[0] = {1, 2}; // La nave uno se mueve 2 posiciones hacia la derecha
    desplazamientos[1] = {2, 3}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[2] = {3, 4}; // La nave uno se mueve 2 posiciones hacia la derecha
    desplazamientos[3] = {4, 5}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos[4] = {5, 6}; // La nave uno se mueve 2 posiciones hacia la derecha
    desplazamientos[5] = {6, 7}; // La nave dos se mueve 4 posiciones hacia abajo

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
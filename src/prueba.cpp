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
    Archivo presentacion("./assets/images/presentacion.txt");
    Archivo margen1("./assets/images/margen1.txt");
    Archivo margen2("./assets/images/margen2.txt");
    list<Dibujo> dibujos1;

    Archivo nivel1("./assets/images/nivel1.txt");
    Archivo ovni("./assets/images/ovni.txt");
    Archivo nave("./assets/images/nave.txt");
    Archivo margen3("./assets/images/margen3.txt");
    Archivo margen4("./assets/images/margen4.txt");
    Archivo bala1("./assets/images/bala1.txt");
    Archivo bala2("./assets/images/bala2.txt");
    list<Dibujo> dibujos2;

    // Vector para almacenar las posiciones iniciales de cada dibujo
    vector<pair<int, int>> posicionesIniciales1;
    vector<pair<int, int>> posicionesIniciales2;

    // Crear naves con posiciones iniciales específicas
    posicionesIniciales1.push_back({-148, 1}); // Posición inicial del titulo
    posicionesIniciales1.push_back({-114, 23}); // Posición inicial del la version
    posicionesIniciales1.push_back({190, 29}); // Posición inicial del nombre
    posicionesIniciales1.push_back({205, 10}); // Posición inicial de nave 1
    posicionesIniciales1.push_back({0, 0}); // Posición inicial del margen1
    posicionesIniciales1.push_back({0, 0}); // Posición inicial del margen2
    posicionesIniciales1.push_back({175, 0}); // Posición inicial del margen2.1

    posicionesIniciales2.push_back({70, 15}); // Posición inicial del numero de nivel
    posicionesIniciales2.push_back({-40, 25}); // Posición inicial de la nave
    posicionesIniciales2.push_back({-20, 25}); // Posición inicial del ovni 1
    posicionesIniciales2.push_back({-10, 25}); // Posición inicial del ovni 2
    posicionesIniciales2.push_back({0, 0}); // Posición inicial del margen3
    posicionesIniciales2.push_back({0, 0}); // Posición inicial del margen4
    posicionesIniciales2.push_back({175, 0}); // Posición inicial del margen4.1
    
    posicionesIniciales2.push_back({-40, 25}); // Bala Nave
    posicionesIniciales2.push_back({-17, 25}); // Bala ovni1
    posicionesIniciales2.push_back({-7, 25}); // Bala ovni1

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = titulo.CrearDibujo();
        dibujos1.push_back(d);
    }

    // Crear alienígenas con posiciones iniciales específicas
    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = version.CrearDibujo();
        dibujos1.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = nombre.CrearDibujo();
        dibujos1.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = presentacion.CrearDibujo();
        dibujos1.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = margen1.CrearDibujo();
        dibujos1.push_back(d);
    }

    for (size_t i = 0; i < 2; i++)
    {
        Dibujo d = margen2.CrearDibujo();
        dibujos1.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = nivel1.CrearDibujo();
        dibujos2.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = nave.CrearDibujo();
        dibujos2.push_back(d);
    }

    for (size_t i = 0; i < 2; i++)
    {
        Dibujo d = ovni.CrearDibujo();
        dibujos2.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = margen3.CrearDibujo();
        dibujos2.push_back(d);
    }

    for (size_t i = 0; i < 2; i++)
    {
        Dibujo d = margen4.CrearDibujo();
        dibujos2.push_back(d);
    }

    for (size_t i = 0; i < 1; i++)
    {
        Dibujo d = bala1.CrearDibujo();
        dibujos2.push_back(d);
    }

    for (size_t i = 0; i < 2; i++)
    {
        Dibujo d = bala2.CrearDibujo();
        dibujos2.push_back(d);
    }

    auto Pantalla = Screen::Create(
    Dimension::Fixed(176),  // Ancho fijo de 200 píxeles
    Dimension::Fixed(36)   // Alto fijo de 100 píxeles
    );

    // Parámetros de desplazamiento independientes para cada dibujo
    vector<pair<int, int>> desplazamientos1(dibujos1.size(), {0, 0});
    vector<pair<int, int>> desplazamientos2(dibujos1.size(), {0, 0});
    vector<pair<int, int>> desplazamientos3(dibujos2.size(), {0, 0});
    vector<pair<int, int>> desplazamientos4(dibujos2.size(), {0, 0});
    vector<pair<int, int>> desplazamientos5(dibujos2.size(), {0, 0});
    vector<pair<int, int>> desplazamientos6(dibujos2.size(), {0, 0});
    vector<pair<int, int>> desplazamientos7(dibujos2.size(), {0, 0});

    // Desplazamiento específico para la nave uno (índice 0) y la nave dos (índice 1)
    desplazamientos1[0] = {1, 0}; // La nave uno se mueve 2 posiciones hacia la derecha
    desplazamientos1[1] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos1[2] = {-1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos1[3] = {-1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    
    desplazamientos1[4] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos1[5] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos1[6] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos2[0] = {-10, -1}; // La nave uno se mueve 2 posiciones hacia la derecha
    desplazamientos2[1] = {10, 1}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos2[2] = {10, 1}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos2[3] = {-10, -1}; // La nave dos se mueve 4 posiciones hacia abajo
    
    desplazamientos2[4] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos2[5] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos2[6] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos3[0] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos3[1] = {2, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos3[2] = {2, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos3[3] = {2, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos3[4] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos3[5] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos3[6] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos3[7] = {2, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos3[8] = {2, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos3[9] = {2, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos4[0] = {5,1}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos4[1] = {-10, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos4[2] = {-10, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos4[3] = {-10, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos4[4] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos4[5] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos4[6] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos4[7] = {-10, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos4[8] = {-10, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos4[9] = {-10, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos5[0] = {0,0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos5[1] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos5[2] = {-2, -1}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos5[3] = {0, -1}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos5[4] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos5[5] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos5[6] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos5[7] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos5[8] = {-2, -1}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos5[9] = {0, -1}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos6[0] = {0,0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos6[1] = {-1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos6[2] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos6[3] = {1, 0}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos6[4] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos6[5] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos6[6] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos6[7] = {2, -1}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos6[8] = {1, 1}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos6[9] = {-1, 1}; // La nave dos se mueve 4 posiciones hacia abajo

    desplazamientos7[0] = {0,0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[1] = {-1,-2}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[2] = {0, 2}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[3] = {0, 1}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[4] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[5] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[6] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[7] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[8] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo
    desplazamientos7[9] = {0, 0}; // La nave dos se mueve 4 posiciones hacia abajo


    // Establecer las posiciones iniciales de cada dibujo
    size_t index = 0;
    for (auto &&dibujo : dibujos1)
    {
        dibujo.EstablecerPosicion(posicionesIniciales1[index].first, posicionesIniciales1[index].second);
        index++;
    }

    //while(true)
    for (size_t i = 0; i < 158; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.05s);

        // Actualizar
        size_t index = 0;
        for (auto &&dibujo : dibujos1)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos1[index].first);
            dibujo.DesplazarY(desplazamientos1[index].second);
            index++;
        }

        // Dibujar
        for (auto &&dibujo : dibujos1)
        {
            dibujo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout << Pantalla.ResetPosition();          
    }

    this_thread::sleep_for(2s);

    for (size_t i = 0; i < 30; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.08s);

        // Actualizar
        size_t index = 0;
        for (auto &&dibujo : dibujos1)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos2[index].first);
            dibujo.DesplazarY(desplazamientos2[index].second);
            index++;
        }

        // Dibujar
        for (auto &&dibujo : dibujos1)
        {
            dibujo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout << Pantalla.ResetPosition();          
    }
    
    size_t index2 = 0;
    for (auto &&dibujo : dibujos2)
    {
    dibujo.EstablecerPosicion(posicionesIniciales2[index2].first, posicionesIniciales2[index2].second);
    index2++;
    }

    for (size_t i = 0; i < 120; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.025s);

        // Actualizar
        size_t index2 = 0;
        for (auto &&dibujo : dibujos2)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos3[index2].first);
            dibujo.DesplazarY(desplazamientos3[index2].second);
            index2++;
        }

        // Dibujar
        for (auto &&dibujo : dibujos2)
        {
            dibujo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout << Pantalla.ResetPosition();          
    }

    for (size_t i = 0; i < 14; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.025s);

        // Actualizar
        size_t index2 = 0;
        for (auto &&dibujo : dibujos2)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos4[index2].first);
            dibujo.DesplazarY(desplazamientos4[index2].second);
            index2++;
        }

        // Dibujar
        for (auto &&dibujo : dibujos2)
        {
            dibujo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout << Pantalla.ResetPosition();          
    }

        for (size_t i = 0; i < 22; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.05s);

        // Actualizar
        size_t index2 = 0;
        for (auto &&dibujo : dibujos2)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos5[index2].first);
            dibujo.DesplazarY(desplazamientos5[index2].second);
            index2++;
        }

        // Dibujar
        for (auto &&dibujo : dibujos2)
        {
            dibujo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout << Pantalla.ResetPosition();          
    }

     for (size_t i = 0; i < 32; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        // Actualizar
        size_t index2 = 0;
        for (auto &&dibujo : dibujos2)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos6[index2].first);
            dibujo.DesplazarY(desplazamientos6[index2].second);
            index2++;
        }

        // Dibujar
        for (auto &&dibujo : dibujos2)
        {
            dibujo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout << Pantalla.ResetPosition();          
    }

    for (size_t i = 0; i < 10; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        // Actualizar
        size_t index2 = 0;
        for (auto &&dibujo : dibujos2)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos7[index2].first);
            dibujo.DesplazarY(desplazamientos7[index2].second);
            index2++;
        }

        // Dibujar
        for (auto &&dibujo : dibujos2)
        {
            dibujo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout << Pantalla.ResetPosition();          
    }


    return 0;
}

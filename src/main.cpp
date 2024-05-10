#include <iostream>
#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <Archivo.hpp>
#include <Crea.hpp>
#include <Anima.hpp>
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
    Archivo fin("./assets/images/fin.txt");
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
    posicionesIniciales2.push_back({55, 100}); // Bala ovni1

    Crea c;
    c.crea(titulo, dibujos1, 1);
    c.crea(version, dibujos1, 1);
    c.crea(nombre, dibujos1, 1);
    c.crea(presentacion, dibujos1, 1);
    c.crea(margen1, dibujos1, 1);
    c.crea(margen2, dibujos1, 2);
    c.crea(nivel1, dibujos2, 1);
    c.crea(nave, dibujos2, 1);
    c.crea(ovni, dibujos2, 2);
    c.crea(margen3, dibujos2, 1);
    c.crea(margen4, dibujos2, 2);
    c.crea(bala1, dibujos2, 1);
    c.crea(bala2, dibujos2, 2);
    c.crea(fin, dibujos2, 1);

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
    vector<pair<int, int>> desplazamientos8(dibujos2.size(), {0, 0});

    // Desplazamientos 1 de la animacion (Portada)
    desplazamientos1[0] = {1, 0}; 
    desplazamientos1[1] = {1, 0};
    desplazamientos1[2] = {-1, 0};
    desplazamientos1[3] = {-1, 0};

    // Desplazamientos 2 de la animacion (Portada)
    desplazamientos2[0] = {-10, -1};
    desplazamientos2[1] = {10, 1};
    desplazamientos2[2] = {10, 1};
    desplazamientos2[3] = {-10, -1};

    // Desplazamientos 3 de la animacion (Ejecucion del juego)
    desplazamientos3[1] = {2, 0};
    desplazamientos3[2] = {2, 0};
    desplazamientos3[3] = {2, 0};
    desplazamientos3[7] = {2, 0}; 
    desplazamientos3[8] = {2, 0}; 
    desplazamientos3[9] = {2, 0}; 
    
    // Desplazamientos 4 de la animacion (Ejecucion del juego)
    desplazamientos4[0] = {5,1}; 
    desplazamientos4[1] = {-10, 0}; 
    desplazamientos4[2] = {-10, 0}; 
    desplazamientos4[3] = {-10, 0}; 
    desplazamientos4[7] = {-10, 0}; 
    desplazamientos4[8] = {-10, 0}; 
    desplazamientos4[9] = {-10, 0}; 

    // Desplazamientos 5 de la animacion (Ejecucion del juego)
    desplazamientos5[2] = {-2, -1}; 
    desplazamientos5[3] = {0, -1}; 
    desplazamientos5[8] = {-2, -1}; 
    desplazamientos5[9] = {0, -1}; 

    // Desplazamientos 6 de la animacion (Ejecucion del juego)
    desplazamientos6[1] = {-1, 0}; 
    desplazamientos6[2] = {1, 0}; 
    desplazamientos6[3] = {1, 0}; 
    desplazamientos6[7] = {2, -1}; 
    desplazamientos6[8] = {1, 1}; 
    desplazamientos6[9] = {-1, 1}; 

    // Desplazamientos 7 de la animacion (Ejecucion del juego)
    desplazamientos7[1] = {-1,-2}; 
    desplazamientos7[2] = {0, 2}; 
    desplazamientos7[3] = {0, 1}; 

    // Desplazamientos 8 de la animacion (Fin del juego)
    desplazamientos8[0] = {1, 1}; 
    desplazamientos8[10] = {0, -5}; 

    // Establecer las posiciones iniciales de cada dibujo
    size_t index1 = 0;
    for (auto &&dibujo : dibujos1)
    {
        dibujo.EstablecerPosicion(posicionesIniciales1[index1].first, posicionesIniciales1[index1].second);
        index1++;
    }

    //while(true)
    for (size_t i = 0; i < 158; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.05s);

        // Actualizar
        size_t index1 = 0;
        for (auto &&dibujo : dibujos1)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos1[index1].first);
            dibujo.DesplazarY(desplazamientos1[index1].second);
            index1++;
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
        size_t index1 = 0;
        for (auto &&dibujo : dibujos1)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos2[index1].first);
            dibujo.DesplazarY(desplazamientos2[index1].second);
            index1++;
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

    for (size_t i = 0; i < 35; i++)
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

    for (size_t i = 0; i < 18; i++)
    {
        
        Pantalla.Clear();
        this_thread::sleep_for(0.2s);

        // Actualizar
        size_t index2 = 0;
        for (auto &&dibujo : dibujos2)
        {
            // Aplicar desplazamientos individuales
            dibujo.DesplazarX(desplazamientos8[index2].first);
            dibujo.DesplazarY(desplazamientos8[index2].second);
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
#include <list>
#include <vector>
#include <Archivo.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <iostream>
#include <string>

using namespace std;
using namespace ftxui;

class Anima
{
private:
    list<Dibujo> &dibujos_;
    vector<pair<int, int>> &posicionesIniciales_;
    vector<pair<int, int>> &desplazamientos_;

public:
    Anima(list<Dibujo> &dibujos, vector<pair<int, int>> &posicionesIniciales, vector<pair<int, int>> &desplazamientos)
        : dibujos_(dibujos), posicionesIniciales_(posicionesIniciales), desplazamientos_(desplazamientos) {}

    void EstablecerPosicionesIniciales()
    {
        auto it = posicionesIniciales_.begin();
        for (auto &dibujo : dibujos_)
        {
            dibujo.EstablecerPosicion(it->first, it->second);
            ++it;
        }
    }

    void ActualizarYDibujar(Screen &pantalla, size_t iteraciones, std::chrono::milliseconds duracion)
    {
        for (size_t i = 0; i < iteraciones; ++i)
        {
            pantalla.Clear();
            this_thread::sleep_for(duracion);

            // Actualizar
            auto it = desplazamientos_.begin();
            for (auto &dibujo : dibujos_)
            {
                dibujo.DesplazarX(it->first);
                dibujo.DesplazarY(it->second);
                ++it;
            }

            // Dibujar
            for (auto &dibujo : dibujos_)
            {
                dibujo.Dibujar(pantalla);
            }

            pantalla.Print();
            cout << pantalla.ResetPosition();
        }
    }
    ~Anima() {}
};

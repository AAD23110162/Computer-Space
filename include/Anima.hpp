#include <list>
#include <vector> // Incluir la librería de vectores
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
public:
    Anima(Screen& pantalla, vector<Dibujo> dibujos, vector<std::pair<int, int>> posicionesIniciales, vector<std::pair<int, int>> desplazamientos, int frames, double sleepTime)
        : pantalla_(pantalla), dibujos_(dibujos), posicionesIniciales_(posicionesIniciales), desplazamientos_(desplazamientos), frames_(frames), sleepTime_(sleepTime) {}

    void play() 
    {
        for (size_t i = 0; i < frames_; i++) 
        {
            pantalla_.Clear();
            this_thread::sleep_for(chrono::milliseconds(static_cast<int>(sleepTime_ * 1000)));

            update();
            draw();
            pantalla_.Print();
            cout << pantalla_.ResetPosition();
        }
    }

private:
    void update() 
    {
        size_t index = 0;
        for (auto& dibujo : dibujos_) 
        {
            dibujo.DesplazarX(desplazamientos_[index].first);
            dibujo.DesplazarY(desplazamientos_[index].second);
            index++;
        }
    }

    void draw() 
    {
        for (auto& dibujo : dibujos_) 
        {
            dibujo.Dibujar(pantalla_);
        }
    }

    Screen& pantalla_;
    std::vector<Dibujo> dibujos_;
    std::vector<std::pair<int, int>> posicionesIniciales_;
    std::vector<std::pair<int, int>> desplazamientos_;
    int frames_;
    double sleepTime_;
};

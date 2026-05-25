#pragma once
#include <string>
#include "Pila.h"
#include "Diseno.h"

class Chatbot {
private:
    Pila<Diseno> historialRecomendaciones;
    Diseno disenos[12];
    int totalDisenos;
public:
    Chatbot();
    Diseno iniciarConversacion();
    Diseno obtenerUltimaRecomendacion();
    const Pila<Diseno>& getHistorial() const;
    int getTotalRecomendaciones();
    Diseno decidir(int ocasion, int estilo, int color);
};

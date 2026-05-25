#include <iostream>
#include <string>
#include "Chatbot.h"
#include "Diseno.h"
using namespace std;
Chatbot::Chatbot() {
    // Inicializar los diseños disponibles
    disenos[0] = Diseno(1, "Floral pastel", "Flores en lila y rosa", "floral");
    disenos[1] = Diseno(2, "Nude Minimalista", "Base nude con linea", "minimalista");
    disenos[2] = Diseno(3, "Glamour Dorado", "Detalles dorados", "glitter");
    disenos[3] = Diseno(4, "Ombre Rosa", "Degradado de blanco a rosa", "degradado");
    disenos[4] = Diseno(5, "Francesa Clasica", "Punta blanca sobre base natural", "minimalista");
    disenos[5] = Diseno(6, "Floral Discreto", "Flores pequenas en tono beige", "floral");
    disenos[6] = Diseno(7, "Vibrante Coral", "Base coral brillante con acabado glossy", "vibrante");
    disenos[7] = Diseno(8, "Degradado Noche", "Ombre de negro a azul marino con glitter", "degradado");
    disenos[8] = Diseno(9, "Pastel Lavanda", "Base lavanda suave con detalles blancos", "minimalista");
    disenos[9] = Diseno(10, "Rojo Clasico", "Base rojo intenso elegante", "vibrante");
    disenos[10] = Diseno(11, "Geometrico Negro", "Lineas geometricas negras sobre base blanca", "minimalista");
    disenos[11] = Diseno(12, "Rosa Glitter", "Base rosa con particulas doradas brillantes", "glitter");

    totalDisenos = 12;
}
Diseno Chatbot::iniciarConversacion() {
    int ocasion, estilo, color;
    // Pregunta 1
    cout << "Para que ocasion?" << endl;
    cout << "1. Uso diario" << endl;
    cout << "2. Evento especial" << endl;
    cout << "3. Trabajo formal" << endl;
    cin >> ocasion;
    // Pregunta 2
    cout << "Que estilo prefieres?" << endl;
    cout << "1. Minimalista" << endl;
    cout << "2. Floral" << endl;
    cout << "3. Glitter" << endl;
    cout << "4. Degradado" << endl;
    cin >> estilo;
    // Pregunta 3
    cout << "Que colores te gustan?" << endl;
    cout << "1. Neutros" << endl;
    cout << "2. Vibrantes" << endl;
    cout << "3. Pasteles" << endl;
    cout << "4. Oscuros" << endl;
    cin >> color;
    // Arbol de decisiones
    Diseno recomendado = decidir(ocasion, estilo, color);
    historialRecomendaciones.apilar(recomendado);
    return recomendado;
}
Diseno Chatbot::obtenerUltimaRecomendacion() {
    return historialRecomendaciones.verCima();
}
int Chatbot::getTotalRecomendaciones() {
    return historialRecomendaciones.getTamano();
}
const Pila<Diseno>& Chatbot::getHistorial() const {
    return historialRecomendaciones;
}
Diseno Chatbot::decidir(int ocasion, int estilo, int color) {
    // EVENTO ESPECIAL //
    if (ocasion == 2) {
        if (estilo == 1) { // minimalista
            if (color == 1) return disenos[4]; // Francesa Clasica
            if (color == 2) return disenos[9]; // Rojo Clasico
            if (color == 3) return disenos[8]; // Pastel Lavanda
            if (color == 4) return disenos[10]; // Geometrico Negro
        }
        if (estilo == 2) { // floral
            if (color == 1) return disenos[5]; // Floral Discreto
            if (color == 2) return disenos[6]; // Vibrante Coral
            if (color == 3) return disenos[0]; // Floral Pastel
            if (color == 4) return disenos[10]; // Geometrico Negro
        }
        if (estilo == 3) { // glitter
            if (color == 1) return disenos[2]; // Glamour Dorado
            if (color == 2) return disenos[11]; // Rosa Glitter
            if (color == 3) return disenos[11]; // Rosa Glitter
            if (color == 4) return disenos[7]; // Degradado Noche
        }
        if (estilo == 4) { // degradado
            if (color == 1) return disenos[3]; // Ombre Rosa
            if (color == 2) return disenos[6]; // Vibrante Coral
            if (color == 3) return disenos[8]; // Pastel Lavanda
            if (color == 4) return disenos[7]; // Degradado Noche
        }
    }
    // TRABAJO FORMAL //
    if (ocasion == 3) {
        if (estilo == 1) { // Minimalista
            if (color == 1) return disenos[4];  // Francesa Clasica       — neutro elegante
            if (color == 2) return disenos[9];  // Rojo Clasico            — vibrante pero formal
            if (color == 3) return disenos[8];  // Pastel Lavanda          — pastel sobrio
            if (color == 4) return disenos[10]; // Geometrico Negro        — oscuro/formal
        }
        if (estilo == 2) { // Floral
            if (color == 1) return disenos[5];  // Floral Discreto         — neutro, discreto
            if (color == 2) return disenos[6];  // Vibrante Coral          — floral llamativo
            if (color == 3) return disenos[0];  // Floral Pastel           — floral suave
            if (color == 4) return disenos[5];  // Floral Discreto         — oscuro→ discreto
        }
        if (estilo == 3) { // Glitter
            if (color == 1) return disenos[2];  // Glamour Dorado          — neutro/dorado
            if (color == 2) return disenos[11]; // Rosa Glitter            — vibrante con brillo
            if (color == 3) return disenos[11]; // Rosa Glitter            — pastel con brillo
            if (color == 4) return disenos[7];  // Degradado Noche         — oscuro con glitter
        }
        if (estilo == 4) { // Degradado
            if (color == 1) return disenos[3];  // Ombre Rosa              — neutro suave
            if (color == 2) return disenos[6];  // Vibrante Coral          — degradado llamativo
            if (color == 3) return disenos[8];  // Pastel Lavanda          — degradado pastel
            if (color == 4) return disenos[7];  // Degradado Noche         — oscuro elegante
        }
    }
    // USO DIARIO //
    if (ocasion == 1) {
        if (estilo == 1) {
            if (color == 1) return disenos[1]; // Nude Minimalista
            if (color == 2) return disenos[9]; // Rojo Clasico
            if (color == 3) return disenos[8]; // Pastel Lavanda
            if (color == 4) return disenos[10]; // Geometrico Negro
        }
        if (estilo == 2) {
            if (color == 1) return disenos[5];
            if (color == 2) return disenos[6];
            if (color == 3) return disenos[0];
            if (color == 4) return disenos[10];
        }
        if (estilo == 3) {
            if (color == 1) return disenos[2];
            if (color == 2) return disenos[11];
            if (color == 3) return disenos[11];
            if (color == 4) return disenos[7];
        }
        if (estilo == 4) {
            if (color == 1) return disenos[3];
            if (color == 2) return disenos[6];
            if (color == 3) return disenos[8];
            if (color == 4) return disenos[7];
        }
    }
    // Caso por defecto
    return disenos[4];
}
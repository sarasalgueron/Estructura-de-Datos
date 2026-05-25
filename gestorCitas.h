#pragma once
#include "Cola.h"
#include "Cita.h"
#include <fstream>
#include <sstream>
class gestorCitas {
	// reservarCita(), cancelarCita(), completarCita(), getColaDia()
	Cola<Cita> colaDia;
public:
	void reservarCita(Cita c) {
		colaDia.encolar(c);
	}
	void cancelarCita(Cita &c) {
		c.setEstado(CANCELADA);

		// de cualquier lugar de la cola
		int contador = 0;       
		int totalElementos = colaDia.getTamano();
		while (contador < totalElementos) {
			if (colaDia.verFrente().getId() == c.getId()) {
				colaDia.desencolar();
			}
			else {
				colaDia.encolar(colaDia.verFrente());
				colaDia.desencolar();
			}
			contador++;
		}
	}
	void completarCita(Cita &c) {
		c.setEstado(COMPLETADA);
		if (!colaDia.estaVacia()) {
			colaDia.desencolar();
		}
		
	}
	Cola<Cita> getColaDia() {
		return colaDia;
	}
	void guardarArchivo() {
		// verificar que el archivo existe
		ofstream archivo("citas.txt");
		if (!archivo.is_open()) {
			return;
		}
		Cola<Cita> colaTemp = getColaDia();
		while (colaTemp.getTamano() != 0) {
			Cita cita = colaTemp.verFrente();
			Diseno d = cita.getDiseno();
			Servicio s = cita.getServicio();
			archivo << cita.getId() <<  ", " << cita.getCliente() << ", " << d.getDescripcion() << ", " << s.getNombre() << ", " << cita.getEstado() << ", " << cita.getFecha() << ", " << cita.getHora() << endl;
			colaTemp.desencolar();
		}

		archivo.close();
	}
	void cargarArchivo() {
		ifstream archivo("citas.txt");

		if (!archivo.is_open()) {
			return;
		}
		string linea;
		while (getline(archivo, linea)) {
			stringstream ss(linea);
			string sId, sCliente, sDiseno, sNombre, sEstado, sFecha, sHora;

			getline(ss, sId, ',');
			getline(ss, sCliente, ',');
			getline(ss, sDiseno, ',');
			getline(ss, sNombre, ',');
			getline(ss, sEstado, ',');
			getline(ss, sFecha, ',');
			getline(ss, sHora, ',');

			// convertir strings a los tipos correctos
			int id = stoi(sId);

			Servicio s(0, 0, sNombre, 0.0);
			Diseno d(0, sDiseno, "", "");
			Cita c(id, sCliente, s, d, sFecha, sHora);
			reservarCita(c);
		}
		archivo.close();

	}

};
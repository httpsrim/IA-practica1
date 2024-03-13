#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

void ComportamientoJugador::PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz){
	switch (current_state.brujula){						//Dibuja el rango que ve el jugador dependiendo del sentido
	case norte:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil - 1][st.col - 1] = terreno[1];
		matriz[st.fil - 1][st.col] = terreno[2];
		matriz[st.fil - 1][st.col + 1] = terreno[3];
		matriz[st.fil - 2][st.col - 2] = terreno[4];
		matriz[st.fil - 2][st.col - 1] = terreno[5];
		matriz[st.fil - 2][st.col] = terreno[6];
		matriz[st.fil - 2][st.col + 1] = terreno[7];
		matriz[st.fil - 2][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col - 3] = terreno[9];
		matriz[st.fil - 3][st.col - 2] = terreno[10];
		matriz[st.fil - 3][st.col - 1] = terreno[11];
		matriz[st.fil - 3][st.col] = terreno[12];
		matriz[st.fil - 3][st.col + 1] = terreno[13];
		matriz[st.fil - 3][st.col + 2] = terreno[14];
		matriz[st.fil - 3][st.col + 3] = terreno[15];
		break;
	case sur:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil + 1][st.col + 1] = terreno[1];
		matriz[st.fil + 1][st.col] = terreno[2];
		matriz[st.fil + 1][st.col - 1] = terreno[3];
		matriz[st.fil + 2][st.col + 2] = terreno[4];
		matriz[st.fil + 2][st.col + 1] = terreno[5];
		matriz[st.fil + 2][st.col] = terreno[6];
		matriz[st.fil + 2][st.col - 1] = terreno[7];
		matriz[st.fil + 2][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col + 3] = terreno[9];
		matriz[st.fil + 3][st.col + 2] = terreno[10];
		matriz[st.fil + 3][st.col + 1] = terreno[11];
		matriz[st.fil + 3][st.col] = terreno[12];
		matriz[st.fil + 3][st.col - 1] = terreno[13];
		matriz[st.fil + 3][st.col - 2] = terreno[14];
		matriz[st.fil + 3][st.col - 3] = terreno[15];
		break;
	case este:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil - 1][st.col + 1] = terreno[1];
		matriz[st.fil][st.col + 1] = terreno[2];
		matriz[st.fil + 1][st.col + 1] = terreno[3];
		matriz[st.fil - 2][st.col + 2] = terreno[4];
		matriz[st.fil - 1][st.col + 2] = terreno[5];
		matriz[st.fil][st.col + 2] = terreno[6];
		matriz[st.fil + 1][st.col + 2] = terreno[7];
		matriz[st.fil + 2][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col + 3] = terreno[9];
		matriz[st.fil - 2][st.col + 3] = terreno[10];
		matriz[st.fil - 1][st.col + 3] = terreno[11];
		matriz[st.fil][st.col + 3] = terreno[12];
		matriz[st.fil + 1][st.col + 3] = terreno[13];
		matriz[st.fil + 2][st.col + 3] = terreno[14];
		matriz[st.fil + 3][st.col + 3] = terreno[15];
		break;
	case oeste:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil + 1][st.col - 1] = terreno[1];
		matriz[st.fil][st.col - 1] = terreno[2];
		matriz[st.fil - 1][st.col - 1] = terreno[3];
		matriz[st.fil + 2][st.col - 2] = terreno[4];
		matriz[st.fil + 1][st.col - 2] = terreno[5];
		matriz[st.fil][st.col - 2] = terreno[6];
		matriz[st.fil - 1][st.col - 2] = terreno[7];
		matriz[st.fil - 2][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col - 3] = terreno[9];
		matriz[st.fil + 2][st.col - 3] = terreno[10];
		matriz[st.fil + 1][st.col - 3] = terreno[11];
		matriz[st.fil][st.col - 3] = terreno[12];
		matriz[st.fil - 1][st.col - 3] = terreno[13];
		matriz[st.fil - 2][st.col - 3] = terreno[14];
		matriz[st.fil - 3][st.col - 3] = terreno[15];
		break;
	case noreste:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil - 1][st.col] = terreno[1];
		matriz[st.fil - 1][st.col + 1] = terreno[2];
		matriz[st.fil][st.col + 1] = terreno[3];
		matriz[st.fil - 2][st.col] = terreno[4];
		matriz[st.fil - 2][st.col + 1] = terreno[5];
		matriz[st.fil - 2][st.col + 2] = terreno[6];
		matriz[st.fil - 1][st.col + 2] = terreno[7];
		matriz[st.fil][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col] = terreno[9];
		matriz[st.fil - 3][st.col + 1] = terreno[10];
		matriz[st.fil - 3][st.col + 2] = terreno[11];
		matriz[st.fil - 3][st.col + 3] = terreno[12];
		matriz[st.fil - 2][st.col + 3] = terreno[13];
		matriz[st.fil - 1][st.col + 3] = terreno[14];
		matriz[st.fil][st.col + 3] = terreno[15];
		break;
	case noroeste:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil][st.col - 1] = terreno[1];
		matriz[st.fil - 1][st.col - 1] = terreno[2];
		matriz[st.fil - 1][st.col] = terreno[3];
		matriz[st.fil][st.col - 2] = terreno[4];
		matriz[st.fil - 1][st.col - 2] = terreno[5];
		matriz[st.fil - 2][st.col - 2] = terreno[6];
		matriz[st.fil - 2][st.col - 1] = terreno[7];
		matriz[st.fil - 2][st.col] = terreno[8];
		matriz[st.fil][st.col - 3] = terreno[9];
		matriz[st.fil - 1][st.col - 3] = terreno[10];
		matriz[st.fil - 2][st.col - 3] = terreno[11];
		matriz[st.fil - 3][st.col - 3] = terreno[12];
		matriz[st.fil - 3][st.col - 2] = terreno[13];
		matriz[st.fil - 3][st.col - 1] = terreno[14];
		matriz[st.fil - 3][st.col] = terreno[15];
		break;
	case suroeste:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil + 1][st.col] = terreno[1];
		matriz[st.fil + 1][st.col - 1] = terreno[2];
		matriz[st.fil][st.col - 1] = terreno[3];
		matriz[st.fil + 2][st.col] = terreno[4];
		matriz[st.fil + 2][st.col - 1] = terreno[5];
		matriz[st.fil + 2][st.col - 2] = terreno[6];
		matriz[st.fil + 1][st.col - 2] = terreno[7];
		matriz[st.fil][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col] = terreno[9];
		matriz[st.fil + 3][st.col - 1] = terreno[10];
		matriz[st.fil + 3][st.col - 2] = terreno[11];
		matriz[st.fil + 3][st.col - 3] = terreno[12];
		matriz[st.fil + 2][st.col - 3] = terreno[13];
		matriz[st.fil + 1][st.col - 3] = terreno[14];
		matriz[st.fil][st.col - 3] = terreno[15];
		break;
	case sureste:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil][st.col + 1] = terreno[1];
		matriz[st.fil + 1][st.col + 1] = terreno[2];
		matriz[st.fil + 1][st.col] = terreno[3];
		matriz[st.fil][st.col + 2] = terreno[4];
		matriz[st.fil + 1][st.col + 2] = terreno[5];
		matriz[st.fil + 2][st.col + 2] = terreno[6];
		matriz[st.fil + 2][st.col + 1] = terreno[7];
		matriz[st.fil + 2][st.col] = terreno[8];
		matriz[st.fil][st.col + 3] = terreno[9];
		matriz[st.fil + 1][st.col + 3] = terreno[10];
		matriz[st.fil + 2][st.col + 3] = terreno[11];
		matriz[st.fil + 3][st.col + 3] = terreno[12];
		matriz[st.fil + 3][st.col + 2] = terreno[13];
		matriz[st.fil + 3][st.col + 1] = terreno[14];
		matriz[st.fil + 3][st.col] = terreno[15];
		break;
	default:
		matriz[st.fil][st.col] = terreno[0];
		break;
	}
}

Action ComportamientoJugador::think(Sensores sensores) {	
	Action accion = actIDLE;
	int a;
	switch (last_action){
		case actWALK:
			switch (current_state.brujula){
				case norte: 
					current_state.fil--; 
					break;
				case noreste: 
					current_state.fil--; 
					current_state.col++; 
					break;
				case este: 
					current_state.col++; 
					break;
				case sureste:
					current_state.fil++; 
					current_state.col++; 
					break;
				case sur: 
					current_state.fil++;
					break;
				case suroeste: 
					current_state.fil++; 
					current_state.col--; 
					break;
				case oeste:
					current_state.col--; 
					break;
				case noroeste: 
					current_state.fil--; 
					current_state.col--; 
					break;
			}
			break;
		case actRUN:
			// Actualización en caso de correr
			break;
		case actTURN_SR:
			// Actualización en caso de girar 45º a la derecha
			a = current_state.brujula;
			a = (a+1)%8;
			current_state.brujula = static_cast<Orientacion>(a);
			break;
		case actTURN_L:
			a = current_state.brujula;
			a = (a+6)%8;
			current_state.brujula = static_cast<Orientacion>(a);
			break;
	}
	//cuando está en nivel 0....
	if (sensores.posF!=-1 and !bien_situado){
		current_state.fil = sensores.posF;
		current_state.col= sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;
	}
	if(sensores.terreno[0] == 'K'){
		tieneBikini = true;
		cout << "tengo bikini\n";
	}
	if(sensores.terreno[0] == 'D'){
		tieneZapas = true;
	}
	if(bien_situado){
		PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado);
	}
	//detecta una nueva acción
	if((sensores.terreno[2] == 'T' ||  sensores.terreno[2] == 'S' || sensores.terreno[2] == 'G' || sensores.terreno[2] == 'K' || sensores.terreno[2] == 'D') && sensores.agentes[2] == '_' && sensores.terreno[2] != 'P'){
		accion = actWALK;
	}
	else if(tieneBikini && sensores.terreno[2] == 'A')
		accion = actWALK;
	else if(tieneZapas && sensores.terreno[2] == 'B')
		accion = actWALK;
	else if(!girar_derecha){
		accion = actTURN_L;
		girar_derecha = (rand()%2 == 0);
	}
	else{
		accion = actTURN_SR;
		girar_derecha = (rand()%2 == 0);
	}

	if(sensores.colision){
		accion = actTURN_SR;
	}
	//Recordar la ultima acción
	last_action = accion;
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
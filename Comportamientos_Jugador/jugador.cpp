#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;
int ComportamientoJugador::costeCasilla(Sensores &sensores){
	switch(sensores.terreno[2]){
		case 'B' :
			if(tieneZapas) return 5;
			else return 25;
			break;
		case 'A':
			if(tieneBikini) return 5;
			else return 50;
			break;
		case 'T':
			return 2;
			break;
		case 'P': case 'M':
			return 100000;
			break;
		default:
			return 1;
			break;
	}
}
Action ComportamientoJugador::buscarSinDescubrir(Sensores &sensores){
	Action accion;
	costeDelante = costeCasilla(sensores);
	costeDcho = costeCasilla(sensores);
	costeIzq = costeCasilla(sensores);
	if(costeDcho < costeDelante && costeDcho < costeIzq) accion = actTURN_SR;
	else if(costeDelante < costeDcho && costeDelante < costeIzq) accion = actWALK;
	else accion = actTURN_L;
	return accion;
}
Action ComportamientoJugador::buscarOrientacion(Sensores &sensores){
	Action accion;
	if(necesitoGirar){
		accion = actTURN_L;
		necesitoGirar = false;
	}
	else if(masAdelante){
		accion = actWALK;
		masAdelante = false;
		necesitoGirar = true;
	}
	if(sensores.terreno[1] == 'G'){
		accion = actWALK;
		necesitoGirar = true;
	}
	else if(sensores.terreno[4] == 'G' || sensores.terreno[5] == 'G'){
		accion = actRUN;
		necesitoGirar = true;
	}
	else if(sensores.terreno[9] == 'G' || sensores.terreno[10] == 'G' || sensores.terreno[11] == 'G'){
		accion = actRUN;
		masAdelante = true;
	}
	else if(sensores.terreno[3] == 'G' || sensores.terreno[7] == 'G' || sensores.terreno[8] == 'G' || sensores.terreno[13] == 'G' || sensores.terreno[14] == 'G' || sensores.terreno[15] == 'G')	
		accion = actTURN_SR;
	else if(sensores.terreno[2] == 'G' || sensores.terreno[6] == 'G' || sensores.terreno[12] == 'G')		
		accion = actWALK;
	else 
		accion = actIDLE;
	return accion;
}
void ComportamientoJugador::PonerTerrenoEnMapa(vector<vector<unsigned char>> &mapaResultado, const state &st, vector<vector<unsigned char>> &mapaAux, int fil, int col){
	for(int i = 0; i < mapaResultado.size();i++){
		for(int j = 0; j < mapaResultado.size();j++){
			if(mapaAux[fil+i][col+j]!='?' and mapaAux[fil+i][col+j] != mapaResultado[i][j])
				mapaResultado[i][j]=mapaAux[fil+i][col+j];
		}
	}
}
void ComportamientoJugador::PonerTerrenoEnMapaN3(vector<vector<unsigned char>> &mapaResultado, const state &st, vector<vector<unsigned char>> &mapaAux, int fil, int col, int diferencia){
	switch(diferencia){
		case 2: //este
			for(int i = 0; i < mapaResultado.size();i++){
				for(int j = 0; j < mapaResultado.size();j++){
				if(mapaAux[col+j][fil+i]!='?' and mapaAux[col+j][fil+i] != mapaResultado[i][j])
					mapaResultado[i][j]=mapaAux[col+j][fil+i];
				}
			}
			break;
		case 4: //sur
			for(int i = mapaResultado.size(); i > 0;i--){
				for(int j = mapaResultado.size(); j > 0;j--){
				if(mapaAux[mapaResultado.size()-fil+i][mapaResultado.size()-col+j]!='?' and mapaAux[mapaResultado.size()-fil+i][mapaResultado.size()-col+j] != mapaResultado[i][j])
					mapaResultado[i][j]=mapaAux[mapaResultado.size()-fil+i][mapaResultado.size()-col+j];
				}
			}
			break;
		case 6: //oeste
			for(int i = 0; i < mapaResultado.size();i--){
				for(int j = 0; j < mapaResultado.size();j--){
				if(mapaAux[mapaResultado.size()-col+j][mapaResultado.size()-fil+i]!='?' and mapaAux[mapaResultado.size()-col+j][mapaResultado.size()-fil+i] != mapaResultado[i][j])
					mapaResultado[i][j]=mapaAux[mapaResultado.size()-col+j][mapaResultado.size()-fil+i];
				}
			}
			break;
		default:
			break;
	}
	
}

void ComportamientoJugador::PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz,const int nivel){
	switch (current_state.brujula){						//Dibuja el rango que ve el jugador dependiendo del sentido
	//Cambiar para q no se quite de pintar el precipicio
	case norte:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil - 1][st.col - 1] = terreno[1];
		matriz[st.fil - 1][st.col] = terreno[2];
		matriz[st.fil - 1][st.col + 1] = terreno[3];
		matriz[st.fil - 2][st.col - 2] = terreno[4];
		matriz[st.fil - 2][st.col - 1] = terreno[5];
if(nivel != 3)		matriz[st.fil - 2][st.col] = terreno[6];
		matriz[st.fil - 2][st.col + 1] = terreno[7];
		matriz[st.fil - 2][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col - 3] = terreno[9];
		matriz[st.fil - 3][st.col - 2] = terreno[10];
if(nivel != 3)		matriz[st.fil - 3][st.col - 1] = terreno[11];
if(nivel != 3)		matriz[st.fil - 3][st.col] = terreno[12];
if(nivel != 3)		matriz[st.fil - 3][st.col + 1] = terreno[13];
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
if(nivel != 3)		matriz[st.fil + 2][st.col] = terreno[6];
		matriz[st.fil + 2][st.col - 1] = terreno[7];
		matriz[st.fil + 2][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col + 3] = terreno[9];
		matriz[st.fil + 3][st.col + 2] = terreno[10];
if(nivel != 3)		matriz[st.fil + 3][st.col + 1] = terreno[11];
if(nivel != 3)		matriz[st.fil + 3][st.col] = terreno[12];
if(nivel != 3)		matriz[st.fil + 3][st.col - 1] = terreno[13];
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
if(nivel != 3)		matriz[st.fil][st.col + 2] = terreno[6];
		matriz[st.fil + 1][st.col + 2] = terreno[7];
		matriz[st.fil + 2][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col + 3] = terreno[9];
		matriz[st.fil - 2][st.col + 3] = terreno[10];
if(nivel != 3)		matriz[st.fil - 1][st.col + 3] = terreno[11];
if(nivel != 3)		matriz[st.fil][st.col + 3] = terreno[12];
if(nivel != 3)		matriz[st.fil + 1][st.col + 3] = terreno[13];
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
if(nivel != 3)		matriz[st.fil][st.col - 2] = terreno[6];
		matriz[st.fil - 1][st.col - 2] = terreno[7];
		matriz[st.fil - 2][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col - 3] = terreno[9];
		matriz[st.fil + 2][st.col - 3] = terreno[10];
if(nivel != 3)		matriz[st.fil + 1][st.col - 3] = terreno[11];
if(nivel != 3)		matriz[st.fil][st.col - 3] = terreno[12];
if(nivel != 3)		matriz[st.fil - 1][st.col - 3] = terreno[13];
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
if(nivel != 3)		matriz[st.fil - 2][st.col + 2] = terreno[6];
		matriz[st.fil - 1][st.col + 2] = terreno[7];
		matriz[st.fil][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col] = terreno[9];
		matriz[st.fil - 3][st.col + 1] = terreno[10];
if(nivel != 3)		matriz[st.fil - 3][st.col + 2] = terreno[11];
if(nivel != 3)		matriz[st.fil - 3][st.col + 3] = terreno[12];
if(nivel != 3)		matriz[st.fil - 2][st.col + 3] = terreno[13];
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
if(nivel != 3)		matriz[st.fil - 2][st.col - 2] = terreno[6];
		matriz[st.fil - 2][st.col - 1] = terreno[7];
		matriz[st.fil - 2][st.col] = terreno[8];
		matriz[st.fil][st.col - 3] = terreno[9];
		matriz[st.fil - 1][st.col - 3] = terreno[10];
if(nivel != 3)		matriz[st.fil - 2][st.col - 3] = terreno[11];
if(nivel != 3)		matriz[st.fil - 3][st.col - 3] = terreno[12];
if(nivel != 3)		matriz[st.fil - 3][st.col - 2] = terreno[13];
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
if(nivel != 3)		matriz[st.fil + 2][st.col - 2] = terreno[6];
		matriz[st.fil + 1][st.col - 2] = terreno[7];
		matriz[st.fil][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col] = terreno[9];
		matriz[st.fil + 3][st.col - 1] = terreno[10];
if(nivel != 3)		matriz[st.fil + 3][st.col - 2] = terreno[11];
if(nivel != 3)		matriz[st.fil + 3][st.col - 3] = terreno[12];
if(nivel != 3)		matriz[st.fil + 2][st.col - 3] = terreno[13];
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
if(nivel != 3)		matriz[st.fil + 2][st.col + 2] = terreno[6];
		matriz[st.fil + 2][st.col + 1] = terreno[7];
		matriz[st.fil + 2][st.col] = terreno[8];
		matriz[st.fil][st.col + 3] = terreno[9];
		matriz[st.fil + 1][st.col + 3] = terreno[10];
if(nivel != 3)		matriz[st.fil + 2][st.col + 3] = terreno[11];
if(nivel != 3)		matriz[st.fil + 3][st.col + 3] = terreno[12];
if(nivel != 3)		matriz[st.fil + 3][st.col + 2] = terreno[13];
		matriz[st.fil + 3][st.col + 1] = terreno[14];
		matriz[st.fil + 3][st.col] = terreno[15];
		break;
	default:
		matriz[st.fil][st.col] = terreno[0];
		break;
	}
}
void ComportamientoJugador::PonerTerrenoEnMatrizAux(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz, const int nivel){
	switch (current_state.brujula){						//Dibuja el rango que ve el jugador dependiendo del sentido
	//Cambiar para q no se quite de pintar el precipicio
	case norte:
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil - 1][st.col - 1] = terreno[1];
		matriz[st.fil - 1][st.col] = terreno[2];
		matriz[st.fil - 1][st.col + 1] = terreno[3];
		matriz[st.fil - 2][st.col - 2] = terreno[4];
		matriz[st.fil - 2][st.col - 1] = terreno[5];
if(nivel != 3)		matriz[st.fil - 2][st.col] = terreno[6];
		matriz[st.fil - 2][st.col + 1] = terreno[7];
		matriz[st.fil - 2][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col - 3] = terreno[9];
		matriz[st.fil - 3][st.col - 2] = terreno[10];
if(nivel != 3)		matriz[st.fil - 3][st.col - 1] = terreno[11];
if(nivel != 3)		matriz[st.fil - 3][st.col] = terreno[12];
if(nivel != 3)		matriz[st.fil - 3][st.col + 1] = terreno[13];
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
if(nivel != 3)		matriz[st.fil + 2][st.col] = terreno[6];
		matriz[st.fil + 2][st.col - 1] = terreno[7];
		matriz[st.fil + 2][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col + 3] = terreno[9];
		matriz[st.fil + 3][st.col + 2] = terreno[10];
if(nivel != 3)		matriz[st.fil + 3][st.col + 1] = terreno[11];
if(nivel != 3)		matriz[st.fil + 3][st.col] = terreno[12];
if(nivel != 3)		matriz[st.fil + 3][st.col - 1] = terreno[13];
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
if(nivel != 3)		matriz[st.fil][st.col + 2] = terreno[6];
		matriz[st.fil + 1][st.col + 2] = terreno[7];
		matriz[st.fil + 2][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col + 3] = terreno[9];
		matriz[st.fil - 2][st.col + 3] = terreno[10];
if(nivel != 3)		matriz[st.fil - 1][st.col + 3] = terreno[11];
if(nivel != 3)		matriz[st.fil][st.col + 3] = terreno[12];
if(nivel != 3)		matriz[st.fil + 1][st.col + 3] = terreno[13];
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
if(nivel != 3)		matriz[st.fil][st.col - 2] = terreno[6];
		matriz[st.fil - 1][st.col - 2] = terreno[7];
		matriz[st.fil - 2][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col - 3] = terreno[9];
		matriz[st.fil + 2][st.col - 3] = terreno[10];
if(nivel != 3)		matriz[st.fil + 1][st.col - 3] = terreno[11];
if(nivel != 3)		matriz[st.fil][st.col - 3] = terreno[12];
if(nivel != 3)		matriz[st.fil - 1][st.col - 3] = terreno[13];
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
if(nivel != 3)		matriz[st.fil - 2][st.col + 2] = terreno[6];
		matriz[st.fil - 1][st.col + 2] = terreno[7];
		matriz[st.fil][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col] = terreno[9];
		matriz[st.fil - 3][st.col + 1] = terreno[10];
if(nivel != 3)		matriz[st.fil - 3][st.col + 2] = terreno[11];
if(nivel != 3)		matriz[st.fil - 3][st.col + 3] = terreno[12];
if(nivel != 3)		matriz[st.fil - 2][st.col + 3] = terreno[13];
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
if(nivel != 3)		matriz[st.fil - 2][st.col - 2] = terreno[6];
		matriz[st.fil - 2][st.col - 1] = terreno[7];
		matriz[st.fil - 2][st.col] = terreno[8];
		matriz[st.fil][st.col - 3] = terreno[9];
		matriz[st.fil - 1][st.col - 3] = terreno[10];
if(nivel != 3)		matriz[st.fil - 2][st.col - 3] = terreno[11];
if(nivel != 3)		matriz[st.fil - 3][st.col - 3] = terreno[12];
if(nivel != 3)		matriz[st.fil - 3][st.col - 2] = terreno[13];
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
if(nivel != 3)		matriz[st.fil + 2][st.col - 2] = terreno[6];
		matriz[st.fil + 1][st.col - 2] = terreno[7];
		matriz[st.fil][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col] = terreno[9];
		matriz[st.fil + 3][st.col - 1] = terreno[10];
if(nivel != 3)		matriz[st.fil + 3][st.col - 2] = terreno[11];
if(nivel != 3)		matriz[st.fil + 3][st.col - 3] = terreno[12];
if(nivel != 3)		matriz[st.fil + 2][st.col - 3] = terreno[13];
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
if(nivel != 3)		matriz[st.fil + 2][st.col + 2] = terreno[6];
		matriz[st.fil + 2][st.col + 1] = terreno[7];
		matriz[st.fil + 2][st.col] = terreno[8];
		matriz[st.fil][st.col + 3] = terreno[9];
		matriz[st.fil + 1][st.col + 3] = terreno[10];
if(nivel != 3)		matriz[st.fil + 2][st.col + 3] = terreno[11];
if(nivel != 3)		matriz[st.fil + 3][st.col + 3] = terreno[12];
if(nivel != 3)		matriz[st.fil + 3][st.col + 2] = terreno[13];
		matriz[st.fil + 3][st.col + 1] = terreno[14];
		matriz[st.fil + 3][st.col] = terreno[15];
		break;
	default:
		matriz[st.fil][st.col] = terreno[0];
		break;
	}
}

void ComportamientoJugador::reinicio(int &fil, int &col, state &st, bool &girarDerecha, bool &orientado, Sensores &sensores,vector<vector<unsigned char>> &mapa){
	fil = 99;
	col = 99;
	last_action = actIDLE;
	current_state.brujula = norte;
	orientado = false;
	for(int i = 0; i < mapa.size();i++){
		for(int j = 0; j < mapa.size();j++){
			mapa[i][j] = '?';
		}
	}
}
/**
 * COSAS A mejorar:
 * -->solucionar el poner las cosas en la matriz para nv 3.
 * Mirar como ir por casillas y explorando..
 * -->hacer pulgacito
*/
Action ComportamientoJugador::think(Sensores sensores) {	
	Action accion = actIDLE;
	int a;
	mapaPulgarcito[current_state.fil][current_state.col] = instante;
    cout << "Instante: " << instante << endl;
	instante++;
	tiempo --;
	voyagiraren --;
	if(voyagiraren < 0){
		voyagiraren = rand()%30+3;	
	}
	if(voyagiraren2 < 0){
		voyagiraren2 = rand()%50+3;	
	}
	if(tiempo < 0){
		tiempo = rand()%20+5;
	}
	if(sensores.reset){
		reinicio(current_state.fil,current_state.col,current_state,girar_derecha,bien_situado,sensores,mapaAux);
	}
	if(!sensores.colision){
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
			switch (current_state.brujula){
				case norte: 
					current_state.fil-=2; 
					break;
				case noreste: 
					current_state.fil-=2; 
					current_state.col+=2; 
					break;
				case este: 
					current_state.col+=2; 
					break;
				case sureste:
					current_state.fil+=2; 
					current_state.col+=2; 
					break;
				case sur: 
					current_state.fil+=2;
					break;
				case suroeste: 
					current_state.fil+=2; 
					current_state.col-=2; 
					break;
				case oeste:
					current_state.col-=2; 
					break;
				case noroeste: 
					current_state.fil-=2; 
					current_state.col-=2; 
					break;
			}
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
	}
	if(!bien_situado){
		accion = buscarOrientacion(sensores);
		PonerTerrenoEnMatrizAux(sensores.terreno,current_state,mapaAux, sensores.nivel);
	}
	//cuando está en nivel 0....
	if (sensores.posF != -1 and !bien_situado){
		int fil = current_state.fil - sensores.posF;
		int col = current_state.col - sensores.posC;
		int diferencia = (current_state.brujula - sensores.sentido + 8)%8;
		cout << diferencia << endl;
        if (diferencia==0) PonerTerrenoEnMapa(mapaResultado,current_state,mapaAux,fil,col);
		//if(sensores.nivel != 3) PonerTerrenoEnMapa(mapaResultado,current_state,mapaAux,fil,col);
		//else if(sensores.nivel == 3 && diferencia == 0) PonerTerrenoEnMapa(mapaResultado,current_state,mapaAux,fil,col);
		//else PonerTerrenoEnMapaN3(mapaResultado,current_state,mapaAux,fil,col,diferencia);

		current_state.fil = sensores.posF;
		current_state.col= sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;
		int size = mapaResultado.size();
		for(int i = 0; i < size; i++){
		    for(int j = 0; j < 3; j++){
         		mapaResultado[i][j] = 'P';
			    mapaResultado[i][size-j-1] = 'P';
			    mapaResultado[j][i] = 'P';
			    mapaResultado[size-j-1][i] = 'P';
			}
		}
	}
	if(sensores.nivel == 0){
		current_state.fil = sensores.posF;
		current_state.col= sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;
	}
	if(sensores.terreno[0] == 'K' && !tieneBikini){
		tieneBikini = true;
	}
	if(sensores.terreno[0] == 'D' && !tieneZapas){
		tieneZapas = true;
	}

	if(bien_situado){
		PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado, sensores.nivel);
	}
	

	if((sensores.terreno[2] == 'T' ||  sensores.terreno[2] == 'S' || sensores.terreno[2] == 'G' || sensores.terreno[2] == 'K' || sensores.terreno[2] == 'D') && sensores.agentes[2] == '_'){
		if(voyagiraren == 0 || voyagiraren2 == 0){
			if(!girar_derecha){
				accion = actTURN_L;

				girar_derecha = (rand()%2 == 0);
				if(necesitoGirar){
					accion = actTURN_SR;
				}
				necesitoGirar = (rand()%2 == 0);
			}
			else{
				accion = actTURN_SR;
				girar_derecha = (rand()%2 == 0);
			}
		}
		else accion = actWALK;
	}
	//detecta una nueva acción
	if(accion == actIDLE){
		if(sensores.terreno[2] == 'X'){
			accion = actWALK;
		}
		else if(sensores.terreno[0] == 'X' && sensores.bateria < 3000){
			accion = actIDLE;
		}
		if(tieneBikini && sensores.terreno[2] == 'A')
			accion = actWALK;
		else if(tieneZapas && sensores.terreno[2] == 'B')
			accion = actWALK;
		else if(sensores.terreno[0] == 'B' && !tieneZapas){
			tiempoEspera++;
			accion = actTURN_SR;
			if(tiempoEspera>3){
				if(sensores.terreno[2] != 'P' || sensores.terreno[2] != 'M'){
					accion = actWALK;
					tiempoEspera = 0;
				}
				else accion = actTURN_SR;
			}
		}
		else if(sensores.terreno[0] == 'A' && !tieneBikini){
			tiempoEspera++;
			accion = actTURN_SR;
			if(tiempoEspera>3){
				if(sensores.terreno[2] != 'P' || sensores.terreno[2] != 'M'){
					accion = actWALK;
					tiempoEspera = 0;
				}
				else accion = actTURN_SR;
			}
		}
		else if(!girar_derecha){
			accion = actTURN_L;
			girar_derecha = (rand()%2 == 0);
		}
		else{
			accion = actTURN_SR;
			girar_derecha = (rand()%2 == 0);
	}
	}
	if(sensores.agentes[2] == 'l'){
				if(!girar_derecha){
			accion = actTURN_L;
			
			girar_derecha = (rand()%2 == 0);
			if(necesitoGirar){
				accion = actTURN_SR;
			}
			necesitoGirar = (rand()%2 == 0);
		}
		else{
			accion = actTURN_SR;
			girar_derecha = (rand()%2 == 0);
		}
	}
	if(sensores.agentes[2] == 'a'){
				if(!girar_derecha){
			accion = actTURN_L;
			
			girar_derecha = (rand()%2 == 0);
			if(necesitoGirar){
				accion = actTURN_SR;
			}
			necesitoGirar = (rand()%2 == 0);
		}
		else{
			accion = actTURN_SR;
			girar_derecha = (rand()%2 == 0);
		}
	}
	if(sensores.colision){
		if(sensores.terreno[2] == 'M'){
		if(!girar_derecha){
			accion = actTURN_L;
			
			girar_derecha = (rand()%2 == 0);
			if(necesitoGirar){
				accion = actTURN_SR;
			}
			necesitoGirar = (rand()%2 == 0);
		}
		else{
			accion = actTURN_SR;
			girar_derecha = (rand()%2 == 0);
		}
		}
		else{
			accion = actWALK;
		}
	}
	
	//Recordar la ultima acción
	last_action = accion;
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}


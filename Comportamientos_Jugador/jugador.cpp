#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

Action ComportamientoJugador::buscarSinDescubrir(Sensores &sensores){
	Action accion;
	switch(current_state.brujula){
		 case norte:
			 if(mapaPulgarcito[current_state.fil-1][current_state.col] < mapaPulgarcito[current_state.fil-1][current_state.col-1]){
				if(mapaPulgarcito[current_state.fil-1][current_state.col] < mapaPulgarcito[current_state.fil-1][current_state.col+1])
				accion = actWALK;
			 }
			 else if(mapaPulgarcito[current_state.fil+1][current_state.col+1] < mapaPulgarcito[current_state.fil+1][current_state.col-1]){
				if(mapaPulgarcito[current_state.fil+ 1][current_state.col+1] < mapaPulgarcito[current_state.fil+1][current_state.col])
				accion = actTURN_SR;
			 }
			 else accion = actTURN_L ;
			 break;
		 case sur:
			 if(mapaPulgarcito[current_state.fil+1][current_state.col] < mapaPulgarcito[current_state.fil+1][current_state.col+1]){
			 if(mapaPulgarcito[current_state.fil+1][current_state.col] < mapaPulgarcito[current_state.fil+1][current_state.col-1])
			 accion = actWALK;
			 }
			 else if(mapaPulgarcito[current_state.fil-1][current_state.col-1] < mapaPulgarcito[current_state.fil-1][current_state.col+1]){
			 if(mapaPulgarcito[current_state.fil-1][current_state.col-1] < mapaPulgarcito[current_state.fil-1][current_state.col])
			 accion = actTURN_SR;
			 }
			 else accion = actTURN_L;
			 break;
		 case este:
			 if(mapaPulgarcito[current_state.fil-1][current_state.col+1] < mapaPulgarcito[current_state.fil][current_state.col+1]){
			 if(mapaPulgarcito[current_state.fil-1][current_state.col+1] < mapaPulgarcito[current_state.fil+1][current_state.col+1])
			 accion = actWALK;
			 }
			 else if(mapaPulgarcito[current_state.fil][current_state.col-1] < mapaPulgarcito[current_state.fil+1][current_state.col-1]){
			 if(mapaPulgarcito[current_state.fil][current_state.col-1] < mapaPulgarcito[current_state.fil-1][current_state.col-1])
			 accion = actTURN_SR;
			 }
			 else accion = actTURN_L;
			 break;
		 case oeste:
			 if(mapaPulgarcito[current_state.fil+1][current_state.col-1] < mapaPulgarcito[current_state.fil][current_state.col-1]){
			 if(mapaPulgarcito[current_state.fil-1][current_state.col-1] < mapaPulgarcito[current_state.fil-1][current_state.col-1])
			 accion = actWALK;
			 }
			 else if(mapaPulgarcito[current_state.fil][current_state.col+1] < mapaPulgarcito[current_state.fil-1][current_state.col+1]){
				if(mapaPulgarcito[current_state.fil][current_state.col+1] < mapaPulgarcito[current_state.fil+1][current_state.col+1])
				accion = actTURN_SR; //REVISAR
			 }
			 else accion = actTURN_L;
			 break;
		 case noreste:
			 if(mapaPulgarcito[current_state.fil-1][current_state.col] < mapaPulgarcito[current_state.fil-1][current_state.col+1]){
			 if(mapaPulgarcito[current_state.fil-1][current_state.col] < mapaPulgarcito[current_state.fil-1][current_state.col+1])
			 accion = actWALK;
			 }
			 else if(mapaPulgarcito[current_state.fil+1][current_state.col-1] < mapaPulgarcito[current_state.fil+1][current_state.col]){
			 if(mapaPulgarcito[current_state.fil+1][current_state.col-1] < mapaPulgarcito[current_state.fil][current_state.col-1])
			 accion = actTURN_SR;
			 }
			 else accion = actTURN_L;
			 break;
		 case noroeste:
			 if(mapaPulgarcito[current_state.fil][current_state.col-1] < mapaPulgarcito[current_state.fil-1][current_state.col-1]){
			 if(mapaPulgarcito[current_state.fil][current_state.col-1] < mapaPulgarcito[current_state.fil-1][current_state.col])
			 accion = actWALK;
			 }
			 else if(mapaPulgarcito[current_state.fil+1][current_state.col] < mapaPulgarcito[current_state.fil+1][current_state.col+1]){
			 if(mapaPulgarcito[current_state.fil+1][current_state.col] < mapaPulgarcito[current_state.fil][current_state.col+1])
			 accion = actTURN_SR;
			 }
			 else accion = actTURN_L;
			 break;
		 case sureste:
			 if(mapaPulgarcito[current_state.fil][current_state.col-1] < mapaPulgarcito[current_state.fil-1][current_state.col-1]){
			 if(mapaPulgarcito[current_state.fil][current_state.col-1] < mapaPulgarcito[current_state.fil-1][current_state.col])
			 accion = actWALK;
			 }
			 else if(mapaPulgarcito[current_state.fil+1][current_state.col+1] < mapaPulgarcito[current_state.fil][current_state.col+1]){
			 if(mapaPulgarcito[current_state.fil+1][current_state.col+1] < mapaPulgarcito[current_state.fil+1][current_state.col])
			 accion = actTURN_SR;
			 }
			 else accion = actTURN_L;
			 break;
		 case suroeste:
			 if(mapaPulgarcito[current_state.fil+1][current_state.col] < mapaPulgarcito[current_state.fil+1][current_state.col-1]){
			 if(mapaPulgarcito[current_state.fil+1][current_state.col] < mapaPulgarcito[current_state.fil][current_state.col-1])
			 accion = actWALK;
			 }
			 else if(mapaPulgarcito[current_state.fil-1][current_state.col+1] < mapaPulgarcito[current_state.fil-1][current_state.col+1]){
			 if(mapaPulgarcito[current_state.fil-1][current_state.col+1] < mapaPulgarcito[current_state.fil][current_state.col+1])
			 accion = actTURN_SR;
			 }
			 else accion = actTURN_L;
			 break;
		 default:
			 accion = actIDLE;
			 break;
	}
	return accion;
}
Action ComportamientoJugador::buscarOrientacion(Sensores &sensores){
	Action accion;
<<<<<<< HEAD
	if(sensores.terreno[1] == 'G'){
		accion = actTURN_L;
		cout << "he visto una G" << endl;
	//	char ch; cin >> ch;	
	}
	/*else if(necesitoGirar){		accion = actTURN_SR;		necesitoGirar = false;	}
	*/else if(sensores.terreno[3] == 'G' || sensores.terreno[7] == 'G' || sensores.terreno[8] == 'G' || sensores.terreno[14] == 'G' || sensores.terreno[15] == 'G')	
=======
	if(sensores.terreno[1] == 'G') 
		accion = actTURN_L;
	if(sensores.terreno[4] == 'G' || sensores.terreno[9] == 'G' || sensores.terreno[10] == 'G' || sensores.terreno[11] == 'G'){
		necesitoGirar = true;
		accion = actTURN_L;
	}
	else if(necesitoGirar){
		accion = actTURN_SR;
		necesitoGirar = false;
	}
	else if(sensores.terreno[3] == 'G' || sensores.terreno[7] == 'G' || sensores.terreno[8] == 'G' || sensores.terreno[14] == 'G' || sensores.terreno[15] == 'G')	
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
		accion = actTURN_SR;
	else if(sensores.terreno[2] == 'G' || sensores.terreno[6] == 'G' || sensores.terreno[12] == 'G')		
		accion = actWALK;
	else 
		accion = actIDLE;
	return accion;
}
<<<<<<< HEAD
<<<<<<< HEAD
void ComportamientoJugador::PonerTerrenoEnMapa(vector<vector<unsigned char>> &mapaResultado, const state &st, vector<vector<unsigned char>> &mapaAux){
	for(int i = 0; i < mapaResultado.size();i++){
		for(int j = 0; j < mapaResultado.size();j++){
			if(mapaAux[st.fil+i][st.col+j]!='?' and mapaAux[st.fil+i][st.col+j]!=mapaResultado[i][j])
				mapaResultado[i][j]=mapaAux[st.fil+i][st.col+j];
		}
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
void ComportamientoJugador::PonerTerrenoEnMatrizAux(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz, const int nivel){
=======
=======

void ComportamientoJugador::PonerTerrenoEnMapa(vector<vector<unsigned char>> &mapaResultado, const state &st, vector<vector<unsigned char>> &mapaAux){
	for(int i = 0; i < mapaResultado.size();i++){
		for(int j = 0; j < mapaResultado.size();j++){
			if(mapaAux[st.fil+i][st.col+j] != '?'){
				mapaResultado[i][j] = mapaAux[st.fil+i][st.col+j];
			}
		}
	}
}
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
void ComportamientoJugador::PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz){
>>>>>>> 4d2c046 (v2,ahora van todos los niveles, queda mejorar cosas)
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
<<<<<<< HEAD
<<<<<<< HEAD
Action ComportamientoJugador::girar(){
}
void ComportamientoJugador::reinicio(int &fil, int &col, state &st, bool &girarDerecha, bool &orientado, Sensores &sensores,vector<vector<unsigned char>> &mapa){
=======

=======
void ComportamientoJugador::PonerTerrenoEnMatrizAux(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz){
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
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
Action ComportamientoJugador::girar(){
	if(!girar_derecha){
		girar_derecha = (rand()%2 == 0);
		return actTURN_L;
	}
	else{
		girar_derecha = (rand()%2 == 0);
		return actTURN_SR;
	}
}
<<<<<<< HEAD
void ComportamientoJugador::reinicio(int &fil, int &col, state &st, bool &girarDerecha, bool &orientado, Sensores &sensores){
>>>>>>> 4d2c046 (v2,ahora van todos los niveles, queda mejorar cosas)
=======
void ComportamientoJugador::reinicio(int &fil, int &col, state &st, bool &girarDerecha, bool &orientado, Sensores &sensores,vector<vector<unsigned char>> &mapa){
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
	fil = 99;
	col = 99;
	last_action = actIDLE;
	current_state.brujula = norte;
	orientado = false;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
	for(int i = 0; i < mapa.size();i++){
		for(int j = 0; j < mapa.size();j++){
			mapa[i][j] = '?';
		}
	}
<<<<<<< HEAD
=======
>>>>>>> 4d2c046 (v2,ahora van todos los niveles, queda mejorar cosas)
=======
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
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
<<<<<<< HEAD
	mapaPulgarcito[current_state.fil][current_state.col] = instante;
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
=======
	if(sensores.reset){
<<<<<<< HEAD
		reinicio(current_state.fil,current_state.col,current_state,girar_derecha,bien_situado,sensores);
>>>>>>> 4d2c046 (v2,ahora van todos los niveles, queda mejorar cosas)
=======
		reinicio(current_state.fil,current_state.col,current_state,girar_derecha,bien_situado,sensores,mapaAux);
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
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
<<<<<<< HEAD
	if(!bien_situado){
		accion = buscarOrientacion(sensores);
		PonerTerrenoEnMatrizAux(sensores.terreno,current_state,mapaAux, sensores.nivel);
	}
=======
>>>>>>> 4d2c046 (v2,ahora van todos los niveles, queda mejorar cosas)
	//cuando está en nivel 0....
	if (sensores.posF!=-1 and !bien_situado){
<<<<<<< HEAD
		current_state.fil = current_state.fil - sensores.posF;
		current_state.col = current_state.col - sensores.posC;
		cout << current_state.fil << " , " << current_state.col << endl;
		PonerTerrenoEnMapa(mapaResultado,current_state,mapaAux);
=======
		current_state.fil -= sensores.posF;
		current_state.col -= sensores.posC;
		cout << current_state.fil << " , " << current_state.col << endl;
		PonerTerrenoEnMapa(mapaResultado,current_state,mapaAux);
		/*
		st.fil = fil2-fil
		st.col = col2-col
		AHora se hace el traspaso
		y después actualiza
		*/
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
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
<<<<<<< HEAD

=======
	if(!bien_situado){
		accion = buscarOrientacion(sensores);
		PonerTerrenoEnMatrizAux(sensores.terreno,current_state,mapaAux);
	}
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
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
		/*else if(tiempo == 0){
			//accion = buscarSinDescubrir(sensores);
			accion = girar();
			tiempo = rand()%20 + 10;
		}*/
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
<<<<<<< HEAD
=======
	if(sensores.agentes[2] == 'l'){
		accion = girar();
	}
	if(sensores.agentes[2] == 'a'){
		accion = girar();
	}
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
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


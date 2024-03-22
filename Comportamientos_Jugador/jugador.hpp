#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

struct state{
  int fil;
  int col;
  Orientacion brujula;
};

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      current_state.fil = 99;
      current_state.col = 99;
      current_state.brujula = norte;
      last_action = actIDLE;
      for(int i = 0; i < size; i++){
		    for(int j = 0; j < 3; j++){
			    mapaResultado[i][j] = 'P';
			    mapaResultado[i][size-j-1] = 'P';
			    mapaResultado[j][i] = 'P';
			    mapaResultado[size-j-1][i] = 'P';
		    }
	    }
    }
    

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}
    //funcion para reiniciar
    void reinicio(int &fil, int &col,state &st, bool &girarDerecha, bool &orientado, Sensores &sensores);    
    Action girar();
   //Función para poner el terreno en matriz
    void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz);
    //Cuando no se orienta poner lo que se ha visitado sin saber su orientacion
    void PonerTerrenoEnMapa(vector<vector<unsigned char>> &mapaResultado, vector<vector<unsigned char>> &mapaAux);
    //Busca una casilla de "orientacion"
    Action buscarOrientacion(Sensores &sensores);
    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  // Declarar aquí las variables de estado
  //int mapaAux[200][200]; 
  //vector<vector<unsigned char>> mapaAux;
  int instante;
  state current_state;
  Orientacion brujula;
  Action last_action;
  bool girar_derecha = false;
  bool bien_situado = false;
  bool tieneBikini = false;
  bool tieneZapas = false;
};
#endif

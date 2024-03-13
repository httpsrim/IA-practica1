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
      /* Esto para que vaya guardando las cosas cuando no esté bien posicionado y se lo pase a mapaResultado cuando ya si este posicionado.
      
      for(int i = 0; i < size;i++){
        for(int j = 0 ; j < size; j++){
          mapaResultado[i][j] = mapaGenerado[i][j];
        }
      }
      */
    

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}
    //Función para poner el terreno en matriz
    void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz);
    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  // Declarar aquí las variables de estado
  state current_state;
  Orientacion brujula;
  Action last_action;
  bool girar_derecha = false;
  bool bien_situado = false;
  bool tieneBikini = false;
  bool tieneZapas = false;
  unsigned int tamMapa;
};
#endif

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
      vector<unsigned char>aux(400,'?');
      for(int i = 0; i < 400;i++){
        mapaAux.push_back(aux);
      }
      /*for(int i = 0; i < size; i++)
        for(int j = 0 ; j < 200; j++)
          mapaPulgarcito[i][j] = 0;
      */for(int i = 0; i < size; i++){
		    for(int j = 0; j < 3; j++){
          mapaResultado[i][j] = 'P';
			    mapaResultado[i][size-j-1] = 'P';
			    mapaResultado[j][i] = 'P';
			    mapaResultado[size-j-1][i] = 'P';
       //   mapaAux[i][j] = 'P';
			 //   mapaAux[i][size-j-1] = 'P';
			 //   mapaAux[j][i] = 'P';
			 //   mapaAux[size-j-1][i] = 'P';
        }
	    }
      instante = 1;
      voyagiraren = 10;
      voyagiraren2 = 20;
      tiempo = 100;

    }
    
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}
    //funcion para reiniciar
    void reinicio(int &fil, int &col,state &st, bool &girarDerecha, bool &orientado, Sensores &sensores, vector<vector<unsigned char>> &mapa);    
    Action girar();
   //Función para poner el terreno en matriz
    void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz, const int nivel);
       //Función para poner el terreno en matriz Aux
    void PonerTerrenoEnMatrizAux(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz, const int nivel);
    //Cuando no se orienta poner lo que se ha visitado sin saber su orientacion
    void PonerTerrenoEnMapa(vector<vector<unsigned char>> &mapaResultado, const state &st, vector<vector<unsigned char>> &mapaAux, int fil, int col);
    //Busca una casilla de "orientacion"
    Action buscarOrientacion(Sensores &sensores);
    //Busca una casilla de "Zapatillas"
    Action buscarZapas(Sensores &sensores);
    //Busca una casilla de "bikini"
    Action buscarBikini(Sensores &sensores);
    //Buscar sin descubrir
    Action buscarSinDescubrir(Sensores &sensores);
    //devuelve el coste de la casilla
    int costeCasilla(Sensores &sensores);
    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    
  private:
  // Declarar aquí las variables de estado
  vector<vector<unsigned char>> mapaAux;
  int instante;
  int mapaPulgarcito[200][200];
  int costeIzq, costeDcho, costeDelante;
  int voyagiraren, voyagiraren2, tiempo;
  int tiempoEspera = 0;
  state current_state;
  Orientacion brujula;
  Action last_action;
  bool girar_derecha = false;
  bool bien_situado = false;
  bool tieneBikini = false;
  bool tieneZapas = false;
  bool necesitoGirar = false;
  bool masAdelante = false;
  bool correr = false;
  bool necesitoIzquierda = false;
};
#endif
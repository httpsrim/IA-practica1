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
      vector<unsigned char>aux(200,'?');
      for(int i = 0; i < 200;i++){
        mapaAux.push_back(aux);
      }
<<<<<<< HEAD
      for(int i = 0; i < 200; i++)
        for(int j = 0 ; j < 200; j++)
          mapaPulgarcito[i][j] = 0;
      for(int i = 0; i < size; i++){
		    for(int j = 0; j < 3; j++){
          mapaResultado[i][j] = 'P';
			    mapaResultado[i][size-j-1] = 'P';
			    mapaResultado[j][i] = 'P';
			    mapaResultado[size-j-1][i] = 'P';
=======
      for(int i = 0; i < size; i++){
		    for(int j = 0; j < 3; j++){
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
          mapaAux[i][j] = 'P';
			    mapaAux[i][size-j-1] = 'P';
			    mapaAux[j][i] = 'P';
			    mapaAux[size-j-1][i] = 'P';
<<<<<<< HEAD
          mapaPulgarcito[i][j] = 10000;
          mapaPulgarcito[i][size-j-1] = 10000;
          mapaPulgarcito[j][i] = 10000;
        }
=======
		    }
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
	    }
<<<<<<< HEAD
      instante = 1;
      voyagiraren = 10;
      voyagiraren2 = 20;
      tiempo = 100;
=======
    }
    
<<<<<<< HEAD
>>>>>>> 4d2c046 (v2,ahora van todos los niveles, queda mejorar cosas)

    }
    
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}
    //funcion para reiniciar
<<<<<<< HEAD
    void reinicio(int &fil, int &col,state &st, bool &girarDerecha, bool &orientado, Sensores &sensores, vector<vector<unsigned char>> &mapa);    
    Action girar();
   //Función para poner el terreno en matriz
    void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz, const int nivel);
       //Función para poner el terreno en matriz Aux
    void PonerTerrenoEnMatrizAux(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz, const int nivel);
    //Cuando no se orienta poner lo que se ha visitado sin saber su orientacion
    void PonerTerrenoEnMapa(vector<vector<unsigned char>> &mapaResultado, const state &st, vector<vector<unsigned char>> &mapaAux);
=======
    void reinicio(int &fil, int &col,state &st, bool &girarDerecha, bool &orientado, Sensores &sensores);    
=======
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}
    //funcion para reiniciar
    void reinicio(int &fil, int &col,state &st, bool &girarDerecha, bool &orientado, Sensores &sensores, vector<vector<unsigned char>> &mapa);    
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
    Action girar();
   //Función para poner el terreno en matriz
    void PonerTerrenoEnMatriz(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz);
       //Función para poner el terreno en matriz Aux
    void PonerTerrenoEnMatrizAux(const vector<unsigned char> &terreno, const state &st, vector<vector<unsigned char>> &matriz);
    //Cuando no se orienta poner lo que se ha visitado sin saber su orientacion
<<<<<<< HEAD
    void PonerTerrenoEnMapa(vector<vector<unsigned char>> &mapaResultado, vector<vector<unsigned char>> &mapaAux);
>>>>>>> 4d2c046 (v2,ahora van todos los niveles, queda mejorar cosas)
=======
    void PonerTerrenoEnMapa(vector<vector<unsigned char>> &mapaResultado, const state &st, vector<vector<unsigned char>> &mapaAux);
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
    //Busca una casilla de "orientacion"
    Action buscarOrientacion(Sensores &sensores);
    //Buscar sin descubrir
    Action buscarSinDescubrir(Sensores &sensores);
    
    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  // Declarar aquí las variables de estado
<<<<<<< HEAD
<<<<<<< HEAD
  vector<vector<unsigned char>> mapaAux;
  int instante;
  int mapaPulgarcito[200][200];
  int voyagiraren, voyagiraren2, tiempo;
=======
  //int mapaAux[200][200]; 
  //vector<vector<unsigned char>> mapaAux;
=======
 
	vector<vector<unsigned char>> mapaAux;
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
  int instante;
>>>>>>> 4d2c046 (v2,ahora van todos los niveles, queda mejorar cosas)
  state current_state;
  Orientacion brujula;
  Action last_action;
  bool girar_derecha = false;
  bool bien_situado = false;
  bool tieneBikini = false;
  bool tieneZapas = false;
  bool necesitoGirar = false;
<<<<<<< HEAD
  bool primera = false;
=======
>>>>>>> 5642f77 (Version 3, he conseguido que vaya la matriz aux para que guarde por donde va)
};
#endif

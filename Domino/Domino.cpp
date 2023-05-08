#include"FuncionesDomino.h"
using namespace std;


int main()
{
	//Declaracion de variables y vectores necesarios**********
	srand(time(NULL)); //semilla para el aleatorio.
	int aleatorio, numeroManoJugador, error = 0, fichainvalida=0, contadorRondTablero = 1, contadormasMas =0;
	int jugador1, jugador2, jugador3, jugador4, pasa1=0, pasa2 = 0, pasa3 = 0, pasa4 = 0,sumaPasa=0;
	bool gano = false;
	char jugarOtra;
	Fichas vectorFichas[28];
	Fichas fichasJugador1[7];
	Fichas fichasJugador2[7];
	Fichas fichasJugador3[7];
	Fichas fichasJugador4[7];
	Fichas tablero[28];
	//*************************************
	do {
		//Introduccion al juego**********************
		cout << "\n\n\t\t\t\t\t******* Binvenido al juego del domino *******\n\n";
		cout << "\t\t En esta ocacion habran 4 jugadores las fichas se repartiran de forma automatica y luego empeazara el juego.\n\n";
		cout << "\t\t La ficha | 6 | 6 | sera la primera en iniciar el sistema se encargara de iniciar con esta ficha.\n\n";
		cout << "\t\t\t\t \t******* Mucha Suerte a los jugadores *******\n\n";
		system("pause");
		system("cls");

		//lleno el tablero para irlo modificando
		llenarTablero(tablero);
		//Funciones para crear mostrar buscar Mula y repartir las 7 fichas a cada jugador.*********
		crearFichas(vectorFichas);
		repartirFichas(vectorFichas, fichasJugador1);
		jugador1 = laMula(tablero, fichasJugador1);
		repartirFichas(vectorFichas, fichasJugador2);
		jugador2 = laMula(tablero, fichasJugador2);
		repartirFichas(vectorFichas, fichasJugador3);
		jugador3 = laMula(tablero, fichasJugador3);
		repartirFichas(vectorFichas, fichasJugador4);
		jugador4 = laMula(tablero, fichasJugador4);
		//************************************

		while (gano == false) {
			//JUGADOR 1
			if (jugador1 == 1) {
				jugador2 = 1;
				jugador3 = 1;
				jugador4 = 1;
				cout << "\n";
				system("cls");
				mostrarTablero(tablero, contadorRondTablero);
				do {
					cout << "\n\n\n\t\t*****Fichas del jugador 1*****\n\n";
					mostrarFichasJugador(fichasJugador1);
					cout << "\nFicha 0 - Ficha 1 - Ficha 2 - Ficha 3 - Ficha 4 - Ficha 5 - Ficha 6 \n";
					cout << "\n\n";
					error = 0;
					cout << "\nPara elegir una ficha digite un numero del 0 al 6 o 7 para pasar el turno."
						<< "\nLas fichas que posean doble 7 no pueden ser utilizadas\n\n";
					cin >> numeroManoJugador;
					if (numeroManoJugador < 0 || numeroManoJugador>7 || fichasJugador1[numeroManoJugador].ladoderecho == 7) {
						cout << "\nFicha invalida intente de nuevo\n";
						int error = 1;
					}
					else if (numeroManoJugador == 7)
					{
						pasa1 = 1;
						error = 0;
						fichainvalida = 0;
					}
					else {
						fichainvalida = jugadaJugador(numeroManoJugador, fichasJugador1, tablero);
						if (fichainvalida == 0) {
							contadorRondTablero++;
						}
					}
					if (fichainvalida == 0) {
						error = 0;
					}
				} while (error == 1 || fichainvalida == 1);
				gano = ganarSinFichas(fichasJugador1);
				sumaPasa = pasa1 + pasa2 + pasa3 + pasa4;
				if (sumaPasa == 4) {
					cout << "\nTodos los jugadores han pasado\n";
					SumaManoMenorGana(fichasJugador1, fichasJugador2, fichasJugador3, fichasJugador4);
					gano = true;
					jugador1 = 0;
					jugador2 = 0;
					jugador3 = 0;
					jugador4 = 0;
				}
				cout << "\n";
				system("pause");
			}
			//JUGADOR 2
			if (jugador2 == 1) {
				jugador1 = 1;
				jugador3 = 1;
				jugador4 = 1;
				system("cls");
				mostrarTablero(tablero, contadorRondTablero);
				do {
					cout << "\n\n\n\t\t*****Fichas del jugador 2*****\n\n";
					mostrarFichasJugador(fichasJugador2);
					cout << "\nFicha 0 - Ficha 1 - Ficha 2 - Ficha 3 - Ficha 4 - Ficha 5 - Ficha 6 \n";
					cout << "\n\n";
					error = 0;
					cout << "\nPara elegir una ficha digite un numero del 0 al 6 o 7 para pasar el turno."
						<< "\nLas fichas que posean doble 7 no pueden ser utilizadas\n\n";
					cin >> numeroManoJugador;
					if (numeroManoJugador < 0 || numeroManoJugador>7 || fichasJugador2[numeroManoJugador].ladoderecho == 7) {
						cout << "\nFicha invalida intente de nuevo\n";
						int error = 1;
					}
					else if (numeroManoJugador == 7) {
						pasa2 = 1;
						error = 0;
						fichainvalida = 0;
					}
					else {
						fichainvalida = jugadaJugador(numeroManoJugador, fichasJugador2, tablero);
						if (fichainvalida == 0) {
							contadorRondTablero++;
						}
					}
					if (fichainvalida == 0) {
						error = 0;
					}
				} while (error == 1 || fichainvalida == 1);
				gano = ganarSinFichas(fichasJugador2);
				sumaPasa = pasa1 + pasa2 + pasa3 + pasa4;
				if (sumaPasa == 4) {
					cout << "\nTodos los jugadores han pasado\n";
					SumaManoMenorGana(fichasJugador1, fichasJugador2, fichasJugador3, fichasJugador4);
					gano = true;
					jugador1 = 0;
					jugador2 = 0;
					jugador3 = 0;
					jugador4 = 0;
				}
				cout << "\n";
				system("pause");
			}
		
			//JUGADOR 3
			if (jugador3 == 1) {
				jugador1 = 1;
				jugador2 = 1;
				jugador4 = 1;
				system("cls");
				mostrarTablero(tablero, contadorRondTablero);
				do {
					cout << "\n\n\n\t\t*****Fichas del jugador 3*****\n\n";
					mostrarFichasJugador(fichasJugador3);
					cout << "\nFicha 0 - Ficha 1 - Ficha 2 - Ficha 3 - Ficha 4 - Ficha 5 - Ficha 6 \n";
					cout << "\n\n";
					error = 0;
					cout << "\nPara elegir una ficha digite un numero del 0 al 6 o 7 para pasar el turno."
						<< "\nLas fichas que posean doble 7 no pueden ser utilizadas\n\n";
					cin >> numeroManoJugador;
					if (numeroManoJugador < 0 || numeroManoJugador>7 || fichasJugador3[numeroManoJugador].ladoderecho == 7) {
						cout << "\nFicha invalida intente de nuevo\n";
						int error = 1;
					}
					else if (numeroManoJugador == 7) {
						pasa3 = 1;
						error = 0;
						fichainvalida = 0;
					}
					else {
						fichainvalida = jugadaJugador(numeroManoJugador, fichasJugador3, tablero);
						if (fichainvalida == 0) {
							contadorRondTablero++;
						}
					}
					if (fichainvalida == 0) {
						error = 0;
					}
				} while (error == 1 || fichainvalida == 1);
				gano = ganarSinFichas(fichasJugador3);
				sumaPasa = pasa1 + pasa2 + pasa3 + pasa4;
				if (sumaPasa == 4) {
					cout << "\nTodos los jugadores han pasado\n";
					SumaManoMenorGana(fichasJugador1, fichasJugador2, fichasJugador3, fichasJugador4);
					gano = true;
					jugador1 = 0;
					jugador2 = 0;
					jugador3 = 0;
					jugador4 = 0;
				}
				cout << "\n";
				system("pause");
			}

			//JUGADOR 4
			if (jugador4 == 1) {
				jugador1 = 1;
				jugador2 = 1;
				jugador3 = 1;
				system("cls");
				mostrarTablero(tablero, contadorRondTablero);
				do {
					cout << "\n\n\n\t\t*****Fichas del jugador 4*****\n\n";
					mostrarFichasJugador(fichasJugador4);
					cout << "\nFicha 0 - Ficha 1 - Ficha 2 - Ficha 3 - Ficha 4 - Ficha 5 - Ficha 6 \n";
					cout << "\n\n";
					error = 0;
					cout << "\nPara elegir una ficha digite un numero del 0 al 6 o 7 para pasar el turno."
						<< "\nLas fichas que posean doble 7 no pueden ser utilizadas\n\n";
					cin >> numeroManoJugador;
					if (numeroManoJugador < 0 || numeroManoJugador>7 || fichasJugador4[numeroManoJugador].ladoderecho == 7) {
						cout << "\nFicha invalida intente de nuevo\n";
						int error = 1;
					}
					else if (numeroManoJugador == 7) {
						pasa4 = 1;
						error = 0;
						fichainvalida = 0;
					}
					else {
						fichainvalida = jugadaJugador(numeroManoJugador, fichasJugador4, tablero);
						if (fichainvalida == 0) {
							contadorRondTablero++;
						}
					}
					if (fichainvalida == 0) {
						error = 0;
					}

				} while (error == 1 || fichainvalida == 1);
				gano = ganarSinFichas(fichasJugador4);
				sumaPasa = pasa1 + pasa2 + pasa3 + pasa4;
				if (sumaPasa == 4) {
					cout << "\nTodos los jugadores han pasado\n";
					SumaManoMenorGana(fichasJugador1, fichasJugador2, fichasJugador3, fichasJugador4);
					gano = true;
					jugador1 = 0;
					jugador2 = 0;
					jugador3 = 0;
					jugador4 = 0;
				}
				cout << "\n";
				system("pause");
			}
		}
		cout << "\n\nDesea jugar otra partida(S/N)\n";
		cin >> jugarOtra;
	}while (jugarOtra == 'S');
	system("pause");




	return 0;
};


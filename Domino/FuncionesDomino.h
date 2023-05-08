#pragma once
#include<iostream>
using namespace std;

struct Fichas {

	int ladoizquierdo;
	int ladoderecho;
};

void crearFichas(Fichas vectorFichas[]) {
	int contadorDerecho = 1;
	//fichas cero
	for (int i = 0; i < 7; i++)
	{
		if (i == 0) {
			vectorFichas[i].ladoizquierdo = 0;
			vectorFichas[i].ladoderecho = 0;
		}
		else {
			vectorFichas[i].ladoizquierdo = 0;
			vectorFichas[i].ladoderecho = i;
		}
	}
	//fichas uno
	for (int i = 7; i < 13; i++)
	{
		vectorFichas[i].ladoizquierdo = 1;
		vectorFichas[i].ladoderecho = contadorDerecho;
		contadorDerecho++;
	}
	//fichas dos
	contadorDerecho = 2;
	for (int i = 13; i < 18; i++)
	{
		vectorFichas[i].ladoizquierdo = 2;
		vectorFichas[i].ladoderecho = contadorDerecho;
		contadorDerecho++;
	}
	//fichas tres
	contadorDerecho = 3;
	for (int i = 18; i < 22; i++)
	{
		vectorFichas[i].ladoizquierdo = 3;
		vectorFichas[i].ladoderecho = contadorDerecho;
		contadorDerecho++;
	}
	//fichas cuatro
	contadorDerecho = 4;
	for (int i = 22; i < 25; i++)
	{
		vectorFichas[i].ladoizquierdo = 4;
		vectorFichas[i].ladoderecho = contadorDerecho;
		contadorDerecho++;
	}
	//fichas cinco
	contadorDerecho = 5;
	for (int i = 25; i < 28; i++)
	{
		vectorFichas[i].ladoizquierdo = 5;
		vectorFichas[i].ladoderecho = contadorDerecho;
		contadorDerecho++;
		if (i == 27) {
			vectorFichas[i].ladoizquierdo = 6;
			vectorFichas[i].ladoderecho = 6;
		}
	}
}

void mostrarFichas(Fichas vectorFichas[]) {

	for (int i = 0; i < 28; i++)
	{
		cout << "| " << vectorFichas[i].ladoizquierdo << "|" << vectorFichas[i].ladoderecho << " |\t";

		if (i == 6) {
			cout<<"\n\n";
		}
		if (i == 12) {
			cout << "\n\n";
		}
		if (i == 17) {
			cout << "\n\n";
		}
		if (i == 21) {
			cout << "\n\n";
		}
		if (i == 24) {
			cout << "\n\n";
		}
		if (i == 26) {
			cout << "\n\n";
		}
	}
	cout << "\n";
	system("pause");
}

void mostrarFichasJugador(struct Fichas fichasJugador1[]) {
	for (int i = 0; i < 7; i++)
	{
		cout << "| " << fichasJugador1[i].ladoizquierdo << "|" << fichasJugador1[i].ladoderecho << " |   ";
	}
}

void repartirFichas(struct Fichas vectorFichas[], struct Fichas	fichasJugador[]) {
	//llena el vector del jugador 1
	for (int i = 0; i < 7; i++)
	{
		int numeroAzar;
		int derecho, izquierdo;
		numeroAzar = rand() % 28;
		if (vectorFichas[numeroAzar].ladoizquierdo != 7) {
			derecho = vectorFichas[numeroAzar].ladoderecho;
			izquierdo = vectorFichas[numeroAzar].ladoizquierdo;
			fichasJugador[i].ladoderecho = derecho;
			fichasJugador[i].ladoizquierdo = izquierdo;
			vectorFichas[numeroAzar].ladoderecho = 7;
			vectorFichas[numeroAzar].ladoizquierdo = 7;
		}
		else {
			i--;
		}
	}
}

void llenarTablero(struct Fichas vectortablero[]) {
	for (int i = 0; i < 28; i++)
	{
		vectortablero[i].ladoderecho = 7;
		vectortablero[i].ladoizquierdo = 7;
	}
}

int laMula(struct Fichas vectortablero[], struct Fichas fichasJugador[]) {	
	for (int i = 0; i < 7 || i == false; i++)
	{
		if (fichasJugador[i].ladoderecho == 6 && fichasJugador[i].ladoizquierdo == 6) {
			vectortablero[0].ladoizquierdo = 6;
			vectortablero[0].ladoderecho = 6;
			fichasJugador[i].ladoizquierdo = 7;
			fichasJugador[i].ladoderecho = 7;
			i = true;
			int jugador = 1;
			return jugador;
		}
	}
}

int contador;
int jugadaJugador(int numeroJugador, struct Fichas fichasjugador[], struct Fichas vectorTablero[]) {
	if (vectorTablero[contador].ladoderecho == fichasjugador[numeroJugador].ladoderecho) {
		vectorTablero[contador +1].ladoizquierdo = fichasjugador[numeroJugador].ladoderecho;
		vectorTablero[contador+1].ladoderecho = fichasjugador[numeroJugador].ladoizquierdo;
		fichasjugador[numeroJugador].ladoderecho = 7;
		fichasjugador[numeroJugador].ladoizquierdo=7;
		contador= contador +1;
		return 0;
	}
	else if (vectorTablero[contador].ladoderecho == fichasjugador[numeroJugador].ladoizquierdo) {
		vectorTablero[contador+1].ladoizquierdo = fichasjugador[numeroJugador].ladoizquierdo;
		vectorTablero[contador+1].ladoderecho = fichasjugador[numeroJugador].ladoderecho;
		fichasjugador[numeroJugador].ladoderecho = 7;
		fichasjugador[numeroJugador].ladoizquierdo = 7;
		contador = contador+1;
		return 0;
	}
	else {
		cout << "\nFicha invalida\n";
		return 1;
	}
}

void mostrarTablero(struct Fichas vectorTablero[], int contadorRonda) {

	cout << "\n\n*******Este es el tablero que se esta llenando de forma horizontal*******\n\n";
	for (int i = 0;i < contadorRonda; i++)
	{
		cout << "| " << vectorTablero[i].ladoizquierdo << "|" << vectorTablero[i].ladoderecho << " |  ";
	}

}

bool ganarSinFichas(struct Fichas fichasJugador[]) {
	int suma=0;
	for (int i = 0; i < 7; i++)
	{
		suma= suma + fichasJugador[i].ladoderecho;
		
	}
	if (suma == 49) {
		cout << "\n\nTe has quedado sin fichas por lo tanto eres el ganador.\n";
		return true;

	}
	else {
		return false;
	}
}

void SumaManoMenorGana(struct Fichas fichasJugador1[], struct Fichas fichasJugador2[], struct Fichas fichasJugador3[], struct Fichas fichasJugador4[]){
	int sumaMano1 = 0, sumaMano2 = 0, sumaMano3 = 0, sumaMano4 = 0,menor=0;

	for (size_t i = 0; i < 7; i++)
	{
		sumaMano1 = sumaMano1 + fichasJugador1[i].ladoderecho + fichasJugador1[i].ladoizquierdo;
		sumaMano2 = sumaMano2 + fichasJugador2[i].ladoderecho + fichasJugador2[i].ladoizquierdo;
		sumaMano3 = sumaMano3 + fichasJugador3[i].ladoderecho + fichasJugador3[i].ladoizquierdo;
		sumaMano4 = sumaMano4 + fichasJugador4[i].ladoderecho + fichasJugador4[i].ladoizquierdo;
		if (sumaMano1 >menor)
		{
			menor = sumaMano1;
		}
		if (menor>sumaMano2)
		{
			menor = sumaMano2;
		}
		if (menor > sumaMano3) {
			menor = sumaMano3;
		}
		if (menor > sumaMano4) {
			menor = sumaMano4;
		}
	}
	if (menor == sumaMano1) {
		cout << "\nLa suma de la mano del jugador 1 es la menor por lo que ah ganado, sus puntos fueron: " << menor<< "\n";
	}
	if (menor == sumaMano2) {
		cout << "\nLa suma de la mano del jugador 2 es la menor por lo que ah ganado, sus puntos fueron: " << menor << "\n";
	}
	if (menor == sumaMano3) {
		cout << "\nLa suma de la mano del jugador 3 es la menor por lo que ah ganado, sus puntos fueron: " << menor << "\n";
	}
	if (menor == sumaMano4) {
		cout << "\nLa suma de la mano del jugador 4 es la menor por lo que ah ganado, sus puntos fueron: " << menor << "\n";
	}
}

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

class Matrix {
public:
		Matrix();
		/**
		Dodawanie do siebie dwoch macierzy.
		@param M1 Wysokosc macierzy1.
		@param N1 Szerokosc macierzy1.
		@param macierz1 Pierwsza macierz.
		@param M2 Wysokosc macierzy2.
		@param N2 Szerokosc macierzy2.
		@param macierz2 Druga macierz.
		@param macierz3 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int dodaj(int M1, int N1, double** macierz1, int M2, int N2, double** macierz2, double** macierz3);
		/**
		Odejmowanie od siebie dwoch macierzy.
		@param M1 Wysokosc macierzy1.
		@param N1 Szerokosc macierzy1.
		@param macierz1 Pierwsza macierz.
		@param M2 Wysokosc macierzy2.
		@param N2 Szerokosc macierzy2.
		@param macierz2 Druga macierz.
		@param macierz3 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int odejmij(int M1, int N1, double** macierz1, int M2, int N2, double** macierz2, double** macierz3);
		/**
		Mnozenie dwoch macierzy przez siebie.
		@param M1 Wysokosc macierzy1.
		@param N1 Szerokosc macierzy1.
		@param macierz1 Pierwsza macierz.
		@param M2 Wysokosc macierzy2.
		@param N2 Szerokosc macierzy2.
		@param macierz2 Druga macierz.
		@param macierz3 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int pomnoz(int M1, int N1, double** macierz1, int M2, int N2, double** macierz2, double** macierz3);
		/**
		Wyswietla macierz.
		@param M Wysokosc macierzy.
		@param N Szerokosc macierzy.
		@param macierz Macierz do wyswietlenia.
		@return Nie zwraca nic.
		*/
		void wyswietl(int M, int N, double** macierz);
		/**
		Oblicza wyznacznik macierzy.
		@param N Rozmiar macierzy.
		@param macierz Macierz, dla ktorej liczony jest wyznacznik.
		@return Wyznacznik.
		*/
		double wyznacznik(int N, double** macierz);
		/**
		Zwraca macierz trojkatna dolna rowna 0.
		@param N Rozmiar macierzy.
		@param macierz1 Macierz, dla ktorej zwracamy trojkat dolny rowny 0.
		@param macierz2 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int gauss(int N, double** macierz1, double** macierz2);
		/**
		Transponuje macierz MxN.
		@param M Wysokosc macierzy.
		@param N Szerokosc macierzy.
		@param macierz1 Macierz do transponowania.
		@param macierz2 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int macierz_transponowana(int M, int N, double** macierz1, double** macierz2);
		/**
		Zwraca dopelnienie macierzy o indeksach [index1][index2].
		@param N Rozmiar macierzy.
		@param index1 Pierwszy index tablicy.
		@param index2 Drugi index tablicy.
		@param macierz1 Macierz, dla ktorej szukamy dopelniania w miejscu [index1][index2].
		@param macierz2 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int dopelnienie(int N, int index1, int index2, double** macierz1, double** macierz2);
		/**
		Zwraca macierz dopelnien.
		@param N Rozmiar macierzy.
		@param macierz1 Macierz, dla której szukamy macierzy dopelnien.
		@param macierz2 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int macierz_dopelnien(int N, double** macierz1, double** macierz2);
		/**
		Zwraca macierz odwrotna.
		@param N Rozmiar macierzy.
		@param macierz1 Macierz, ktora odwracamy.
		@param macierz2 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int macierz_odwrotna(int N, double** macierz1, double** macierz2);
		/**
		Zwraca macierz dolaczona.
		@param N Rozmiar macierzy.
		@param macierz1 Macierz, dla ktorej szukamy macierzy dolaczonej.
		@param macierz2 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int macierz_dolaczona(int N, double** macierz1, double** macierz2);
		/**
		Zwraca slad macierzy.
		@param N Rozmiar macierzy.
		@param macierz Macierz, dla ktorej liczymy slad macierzy.
		@return Slad macierzy.
		*/
		double slad_macierzy(int N, double** macierz);
		/**
		Zwraca macierz diagonalna.
		@param N Rozmiar macierzy.
		@param macierz1 Macierz, ktora diagonalizujemy.
		@param macierz2 Macierz wynikowa.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int macierz_diagonalna(int N, double** macierz1, double** macierz2);
		/**
		Rozwiazywanie ukladu rownan liniowych.
		@param N Rozmiar pierwszej macierzy i drugiego wektora.
		@param macierz1 Pierwsza macierz.
		@param macierz2 Wektor wynikowy.
		@param macierz3 Wektor szukany.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int metoda_eliminacji_gaussa(int N, double** macierz1, double** macierz2, double** macierz3);
		/**
		Zapisuje macierz z pliku do wskaznika. Plik musi posiadac w pierwszej linii liczbe wierszy, w drugiej liczbe kolumn, a nastepnie macierz w postaci liczba;liczba;.
		@param nazwa Nazwa pliku, z ktorego wczytuje sie macierz.
		@param M Wysokosc macierzy.
		@param N Szerokosc maciery.
		@param macierz Wskaznik, do ktorego zapisujemy macierz z pliku.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int wczytaj(std::string nazwa,int M, int N, double** macierz);
		/**
		Zapisuje macierz do pliku.
		@param nazwa Nazwa pliku, do ktorego zapisujemy macierz.
		@param M Wysokosc macierzy.
		@param N Szerokosc maciery.
		@param macierz Wskaznik, z ktorego zapisujemy macierz do pliku.
		@return 0 Blad, 1 Udalo siê dokonac operacji.
		*/
		int zapisz(std::string nazwa, int M, int N, double** macierz);
		/**
		Wyswietla dostepne operacje i informacje.
		@return Nie zwraca nic.
		*/
		void informacje();
private:
	double** fun(double**, int, int);
	double** fun2(double**, double**, int, int);
};
#include "Actias_matrix.h"

Matrix::Matrix() {}

int Matrix::dodaj(int M1, int N1, double** macierz1, int M2, int N2, double** macierz2, double** macierz3) {
	if (N1 != N2 || M1 != M2 || N1 < 0 || M1 < 0 || N2 < 0 || M2 < 0) {
		std::cout << "Zly rozmiar macierzy." << std::endl;
		return 0;
	}

	double** tmp = new double*[M1];
	for (int i = 0; i < M1; i++)
		tmp[i] = new double[N1];

	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			tmp[i][j] = 0;

	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			tmp[i][j] += (macierz1[i][j] + macierz2[i][j]);

	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			macierz3[i][j] = tmp[i][j];

	for (int i = 0; i < M1; i++)
		delete[] tmp[i];
	delete[] tmp;
	return 1;
}

int Matrix::odejmij(int M1, int N1, double** macierz1, int M2, int N2, double** macierz2, double** macierz3) {
	if (N1 != N2 || M1 != M2 || N1 < 0 || M1 < 0 || N2 < 0 || M2 < 0) {
		std::cout << "Zly rozmiar macierzy." << std::endl;
		return 0;
	}
	double** tmp = new double*[M1];
	for (int i = 0; i < M1; i++)
		tmp[i] = new double[N1];

	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			tmp[i][j] = 0;

	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			tmp[i][j] += (macierz1[i][j] - macierz2[i][j]);

	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			macierz3[i][j] = tmp[i][j];

	for (int i = 0; i < M1; i++)
		delete[] tmp[i];
	delete[] tmp;
	return 1;
}

void Matrix::wyswietl(int M, int N, double** macierz) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			std::cout << macierz[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Matrix::pomnoz(int M1, int N1, double** macierz1, int M2, int N2, double** macierz2, double** macierz3) {
	if (M2 != N1 || N1 < 0 || M1 < 0 || N2 < 0 || M2 < 0) {
		std::cout << "Zly rozmiar macierzy." << std::endl;
		return 0;
	}

	double** tmp = new double*[M1];
	for (int i = 0; i < M1; i++)
		tmp[i] = new double[N2];
	
	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N2; j++)
			tmp[i][j] = 0;

	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N2; j++)
			for (int k = 0; k < M2; k++)
				tmp[i][j] += (macierz1[i][k] * macierz2[k][j]);
	
	for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			macierz3[i][j] = tmp[i][j];

	for (int i = 0; i < M1; i++)
		delete[] tmp[i];
	delete[] tmp;
	return 1;
}

double Matrix::wyznacznik(int N, double** macierz) {
	if (N < 1) {
		std::cout << "Zly rozmiar macierzy." << std::endl;
		return NULL;
	}
	if (N == 1)
		return macierz[0][0];
	if (N == 2)
		return macierz[0][0] * macierz[1][1] - macierz[0][1] * macierz[1][0];
	if (N == 3)
		return macierz[0][0] * macierz[1][1] * macierz[2][2] + macierz[1][0] * macierz[2][1] * macierz[0][2] +
		macierz[2][0] * macierz[0][1] * macierz[1][2] - macierz[0][2] * macierz[1][1] * macierz[2][0] -
		macierz[0][1] * macierz[1][0] * macierz[2][2] - macierz[0][0] * macierz[1][2] * macierz[2][1];
	if (N == 4) {
		double wynik = 0;
		int zmienna = 0;
		double** tmp = new double*[3];
		for (int i = 0; i < 3; i++)
			tmp[i] = new double[3];
	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (k == i)
						zmienna = 1;
					tmp[j][k] = macierz[j + 1][k + zmienna];
				}
				zmienna = 0;
			}
			if (i % 2 == 0)
				wynik += (macierz[0][i]*wyznacznik(3,tmp));
			else 
				wynik -= (macierz[0][i] * wyznacznik(3, tmp));
		}

		for (int i = 0; i < 3; i++)
			delete[] tmp[i];
		delete[] tmp;
		return wynik;
	}
	if (N > 4 && N < 12) {
		double wynik = 0;
		int zmienna = 0;
		double** tmp = new double*[N-1];
		for (int i = 0; i < N-1; i++)
			tmp[i] = new double[N-1];
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N-1; j++) {
				for (int k = 0; k < N-1; k++) {
					if (k == i)
						zmienna = 1;
					tmp[j][k] = macierz[j + 1][k + zmienna];
				}
				zmienna = 0;
			}
			if (i % 2 == 0)
				wynik += (macierz[0][i] * wyznacznik(N-1, tmp));
			else
				wynik -= (macierz[0][i] * wyznacznik(N-1, tmp));
		}
		for (int i = 0; i < N-1; i++)
			delete[] tmp[i];
		delete[] tmp;
		return wynik;
	}
	if (N > 11) {
		double** tmp = new double*[N];
		for (int i = 0; i < N; i++)
			tmp[i] = new double[N];
		macierz_diagonalna(N, macierz, tmp);
		double wynik = 1;
		for (int i = 0; i < N; i++)
			wynik *= tmp[i][i];

		for (int i = 0; i < N; i++)
			delete[] tmp[i];
		delete[] tmp;
		return wynik;
	}
}

int Matrix::gauss(int N, double** macierz1, double** macierz2) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			macierz2[i][j] = macierz1[i][j];
	
	int zapamietana = N-1;
	for (int i = 0; i < N; i++)
		if (macierz2[i][i] == 0) {
			for(int j = N - 1; j > -1; j--)
				if (macierz2[i][j] != 0) {
					zapamietana = j;
					break;
				}
			for (int j = 0; j < N; j++)
				macierz2[j][i] += macierz2[j][zapamietana];
		}

	for (int i = 0; i < N - 1; i++) {
		zapamietana = N - 1;
		for (int i = 0; i < N; i++)
			if (macierz2[i][i] == 0) {
				for (int j = N - 1; j > -1; j--)
					if (macierz2[i][j] != 0) {
						zapamietana = j;
						break;
					}
				for (int j = 0; j < N; j++)
					macierz2[j][i] += macierz2[j][zapamietana];
			}
		fun(macierz2, N, i);
	}
	return 1;
}

double** Matrix::fun(double **macierz, int ilosc_pkt, int kolumna) {
	double tmp = 0;
	for (int i = kolumna + 1; i < ilosc_pkt; i++) {
		tmp = macierz[i][kolumna] / macierz[kolumna][kolumna];
		for (int j = kolumna; j < ilosc_pkt; j++) {
			macierz[i][j] -= macierz[kolumna][j] * tmp;
		}
	}
	return macierz;
}

int Matrix::macierz_transponowana(int M, int N, double** macierz1, double** macierz2) {
	double** tmp = new double*[M];
	for (int i = 0; i < M; i++)
		tmp[i] = new double[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j] = macierz1[j][i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			macierz2[i][j] = tmp[i][j];

	for (int i = 0; i < N; i++)
		delete[] tmp[i];
	delete tmp;
	return 1;
}

int Matrix::dopelnienie(int N, int index1, int index2, double** macierz1, double** macierz2) {
	int zmienna = 0;
	int zmienna2 = 0;
		for (int j = 0; j < N-1; j++) {
			if (j == index2)
				zmienna2 = 1;
			for (int k = 0; k < N-1; k++) {
				if (k == index1)
					zmienna = 1;
				macierz2[j][k] = macierz1[j + zmienna2][k + zmienna];
			}
			zmienna = 0;
		}
	return 1;
}

int Matrix::macierz_dopelnien(int N, double** macierz1, double** macierz2) {
	double** tmp = new double*[N-1];
	for (int i = 0; i < N-1; i++)
		tmp[i] = new double[N-1];

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if ((i + j) % 2 == 0) {
				dopelnienie(N, j, i, macierz1, tmp);
				macierz2[i][j] = wyznacznik(N - 1, tmp);
			}
			else {
				dopelnienie(N, j, i, macierz1, tmp);
				macierz2[i][j] = -wyznacznik(N - 1, tmp);
			}
		}
	for (int i = 0; i < N - 1; i++)
		delete[] tmp[i];
	delete[] tmp;
	return 1;
}

int Matrix::macierz_odwrotna(int N, double** macierz1, double** macierz2) {
	macierz_dolaczona(N, macierz1, macierz2);
	double wyznacznik_macierzy;
	wyznacznik_macierzy = 1./wyznacznik(N, macierz1);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			macierz2[i][j] *= wyznacznik_macierzy;
	return 1;
}

int Matrix::macierz_dolaczona(int N, double** macierz1, double** macierz2) {
	macierz_dopelnien(N, macierz1, macierz2);
	macierz_transponowana(N, N, macierz2, macierz2);
	return 1;
}

double Matrix::slad_macierzy(int N, double** macierz) {
	double wynik = 0;
	for (int i = 0; i < N; i++)
		wynik += macierz[i][i];
	return wynik;
}

int Matrix::macierz_diagonalna(int N, double** macierz1, double** macierz2) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			macierz2[i][j] = macierz1[i][j];

	gauss(N, macierz2, macierz2);
	macierz_transponowana(N, N, macierz2, macierz2);
	gauss(N, macierz2, macierz2);
	return 1;
}

double** Matrix::fun2(double **tab1, double **tab2, int ilosc_pkt, int kolumna) {
	double tmp = 0;
	for (int i = kolumna + 1; i < ilosc_pkt; i++) {
		tmp = tab1[i][kolumna] / tab1[kolumna][kolumna];
		for (int j = kolumna; j < ilosc_pkt; j++) {
			tab1[i][j] -= tab1[kolumna][j] * tmp;
		}
		tab2[i][0] -= tab2[kolumna][0] * tmp;
	}
	return tab1;
}

int Matrix::metoda_eliminacji_gaussa(int N, double** macierz1, double** macierz2, double** macierz3) {
	double **tab1 = new double*[N];
	double **tab2 = new double*[N];
	double tmp;

	for (int i = 0; i < N; i++) {
		tab1[i] = new double[N];
		tab2[i] = new double[1];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tab1[i][j] = macierz1[i][j];

	for (int i = 0; i < N; i++) {
		tab2[i][0] = macierz2[i][0];
		macierz3[i][0] = 0;
	}
	for (int i = 0; i < N - 1; i++)
		fun2(tab1, tab2, N, i);

	macierz3[N - 1][0] = tab2[N - 1][0] / tab1[N - 1][N - 1];
	tmp = 0;
	int j;

	for (int i = N - 2; i > -1; i--) {
		for (j = N - 1; j > i; j--) {
			tmp += tab1[i][j] * macierz3[j][0];
		}
		macierz3[i][0] = (tab2[i][0] - tmp) / tab1[i][j];
		tmp = 0;
	}
	
	for (int i = 0; i < N; i++)
		delete[] tab1[i];
	delete[] tab1;

	for (int i = 0; i < N; i++)
		delete[] tab2[i];
	delete[] tab2;
	return 1;
}

int Matrix::wczytaj(std::string nazwa,int M, int N, double** macierz) {
	int M_tmp, N_tmp;
	std::fstream plik;
	std::string tmp;
	plik.open(nazwa, std::ios::in);
	if (!plik.good()) {
		plik.close();
		return 0;
	}
	else {
		std::getline(plik, tmp);
		M_tmp = atof(tmp.c_str());
		std::getline(plik, tmp);
		N_tmp = atof(tmp.c_str());

		if (M != M_tmp || N != N_tmp) {
			std::cout << "Rozmiary macierzy sie nie zgadzaja." << std::endl;
			return 0;
		}
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++) {
				std::getline(plik, tmp, ';');
				macierz[i][j] = atof(tmp.c_str());
			}
		plik.close();
		return 1;
	}
}

int Matrix::zapisz(std::string nazwa, int M, int N, double** macierz) {
	std::fstream plik;
	plik.open(nazwa, std::ios::out);
	if (!plik.good()) {
		plik.close();
		return 0;
	}
	else {
		plik << M << "\n";
		plik << N << "\n";

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				plik << macierz[i][j] << ";";
			}
			plik << "\n";
		}
		plik.close();
		return 1;
	}
}

void Matrix::informacje() {
	std::cout << "Pakiet funkcji zawarty w tej bilbiotece sluzy do wykonywania wiekszosci operacji macierzowych.\n"
		"Podawane macierze sa zawsze podwojnymi wskaznikami na typ double.\n"
		"Rozmiar kazdej macierzy to MxN gdzie M to liczba wierszy, a N to liczba kolumn.\n"
		"Wektory powstaja w taki sam sposob, po porstu jest to macierz Mx1.\n"
		"Dostepne operacje:\n"
		"wyswietl\ndodaj\nodejmij\npomnoz\nwyznacznik\ngauss\nmetoda_eliminacji_gaussa\nslad_macierzy\ndopelnienie\nmacierz_transponowana\nmacierz_dopelnien\nmacierz_odwrotna\nmacierz_dolaczona\nmacierz_diagonalna\nwczytaj\nzapisz\n";
}
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

using namespace std;

typedef std::vector<std::vector<double>> Matrica;



Matrica KreirajMatricu(int br_redova, int br_kolona) {
	return Matrica(br_redova, std::vector<double>(br_kolona));
}
int BrojRedova(Matrica m) {
	return m.size();
}
int BrojKolona(Matrica m) {
	if (m.size() != 0) return m[0].size();
	return 0;
}



Matrica UnesiMatricu(int br_redova, int br_kolona) {
	auto m = KreirajMatricu(br_redova, br_kolona);
	for (int i = 0; i < br_redova; i++)
		for (int j = 0; j < br_kolona; j++) {
			std::cout << "Element (" << i + 1 << "," << j + 1 << "): ";
			std::cin >> m[i][j];
		}
	return m;
}
void IspisiMatricu(Matrica m, int sirina) {
	for (int i = 0; i < BrojRedova(m); i++) {
		for (int j = 0; j < BrojKolona(m); j++)
			std::cout << std::setw(sirina) << m[i][j];
		std::cout << std::endl;
	}
	cout << endl;
}



Matrica SaberiMatrice(Matrica m1, Matrica m2) {
	auto m3 = KreirajMatricu(BrojRedova(m1), BrojKolona(m1));
	if (BrojRedova(m1) != BrojRedova(m2) && BrojKolona(m1) != BrojKolona(m2)) throw domain_error("Matrice nisu kompatibilne za sabiranje. Ponovite unos.");
	cout << "Zbir vasih matrica izgleda ovako: " << endl;
	for (int i = 0; i < BrojRedova(m1); i++)
		for (int j = 0; j < BrojKolona(m1); j++) m3[i][j] = m1[i][j] + m2[i][j];
	return m3;
}

Matrica PomnoziMatricuSkalarom(Matrica m, int skalar, int broj_matrice) {
	auto m1 = KreirajMatricu(BrojRedova(m), BrojKolona(m));
	cout << "Proizvod skalara i vase " << broj_matrice << ". matrice izgleda ovako: " << endl;
	for (int i = 0; i < BrojRedova(m); i++)
		for (int j = 0; j < BrojKolona(m); j++)
			m1[i][j] = skalar * m[i][j];
	return m1;
}

Matrica PomnoziMatrice(Matrica m1, Matrica m2) {

	auto m3 = KreirajMatricu(BrojRedova(m1), BrojKolona(m2));
	if (BrojRedova(m1) != BrojRedova(m2) || BrojKolona(m1) != BrojKolona(m2)) throw domain_error("Matrice nisu kompatibilne za mnozenje. Ponovite unos.");
	cout << "Proizvod vasih matrica izgleda ovako: " << endl;
	for (int i = 0; i < BrojRedova(m1); i++)
		for (int j = 0; j < BrojKolona(m2); j++) {
			double suma = 0;
			for (int k = 0; k < BrojRedova(m2); k++) suma += m1[i][k] * m2[k][j];
			m3[i][j] = suma;
		}
	return m3;
}



int main()
{
	int r1, k1, r2, k2, skalar;

	cout << "Unesite broj redova prve matrice: " << endl;
	cin >> r1;
	cout << "Unesite broj kolona prve matrice: " << endl;
	cin >> k1;
	Matrica a = UnesiMatricu(r1, k1);
	cout << endl << "Vasa matrica izgleda ovako: " << endl;
	IspisiMatricu(a, 3);

	cout << endl << "------------------------------------------------------------------------------------------------" << endl << endl << endl;
	cout << "Unesite broj redova druge matrice: " << endl;
	cin >> r2;
	cout << "Unesite broj kolona druge matrice: " << endl;
	cin >> k2;
	Matrica b = UnesiMatricu(r2, k2);
	cout << endl << "Vasa matrica izgleda ovako: " << endl;
	IspisiMatricu(b, 3);

	cout << endl << "------------------------------------------------------------------------------------------------" << endl << endl << endl;
	cout << "Unesite skalar kojim cete mnoziti obje matrice: " << endl;
	cin >> skalar;

	cout << endl << "------------------------------------------------------------------------------------------------" << endl << endl << endl;
	try {
		IspisiMatricu(SaberiMatrice(a, b), 3);
	}
	catch (domain_error izuzetak) {
		cout << izuzetak.what() << endl;
	}

	cout << endl << "------------------------------------------------------------------------------------------------" << endl << endl << endl;
	IspisiMatricu(PomnoziMatricuSkalarom(a, skalar, 1), 3);

	cout << endl << "------------------------------------------------------------------------------------------------" << endl << endl << endl;
	IspisiMatricu(PomnoziMatricuSkalarom(b, skalar, 2), 3);


	cout << endl << "------------------------------------------------------------------------------------------------" << endl << endl << endl;
	try {
		IspisiMatricu(PomnoziMatrice(a, b), 3);
	}
	catch (domain_error izuzetak) {
		cout << izuzetak.what() << endl;
	}

	return 0;
}
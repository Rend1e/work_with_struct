#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

struct point {
	string gr;
	string fam;
	string name;
	string otch;
	string age;
	int ozenki[5];
	double sr;
};
void puzir(point* arr, int size) {
	int c;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j].sr > arr[j + 1].sr) {
				c = arr[j].sr;
				arr[j].sr = arr[j + 1].sr;
				arr[j + 1].sr = c;
			}
		}
	}
}

int main() {
	//vyvod na output po sort po ozenkam
	ifstream f1;
	f1.open("input.txt");
	ofstream f2;
	f2.open("output.txt");
	point a[100];


	if (!f1.is_open())  //проверка открытия файла
	{
		cout << "input not founded" << endl; //если не нашел ошибка
	}
	else
	{
		//double b[100];
		int kol = 0;
		while (!f1.eof()) {
			f1 >> a[kol].gr;
			f1 >> a[kol].fam;
			f1 >> a[kol].name;
			f1 >> a[kol].otch;
			f1 >> a[kol].age;
			a[kol].sr = 0;
			for (int i = 0; i < 5; i++) {
				f1 >> a[kol].ozenki[i];
				a[kol].sr += a[kol].ozenki[i];
			}
			a[kol].sr /= 5;
			kol++;		
		}
		puzir(a, kol);
		for (int i = 0; i < kol; i++) {
			f2 << a[i].gr << endl;
			f2 << a[i].fam << endl;
			f2 << a[i].name << endl;
			f2 << a[i].otch << endl;
			f2 << a[i].age << endl;
			f2 << a[i].sr << endl;
			//f2 << endl;
		}
	}
	f1.close();
	f2.close();
	return 0;
}
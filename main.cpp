
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

#include "Graph.h" //класс вершин
#include "Road.h" //класс рЄбер


using namespace std;



int main() {
	/*  —читываем информацию из файла */

	int N; //число вершин
	int M; //число рЄбер

	string info; //переменна€ информации о топологии на экране

	ifstream f; //входной поток дл€ считывани€ данных из file.txt
	f.open("file.txt");
	f >> N; //считываем число вершин
	info += to_string(N) + " graph\n\n";

	Graph* Graphs = new Graph[N]; //создаЄм N вершин

	for (int i = 0; i < N; i++) { //забиваем вершины данными
		Graphs[i].N = i + 1; // номер вершины
		f >> Graphs[i].x; //координаты
		f >> Graphs[i].y; //координаты

		info += "(" + to_string(Graphs[i].N) + ") [" + to_string(Graphs[i].x) + ";" + to_string(Graphs[i].y) + "]\n";
	}

	f >> M; //считываем число рЄбер
	info += "\n" + to_string(M) + " roads\n\n";

	Road* Roads = new Road[M]; //создаЄм M рЄбер

	int A, B; 
	int* H = new int[M]; 
	int* T = new int[M];
	int* F = new int[M];

	for (int i = 0; i < M; i++) { //забиваем рЄбра данными
		Roads[i].M = i + 1; //идентификатор ребра

		f >> A; //начало ребра
		H[i] = A;
		Roads[i].A = Graphs[A];

		f >> B; //конец ребра
		T[i] = B;
		Roads[i].B = Graphs[B];

		f >> Roads[i].F; //пропускна€ способность ребра
		F[i] = Roads[i].F;

		info += "(" + to_string(Roads[i].M) + ") [" + to_string(Graphs[A].N) + ";" + to_string(Graphs[B].N) + "] = " + to_string(Roads[i].F) + "\n";
	}

	f.close(); //закрываем поток данных
}


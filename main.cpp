
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

#include "Graph.h" //����� ������
#include "Road.h" //����� ����


using namespace std;



int main() {
	/*  ��������� ���������� �� ����� */

	int N; //����� ������
	int M; //����� ����

	string info; //���������� ���������� � ��������� �� ������

	ifstream f; //������� ����� ��� ���������� ������ �� file.txt
	f.open("file.txt");
	f >> N; //��������� ����� ������
	info += to_string(N) + " graph\n\n";

	Graph* Graphs = new Graph[N]; //������ N ������

	for (int i = 0; i < N; i++) { //�������� ������� �������
		Graphs[i].N = i + 1; // ����� �������
		f >> Graphs[i].x; //����������
		f >> Graphs[i].y; //����������

		info += "(" + to_string(Graphs[i].N) + ") [" + to_string(Graphs[i].x) + ";" + to_string(Graphs[i].y) + "]\n";
	}

	f >> M; //��������� ����� ����
	info += "\n" + to_string(M) + " roads\n\n";

	Road* Roads = new Road[M]; //������ M ����

	int A, B; 
	int* H = new int[M]; 
	int* T = new int[M];
	int* F = new int[M];

	for (int i = 0; i < M; i++) { //�������� ���� �������
		Roads[i].M = i + 1; //������������� �����

		f >> A; //������ �����
		H[i] = A;
		Roads[i].A = Graphs[A];

		f >> B; //����� �����
		T[i] = B;
		Roads[i].B = Graphs[B];

		f >> Roads[i].F; //���������� ����������� �����
		F[i] = Roads[i].F;

		info += "(" + to_string(Roads[i].M) + ") [" + to_string(Graphs[A].N) + ";" + to_string(Graphs[B].N) + "] = " + to_string(Roads[i].F) + "\n";
	}

	f.close(); //��������� ����� ������
}


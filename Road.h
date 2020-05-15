#pragma once
using namespace std;

class Road {
public:
	int M; //идентификатор ребра
	Graph A, B; //концы ребра
	int F; //ВЕС ребра
};
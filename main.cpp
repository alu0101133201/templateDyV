#include<iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include"framework/Framework.h"
#include"examples/FibonacciP.h"
#include"examples/FibonacciS.h"
#include"examples/MergeP.h"
#include"examples/MergeS.h"

using namespace std;


int main(int argc, char* argv[]){
	/*
	if (argc != 2) {
		cout << "\nNúmero de parametros incorrecto. Encontrado " << argc-1 << " requerido 1."<< endl;
		exit(-1);
	}*/

	std::vector<int> prueba;
	prueba.push_back(3);
	prueba.push_back(2);
	prueba.push_back(0);
	prueba.push_back(1);
	prueba.push_back(8);


	Problema* problema = new MergeP(prueba);
	Solucion* solucion = new MergeS();
	Framework* framework = new Framework();

	framework->divideyVenceras(problema, solucion);
	cout << "\nResultado:" << endl;
	solucion->resolver();

};

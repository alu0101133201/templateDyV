#include<iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include"framework/Framework.h"
#include"examples/FibonacciP.h"
#include"examples/FibonacciS.h"
#include"examples/MergeP.h"
#include"examples/MergeS.h"
#include"examples/quickP.h"
#include"examples/quickS.h"

using namespace std;


int main(int argc, char* argv[]){
	std::vector<int> prueba(argc - 1);

	if (argc < 2) {
		cout << "\nNúmero de parametros incorrecto. Encontrado " << argc-1 << " requerido 1."<< endl;
		exit(-1);
	} else {
    for (int i = 1; i < argc; i++) {
      prueba[i-1] = atoi(argv[i]);
    }
  }




	Problema* problema = new MergeP(prueba);
	Solucion* solucion = new MergeS();
	Framework* framework = new Framework();

	Problema* problema1 = new quickP(prueba);
	Solucion* solucion1 = new quickS();
	Framework* framework1 = new Framework();

	framework->divideyVenceras(problema, solucion);
	framework1->divideyVenceras(problema1, solucion1);

	cout << "\nResultado merge:" << endl;
	solucion->resolver();

	cout << "\nResultado quicksort:" << endl;
	solucion1->resolver();

};

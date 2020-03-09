
#include<iostream>
#include "MergeS.h"

MergeS::MergeS() : Solucion::Solucion() {
}

MergeS::~MergeS() {
}


void MergeS::resolver() {
	std::cout << "[ ";
	for (int i = 0; i < _n.size(); i++) {
		std::cout << _n[i] << " ";
	}
	std::cout << "]\n";
}

void MergeS::mezcla(pair<Solucion*,Solucion*> subSoluciones) {
  // for (int i = 0; i < ((MergeS*)subSoluciones.first)->_n.size(); i++)
  //   std::cout << "primer vector a mezclar: " << ((MergeS*)subSoluciones.first)->_n[i] << "\n";
  //
  // for (int i = 0; i < ((MergeS*)subSoluciones.second)->_n.size(); i++)
  //   std::cout << "Segundo vector a mezclar: " << ((MergeS*)subSoluciones.second)->_n[i] << "\n";
  int izq = 0;
  int dcha = 0;
  std::vector<int> primero = ((MergeS*)subSoluciones.first)->_n;
  std::vector<int> segundo = ((MergeS*)subSoluciones.second)->_n;

  if (primero.size() < 1 || segundo.size() < 1) {
    _n.push_back(primero[izq]);
  } else {
    while ((izq < primero.size()) && (dcha < segundo.size())) {
      if (primero[izq] < segundo[dcha]) {
        _n.push_back(primero[izq]);
        izq++;
      }
      else {
        _n.push_back(segundo[dcha]);
        dcha++;
      }
    }
    while (izq < primero.size()){
      _n.push_back(primero[izq]);
      izq++;
    }
    while (dcha < segundo.size()) {
      _n.push_back(segundo[dcha]);
      dcha++;
    }
  }
}


Solucion* MergeS::getInstance() {
	return new MergeS();
}

void MergeS::setValor(std::vector<int> n) {
	_n = n;
}

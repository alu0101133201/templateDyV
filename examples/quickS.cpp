
#include<iostream>
#include "quickS.h"

quickS::quickS() : Solucion::Solucion() {
}

quickS::~quickS() {
}


void quickS::resolver() {
	std::cout << "[ ";
	for (int i = 0; i < _n.size(); i++) {
		std::cout << _n[i] << " ";
	}
	std::cout << "]\n";
}

void quickS::mezcla(pair<Solucion*,Solucion*> subSoluciones) {
  std::vector<int> primero = ((quickS*)subSoluciones.first)->_n;
  std::vector<int> segundo = ((quickS*)subSoluciones.second)->_n;

  for (int i = 0; i < primero.size(); i++)
    _n.push_back(primero[i]);
  for (int i = 0; i < segundo.size(); i++)
    _n.push_back(segundo[i]);
}


Solucion* quickS::getInstance() {
	return new quickS();
}

void quickS::setValor(std::vector<int> n) {
	_n = n;
}

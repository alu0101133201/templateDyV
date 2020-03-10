
#include "quickP.h"
#include <math.h>

quickP::quickP(std::vector<int> n) : Problema::Problema() {
	_n = n;
}

quickP::~quickP() {

}

bool quickP::isCasoMinimo() {
	return (_n.size() < 3);
}

pair<Problema*,Problema*> quickP::descomponer() {
	pair<Problema*,Problema*> subProblemas;

  for (int i = 0; i < _n.size(); i++)
    std::cout << _n[i] << " ";
  
  int izq = 1;
  int dcha = _n.size() - 1;
  int pivote = _n[0];
  int aux;

  while (izq < dcha) {
    while (_n[izq] < pivote)
      izq++;
    while (_n[dcha] > pivote)
      dcha--;

    if (izq < dcha) {
      aux = _n[izq];
      _n[izq] = _n[dcha];
      _n[dcha] = aux;
      izq++; dcha--;
    }
  }

  aux = _n[dcha];
  _n[dcha] = pivote;
  _n[0] = aux;


  std::vector<int> primerVector;
  std::vector<int> segundoVector;

  for (int i = 0; i <= dcha; i++) {
      primerVector.push_back(_n[i]);
  }
  for (int i = dcha + 1; i < _n.size(); i++) {
      segundoVector.push_back(_n[i]);
  }

	subProblemas.first = new quickP(primerVector);
	subProblemas.second = new quickP(segundoVector);
	return subProblemas;
}

void quickP::solver(Solucion* s) {
  std::vector<int> aux;
  if (_n.size() == 2) {
    if (_n[0] > _n[1]) {
      aux.push_back(_n[1]);
      aux.push_back(_n[0]);
    }
    else {
      aux = _n;
    }
    ((quickS*)s)->setValor(aux);
  }
  else {
    ((quickS*)s)->setValor(_n);

  }
}

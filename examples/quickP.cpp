
#include "quickP.h"
#include <math.h>

quickP::quickP(std::vector<int> n) : Problema::Problema() {
	_n = n;
}

quickP::~quickP() {

}

bool quickP::isCasoMinimo() {
	return (_n.size() < 2);
}

pair<Problema*,Problema*> quickP::descomponer() {
	pair<Problema*,Problema*> subProblemas;

  
  int izq = 1;
  int dcha = _n.size() - 1;
  int pivote = _n[0];
  int aux;

  while (izq <= dcha) {
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

  std::cout << "derecha vale: " << dcha << "\n";
  for (int i = 0; i <= dcha; i++) {
      primerVector.push_back(_n[i]);
  }
  std::cout << "El size de n es: " << _n.size() << "\n";
  for (int i = dcha + 1; i < _n.size(); i++) {
    std::cout << "Se está meitneod el índice i e ne l segundo vector: " << i << "\n";
      segundoVector.push_back(_n[i]);
  }
	subProblemas.first = new quickP(primerVector);
	subProblemas.second = new quickP(segundoVector);
	return subProblemas;
}

void quickP::solver(Solucion* s) {
	((quickS*)s)->setValor(_n);
}

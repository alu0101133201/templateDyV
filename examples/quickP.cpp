
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







  std::vector<int> primerVector;
  std::vector<int> segundoVector;
  int med = _n.size() / 2;

  for (int i = 0; i < med; i++) {
      primerVector.push_back(_n[i]);
  }
  for (int i = med; i < _n.size(); i++) {
      segundoVector.push_back(_n[i]);
  }
	subProblemas.first = new quickP(primerVector);
	subProblemas.second = new quickP(segundoVector);
	return subProblemas;
}

void quickP::solver(Solucion* s) {
	((quickS*)s)->setValor(_n);
}

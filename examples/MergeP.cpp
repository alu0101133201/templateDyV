
#include "MergeP.h"
#include <math.h>

MergeP::MergeP(std::vector<int> n) : Problema::Problema() {
	_n = n;
}

MergeP::~MergeP() {

}

bool MergeP::isCasoMinimo() {
	return (_n.size() < 2);
}

pair<Problema*,Problema*> MergeP::descomponer() {
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

	subProblemas.first = new MergeP(primerVector);
	subProblemas.second = new MergeP(segundoVector);
	return subProblemas;
}

void MergeP::solver(Solucion* s) {
	((MergeS*)s)->setValor(_n);
}

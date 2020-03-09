#pragma once

#include <vector>

#include "../framework/Problema.h"
#include "quickS.h"
class quickP: public Problema {
public:
		quickP(std::vector<int> n);
	virtual ~quickP();

	bool isCasoMinimo();
	pair<Problema*,Problema*> descomponer();
	void solver(Solucion* s);

private:
	std::vector<int> _n;
};

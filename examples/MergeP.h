#pragma once

#include <vector>

#include "../framework/Problema.h"
#include "MergeS.h"
class MergeP: public Problema {
public:
		MergeP(std::vector<int> n);
	virtual ~MergeP();

	bool isCasoMinimo();
	pair<Problema*,Problema*> descomponer();
	void solver(Solucion* s);

private:
	std::vector<int> _n;
};

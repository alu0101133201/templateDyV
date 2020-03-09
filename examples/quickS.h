#pragma once

#include "../framework/Solucion.h"

class quickS: public Solucion {
public:
	quickS();
	virtual ~quickS();

	void resolver();
	void mezcla(pair<Solucion*,Solucion*>);
	Solucion* getInstance();

	void setValor(std::vector<int>);

private:
	std::vector<int> _n;

};

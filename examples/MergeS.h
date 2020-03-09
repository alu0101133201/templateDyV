#pragma once

#include "../framework/Solucion.h"

class MergeS: public Solucion {
public:
	MergeS();
	virtual ~MergeS();

	void resolver();
	void mezcla(pair<Solucion*,Solucion*>);
	Solucion* getInstance();

	void setValor(std::vector<int>);

private:
	std::vector<int> _n;

};

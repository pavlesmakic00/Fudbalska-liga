#ifndef _mec_h_
#define _mec_h_
#include <iostream>
#include "Tim.h"
#include "Par.h"
using namespace std;
class Mec
{
	enum IM { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };
    IM ishodMeca;
	Par<Tim>parTimova;
	bool odigranMec = 0;
public:
	Mec(Tim& t1, Tim& t2):parTimova(t1,t2) {}

	Par<Tim>& getParTimova() { return parTimova; }
	const Par<Tim>& getParTimova()const { return parTimova; }

	bool odigranMecProvera() const { return odigranMec; }

	void odigrajMec();

	void promeniVrednosti(Tim& p, Tim& g);

	Par<int> getParPoeni();

	friend ostream& operator <<(ostream& it,const Mec& m);
};
#endif

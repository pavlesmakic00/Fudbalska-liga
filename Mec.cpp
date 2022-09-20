#include "Mec.h"
#include "Greska.h"
void Mec::promeniVrednosti(Tim &p,Tim &g)
{
	for (int i = 0; i < p.getTrenBrIgraca(); i++)
	{
		if (&p[i] != nullptr) {
			p[i].povecajVrednost(10);
		}
	}
	for (int i = 0; i < g.getTrenBrIgraca(); i++)
	{
		if (&g[i] != nullptr) {
			g[i].smanjiVrednost(10);
		}
	}
}
void Mec::odigrajMec()
{
	if (parTimova.getVrednost1().srednjaVrednostTima() > parTimova.getVrednost2().srednjaVrednostTima()) {
		ishodMeca = POBEDA_DOMACIN;
		promeniVrednosti(parTimova.getVrednost1(), parTimova.getVrednost2());

	}
	else if (parTimova.getVrednost1().srednjaVrednostTima() < parTimova.getVrednost2().srednjaVrednostTima()) {
		ishodMeca = POBEDA_GOST;
		promeniVrednosti(parTimova.getVrednost2(), parTimova.getVrednost1());
	}
	else {
		ishodMeca = NERESENO;
	}
	odigranMec = 1;
}
Par<int> Mec::getParPoeni()
{
	int* x = new int;
	int* y = new int;
	if (!odigranMec)throw GNeodigranMec();
	if (ishodMeca == POBEDA_DOMACIN) { *x = 3; *y = 0; }
	else if (ishodMeca == POBEDA_GOST) { *x = 0; *y = 3; }
	else { *x = 1; *y = 1; }

	

	return Par<int>(*x, *y);
}
ostream& operator<<(ostream& it, const Mec& m)
{
	it << m.parTimova;

	if (m.odigranMec) {
		if (m.ishodMeca==0)it << "POBEDA_DOMACIN";	
		else if (m.ishodMeca == 1) it << "NERESENO";
		else it << "POBEDA_GOST";
	}
	return it;
}
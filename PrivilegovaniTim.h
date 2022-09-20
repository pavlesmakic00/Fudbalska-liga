#ifndef _privilegovanitim_h_
#define _privilegovanitim_h_
#include "Tim.h"
#include "Greska.h"
class PrivilegovaniTim:public Tim
{
	int minimalnaVr;
	void pisi(ostream& it)const override;
public:
	PrivilegovaniTim(string n, int m, int min) :Tim(n, m), minimalnaVr(min) {}

	void prikljuciIgraca(Igrac igrac, int pozicija)override;

	/*friend ostream& operator<<(ostream& it, const PrivilegovaniTim& pt);*/

};
#endif
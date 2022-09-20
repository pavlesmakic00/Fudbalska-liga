#include "PrivilegovaniTim.h"
#include "Greska.h"
void PrivilegovaniTim::prikljuciIgraca(Igrac igrac, int pozicija)
{
	
	if (igrac.getVrIgraca() >= minimalnaVr) {
		if (igraci[pozicija] == nullptr) trenutniBrIgraca++;
		igraci[pozicija] = new Igrac(igrac);
	}
	else
		throw GIspodMin();
    	
}
void PrivilegovaniTim::pisi(ostream& it) const
{
	cout << this->naziv;
	cout << "(" << this->minimalnaVr << ")";
	int k = 0;
	it << "[";
	for (int i = 0; i < maxBrIgraca; i++)
	{
		if (igraci[i] != nullptr) {
			if (k == 0) it << *(igraci[i]);
			else
				it << "," << *(igraci[i]);
			k++;
		}
	}
	it << "]";
	
}
//ostream& operator<<(ostream& it, const PrivilegovaniTim& pt)
//{
//	pt.pisi(it);
//	return it;
//}
#ifndef _tim_h_
#define _tim_h_
#include "Igrac.h"
class Tim
{
protected:
	string naziv;
	int maxBrIgraca;
	Igrac** igraci;
	int trenutniBrIgraca=0;
	virtual void pisi(ostream& it)const;

public:
	Tim(string i, int m) :naziv(i), maxBrIgraca(m) {
		igraci = new Igrac * [maxBrIgraca]();
	}
	Tim(const Tim& t);
	Tim(Tim&& t);
	Tim& operator=(const Tim& t);
	Tim& operator=(Tim&&);
	~Tim();

	int getTrenBrIgraca()const {return trenutniBrIgraca; }
	double srednjaVrednostTima ()const;

	virtual void prikljuciIgraca(Igrac igrac, int pozicija);

	Igrac& operator [](int pozicija);

	const Igrac& operator [](int pozicija)const;

	friend bool operator==(const Tim& t1, const Tim& t2);

	friend bool operator!=(const Tim& t1, const Tim& t2);

	friend ostream& operator<<(ostream &it,const Tim& t);
};
#endif

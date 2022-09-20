#include "Tim.h"
void Tim::prikljuciIgraca(Igrac igrac, int pozicija)
{
	if (igraci[pozicija]==nullptr) trenutniBrIgraca++;
	igraci[pozicija] = new Igrac(igrac);
	
}
Igrac& Tim::operator[](int pozicija)
{
	return *igraci[pozicija];
}
const Igrac& Tim::operator[](int pozicija) const
{
	return *igraci[pozicija];
}
bool operator==(const Tim& t1, const Tim& t2)
{
	int x = 1;

	if (t1.maxBrIgraca == t2.maxBrIgraca && t1.naziv == t2.naziv) {
		x = 0;
		for (int i = 0; i < t1.maxBrIgraca; i++)
		{
			if (t1.igraci[i] != nullptr && t2.igraci[i] != nullptr) {
				if (*t1.igraci[i] != *t2.igraci[i]) x = 1;
			}
		}
	}

	return (!x) && t1.naziv==t2.naziv && t1.maxBrIgraca==t2.maxBrIgraca;
}
bool operator!=(const Tim& t1, const Tim& t2)
{
	return !(t1==t2);
}
void Tim::pisi(ostream& it) const
{
	cout << this->naziv;
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
ostream& operator<<(ostream& it, const Tim& t)
{
	t.pisi(it);
	return it;
}
double Tim::srednjaVrednostTima() const
{
	int sum = 0;
	for (int i = 0; i <maxBrIgraca; i++)
	{
		if (igraci[i] != nullptr) {
			sum += igraci[i]->getVrIgraca();
		}
	}
	return ((double)sum/trenutniBrIgraca);
}
Tim::Tim(const Tim& t)
{
	this->naziv = t.naziv;
	this->igraci = new Igrac * [maxBrIgraca = t.maxBrIgraca];

	for (int i = 0; i < t.maxBrIgraca; i++)
	{	
		if (t.igraci[i] == nullptr) igraci[i] = nullptr;
		else
			igraci[i] = new Igrac(*t.igraci[i]);
	}
}
Tim::Tim(Tim&& t)
{
	this->naziv = t.naziv;
	this->maxBrIgraca = t.maxBrIgraca;
	this->igraci = t.igraci;
	t.igraci = nullptr;
}
Tim& Tim::operator=(const Tim& t)
{
	if (this != &t) {
		delete[]igraci;
		this->naziv = t.naziv;
		this->igraci = new Igrac * [maxBrIgraca = t.maxBrIgraca];

		for (int i = 0; i < t.maxBrIgraca; i++)
		{
			if (t.igraci[i] == nullptr) igraci[i] = nullptr;
			else
				igraci[i] = new Igrac(*t.igraci[i]);
		}
	}
	return *this;
}
Tim& Tim::operator=(Tim&& t)
{
	if (this != &t) {
		delete[]igraci;
		this->naziv = t.naziv;
		this->maxBrIgraca = t.maxBrIgraca;
		this->igraci = t.igraci;
		t.igraci = nullptr;
	}
	return *this;
}
Tim::~Tim()
{
	for (int i = 0; i < maxBrIgraca; i++)
		delete igraci[i];
	delete[]igraci;
	igraci = nullptr;
}
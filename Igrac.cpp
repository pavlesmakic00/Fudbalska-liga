#include "Igrac.h"
Igrac& Igrac::povecajVrednost(int procenat)
{
	this->vrIgraca = this->vrIgraca * (1.0 + procenat / 100.0);
	return *this;
}
Igrac& Igrac::smanjiVrednost(int procenat)
{
	this->vrIgraca = this->vrIgraca * (1.0 - procenat / 100.0);
	return *this;
}
bool operator==(const Igrac& i1, const Igrac& i2)
{
	return i1.ime==i2.ime && i1.vrIgraca==i2.vrIgraca;
}
bool operator!=(const Igrac& i1, const Igrac& i2)
{
	return !(i1==i2);
}
ostream& operator<<(ostream& it, const Igrac& i)
{
	return it << i.ime << "#" << i.vrIgraca;
}
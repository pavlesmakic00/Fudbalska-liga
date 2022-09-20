#ifndef _igrac_h_
#define _igrac_h_
#include <iostream>
using namespace std;
class Igrac
{
	string ime;
	int vrIgraca;
public:
	Igrac(string i, int v = 1000) :ime(i), vrIgraca(v) {}

	string getIme()const { return ime; }
	int getVrIgraca()const { return vrIgraca; }

	Igrac& povecajVrednost(int  procenat);
	Igrac& smanjiVrednost(int  procenat);

	friend bool operator==(const Igrac& i1, const Igrac& i2);
	friend bool operator!=(const Igrac& i1, const Igrac& i2);

	friend ostream& operator <<(ostream& it, const Igrac& i);
};
#endif


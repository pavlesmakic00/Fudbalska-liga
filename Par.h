#ifndef _par_h_
#define _par_h_
#include <iostream>
using namespace std;
template<typename T>
class Par
{
	T* pok1;
	T* pok2;
public:
	Par(T& info1,T& info2) {	pok1 = &info1;	pok2 = &info2;	}
	~Par() { pok1 = pok2 = nullptr; }

	void postaviVrednost1(T& info1) { pok1 = &info1;}
	void postaviVrednost2(T& info2) { pok2 = &info2; }

	T& getVrednost1() { return *pok1; }
	T& getVrednost2() { return *pok2; }

	friend bool operator==(const Par& p1, const Par& p2) { return *(p1.pok1) == *(p2.pok1) && *(p1.pok2) == *(p2.pok2); }	
	
	friend bool operator!=(const Par& p1, const Par& p2) { return !(p1 == p2); }
		
	
	friend ostream& operator<<(ostream& it, const Par& p) {
		return it <<"["<< *(p.pok1) << "-" << *(p.pok2) << "]";
	}
};
#endif

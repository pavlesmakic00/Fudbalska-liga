#ifndef _greska_h_
#define _greska_h_
#include <iostream>
#include <exception>
using namespace std;
class GIspodMin:public exception
{
public:
	const char* what()const override { return "Greska:Vrednost igraca je manja od minimalne vrednosti!";}
	
};
class GNeodigranMec :public exception
{
	const char* what()const override { return "Greska:Mec nije odigran!"; }
};
#endif
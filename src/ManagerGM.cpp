#include "ManagerGM.h"

ManagerGM::ManagerGM(unsigned int cod, string name, string dn, string nac, string det)
: Pessoa(cod, name, dn, nac), detalhes(det) {}

ManagerGM::~ManagerGM() {}

string ManagerGM::getdet()
{return detalhes;}

void ManagerGM::setdet(string det)
{detalhes=det;}

void ManagerGM::info()
{
	Pessoa::info();
	cout << "Detalhes: " << detalhes << endl;
}

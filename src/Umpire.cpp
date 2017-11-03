#include "Umpire.h"

Umpire::Umpire(unsigned int cod, string name, string dn, string nac, string det)
: Pessoa(cod, name, dn, nac), detalhes(det) {}

Umpire::~Umpire() {}

string Umpire::getdet()
{return detalhes;}

void Umpire::setdet(string det)
{detalhes=det;}

void Umpire::info()
{
	Pessoa::info();
	cout << "Detalhes: " << detalhes << endl;
}

#include "PrepFisico.h"

PrepFisico::PrepFisico(unsigned int cod, string name, string dn, string nac, string det)
: Pessoa(cod, name, dn, nac), detalhes(det) {}

PrepFisico::~PrepFisico() {}

string PrepFisico::getdet()
{return detalhes;}

void PrepFisico::setdet(string det)
{detalhes=det;}

void PrepFisico::info()
{
	Pessoa::info();
	cout << "Detalhes: " << detalhes << endl;
}

#include "Treinador.h"

Treinador::Treinador(unsigned int cod, string name, string dn, string nac, string det)
: Pessoa(cod, name, dn, nac), detalhes(det) {}

Treinador::~Treinador() {}

string Treinador::getdet()
{return detalhes;}

void Treinador::setdet(string det)
{detalhes=det;}

void Treinador::info()
{
	Pessoa::info();
	cout << "Detalhes: " << detalhes << endl;
}

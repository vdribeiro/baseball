#include "Manager.h"

Manager::Manager(unsigned int cod, string name, string dn, string nac, vector <Treinador *> coa, string det)
: Pessoa(cod, name, dn, nac), trn(coa), detalhes(det) {}

Manager::~Manager() {}

vector <Treinador *> Manager::gettrn()
{return trn;}

void Manager::settrn(vector <Treinador *> coa)
{trn=coa;}

string Manager::getdet()
{return detalhes;}

void Manager::setdet(string det)
{detalhes=det;}

void Manager::info()
{
	Pessoa::info();
	cout << "Detalhes: " << detalhes << endl;
	cout << endl << "Equipa de Treinadores: " << endl;
	vector<Treinador*>::iterator it;
	for (it = trn.begin(); it != trn.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}

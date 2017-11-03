#include "Utilizador.h"

Utilizador::Utilizador(unsigned int cod, string name, string dn, string nac, string senha, unsigned int pri)
: Pessoa(cod, name, dn, nac), prioridade(pri), pass(senha) {}

Utilizador::~Utilizador() {}

unsigned int Utilizador::getpri()
{return prioridade;}

void Utilizador::setpri(unsigned int pri)
{prioridade=pri;}

string Utilizador::getpass()
{return pass;}

void Utilizador::setpass(string pword)
{pass=pword;}

void Utilizador::info()
{
	Pessoa::info();
	cout << "Prioridade: " << prioridade << endl;
	cout << "Password: " << pass << endl;
}

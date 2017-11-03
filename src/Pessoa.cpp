#include "Pessoa.h"

Pessoa::Pessoa(unsigned int cod, string name, string dn, string nac)
: id(cod), nome(name), data_nasc(dn), nacionalidade(nac) {}

Pessoa::~Pessoa() {}

unsigned int Pessoa::getid()
{return id;}

void Pessoa::setid(unsigned int cod)
{id=cod;}

string Pessoa::getnome()
{return nome;}

void Pessoa::setnome(string name)
{nome=name;}

string Pessoa::getdn()
{return data_nasc;}

void Pessoa::setdn(string dn)
{data_nasc=dn;}

string Pessoa::getnac()
{return nacionalidade;}

void Pessoa::setnac(string nac)
{nacionalidade=nac;}

void Pessoa::info()
{
	cout << "Id: " << id << endl;
	cout << "Nome: " << nome << endl;
	cout << "Data de Nascimento: " << data_nasc << endl;
	cout << "Nacionalidade: " << nacionalidade << endl;
}

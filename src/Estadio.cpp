#include "Estadio.h"

Estadio::Estadio(unsigned int cod, string name, unsigned int cap)
: id(cod), nome(name), capacidade(cap) {}

Estadio::~Estadio() {}

unsigned int Estadio::getid()
{return id;}

void Estadio::setid(unsigned int cod)
{id=cod;}

string Estadio::getnome()
{return nome;}

void Estadio::setnome(string name)
{nome=name;}

unsigned int Estadio::getcap()
{return capacidade;}

void Estadio::setcap(unsigned int cap)
{capacidade=cap;}

void Estadio::imprime()
{
	cout << "Codigo: " << id << endl;
	cout << "Nome: " << nome << endl;
	cout << "Capacidade: " << capacidade << endl;
}

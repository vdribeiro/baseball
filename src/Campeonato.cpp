#include "Campeonato.h"

Campeonato::Campeonato(unsigned int cod, string name, vector <Jogo *> games, unsigned int year)
: id(cod), nome(name), jogos(games), ano(year) {}

Campeonato::~Campeonato() {}

unsigned int Campeonato::getid()
{return id;}

void Campeonato::setid(unsigned int cod)
{id=cod;}

string Campeonato::getnome()
{return nome;}

void Campeonato::setnome(string name)
{nome=name;}

vector <Jogo *> Campeonato::getjogos()
{return jogos;}

void Campeonato::setjogos(vector <Jogo *> games)
{jogos=games;}

unsigned int Campeonato::getano()
{return ano;}

void Campeonato::setano(unsigned int year)
{ano=year;}

void Campeonato::imprime()
{
	cout << endl << "CALENDARIO DE JOGOS" << endl << endl;
	cout << "Codigo: " << id << endl;
	cout << "Nome: " << nome << endl;
	cout << "Ano: " << ano << endl;
	cout << endl << "Jogos : " << endl;
	vector<Jogo*>::iterator it;
	for (it = jogos.begin(); it != jogos.end(); it++)
	{
		(*it)->imprime();
		cout << endl;
	}
}

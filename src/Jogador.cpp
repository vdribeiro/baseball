#include "Jogador.h"

Jogador::Jogador(unsigned int cod, string name, string dn, string nac,
		unsigned int kg, float ht, string pos, double sal, string det)
: Pessoa(cod, name, dn, nac), peso(kg), altura(ht), posicao(pos), salario(sal), bio(det) {}

Jogador::~Jogador() {}

unsigned int Jogador::getpeso()
{return peso;}

void Jogador::setpeso(unsigned int kg)
{peso=kg;}

float Jogador::getaltura()
{return altura;}

void Jogador::setaltura(float ht)
{altura = ht;}

string Jogador::getpos()
{return posicao;}

void Jogador::setpos(string pos)
{posicao=pos;}

double Jogador::getsal()
{return salario;}

void Jogador::setsal(double sal)
{salario = sal;}

string Jogador::getbio()
{return bio;}

void Jogador::setbio(string det)
{bio = det;}

void Jogador::info()
{
	Pessoa::info();
	cout << "Peso: " << peso << endl;
	cout << "Altura: " << altura << endl;
	cout << "Posicao: " << posicao << endl;
	cout << "Salario: " << salario << endl;
	cout << "Biografia: " << bio << endl;
}

#include "Jogo.h"


Jogo::Jogo(unsigned int cod, Equipa *visitant, Equipa *visitad, string date, vector <Umpire *> arbito, unsigned int strike,
		unsigned int homrun, unsigned int spectadores, string result, string batidas, string erro):
		id (cod), visitante(visitant), visitado(visitad), data(date), arbitos(arbito), strikes(strike), homerun(homrun),
		espectadores(spectadores), resultado(result), Hit(batidas), error(erro)
		{}

Jogo::~Jogo() {}

unsigned int Jogo::getid()
{return id;}

void Jogo::setid(unsigned int cod)
{id = cod;}

Equipa *Jogo::getvisitante()
{return visitante;}

void Jogo::setvisitante (Equipa *visitant)
{visitante=visitant;}

Equipa *Jogo::getvisitado()
{return visitado;}

void Jogo::setvisitado (Equipa *visitad)
{visitado= visitad;}

string Jogo::getdata()
{return data;}

void Jogo::setdata(string date)
{data=date;}

vector <Umpire *> Jogo::getarbitos()
{return arbitos;}

void Jogo::setarbitos(vector <Umpire *> arbito)
{arbitos=arbito;}

unsigned int Jogo::getstrikes()
{return strikes;}

void Jogo::setstrikes(unsigned int strike)
{strikes=strike;}

unsigned int Jogo::gethomerun()
{return homerun;}

void Jogo::sethomerun (unsigned int homrun)
{homerun=homrun;}

unsigned int Jogo::getespectadores()
{return espectadores;}

void Jogo::setespectadores (unsigned int spectadores)
{espectadores=spectadores;}

string Jogo::getresultado()
{return resultado;}

void Jogo::setresultado (string result)
{resultado=result;}

string Jogo::gethit()
{return Hit;}

void Jogo::sethit (string batidas)
{Hit=batidas;}

string Jogo::geterror()
{return error;}

void Jogo::seterror (string erro)
{error=erro;}

void Jogo::imprime()
{
	cout << "Codigo: " << id << endl;
	cout << "Equipa visitante: " << endl;
	visitante->imprime();
	cout << "Equipa da casa: " << endl;
	visitado->imprime();
	cout << "Data: " << data << endl << endl;
	cout << "Arbito(s): " << endl;
	vector<Umpire*>::iterator it;
	for (it = arbitos.begin(); it != arbitos.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
	cout << "strikes: " << strikes << endl;
	cout << "Homerun: " << homerun << endl;
	cout << "Espectadores: " << espectadores << endl;
	cout << "Resultado: " << resultado << endl;
	cout << "Hit: " << Hit << endl;
	cout << "Erros: " << error << endl;
}

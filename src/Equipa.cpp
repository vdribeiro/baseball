#include "Equipa.h"

Equipa::Equipa(unsigned int cod, string name, Estadio *sta, vector <Jogador *> plr, ManagerGM *ctm, Manager *hch, PrepFisico *fis, string cnt, string spo, string det)
: id(cod), nome(name), est(sta), jog(plr), mgm(ctm), man(hch), prp(fis), pais(cnt), patrocinadores(spo), detalhes(det) {}

Equipa::~Equipa() {}

unsigned int Equipa::getid()
{return id;}

void Equipa::setid(unsigned int cod)
{id = cod;}

string Equipa::getnome()
{return nome;}

void Equipa::setnome(string name)
{nome=name;}

Estadio *Equipa::getest()
{return est;}

void Equipa::setest(Estadio *sta)
{est=sta;}

vector <Jogador *> Equipa::getjog()
{return jog;}

void Equipa::setjog(vector <Jogador *> plr)
{jog = plr;}

ManagerGM *Equipa::getmgm()
{return mgm;}

void Equipa::setmgm(ManagerGM *ctm)
{mgm=ctm;}

Manager *Equipa::getman()
{return man;}

void Equipa::setman(Manager *hch)
{man=hch;}

PrepFisico *Equipa::getfis()
{return prp;}

void Equipa::setfis(PrepFisico *fis)
{prp=fis;}

string Equipa::getpais()
{return pais;}

void Equipa::setpais(string nac)
{pais=nac;}

string Equipa::getpat()
{return patrocinadores;}

void Equipa::setpat(string pat)
{patrocinadores=pat;}

string Equipa::getdet()
{return detalhes;}

void Equipa::setdet(string det)
{detalhes=det;}

void Equipa::imprime()
{
	cout << endl << "Equipa" << endl;
	cout << "Codigo: " << id << endl;
	cout << "Nome: " << nome <<endl;
	cout << endl << "Estadio: " << endl;
	est->imprime();
	cout << endl << "Jogadores: " << endl;
	vector<Jogador*>::iterator it;
	for (it = jog.begin(); it != jog.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
	cout << "Manager GM: " << endl;
	mgm->info();
	cout << endl << "Manager: " << endl;
	man->info();
	cout << "Medicos: " << endl;
	prp->info();
	cout << endl << "Pais: " << pais << endl;
	cout << "Patrocinador(es): " << patrocinadores << endl;
	cout << "Detalhes: " << detalhes << endl;
}

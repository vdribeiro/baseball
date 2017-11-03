#include "Baseball.h"

//Construtor, Destrutor, Getters e Setters
Baseball::Baseball(unsigned int cod, string name, string version)
: id(cod), nome(name), versao(version) {}

Baseball::~Baseball() {}

unsigned int Baseball::getcod()
{return id;}

void Baseball::setcod(unsigned int cod)
{id=cod;}

string Baseball::getname()
{return nome;}

void Baseball::setname(string name)
{nome=name;}

string Baseball::getversao()
{return versao;}

void Baseball::setversao(string ver)
{versao=ver;}

vector <Utilizador *> Baseball::getuti()
{return utilizadores;}

void Baseball::setuti(vector <Utilizador *> uti)
{utilizadores=uti;}

vector <Campeonato *> Baseball::getcam()
{return campeonatos;}

void Baseball::setcam(vector <Campeonato *> cam)
{campeonatos=cam;}

vector <Jogo *> Baseball::getjog()
{return jogos;}

void Baseball::setjog(vector <Jogo *> jog)
{jogos=jog;}

vector <Equipa *> Baseball::getequ()
{return equipas;}

void Baseball::setequ(vector <Equipa *> equ)
{equipas=equ;}

vector <Estadio *> Baseball::getest()
{return estadios;}

void Baseball::setest(vector <Estadio *> est)
{estadios=est;}

vector <Jogador *> Baseball::getply()
{return jogadores;}

void Baseball::setply(vector <Jogador *> ply)
{jogadores=ply;}

vector <Manager *> Baseball::getman()
{return managers;}

void Baseball::setman(vector <Manager *> man)
{managers=man;}

vector <ManagerGM *> Baseball::getmgm()
{return mangms;}

void Baseball::setmgm(vector <ManagerGM *> mgm)
{mangms=mgm;}

vector <PrepFisico *> Baseball::getmed()
{return medicos;}

void Baseball::setmed(vector <PrepFisico *> med)
{medicos=med;}

vector <Treinador *> Baseball::gettre()
{return treinadores;}

void Baseball::settre(vector <Treinador *> tre)
{treinadores=tre;}

vector <Umpire *> Baseball::getarb()
{return arbitos;}

void Baseball::setarb(vector <Umpire *> arb)
{arbitos=arb;}

vector <Pessoa *> Baseball::getpes()
{return pessoas;}

void Baseball::setpes(vector <Pessoa *> pes)
{pessoas=pes;}
//---------------------------------------------------------------------

//Info
void Baseball::imprime()
{
	cout << "Id: " << id << endl;
	cout << "Nome: " << nome << endl;
	cout << "Versao: " << versao << endl << endl;
}

void Baseball::infouti()
{
	vector<Utilizador *>::iterator it;
	for (it = utilizadores.begin(); it != utilizadores.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}

void Baseball::infocmp()
{
	vector<Campeonato *>::iterator it;
	for (it = campeonatos.begin(); it != campeonatos.end(); it++)
	{
		(*it)->imprime();
		cout << endl;
	}
}

void Baseball::infocmp(unsigned int year)
{
	vector<Campeonato *>::iterator it;
	for (it = campeonatos.begin(); it != campeonatos.end(); it++)
	{
		if (year==(*it)->getano())
		{
			(*it)->imprime();
			cout << endl;
		}
	}
}

void Baseball::infojog()
{
	vector<Jogo *>::iterator it;
	for (it = jogos.begin(); it != jogos.end(); it++)
	{
		(*it)->imprime();
		cout << endl;
	}
}

void Baseball::infoequ()
{
	vector<Equipa *>::iterator it;
	for (it = equipas.begin(); it != equipas.end(); it++)
	{
		(*it)->imprime();
		cout << endl;
	}

}

void Baseball::infoest()
{
	vector<Estadio *>::iterator it;
	for (it = estadios.begin(); it != estadios.end(); it++)
	{
		(*it)->imprime();
		cout << endl;
	}
}

void Baseball::infoply()
{
	vector<Jogador *>::iterator it;
	for (it = jogadores.begin(); it != jogadores.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}

void Baseball::infoman()
{
	vector<Manager *>::iterator it;
	for (it = managers.begin(); it != managers.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}

void Baseball::infomgm()
{
	vector<ManagerGM *>::iterator it;
	for (it = mangms.begin(); it != mangms.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}

void Baseball::infoprp()
{
	vector<PrepFisico *>::iterator it;
	for (it = medicos.begin(); it != medicos.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}

void Baseball::infotrn()
{
	vector<Treinador *>::iterator it;
	for (it = treinadores.begin(); it != treinadores.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}

void Baseball::infoarb()
{
	vector<Umpire *>::iterator it;
	for (it = arbitos.begin(); it != arbitos.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}

void Baseball::infoppl()
{
	if (Baseball::loadppl()==false)
	{return;}
	vector<Pessoa *>::iterator it;
	for (it = pessoas.begin(); it != pessoas.end(); it++)
	{
		(*it)->info();
		cout << endl;
	}
}
//---------------------------------------------------------------------

//Procura
//Iteradores
vector <Utilizador *>::iterator Baseball::getituti(unsigned int id)
{
	vector <Utilizador *>::iterator iter;
    for (iter = utilizadores.begin(); iter != utilizadores.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <Campeonato *>::iterator Baseball::getitcmp(unsigned int id)
{
	vector <Campeonato *>::iterator iter;
    for (iter = campeonatos.begin(); iter != campeonatos.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <Jogo *>::iterator Baseball::getitjgo(unsigned int id)
{
	vector <Jogo *>::iterator iter;
    for (iter = jogos.begin(); iter != jogos.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <Equipa *>::iterator Baseball::getitequ(unsigned int id)
{
	vector <Equipa *>::iterator iter;
    for (iter = equipas.begin(); iter != equipas.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <Estadio *>::iterator Baseball::getitest(unsigned int id)
{
	vector <Estadio *>::iterator iter;
    for (iter = estadios.begin(); iter != estadios.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <Jogador *>::iterator Baseball::getitply(unsigned int id)
{
	vector <Jogador *>::iterator iter;
    for (iter = jogadores.begin(); iter != jogadores.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <Manager *>::iterator Baseball::getitman(unsigned int id)
{
	vector <Manager *>::iterator iter;
    for (iter = managers.begin(); iter != managers.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <ManagerGM *>::iterator Baseball::getitmgm(unsigned int id)
{
	vector <ManagerGM *>::iterator iter;
    for (iter = mangms.begin(); iter != mangms.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <PrepFisico *>::iterator Baseball::getitfis(unsigned int id)
{
	vector <PrepFisico *>::iterator iter;
    for (iter = medicos.begin(); iter != medicos.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <Treinador *>::iterator Baseball::getittrn(unsigned int id)
{
	vector <Treinador *>::iterator iter;
    for (iter = treinadores.begin(); iter != treinadores.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

vector <Umpire *>::iterator Baseball::getitarb(unsigned int id)
{
	vector <Umpire *>::iterator iter;
    for (iter = arbitos.begin(); iter != arbitos.end(); iter++)
		if ((*iter)->getid() == id)
			return iter;

	return iter;
}

//Objectos
Utilizador *Baseball::getobjuti(unsigned int id)
{
	vector <Utilizador *>::iterator iter;
	for (iter = utilizadores.begin(); iter != utilizadores.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

Campeonato *Baseball::getobjcmp(unsigned int id)
{
	vector <Campeonato *>::iterator iter;
	for (iter = campeonatos.begin(); iter != campeonatos.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

Jogo *Baseball::getobjjgo(unsigned int id)
{
	vector <Jogo *>::iterator iter;
	for (iter = jogos.begin(); iter != jogos.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

Equipa *Baseball::getobjequ(unsigned int id)
{
	vector <Equipa *>::iterator iter;
	for (iter = equipas.begin(); iter != equipas.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

Estadio *Baseball::getobjest(unsigned int id)
{
	vector <Estadio *>::iterator iter;
	for (iter = estadios.begin(); iter != estadios.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

Jogador *Baseball::getobjply(unsigned int id)
{
	vector <Jogador *>::iterator iter;
	for (iter = jogadores.begin(); iter != jogadores.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

Manager *Baseball::getobjman(unsigned int id)
{
	vector <Manager *>::iterator iter;
	for (iter = managers.begin(); iter != managers.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

ManagerGM *Baseball::getobjmgm(unsigned int id)
{
	vector <ManagerGM *>::iterator iter;
	for (iter = mangms.begin(); iter != mangms.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

PrepFisico *Baseball::getobjfis(unsigned int id)
{
	vector <PrepFisico *>::iterator iter;
	for (iter = medicos.begin(); iter != medicos.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

Treinador *Baseball::getobjtrn(unsigned int id)
{
	vector <Treinador *>::iterator iter;
	for (iter = treinadores.begin(); iter != treinadores.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}

Umpire *Baseball::getobjarb(unsigned int id)
{
	vector <Umpire *>::iterator iter;
	for (iter = arbitos.begin(); iter != arbitos.end(); iter++)
		if ((*iter)->getid() == id)
			return (*iter);

	return NULL;
}
//---------------------------------------------------------------------

//Vectores
//-Inicializa vectores
bool Baseball::init()
{
	try
	{
		if (utilizadores.empty())
		{
			Utilizador *ut = new Utilizador(1, "Administrador", "02/12/1986", "Portugues", "admin", 1);
			utilizadores.push_back(ut);
		}
		if ((jogadores.empty()) && (arbitos.empty()) && (medicos.empty()) && (mangms.empty()) &&
				(treinadores.empty()) && (managers.empty()) && (estadios.empty()) &&
				(equipas.empty()) && (jogos.empty()) && (campeonatos.empty()))
		{
			Jogador *j1 = new Jogador(1, "Soneca", "01/01/0000", "Portugues", 60, 1.80, "CF", 1000000.999,
					"De origem desconhecida, Soneca e considerado o primeiro jogador do Baseball.");
			jogadores.push_back(j1);
			Jogador *j2 = new Jogador(2, "Tomy", "03/03/1989", "Portugues", 70, 1.72, "P", 500,
					"Jogador olho de aguia");
			jogadores.push_back(j2);
			Jogador *j3 = new Jogador(3, "Vitor", "02/12/1986", "Portugues", 60, 1.80, "C", 0.2,
					"Jovem humilde de salario a condizer, encontra-se neste momento a confecionar panquecas para o pequeno-almoco.");
			jogadores.push_back(j3);
			Jogador *j4 = new Jogador(4, "Deus-Rei do Sol", "02/07/1991", "Solarius", 50, 1.70, "2B", 2012,
					"Nascer a meio do ano, a meio do dia, meia hora depois, fez Ze Manel renascer como o Deus do Sol.");
			jogadores.push_back(j4);
			Jogador *j5 = new Jogador(5, "Pablo", "20/02/2002", "Espanhol", 30, 0.50, "3B", 70,
					"Pablo ou Pablosito e a mais recente aquisicao do Portugal do Pequeninos.");
			jogadores.push_back(j5);
			Jogador *j6 = new Jogador(6, "Miguel Joao", "29/08/1958", "Terra do Nunca", 50, 1.75, "1B", 999999,
					"Conhecido no mundo artistico como o Rei do Pop, mudou de nome quando ouviu falar de Portugal.");
			jogadores.push_back(j6);
			Jogador *j7 = new Jogador(7, "Monstro Maritimo", "04/03/1974", "Marugues", 160, 2.50, "SS", 10,
					"Monstro Maritimo procura parceira para amar.");
			jogadores.push_back(j7);

			Umpire *u = new Umpire(1, "Kowalski", "17/06/1969", "Polaco",
					"Adora Koalas");
			arbitos.push_back(u);

			PrepFisico *p1 = new PrepFisico(1, "House", "11/06/1959", "Ingles",
					"O melhor medico do mundo e tambem estrela de uma serie televisiva.");
			medicos.push_back(p1);
			PrepFisico *p2 = new PrepFisico(2, "Professor Xibanga", "24/12/1975", "Africano",
					"Aprendeu as tecnicas com um xama tribal e desvia o mau olhado com macumbas.");
			medicos.push_back(p2);

			ManagerGM *g1 = new ManagerGM(1, "Contract", "05/06/1987", "Libanes",
					"Especialista de contratos, o nome diz tudo.");
			mangms.push_back(g1);
			ManagerGM *g2 = new ManagerGM(2, "Diana", "05/06/1987", "Portuguesa",
					"Contabilista mestre e auditora de gema.");
			mangms.push_back(g2);

			Treinador *t1 = new Treinador(1, "Kapinos", "09/09/1981", "LaLonge",
					"Uns kapinos ali outros kapinos acola.");
			treinadores.push_back(t1);
			Treinador *t2 = new Treinador(2, "Clone1", "06/06/1984", "Dolly Research Center",
					"CONFIDENCIAL");
			treinadores.push_back(t2);
			Treinador *t3 = new Treinador(3, "Clone2", "06/06/1986", "Dolly Research Center",
					"CONFIDENCIAL");
			treinadores.push_back(t3);

			vector <Treinador *> coa1;
			vector <Treinador *> coa2;
			coa1.push_back(t1);
			coa2.push_back(t2);
			coa2.push_back(t3);
			Manager *m1 = new Manager(1, "Brutus", "02/07/1978", "Italiano", coa1,
					"Conhecido como O Penedo, este manager e uma versao moderna do exterminador.");
			managers.push_back(m1);
			Manager *m2 = new Manager(2, "CEO", "23/11/1959", "Desconhecida", coa2,
					"Presidente da DRS (Dolly Research Center) este homem misterioso nunca dispensa da presenca dos seus dois clones.");
			managers.push_back(m2);

			Estadio *e1 = new Estadio(1, "O REAL E VERDADEIRO ESTADIO", 50505);
			estadios.push_back(e1);
			Estadio *e2 = new Estadio(2, "O VERDADEIRO E REAL ESTADIO", 50505);
			estadios.push_back(e2);

			vector <Jogador *> plr1;
			vector <Jogador *> plr2;
			plr1.push_back(j1);
			plr1.push_back(j2);
			plr1.push_back(j3);
			plr2.push_back(j4);
			plr2.push_back(j5);
			plr2.push_back(j6);
			Equipa *i1= new Equipa(1, "Os Grandes", e1, plr1, g2, m1, p1, "Portugal", "Induflex", "A equipa boa.");
			equipas.push_back(i1);
			Equipa *i2= new Equipa(2, "Os Maiores", e2, plr2, g1, m2, p2, "Espanha", "Indux", "A equipa ma.");
			equipas.push_back(i2);

			vector <Umpire *> arbs;
			arbs.push_back(u);
			Jogo *ojogo = new Jogo(1, i1, i2, "12/12/2012", arbs, 9, 9, 50000, "9-9", "99", "0");
			jogos.push_back(ojogo);

			vector <Jogo *> jos;
			jos.push_back(ojogo);
			Campeonato *c = new Campeonato(1, "Liga Mundo", jos, 2012);
			campeonatos.push_back(c);
		}

	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	return true;
}
//-Limpa vectores
bool Baseball::resetdados()
{
	try
	{
		utilizadores.clear();
		campeonatos.clear();
		jogos.clear();
		equipas.clear();
		estadios.clear();
		jogadores.clear();
		managers.clear();
		mangms.clear();
		medicos.clear();
		treinadores.clear();
		arbitos.clear();
		pessoas.clear();
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	return true;
}
//---------------------------------------------------------------------

//CRUD
//Utilizadores
bool Baseball::adduti()
{
	unsigned int idu, prioridade;
	string name, data_nasc, nacionalidade, pass;
	if (utilizadores.empty())
	{
		idu = 1;
	} else
	{
		idu = utilizadores.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira password: ";
	cin >> pass;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	do
	{
		cout << "Insira prioridade (1- Administrador | 2- Utilizador): ";
		cin >> prioridade;
	} while ((prioridade<1) || (prioridade>2));
	try
	{
		Utilizador *u = new Utilizador(idu, name, data_nasc, nacionalidade, pass, prioridade);
		utilizadores.push_back(u);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
	    return false;
	}
	cout << "Utilizador adicionado" << endl << "O seu login e: " << idu << endl;
	return true;
}

bool Baseball::edtuti()
{
	unsigned int idu, prioridade;
	string name, data_nasc, nacionalidade, pass;
	cout << "Insira id: ";
	cin >> idu;
	vector <Utilizador *>::iterator iter;
	iter = Baseball::getituti(idu);
	if (iter == utilizadores.end())
	{
		cout << "Utilizador inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira password: ";
	cin >> pass;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	do
	{
		cout << "Insira prioridade (1- Administrador | 2- Utilizador): ";
		cin >> prioridade;
	} while ((prioridade<1) || (prioridade>2));
	try
	{
		(*iter)->setnome(name);
		(*iter)->setpass(pass);
		(*iter)->setdn(data_nasc);
		(*iter)->setnac(nacionalidade);
		(*iter)->setpri(prioridade);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Utilizador editado" << endl;
	return true;
}

bool Baseball::rmvuti()
{
	unsigned int idu;
	cout << "Insira id: ";
	cin >> idu;
	vector <Utilizador *>::iterator iter;
	iter = Baseball::getituti(idu);
	if (iter == utilizadores.end())
	{
		cout << "Utilizador inexistente" << endl;
		return false;
	}
	try
	{
		delete (*iter);
		utilizadores.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Utilizador removido" << endl;
	return true;
}

//Campeonatos
bool Baseball::addcmp()
{
	unsigned int idc, idj, year;
	string name;
	vector <Jogo *> jogos;
	if (campeonatos.empty())
	{
		idc = 1;
	} else
	{
		idc = campeonatos.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira ano: ";
	cin >> year;
	cout << "Insira id dos jogos (0 para sair): " << endl;
	Jogo *game;
	do
	{
		cin >> idj;
		if (idj!=0)
		{
			game = Baseball::getobjjgo(idj);
			if (game == NULL)
			{
				cout << "Jogo inexistente" << endl;
			} else
			{
				jogos.push_back(game);
				cout << "Adicionado" << endl;
			}
		}
	} while (idj!=0);
	try
	{
		Campeonato *c = new Campeonato(idc, name, jogos, year);
		campeonatos.push_back(c);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Campeonato adicionado com id: " << idc << endl;
	return true;
}

bool Baseball::edtcmp()
{
	unsigned int idc, idj, year;
	string name;
	vector <Jogo *> jogos;
	cout << "Insira id: ";
	cin >> idc;
	vector <Campeonato *>::iterator iter;
	iter = Baseball::getitcmp(idc);
	if (iter == campeonatos.end())
	{
		cout << "Campeonato inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira ano: ";
	cin >> year;
	cout << "Insira id dos jogos (0 para sair): " << endl;
	Jogo *game;
	do
	{
		cin >> idj;
		if (idj!=0)
		{
			game = Baseball::getobjjgo(idj);
			if (game == NULL)
			{
				cout << "Jogo inexistente" << endl;
			} else
			{
				jogos.push_back(game);
				cout << "Adicionado" << endl;
			}
		}
	} while (idj!=0);
	try
	{
		(*iter)->setnome(name);
		(*iter)->setjogos(jogos);
		(*iter)->setano(year);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Campeonato editado" << endl;
	return true;
}

bool Baseball::rmvcmp()
{
	unsigned int idc;
	cout << "Insira id: ";
	cin >> idc;
	vector <Campeonato *>::iterator iter;
	iter = Baseball::getitcmp(idc);
	if (iter == campeonatos.end())
	{
		cout << "Campeonato inexistente" << endl;
		return false;
	}
	try
	{
		delete (*iter);
		campeonatos.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Campeonato removido" << endl;
	return true;
}

//Jogos
bool Baseball::addjgo()
{
	unsigned int idj, idg, idh, ida;
	Equipa *visitante;
	Equipa *visitado;
	string data;
	vector <Umpire *> umps;
	unsigned int strikes;
	unsigned int homerun;
	unsigned int espectadores;
	string resultado;
	string hits;
	string erros;
	if (equipas.empty())
	{
		cout << "Nao existem equipas" << endl;
		return false;
	}
	if (jogos.empty())
	{
		idj=1;
	} else
	{
		idj = jogos.back()->getid() + 1;
	}
	cout << "Insira id da equipa visitante: ";
	do
	{
		cin >> idg;
		visitante = Baseball::getobjequ(idg);
		if (visitante == NULL)
		{
			cout << "Equipa inexistente" << endl;
		}
	} while (visitante==NULL);
	cout << "Insira id da equipa visitada: ";
	do
	{
		cin >> idh;
		visitado = Baseball::getobjequ(idh);
		if (visitado == NULL)
		{
			cout << "Equipa inexistente" << endl;
		}
	} while (visitado==NULL);
	cout << "Insira data: ";
	cin >> data;
	cout << "Insira id dos arbitos (0 para sair): " << endl;
	Umpire *arbit;
	do
	{
		cin >> ida;
		if (ida!=0)
		{
			arbit = Baseball::getobjarb(ida);
			if (arbit == NULL)
			{
				cout << "Arbito inexistente" << endl;
			} else
			{
				umps.push_back(arbit);
				cout << "Adicionado" << endl;
			}
		}
	} while (ida!=0);
	cout << "Insira nº de strikes: ";
	cin >> strikes;
	cout << "Insira nº de homeruns: ";
	cin >> homerun;
	cout << "Insira nº de espectadores: ";
	cin >> espectadores;
	cout << "Insira resultado do jogo: ";
	cin >> resultado;
	cout << "Insira nº de batidas: ";
	cin >> hits;
	cout << "Insira nº de erros: ";
	cin >> erros;
	try
	{
		Jogo *j = new Jogo(idj, visitante, visitado, data, umps, strikes, homerun, espectadores, resultado, hits, erros); //Construtor
		jogos.push_back(j);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Jogo adicionado com id: " << idj << endl;
	return true;
}

bool Baseball::edtjgo()
{
	unsigned int idj, idg, idh, ida;
	Equipa *visitante;
	Equipa *visitado;
	string data;
	vector <Umpire *> umps;
	unsigned int strikes;
	unsigned int homerun;
	unsigned int espectadores;
	string resultado;
	string hits;
	string erros;
	cout << "Insira id: ";
	cin >> idj;
	vector <Jogo *>::iterator iter;
	iter = Baseball::getitjgo(idj);
	if (iter == jogos.end())
	{
		cout << "Jogo inexistente" << endl;
		return false;
	}
	cout << "Insira id da equipa visitante: ";
	do
	{
		cin >> idg;
		visitante = Baseball::getobjequ(idg);
		if (visitante == NULL)
		{
			cout << "Equipa inexistente" << endl;
		}
	} while (visitante==NULL);
	cout << "Insira id da equipa visitada: ";
	do
	{
		cin >> idh;
		visitado = Baseball::getobjequ(idh);
		if (visitado == NULL)
		{
			cout << "Equipa inexistente" << endl;
		}
	} while (visitado==NULL);
	cout << "Insira data: ";
	cin >> data;
	cout << "Insira id dos arbitos (0 para sair): " << endl;
	Umpire *arbit;
	do
	{
		cin >> ida;
		if (ida!=0)
		{
			arbit = Baseball::getobjarb(ida);
			if (arbit == NULL)
			{
				cout << "Arbito inexistente" << endl;
			} else
			{
				umps.push_back(arbit);
				cout << "Adicionado" << endl;
			}
		}
	} while (ida!=0);
	cout << "Insira nº de strikes: ";
	cin >> strikes;
	cout << "Insira nº de homeruns: ";
	cin >> homerun;
	cout << "Insira nº de espectadores: ";
	cin >> espectadores;
	cout << "Insira resultado do jogo: ";
	cin >> resultado;
	cout << "Insira nº de batidas: ";
	cin >> hits;
	cout << "Insira nº de erros: ";
	cin >> erros;
	try
	{
		(*iter)->setvisitante(visitante);
		(*iter)->setvisitado(visitado);
		(*iter)->setdata(data);
		(*iter)->setarbitos(umps);
		(*iter)->setstrikes(strikes);
		(*iter)->sethomerun(homerun);
		(*iter)->setespectadores(espectadores);
		(*iter)->setresultado(resultado);
		(*iter)->sethit(hits);
		(*iter)->seterror(erros);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Jogo editado"  << endl;
	return true;
}

bool Baseball::rmvjgo()
{
	unsigned int idj;
	cout << "Insira id: ";
	cin >> idj;
	vector <Jogo *>::iterator iter;
	iter = Baseball::getitjgo(idj);
	if (iter == jogos.end())
	{
		cout << "Jogo inexistente" << endl;
		return false;
	}
	try
	{
		delete (*iter);
		jogos.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Jogo removido" << endl;
	return true;
}

//Equipas
bool Baseball::addequ()
{
	unsigned int idt, ide, idj, idg, idm, idp;
	string name;
	Estadio *est;
	vector <Jogador *> jog;
	ManagerGM *mgm;
	Manager *man;
	PrepFisico *prp;
	string pais;
	string patrocinadores;
	string detalhes;
	if (equipas.empty())
	{
		idt=1;
	} else
	{
		idt = equipas.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira id do estadio (0 para nenhum): ";
	do
	{
		cin >> ide;
		if (ide!=0)
		{
			est = Baseball::getobjest(ide);
			if (est == NULL)
			{
				cout << "Estadio inexistente" << endl;
			} else
			{
				ide=0;
			}
		}
	} while (ide!=0);
	cout << "Insira id dos jogadores (0 para sair): " << endl;
	Jogador *player;
	do
	{
		cin >> idj;
		if (idj!=0)
		{
			player = Baseball::getobjply(idj);
			if (player == NULL)
			{
				cout << "Jogador inexistente" << endl;
			} else
			{
				jog.push_back(player);
				cout << "Adicionado" << endl;
			}
		}
	} while (idj!=0);
	cout << "Insira id do GM (0 para nenhum): ";
	do
	{
		cin >> idg;
		if (idg!=0)
		{
			mgm = Baseball::getobjmgm(idg);
			if (mgm == NULL)
			{
				cout << "GM inexistente" << endl;
			} else
			{
				idg=0;
			}
		}
	} while (idg!=0);
	cout << "Insira id do manager (0 para nenhum): ";
	do
	{
		cin >> idm;
		if (idm!=0)
		{
			man = Baseball::getobjman(idm);
			if (man == NULL)
			{
				cout << "Manager inexistente" << endl;
			} else
			{
				idm=0;
			}
		}
	} while (idm!=0);
	cout << "Insira id do preparador fisico (0 para nenhum): ";
	do
	{
		cin >> idp;
		if (idp!=0)
		{
			prp = Baseball::getobjfis(idp);
			if (prp == NULL)
			{
				cout << "Preparador inexistente" << endl;
			} else
			{
				idp=0;
			}
		}
	} while (idp!=0);
	cout << "Insira pais: ";
	cin >> pais;
	cout << "Insira patrocinadores: ";
	cin >> patrocinadores;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		Equipa *e = new Equipa(idt, name, est, jog, mgm, man, prp, pais, patrocinadores, detalhes);
		equipas.push_back(e);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Equipa adicionada com id: " << idt << endl;
	return true;
}

bool Baseball::edtequ()
{
	unsigned int idt, ide, idj, idg, idm, idp;
	string name;
	Estadio *est;
	vector <Jogador *> jog;
	ManagerGM *mgm;
	Manager *man;
	PrepFisico *prp;
	string pais;
	string patrocinadores;
	string detalhes;
	cout << "Insira id: ";
	cin >> idt;
	vector <Equipa *>::iterator iter;
	iter = Baseball::getitequ(idt);
	if (iter == equipas.end())
	{
		cout << "Equipa inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira id do estadio (0 para nenhum): ";
	do
	{
		cin >> ide;
		if (ide!=0)
		{
			est = Baseball::getobjest(ide);
			if (est == NULL)
			{
				cout << "Estadio inexistente" << endl;
			} else
			{
				ide=0;
			}
		}
	} while (ide!=0);
	cout << "Insira id dos jogadores (0 para sair): " << endl;
	Jogador *player;
	do
	{
		cin >> idj;
		if (idj!=0)
		{
			player = Baseball::getobjply(idj);
			if (player == NULL)
			{
				cout << "Jogador inexistente" << endl;
			} else
			{
				jog.push_back(player);
				cout << "Adicionado" << endl;
			}
		}
	} while (idj!=0);
	cout << "Insira id do GM (0 para nenhum): ";
	do
	{
		cin >> idg;
		if (idg!=0)
		{
			mgm = Baseball::getobjmgm(idg);
			if (mgm == NULL)
			{
				cout << "GM inexistente" << endl;
			} else
			{
				idg=0;
			}
		}
	} while (idg!=0);
	cout << "Insira id do manager (0 para nenhum): ";
	do
	{
		cin >> idm;
		if (idm!=0)
		{
			man = Baseball::getobjman(idm);
			if (man == NULL)
			{
				cout << "Manager inexistente" << endl;
			} else
			{
				idm=0;
			}
		}
	} while (idm!=0);
	cout << "Insira id do preparador fisico (0 para nenhum): ";
	do
	{
		cin >> idp;
		if (idp!=0)
		{
			prp = Baseball::getobjfis(idp);
			if (prp == NULL)
			{
				cout << "Preparador inexistente" << endl;
			} else
			{
				idp=0;
			}
		}
	} while (idp!=0);
	cout << "Insira pais: ";
	cin >> pais;
	cout << "Insira patrocinadores: ";
	cin >> patrocinadores;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		//idt, name, est, jog, mgm, man, prp, pais, patrocinadores, detalhes
		(*iter)->setnome(name);
		(*iter)->setest(est);
		(*iter)->setjog(jog);
		(*iter)->setmgm(mgm);
		(*iter)->setman(man);
		(*iter)->setfis(prp);
		(*iter)->setpais(pais);
		(*iter)->setpat(patrocinadores);
		(*iter)->setdet(detalhes);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Equipa editada" << endl;
	return true;
}

bool Baseball::rmvequ()
{
	unsigned int ide;
	cout << "Insira id: ";
	cin >> ide;
	vector <Equipa *>::iterator iter;
	iter = Baseball::getitequ(ide);
	if (iter == equipas.end())
	{
		cout << "Equipa inexistente" << endl;
		return false;
	}
	try
	{
		delete (*iter);
		equipas.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Equipa removido" << endl;
	return true;
}

//Estadios
bool Baseball::addest()
{
	unsigned int ids;
	string name;
	unsigned int capacidade;
	if (estadios.empty())
	{
		ids=1;
	} else
	{
		ids = estadios.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira capacidade: ";
	cin >> capacidade;
	try
	{
		Estadio *e = new Estadio(ids, name, capacidade);
		estadios.push_back(e);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Estadio adicionado com id: " << ids << endl;
	return true;
}

bool Baseball::edtest()
{
	unsigned int ids, capacidade;
	string name;
	cout << "Insira id: ";
	cin >> ids;
	vector <Estadio *>::iterator iter;
	iter = Baseball::getitest(ids);
	if (iter == estadios.end())
	{
		cout << "Estadio inexistente." << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira capacidade: ";
	cin >> capacidade;
	try
	{
		(*iter)->setnome(name);
		(*iter)->setcap(capacidade);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Estadio editado" << endl;
	return true;
}

bool Baseball::rmvest()
{
	unsigned int ids;
	cout << "Insira id: ";
	cin >> ids;
	vector <Estadio *>::iterator iter;
	iter = Baseball::getitest(ids);
	if (iter == estadios.end())
	{
		cout << "Estadio inexistente." << endl;
		return false;
	}
	try
	{
		delete (*iter);
		estadios.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Estadio removido" << endl;
	return true;
}

//-Jogadores
bool Baseball::addply()
{
	unsigned int idp;
	string name, data_nasc, nacionalidade;
	unsigned int peso;
	float altura;
	string posicao, bio;
	double salario;
	if (jogadores.empty())
	{
		idp = 1;
	} else
	{
		idp = jogadores.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira peso: ";
	cin >> peso;
	cout << "Insira altura: ";
	cin >> altura;
	cout << "POSICOES" << endl <<
	"P: Pitcher" << endl << "C: Catcher" << endl << "SS: Shortstop" << endl <<
	"1B: First Base" << endl << "2B: Second Base" << endl << "3B: Third Base" << endl <<
	"LF: Left Field" << endl << "CF: Center Field" << endl << "RF: Right Field" << endl;
	cout << "Insira posicao:" << endl;
	cin >> posicao;
	cout << "Insira salario: ";
	cin >> salario;
	cout << "Insira biografia: ";
	cin >> bio;
	try
	{
		Jogador *j = new Jogador(idp, name, data_nasc, nacionalidade, peso, altura, posicao, salario, bio);
		jogadores.push_back(j);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Jogador adicionado" << endl << "O seu id e: " << idp << endl;
	return true;
}

bool Baseball::edtply()
{
	unsigned int idp;
	string name, data_nasc, nacionalidade;
	unsigned int peso;
	float altura;
	string posicao, bio;
	double salario;
	cout << "Insira id: ";
	cin >> idp;
	vector <Jogador *>::iterator iter;
	iter = Baseball::getitply(idp);
	if (iter == jogadores.end())
	{
		cout << "Jogador inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira peso: ";
	cin >> peso;
	cout << "Insira altura: ";
	cin >> altura;
	cout << "POSICOES" << endl <<
	"P: Pitcher" << endl << "C: Catcher" << endl << "SS: Shortstop" << endl <<
	"1B: First Base" << endl << "2B: Second Base" << endl << "3B: Third Base" << endl <<
	"LF: Left Field" << endl << "CF: Center Field" << endl << "RF: Right Field" << endl;
	cout << "Insira posicao:" << endl;
	cin >> posicao;
	cout << "Insira salario: ";
	cin >> salario;
	cout << "Insira biografia: ";
	cin >> bio;
	try
	{
		(*iter)->setnome(name);
		(*iter)->setdn(data_nasc);
		(*iter)->setnac(nacionalidade);
		(*iter)->setpeso(peso);
		(*iter)->setaltura(altura);
		(*iter)->setpos(posicao);
		(*iter)->setsal(salario);
		(*iter)->setbio(bio);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Jogador editado" << endl;
	return true;
}

bool Baseball::rmvply()
{
	unsigned int idp;
	cout << "Insira id: ";
	cin >> idp;
	vector <Jogador *>::iterator iter;
	iter = Baseball::getitply(idp);
	if (iter == jogadores.end())
	{
		cout << "Jogador inexistente." << endl;
		return false;
	}
	try
	{
		delete (*iter);
		jogadores.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Jogador removido" << endl;
	return true;
}

//-Managers
bool Baseball::addman()
{
	unsigned int idm, idt;
	string name, data_nasc, nacionalidade;
	vector <Treinador *> trn;
	string detalhes;
	if (managers.empty())
	{
		idm = 1;
	} else
	{
		idm = managers.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira id dos treinadores (0 para sair): " << endl;
	Treinador *treina;
	do
	{
		cin >> idt;
		if (idt!=0)
		{
			treina = Baseball::getobjtrn(idt);
			if (treina == NULL)
			{
				cout << "Treinador inexistente" << endl;
			} else
			{
				trn.push_back(treina);
				cout << "Adicionado" << endl;
			}
		}
	} while (idt!=0);
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		Manager *m = new Manager(idm, name, data_nasc, nacionalidade, trn, detalhes);
		managers.push_back(m);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Manager adicionado" << endl << "O seu id e: " << idm << endl;
	return true;
}

bool Baseball::edtman()
{
	unsigned int idm, idt;
	string name, data_nasc, nacionalidade, detalhes;
	vector <Treinador *> trn;
	cout << "Insira id: ";
	cin >> idm;
	vector <Manager *>::iterator iter;
	iter = Baseball::getitman(idm);
	if (iter == managers.end())
	{
		cout << "Manager inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira id dos treinadores (0 para sair): " << endl;
	Treinador *treina;
	do
	{
		cin >> idt;
		if (idt!=0)
		{
			treina = Baseball::getobjtrn(idt);
			if (treina == NULL)
			{
				cout << "Treinador inexistente" << endl;
			} else
			{
				trn.push_back(treina);
				cout << "Adicionado" << endl;
			}
		}
	} while (idt!=0);
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		(*iter)->setnome(name);
		(*iter)->setdn(data_nasc);
		(*iter)->setnac(nacionalidade);
		(*iter)->settrn(trn);
		(*iter)->setdet(detalhes);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Manager editado" << endl;
	return true;
}

bool Baseball::rmvman()
{
	unsigned int idm;
	cout << "Insira id: ";
	cin >> idm;
	vector <Manager *>::iterator iter;
	iter = Baseball::getitman(idm);
	if (iter == managers.end())
	{
		cout << "Manager inexistente." << endl;
		return false;
	}
	try
	{
		delete (*iter);
		managers.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Manager removido" << endl;
	return true;
}

//-GM's
bool Baseball::addmgm()
{
	unsigned int idg;
	string name, data_nasc, nacionalidade, detalhes;
	if (mangms.empty())
	{
		idg = 1;
	} else
	{
		idg = mangms.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		ManagerGM *g = new ManagerGM(idg, name, data_nasc, nacionalidade, detalhes);
		mangms.push_back(g);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "GM adicionado" << endl << "O seu id e: " << idg << endl;
	return true;
}

bool Baseball::edtmgm()
{
	unsigned int idg;
	string name, data_nasc, nacionalidade, detalhes;
	cout << "Insira id: ";
	cin >> idg;
	vector <ManagerGM *>::iterator iter;
	iter = Baseball::getitmgm(idg);
	if (iter == mangms.end())
	{
		cout << "GM inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		(*iter)->setnome(name);
		(*iter)->setdn(data_nasc);
		(*iter)->setnac(nacionalidade);
		(*iter)->setdet(detalhes);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "GM editado" << endl;
	return true;
}

bool Baseball::rmvmgm()
{
	unsigned int idg;
	cout << "Insira id: ";
	cin >> idg;
	vector <ManagerGM *>::iterator iter;
	iter = Baseball::getitmgm(idg);
	if (iter == mangms.end())
	{
		cout << "GM inexistente." << endl;
		return false;
	}
	try
	{
		delete (*iter);
		mangms.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "GM removido" << endl;
	return true;
}

//-Medicos
bool Baseball::addfis()
{
	unsigned int idf;
	string name, data_nasc, nacionalidade, detalhes;
	if (medicos.empty())
	{
		idf = 1;
	} else
	{
		idf = medicos.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		PrepFisico *m = new PrepFisico(idf, name, data_nasc, nacionalidade, detalhes);
		medicos.push_back(m);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Medico adicionado" << endl << "O seu id e: " << idf << endl;
	return true;
}

bool Baseball::edtfis()
{
	unsigned int idf;
	string name, data_nasc, nacionalidade, detalhes;
	cout << "Insira id: ";
	cin >> idf;
	vector <PrepFisico *>::iterator iter;
	iter = Baseball::getitfis(idf);
	if (iter == medicos.end())
	{
		cout << "Medico inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		(*iter)->setnome(name);
		(*iter)->setdn(data_nasc);
		(*iter)->setnac(nacionalidade);
		(*iter)->setdet(detalhes);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Medico editado" << endl;
	return true;
}

bool Baseball::rmvfis()
{
	unsigned int idf;
	cout << "Insira id: ";
	cin >> idf;
	vector <PrepFisico *>::iterator iter;
	iter = Baseball::getitfis(idf);
	if (iter == medicos.end())
	{
		cout << "Preparador inexistente." << endl;
		return false;
	}
	try
	{
		delete (*iter);
		medicos.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Preparador removido" << endl;
	return true;
}

//-Treinadores
bool Baseball::addtrn()
{
	unsigned int idt;
	string name, data_nasc, nacionalidade, detalhes;
	if (treinadores.empty())
	{
		idt = 1;
	} else
	{
		idt = treinadores.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		Treinador *t = new Treinador(idt, name, data_nasc, nacionalidade, detalhes);
		treinadores.push_back(t);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Treinador adicionado" << endl << "O seu id e: " << idt << endl;
	return true;
}

bool Baseball::edttrn()
{
	unsigned int idt;
	string name, data_nasc, nacionalidade, detalhes;
	cout << "Insira id: ";
	cin >> idt;
	vector <Treinador *>::iterator iter;
	iter = Baseball::getittrn(idt);
	if (iter == treinadores.end())
	{
		cout << "Treinador inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		(*iter)->setnome(name);
		(*iter)->setdn(data_nasc);
		(*iter)->setnac(nacionalidade);
		(*iter)->setdet(detalhes);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Treinador editado" << endl;
	return true;
}

bool Baseball::rmvtrn()
{
	unsigned int idt;
	cout << "Insira id: ";
	cin >> idt;
	vector <Treinador *>::iterator iter;
	iter = Baseball::getittrn(idt);
	if (iter == treinadores.end())
	{
		cout << "Treinador inexistente." << endl;
		return false;
	}
	try
	{
		delete (*iter);
		treinadores.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Treinador removido" << endl;
	return true;
}

//-Arbitos
bool Baseball::addarb()
{
	unsigned int ida;
	string name, data_nasc, nacionalidade, detalhes;
	if (arbitos.empty())
	{
		ida = 1;
	} else
	{
		ida = arbitos.back()->getid() + 1;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		Umpire *a = new Umpire(ida, name, data_nasc, nacionalidade, detalhes);
		arbitos.push_back(a);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Arbito adicionado" << endl << "O seu id e: " << ida << endl;
	return true;
}

bool Baseball::edtarb()
{
	unsigned int ida;
	string name, data_nasc, nacionalidade, detalhes;
	cout << "Insira id: ";
	cin >> ida;
	vector <Umpire *>::iterator iter;
	iter = Baseball::getitarb(ida);
	if (iter == arbitos.end())
	{
		cout << "Arbito inexistente" << endl;
		return false;
	}
	cout << "Insira nome: ";
	cin >> name;
	cout << "Insira data de nascimento: ";
	cin >> data_nasc;
	cout << "Insira nacionalidade: ";
	cin >> nacionalidade;
	cout << "Insira detalhes: ";
	cin >> detalhes;
	try
	{
		(*iter)->setnome(name);
		(*iter)->setdn(data_nasc);
		(*iter)->setnac(nacionalidade);
		(*iter)->setdet(detalhes);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Arbito editado" << endl;
	return true;
}

bool Baseball::rmvarb()
{
	unsigned int ida;
	cout << "Insira id: ";
	cin >> ida;
	vector <Umpire *>::iterator iter;
	iter = Baseball::getitarb(ida);
	if (iter == arbitos.end())
	{
		cout << "Arbito inexistente." << endl;
		return false;
	}
	try
	{
		delete (*iter);
		arbitos.erase(iter);
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	cout << "Arbito removido" << endl;
	return true;
}
//---------------------------------------------------------------------

//Ficheiros
//-Leitura
bool Baseball::ledados()
{
	/*Baseball::readuti();
	Baseball::readcmp();
	Baseball::readjog();
	Baseball::readequ();
	Baseball::readest();
	Baseball::readply();
	Baseball::readman();
	Baseball::readmgm();
	Baseball::readmed();
	Baseball::readtrn();
	Baseball::readarb();*/
	return true;
}

bool Baseball::readuti()
{
	unsigned int idu, prioridade;
	string name, data_nasc, nacionalidade, pass;
	string line;
	ifstream futi("utilizadores.txt");
	try
	{
		if (futi.is_open())
		{
			while (!futi.eof())
			{
				getline(futi,line);
				cout << line << endl;
				//Tratar string
				Utilizador *u = new Utilizador(idu, name, data_nasc, nacionalidade, pass, prioridade);
				utilizadores.push_back(u);
			}
			futi.close();
		} else
		{
			cout << "Erro a abrir ficheiro" << endl;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

//-Escrita
bool Baseball::guardadados()
{
	return true;
}

bool Baseball::writeuti()
{
	//string line;
	ofstream futi("utilizadores.txt");
	try
	{
		if (futi.is_open())
		{
			vector<Utilizador *>::iterator it;
			for (it = utilizadores.begin(); it != utilizadores.end(); it++)
			{
				/*line = (*it)->getid() + "_" + (*it)->getnome() + "_" +
				 * (*it)->getdn() + "_"	+ (*it)->getnac() + "_" +
				 * (*it)->getpass() + "_" + (*it)->getpri() + "\n" ;
				cout << line << endl;*/
				futi << (*it)->getid() << "_" << (*it)->getnome() << "_" << (*it)->getdn() << "_" << (*it)->getnac() << "_" << (*it)->getpass() + "_" << (*it)->getpri() << endl;
			}
			futi.close();
		} else
		{
			cout << "Erro a abrir ficheiro" << endl;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}
//---------------------------------------------------------------------

//Login
int Baseball::login(unsigned int login, string senha)
{
	char go = 's';
	vector <Utilizador *>::iterator it;
	for (it = utilizadores.begin(); it != utilizadores.end(); it++)
	{
		if ((*it)->getid()==login)
		{
			if ((*it)->getpass()==senha)
			{
				return (*it)->getpri();
			} else
			{
				cout << "Senha incorrecta" << endl;
				return -1;
			}
		}
	}
	cout << "Utilizador nao encontrado. Deseja entrar como Visitante? (s/n)" << endl;
	cin >> go;
	if ((go == 's') || (go == 'S'))
	{
		return 0;
	}
	return -1;
}

//Pessoas
bool Baseball::loadppl()
{
	pessoas.clear();
	try
	{
		cout << "Pessoas" << endl;
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	return true;
}
//---------------------------------------------------------------------

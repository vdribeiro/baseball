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

void Baseball::infouti(string priority)
{
	unsigned int prio=2;
	if (priority == "administrador") {prio=1;}
	vector<Utilizador *>::iterator it;
	for (it = utilizadores.begin(); it != utilizadores.end(); it++)
	{
		if (prio==(*it)->getpri())
		{
			(*it)->info();
			cout << endl;
		}
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

void Baseball::infojog(string home, string guest)
{
	vector<Jogo *>::iterator it;
	for (it = jogos.begin(); it != jogos.end(); it++)
	{
		if ((home == (*it)->getvisitado()->getnome()) &&
				(guest == (*it)->getvisitante()->getnome()))
		{
			(*it)->imprime();
			cout << endl;
		}
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

void Baseball::infoequ(string country)
{
	vector<Equipa *>::iterator it;
	for (it = equipas.begin(); it != equipas.end(); it++)
	{
		if (country == (*it)->getpais())
		{
			(*it)->imprime();
			cout << endl;
		}
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

void Baseball::infoest(string team)
{
	vector<Equipa *>::iterator it;
	for (it = equipas.begin(); it != equipas.end(); it++)
	{
		if (team == (*it)->getnome())
		{
			(*it)->getest()->imprime();
			cout << endl;
		}
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

void Baseball::infoply(string position)
{
	vector<Jogador *>::iterator it;
	for (it = jogadores.begin(); it != jogadores.end(); it++)
	{
		if (position == (*it)->getpos())
		{
			(*it)->info();
			cout << endl;
		}
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
	if (Baseball::readuti())
	{cout << "Utilizadores Carregados" << endl;}
	if (Baseball::readarb())
	{cout << "Arbitos Carregados" << endl;}
	if (Baseball::readmed())
	{cout << "Medicos Carregados" << endl;}
	if (Baseball::readtrn())
	{cout << "Treinadores Carregados" << endl;}
	if (Baseball::readmgm())
	{cout << "GM's Carregados" << endl;}
	if (Baseball::readply())
	{cout << "Jogadores Carregados" << endl;}
	if (Baseball::readest())
	{cout << "Estadios Carregados" << endl;}
	if (Baseball::readman())
	{cout << "Managers Carregados" << endl;}
	if (Baseball::readequ())
	{cout << "Equipas Carregados" << endl;}
	if (Baseball::readjog())
	{cout << "Jogos Carregados" << endl;}
	if (Baseball::readcmp())
	{cout << "Campeonatos Carregados" << endl;}
	cout << endl;
	return true;
}

bool Baseball::readuti()
{
	unsigned int idu, prioridade;
	string name, data_nasc, nacionalidade, pass;
	string temp;
	ifstream futi("utilizadores.txt");
	try
	{
		if (futi.is_open())
		{
			while (!futi.eof())
			{
				getline(futi, temp, ',');
				idu = atoi(temp.c_str());
				getline(futi, name, ',');
				getline(futi, data_nasc, ',');
				getline(futi, nacionalidade, ',');
				getline(futi, pass, ',');
				getline(futi, temp, ',');
				prioridade = atoi(temp.c_str());
				Utilizador *u = new Utilizador(idu, name, data_nasc, nacionalidade, pass, prioridade);
				utilizadores.push_back(u);
				getline(futi, temp);
			}
			futi.close();
			utilizadores.pop_back();
			//Baseball::infouti();
		} else
		{
			cout << "Erro a abrir o ficheiro utilizadores" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readcmp()
{
	unsigned int idc, year, idj, n;
	string name;
	vector <Jogo *> games;
	Jogo *game;
	string temp;
	ifstream fcmp("campeonatos.txt");
	try
	{
		if (fcmp.is_open())
		{
			while (!fcmp.eof())
			{
				getline(fcmp, temp, ',');
				idc = atoi(temp.c_str());
				getline(fcmp, name, ',');
				getline(fcmp, temp, ',');
				n = atoi(temp.c_str());
				games.clear();
				for(unsigned int i=0; i!=n; i++)
				{
					getline(fcmp, temp, ',');
					idj = atoi(temp.c_str());
					game = Baseball::getobjjgo(idj);
					if (game == NULL)
					{
						//cout << "Campeonato:: Jogo inexistente" << endl;
					} else
					{
						games.push_back(game);
					}
				}
				getline(fcmp, temp, ',');
				year = atoi(temp.c_str());
				Campeonato *c = new Campeonato(idc, name, games, year);
				campeonatos.push_back(c);
				getline(fcmp, temp);
			}
			fcmp.close();
			campeonatos.pop_back();
			//Baseball::infocmp();
		} else
		{
			cout << "Erro a abrir o ficheiro campeonatos" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readjog()
{
	unsigned int idj, ide, ida, strikes, homerun, espectadores, n;
	Equipa *visitante;
	Equipa *visitado;
	string data, resultado, hit, erro;
	vector <Umpire *> arbitos;
	Umpire *arbit;
	string temp;
	ifstream fjog("jogos.txt");
	try
	{
		if (fjog.is_open())
		{
			while (!fjog.eof())
			{
				getline(fjog, temp, ',');
				idj = atoi(temp.c_str());
				getline(fjog, temp, ',');
				ide = atoi(temp.c_str());
				visitante = Baseball::getobjequ(ide);
				if (visitante == NULL)
				{
					//cout << "Jogo:: Equipa inexistente" << endl;
				}
				getline(fjog, temp, ',');
				ide = atoi(temp.c_str());
				visitado = Baseball::getobjequ(ide);
				if (visitado == NULL)
				{
					//cout << "Jogo:: Equipa inexistente" << endl;
				}
				getline(fjog, data, ',');
				getline(fjog, temp, ',');
				n = atoi(temp.c_str());
				arbitos.clear();
				for(unsigned int i=0; i!=n; i++)
				{
					getline(fjog, temp, ',');
					ida = atoi(temp.c_str());
					arbit = Baseball::getobjarb(ida);
					if (arbit == NULL)
					{
						//cout << "Jogo:: Arbito inexistente" << endl;
					} else
					{
						arbitos.push_back(arbit);
					}
				}
				getline(fjog, temp, ',');
				strikes= atoi(temp.c_str());
				getline(fjog, temp, ',');
				homerun = atoi(temp.c_str());
				getline(fjog, temp, ',');
				espectadores = atoi(temp.c_str());
				getline(fjog, resultado, ',');
				getline(fjog, hit, ',');
				getline(fjog, erro, ',');
				Jogo *j = new Jogo(idj, visitante, visitado, data, arbitos, strikes, homerun, espectadores, resultado, hit, erro);
				jogos.push_back(j);
				getline(fjog, temp);
			}
			fjog.close();
			jogos.pop_back();
			//Baseball::infojog();
		} else
		{
			cout << "Erro a abrir o ficheiro jogos" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readequ()
{
	unsigned int ide, idt, idp, n;
	string name, pais, patrocina, bio;
	Estadio *estadio;
	vector <Jogador *> players;
	Jogador *play;
	ManagerGM *ctm;
	Manager *hman;
	PrepFisico *fis;
	string temp;
	ifstream fequ("equipas.txt");
	try
	{
		if (fequ.is_open())
		{
			while (!fequ.eof())
			{
				getline(fequ, temp, ',');
				ide = atoi(temp.c_str());
				getline(fequ, name, ',');
				getline(fequ, temp, ',');
				idt = atoi(temp.c_str());
				estadio = Baseball::getobjest(idt);
				if (estadio == NULL)
				{
					//cout << "Equipa:: Estadio inexistente" << endl;
				}
				getline(fequ, temp, ',');
				n = atoi(temp.c_str());
				players.clear();
				for(unsigned int i=0; i!=n; i++)
				{
					getline(fequ, temp, ',');
					idp = atoi(temp.c_str());
					play = Baseball::getobjply(idp);
					if (play == NULL)
					{
						//cout << "Equipa:: Jogador inexistente" << endl;
					} else
					{
						players.push_back(play);
					}
				}
				getline(fequ, temp, ',');
				idt = atoi(temp.c_str());
				ctm = Baseball::getobjmgm(idt);
				if (ctm == NULL)
				{
					//cout << "Equipa:: ManagerGM inexistente" << endl;
				}
				getline(fequ, temp, ',');
				idt = atoi(temp.c_str());
				hman = Baseball::getobjman(idt);
				if (hman == NULL)
				{
					//cout << "Equipa:: Manager inexistente" << endl;
				}
				getline(fequ, temp, ',');
				idt = atoi(temp.c_str());
				fis = Baseball::getobjfis(idt);
				if (fis == NULL)
				{
					//cout << "Equipa:: Medico inexistente" << endl;
				}
				getline(fequ, pais, ',');
				getline(fequ, patrocina, ',');
				getline(fequ, bio, ',');
				Equipa *e = new Equipa(ide, name, estadio, players, ctm, hman, fis, pais, patrocina, bio);
				equipas.push_back(e);
				getline(fequ, temp);
			}
			fequ.close();
			equipas.pop_back();
			//Baseball::infoequ();
		} else
		{
			cout << "Erro a abrir o ficheiro equipas" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readest()
{
	unsigned int ide, cap;
	string name;
	string temp;
	ifstream fest("estadios.txt");
	try
	{
		if (fest.is_open())
		{
			while (!fest.eof())
			{
				getline(fest, temp, ',');
				ide = atoi(temp.c_str());
				getline(fest, name, ',');
				getline(fest, temp, ',');
				cap = atoi(temp.c_str());
				Estadio *e = new Estadio(ide, name, cap);
				estadios.push_back(e);
				getline(fest, temp);
			}
			fest.close();
			estadios.pop_back();
			//Baseball::infoest();
		} else
		{
			cout << "Erro a abrir o ficheiro estadios" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readply()
{
	unsigned int idp, peso;
	string name, data_nasc, nacionalidade, posicao, bio;
	float altura;
	double salario;
	string temp;
	ifstream fply("jogadores.txt");
	try
	{
		if (fply.is_open())
		{
			while (!fply.eof())
			{
				getline(fply, temp, ',');
				idp = atoi(temp.c_str());
				getline(fply, name, ',');
				getline(fply, data_nasc, ',');
				getline(fply, nacionalidade, ',');
				getline(fply, temp, ',');
				peso = atoi(temp.c_str());
				getline(fply, temp, ',');
				altura = atof(temp.c_str());
				getline(fply, posicao, ',');
				getline(fply, temp, ',');
				salario = atof(temp.c_str());
				getline(fply, bio, ',');
				Jogador *j = new Jogador(idp, name, data_nasc, nacionalidade, peso, altura, posicao, salario, bio);
				jogadores.push_back(j);
				getline(fply, temp);
			}
			fply.close();
			jogadores.pop_back();
			//Baseball::infoply();
		} else
		{
			cout << "Erro a abrir o ficheiro jogadores" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readman()
{
	unsigned int idm, idt, n;
	string name, data_nasc, nacionalidade, bio;
	vector <Treinador *> treinam;
	Treinador *treina;
	string temp;
	ifstream fman("managers.txt");
	try
	{
		if (fman.is_open())
		{
			while (!fman.eof())
			{
				getline(fman, temp, ',');
				idm = atoi(temp.c_str());
				getline(fman, name, ',');
				getline(fman, data_nasc, ',');
				getline(fman, nacionalidade, ',');
				getline(fman, temp, ',');
				n = atoi(temp.c_str());
				treinam.clear();
				for(unsigned int i=0; i!=n; i++)
				{
					getline(fman, temp, ',');
					idt = atoi(temp.c_str());
					treina = Baseball::getobjtrn(idt);
					if (treina == NULL)
					{
						//cout << "Manager:: Treinador inexistente" << endl;
					} else
					{
						treinam.push_back(treina);
					}
				}
				getline(fman, bio, ',');
				Manager *m = new Manager(idm, name, data_nasc, nacionalidade, treinam, bio);
				managers.push_back(m);
				getline(fman, temp);
			}
			fman.close();
			managers.pop_back();
			//Baseball::infoman();
		} else
		{
			cout << "Erro a abrir o ficheiro managers" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readmgm()
{
	unsigned int idg;
	string name, data_nasc, nacionalidade, bio;
	string temp;
	ifstream fmgm("mangms.txt");
	try
	{
		if (fmgm.is_open())
		{
			while (!fmgm.eof())
			{
				getline(fmgm, temp, ',');
				idg = atoi(temp.c_str());
				getline(fmgm, name, ',');
				getline(fmgm, data_nasc, ',');
				getline(fmgm, nacionalidade, ',');
				getline(fmgm, bio, ',');
				ManagerGM *g = new ManagerGM(idg, name, data_nasc, nacionalidade, bio);
				mangms.push_back(g);
				getline(fmgm, temp);
			}
			fmgm.close();
			mangms.pop_back();
			//Baseball::infomgm();
		} else
		{
			cout << "Erro a abrir o ficheiro mangms" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readmed()
{
	unsigned int idf;
	string name, data_nasc, nacionalidade, bio;
	string temp;
	ifstream ffis("medicos.txt");
	try
	{
		if (ffis.is_open())
		{
			while (!ffis.eof())
			{
				getline(ffis, temp, ',');
				idf = atoi(temp.c_str());
				getline(ffis, name, ',');
				getline(ffis, data_nasc, ',');
				getline(ffis, nacionalidade, ',');
				getline(ffis, bio, ',');
				PrepFisico *f = new PrepFisico(idf, name, data_nasc, nacionalidade, bio);
				medicos.push_back(f);
				getline(ffis, temp);
			}
			ffis.close();
			medicos.pop_back();
			//Baseball::infoprp();
		} else
		{
			cout << "Erro a abrir o ficheiro medicos" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readtrn()
{
	unsigned int idt;
	string name, data_nasc, nacionalidade, bio;
	string temp;
	ifstream ftrn("treinadores.txt");
	try
	{
		if (ftrn.is_open())
		{
			while (!ftrn.eof())
			{
				getline(ftrn, temp, ',');
				idt = atoi(temp.c_str());
				getline(ftrn, name, ',');
				getline(ftrn, data_nasc, ',');
				getline(ftrn, nacionalidade, ',');
				getline(ftrn, bio, ',');
				Treinador *t = new Treinador(idt, name, data_nasc, nacionalidade, bio);
				treinadores.push_back(t);
				getline(ftrn, temp);
			}
			ftrn.close();
			treinadores.pop_back();
			//Baseball::infotrn();
		} else
		{
			cout << "Erro a abrir o ficheiro treinadores" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::readarb()
{
	unsigned int ida;
	string name, data_nasc, nacionalidade, bio;
	string temp;
	ifstream farb("arbitos.txt");
	try
	{
		if (farb.is_open())
		{
			while (!farb.eof())
			{
				getline(farb, temp, ',');
				ida = atoi(temp.c_str());
				getline(farb, name, ',');
				getline(farb, data_nasc, ',');
				getline(farb, nacionalidade, ',');
				getline(farb, bio, ',');
				Umpire *a = new Umpire(ida, name, data_nasc, nacionalidade, bio);
				arbitos.push_back(a);
				getline(farb, temp);
			}
			farb.close();
			arbitos.pop_back();
			//Baseball::infoarb();
		} else
		{
			cout << "Erro a abrir o ficheiro arbitos" << endl;
			return false;
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
	if (Baseball::writeuti())
	{cout << "Utilizadores Guardados" << endl;}
	if (Baseball::writecmp())
	{cout << "Campeonatos Guardados" << endl;}
	if (Baseball::writejog())
	{cout << "Jogos Guardados" << endl;}
	if (Baseball::writeequ())
	{cout << "Equipas Guardados" << endl;}
	if (Baseball::writeest())
	{cout << "Estadios Guardados" << endl;}
	if (Baseball::writeply())
	{cout << "Jogadores Guardados" << endl;}
	if (Baseball::writeman())
	{cout << "Managers Guardados" << endl;}
	if (Baseball::writemgm())
	{cout << "GM's Guardados" << endl;}
	if (Baseball::writemed())
	{cout << "Medicos Guardados" << endl;}
	if (Baseball::writetrn())
	{cout << "Treinadores Guardados" << endl;}
	if (Baseball::writearb())
	{cout << "Arbitos Guardados" << endl;}
	cout << endl;
	return true;
}

bool Baseball::writeuti()
{
	ofstream futi("utilizadores.txt");
	vector<Utilizador *>::iterator it;
	try
	{
		if (futi.is_open())
		{
			for (it = utilizadores.begin(); it != utilizadores.end(); it++)
			{
				futi << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getdn() << "," << (*it)->getnac() << "," <<
						(*it)->getpass() << "," << (*it)->getpri() << "," << 0 << endl;
			}
			futi.close();
		} else
		{
			cout << "Erro a abrir o ficheiro utilizadores" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writecmp()
{
	ofstream fcmp("campeonatos.txt");
	vector<Campeonato *>::iterator it;
	vector<Jogo *>::iterator itj;
	vector<Jogo *> games;
	unsigned int tam=0;
	try
	{
		if (fcmp.is_open())
		{
			for (it = campeonatos.begin(); it != campeonatos.end(); it++)
			{
				games.clear();
				games = (*it)->getjogos();
				tam = games.size();
				fcmp << (*it)->getid() << "," << (*it)->getnome() << "," << tam;
				for (itj = games.begin(); itj != games.end(); itj++)
				{
					fcmp << "," << (*itj)->getid();
				}
				fcmp << "," << (*it)->getano() << "," << 0 << endl;
			}
			fcmp.close();
		} else
		{
			cout << "Erro a abrir o ficheiro campeonatos" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writejog()
{
	ofstream fjog("jogos.txt");
	vector<Jogo *>::iterator it;
	vector<Umpire *>::iterator ita;
	vector<Umpire *> referee;
	unsigned int tam=0;
	try
	{
		if (fjog.is_open())
		{
			for (it = jogos.begin(); it != jogos.end(); it++)
			{
				referee.clear();
				referee = (*it)->getarbitos();
				tam = referee.size();
				fjog << (*it)->getid() << "," << (*it)->getvisitante()->getid() << "," <<
						(*it)->getvisitado()->getid()<< ","	<< (*it)->getdata() << "," << tam;
				for (ita = referee.begin(); ita != referee.end(); ita++)
				{
					fjog << "," << (*ita)->getid();
				}
				fjog << "," << (*it)->getstrikes() << "," << (*it)->gethomerun() <<
						"," << (*it)->getespectadores()<< "," << (*it)->getresultado() <<
						"," << (*it)->gethit() << "," << (*it)->geterror() <<
						"," << 0 << endl;
			}
			fjog.close();
		} else
		{
			cout << "Erro a abrir o ficheiro jogos" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writeequ()
{
	ofstream fequ("equipas.txt");
	vector<Equipa *>::iterator it;
	vector<Jogador *>::iterator itj;
	vector<Jogador *> players;
	unsigned int tam=0;
	try
	{
		if (fequ.is_open())
		{
			for (it = equipas.begin(); it != equipas.end(); it++)
			{
				players.clear();
				players = (*it)->getjog();
				tam = players.size();
				fequ << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getest()->getid() << "," << tam;
				for (itj = players.begin(); itj != players.end(); itj++)
				{
					fequ << "," << (*itj)->getid();
				}
				fequ << "," << (*it)->getmgm()->getid() << "," << (*it)->getman()->getid() <<
						"," << (*it)->getfis()->getid() << "," << (*it)->getpais() <<
						"," << (*it)->getpat() << "," << (*it)->getdet() << "," << 0 << endl;
			}
			fequ.close();
		} else
		{
			cout << "Erro a abrir o ficheiro equipas" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writeest()
{
	ofstream fest("estadios.txt");
	try
	{
		if (fest.is_open())
		{
			vector<Estadio *>::iterator it;
			for (it = estadios.begin(); it != estadios.end(); it++)
			{
				fest << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getcap() << "," << 0 << endl;
			}
			fest.close();
		} else
		{
			cout << "Erro a abrir o ficheiro estadios" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writeply()
{
	ofstream fply("jogadores.txt");
	try
	{
		if (fply.is_open())
		{
			vector<Jogador *>::iterator it;
			for (it = jogadores.begin(); it != jogadores.end(); it++)
			{
				fply << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getdn() << "," << (*it)->getnac() << "," <<
						(*it)->getpeso() << "," << (*it)->getaltura() << "," <<
						(*it)->getpos() << "," << (*it)->getsal() << "," <<
						(*it)->getbio() << "," << 0 << endl;
			}
			fply.close();
		} else
		{
			cout << "Erro a abrir o ficheiro jogadores" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writeman()
{
	ofstream fman("managers.txt");
	vector<Manager *>::iterator it;
	vector<Treinador*>::iterator itt;
	vector<Treinador *> trainer;
	unsigned int tam=0;
	try
	{
		if (fman.is_open())
		{
			for (it = managers.begin(); it != managers.end(); it++)
			{
				trainer.clear();
				trainer = (*it)->gettrn();
				tam = trainer.size();
				fman << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getdn() << "," << (*it)->getnac() << "," << tam;
				for (itt = trainer.begin(); itt != trainer.end(); itt++)
				{
					fman << "," << (*itt)->getid();
				}
				fman << "," << (*it)->getdet() << "," << 0 << endl;
			}
			fman.close();
		} else
		{
			cout << "Erro a abrir o ficheiro managers" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writemgm()
{
	ofstream fmgm("mangms.txt");
	try
	{
		if (fmgm.is_open())
		{
			vector<ManagerGM *>::iterator it;
			for (it = mangms.begin(); it != mangms.end(); it++)
			{
				fmgm << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getdn() << "," << (*it)->getnac() << "," <<
						(*it)->getdet() << "," << 0 << endl;
			}
			fmgm.close();
		} else
		{
			cout << "Erro a abrir o ficheiro mangms" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writemed()
{
	ofstream fmed("medicos.txt");
	try
	{
		if (fmed.is_open())
		{
			vector<PrepFisico *>::iterator it;
			for (it = medicos.begin(); it != medicos.end(); it++)
			{
				fmed << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getdn() << "," << (*it)->getnac() << "," <<
						(*it)->getdet() << "," << 0 << endl;
			}
			fmed.close();
		} else
		{
			cout << "Erro a abrir o ficheiro medicos" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writetrn()
{
	ofstream ftrn("treinadores.txt");
	try
	{
		if (ftrn.is_open())
		{
			vector<Treinador *>::iterator it;
			for (it = treinadores.begin(); it != treinadores.end(); it++)
			{
				ftrn << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getdn() << "," << (*it)->getnac() << "," <<
						(*it)->getdet() << "," << 0 << endl;
			}
			ftrn.close();
		} else
		{
			cout << "Erro a abrir o ficheiro treinadores" << endl;
			return false;
		}
	} catch(ErroFx erro) {
		cout << "Erro no ficheiro " << erro.ficheiro << endl;
		return false;
	}
	return true;
}

bool Baseball::writearb()
{
	ofstream farb("arbitos.txt");
	try
	{
		if (farb.is_open())
		{
			vector<Umpire *>::iterator it;
			for (it = arbitos.begin(); it != arbitos.end(); it++)
			{
				farb << (*it)->getid() << "," << (*it)->getnome() << "," <<
						(*it)->getdn() << "," << (*it)->getnac() << "," <<
						(*it)->getdet() << "," << 0 << endl;
			}
			farb.close();
		} else
		{
			cout << "Erro a abrir o ficheiro arbitos" << endl;
			return false;
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
//---------------------------------------------------------------------

//Pessoas
bool Baseball::loadppl()
{
	pessoas.clear();
	try
	{
		cout << "A carregar todas as Pessoas do sistema..." << endl;
		pessoas.insert(pessoas.end(),utilizadores.begin(),utilizadores.end());
		pessoas.insert(pessoas.end(),jogadores.begin(),jogadores.end());
		pessoas.insert(pessoas.end(),arbitos.begin(),arbitos.end());
		pessoas.insert(pessoas.end(),medicos.begin(),medicos.end());
		pessoas.insert(pessoas.end(),treinadores.begin(),treinadores.end());
		pessoas.insert(pessoas.end(),managers.begin(),managers.end());
		pessoas.insert(pessoas.end(),mangms.begin(),mangms.end());
		InsertionSort(pessoas);
		cout << "Pessoas carregadas" << endl;
	} catch(ErroVector erro) {
		cout << "Erro no vector " << erro.vector << endl;
		return false;
	}
	return true;
}
//---------------------------------------------------------------------

//Simulacao
bool Baseball::simulacao(int modo)
{
	unsigned int idh, idg;
	Equipa *home;
	Equipa *guest;
	unsigned int innings=9;
	vector <Jogador *> plysimh, plysimg;
	cout << endl << "SIMULACAO DE BASEBALL - VERSAO 1.0" << endl << endl;
	cout << "Equipas existentes: " << endl;
	vector<Equipa *>::iterator it;
	for (it = equipas.begin(); it != equipas.end(); it++)
	{
		cout << (*it)->getid() << "-> " << (*it)->getnome() << endl;
	}
	cout << "Insira id da equipa da casa: ";
	do
	{
		cin >> idh;
		home = Baseball::getobjequ(idh);
		if (home == NULL)
		{
			cout << "Equipa inexistente" << endl;
		}
	} while (home==NULL);
	cout << "Insira id da equipa visitante: ";
	do
	{
		cin >> idg;
		guest = Baseball::getobjequ(idg);
		if (guest == NULL)
		{
			cout << "Equipa inexistente" << endl;
		}
	} while (guest==NULL);
	plysimh = home->getjog();
	plysimg = guest->getjog();
	if ( (plysimh.size()<9) && (plysimg.size()<9) )
	{
		if (plysimh.size() > plysimg.size())
		{
			innings=plysimg.size();
		}else
		{
			innings=plysimh.size();
		}
	}
	try
	{
		Simulacao *sim = new Simulacao(plysimh, plysimg);
		cout << "Rondas: " << innings << endl;
		getchar();
		Baseball::pause(modo);
		cout << "Inicio do jogo" << endl << endl;
		sim->simula(modo, innings);
		//sim->~Simulacao();
		delete(sim);
	} catch(ErroSim erro) {
		cout << "Erro na simulacao " << erro.simul << endl;
		return false;
	}
	return true;
}

void Baseball::pause(int modo)
{
	if (modo==1)
	{
		string c;
		cout << endl << "Pressione enter para continuar..." << endl;
		getline (cin, c);
	}
	//c = getchar();
	//cout << c << endl;
}

void Baseball::simhelp()
{
	cout << "AJUDA: " << endl << endl <<
	"A simulacao do jogo pode ser feita de duas maneiras: Completa e Passo a Passo." << endl <<
	"A Simulacao Completa corre o jogo sem paragens mostrando o resultado;" << endl <<
	"A Simulacao Passo a Passo, como o nome diz, corre o jogo com intervalos de accao" << endl <<
	"em que o utilizador pressiona uma tecla para prosseguir." << endl <<
	"O numero de rondas por defeito é 9. No entanto, se nao houver jogadores suficientes" << endl <<
	"o numero de rondas é igual ao numero de jogadores da equipa com menos jogadores." << endl << endl;
}
//---------------------------------------------------------------------

//Ajuda
void Baseball::help()
{
	cout << "AJUDA:" << endl << endl <<
    "O acesso ao sistema é definido em função da prioridade do Utilizador." << endl <<
    "O utilizador que entra no sistema como visitante so tem acesso a informação contida nas diferentes opções," << endl <<
    "ou seja, so pode visualizar o conteudo de cada classe e realizar pesquisas." << endl <<
    "O Utilizador registado no sistema tem uma maior acessibilidade pois pode realizar tarefas relativas" << endl <<
    "a sua actualização, podendo deste modo adicionar, remover, editar, visualizar e pesquisar informações." << endl <<
    "O Administrador tem acesso aos mesmos dados que o Utilizador, no entanto, pode tambem adicionar, remover," << endl <<
    "editar e visualizar Utilizadores podendo também visualizar todas as pessoas envolvidas no sistema." << endl << endl;
}
//---------------------------------------------------------------------

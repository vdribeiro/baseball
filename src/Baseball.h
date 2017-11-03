#ifndef BASEBALL_H_
#define BASEBALL_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "Erro.h"
#include "Utilizador.h"
#include "Campeonato.h"

class Baseball
{
	protected:
		unsigned int id;
		string nome, versao;
		vector <Utilizador *> utilizadores;
		vector <Campeonato *> campeonatos;
		vector <Jogo *> jogos;
		vector <Equipa *> equipas;
		vector <Estadio *> estadios;
		vector <Jogador *> jogadores;
		vector <Manager *> managers;
		vector <ManagerGM *> mangms;
		vector <PrepFisico *> medicos;
		vector <Treinador *> treinadores;
		vector <Umpire *> arbitos;
		vector <Pessoa *> pessoas;

	public:
		Baseball(unsigned int cod, string name, string version); //Construtor
		~Baseball(); //Destrutor

		//Getters e Setters
		unsigned int getcod();
		void setcod(unsigned int cod);
		string getname();
		void setname(string name);
		string getversao();
		void setversao(string ver);
		vector <Utilizador *> getuti();
		void setuti(vector <Utilizador *> uti);
		vector <Campeonato *> getcam();
		void setcam(vector <Campeonato *> cam);
		vector <Jogo *> getjog();
		void setjog(vector <Jogo *> jog);
		vector <Equipa *> getequ();
		void setequ(vector <Equipa *> equ);
		vector <Estadio *> getest();
		void setest(vector <Estadio *> est);
		vector <Jogador *> getply();
		void setply(vector <Jogador *> ply);
		vector <Manager *> getman();
		void setman(vector <Manager *> man);
		vector <ManagerGM *> getmgm();
		void setmgm(vector <ManagerGM *> mgm);
		vector <PrepFisico *> getmed();
		void setmed(vector <PrepFisico *> med);
		vector <Treinador *> gettre();
		void settre(vector <Treinador *> tre);
		vector <Umpire *> getarb();
		void setarb(vector <Umpire *> arb);
		vector <Pessoa *> getpes();
		void setpes(vector <Pessoa *> pes);

		//Imprime
		void imprime();
		void infouti();
		void infocmp();
		void infocmp(unsigned int year);
		void infojog();
		void infoequ();
		void infoest();
		void infoply();
		void infoman();
		void infomgm();
		void infoprp();
		void infotrn();
		void infoarb();
		void infoppl();

		//Procura
		//-por iteradores
		vector <Utilizador *>::iterator getituti(unsigned int id);
		vector <Campeonato *>::iterator getitcmp(unsigned int id);
		vector <Jogo *>::iterator getitjgo(unsigned int id);
		vector <Equipa *>::iterator getitequ(unsigned int id);
		vector <Estadio *>::iterator getitest(unsigned int id);
		vector <Jogador *>::iterator getitply(unsigned int id);
		vector <Manager *>::iterator getitman(unsigned int id);
		vector <ManagerGM *>::iterator getitmgm(unsigned int id);
		vector <PrepFisico *>::iterator getitfis(unsigned int id);
		vector <Treinador *>::iterator getittrn(unsigned int id);
		vector <Umpire *>::iterator getitarb(unsigned int id);

		//-por objectos
		Utilizador *getobjuti(unsigned int id);
		Campeonato *getobjcmp(unsigned int id);
		Jogo *getobjjgo(unsigned int id);
		Equipa *getobjequ(unsigned int id);
		Estadio *getobjest(unsigned int id);
		Jogador *getobjply(unsigned int id);
		Manager *getobjman(unsigned int id);
		ManagerGM *getobjmgm(unsigned int id);
		PrepFisico *getobjfis(unsigned int id);
		Treinador *getobjtrn(unsigned int id);
		Umpire *getobjarb(unsigned int id);

		//Vectores
		//-Inicializa vectores
		bool init();
		//-Limpa vectores
		bool resetdados();

		//CRUD
		//-Utilizadores
		bool adduti();
		bool edtuti();
		bool rmvuti();

		//-Campeonatos
		bool addcmp();
		bool edtcmp();
		bool rmvcmp();

		//-Jogos
		bool addjgo();
		bool edtjgo();
		bool rmvjgo();

		//-Equipas
		bool addequ();
		bool edtequ();
		bool rmvequ();

		//-Estadios
		bool addest();
		bool edtest();
		bool rmvest();

		//-Jogadores
		bool addply();
		bool edtply();
		bool rmvply();

		//-Managers
		bool addman();
		bool edtman();
		bool rmvman();

		//-GM's
		bool addmgm();
		bool edtmgm();
		bool rmvmgm();

		//-Medicos
		bool addfis();
		bool edtfis();
		bool rmvfis();

		//-Treinadores
		bool addtrn();
		bool edttrn();
		bool rmvtrn();

		//-Arbitos
		bool addarb();
		bool edtarb();
		bool rmvarb();

		//Ficheiros
		//-Leitura
		bool ledados();
		bool readuti();
		bool readcmp();
		bool readjog();
		bool readequ();
		bool readest();
		bool readply();
		bool readman();
		bool readmgm();
		bool readmed();
		bool readtrn();
		bool readarb();

		//-Escrita
		bool guardadados();
		bool writeuti();
		bool writecmp();
		bool writejog();
		bool writeequ();
		bool writeest();
		bool writeply();
		bool writeman();
		bool writemgm();
		bool writemed();
		bool writetrn();
		bool writearb();

		//Sistema de Login
		int login(unsigned int login, string senha);

		//Carrega Pessoas
		bool loadppl();

};

#endif /* BASEBALL_H_ */

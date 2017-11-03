#ifndef EQUIPA_H_
#define EQUIPA_H_

#include "Jogador.h"
#include "Manager.h"
#include "ManagerGM.h"
#include "PrepFisico.h"
#include "Estadio.h"

class Equipa
{
    protected:
		unsigned int id;
		string nome;
		Estadio *est;
		vector <Jogador *> jog;
		ManagerGM *mgm;
		Manager *man;
		PrepFisico *prp;
		string pais;
		string patrocinadores;
        string detalhes;

    public:
        Equipa(unsigned int cod, string name, Estadio *sta, vector <Jogador *> plr, ManagerGM *ctm, Manager *hch, PrepFisico *fis, string cnt, string spo, string det); //Construtor
        ~Equipa(); //Destrutor

		//Getters e Setters
        unsigned int getid();
		void setid(unsigned int cod);
		string getnome();
		void setnome(string name);
		Estadio *getest();
		void setest(Estadio *sta);
		vector <Jogador *> getjog();
		void setjog(vector <Jogador *> plr);
		ManagerGM *getmgm();
		void setmgm(ManagerGM *ctm);
		Manager *getman();
		void setman(Manager *hch);
		PrepFisico *getfis();
		void setfis(PrepFisico *fis);
        string getpais();
        void setpais(string nac);
        string getpat();
        void setpat(string pat);
        string getdet();
        void setdet(string det);

        //Imprime
        void imprime();
};

#endif /* EQUIPA_H_ */

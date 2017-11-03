#ifndef JOGO_H_
#define JOGO_H_

#include "Equipa.h"
#include "Umpire.h"

class Jogo
{
    protected:
		unsigned int id;
		Equipa *visitante;
		Equipa *visitado;
		string data;
		vector <Umpire *> arbitos;
		unsigned int strikes;
		unsigned int homerun;
		unsigned int espectadores;
		string resultado;
		string Hit;
		string error;

    public:
		Jogo(unsigned int cod, Equipa *visitant, Equipa *visitad, string date, vector <Umpire *> arbito, unsigned int strike,
				unsigned int homrun, unsigned int spectadores, string result, string batidas, string erro); //Construtor
		~Jogo(); //Destrutor

		//Getters e Setters
		unsigned int getid();
		void setid(unsigned int cod);
		Equipa *getvisitante();
		void setvisitante (Equipa *visitant);
		Equipa *getvisitado();
		void setvisitado (Equipa *visitad);
		string getdata();
		void setdata(string date);
		vector <Umpire *> getarbitos();
		void setarbitos(vector <Umpire *> arbito);
		unsigned int getstrikes();
		void setstrikes(unsigned int strike);
		unsigned int gethomerun();
		void sethomerun (unsigned int homrun);
		unsigned int getespectadores();
		void setespectadores (unsigned int spectadores);
		string getresultado();
		void setresultado (string result);
		string gethit();
		void sethit (string batidas);
		string geterror();
		void seterror (string erro);

	   //Imprime
	   void imprime();

};

#endif /* JOGO_H_ */

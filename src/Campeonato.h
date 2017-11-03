#ifndef CAMPEONATO_H_
#define CAMPEONATO_H_

#include "Jogo.h"

class Campeonato
{
    protected:
		unsigned int id;
		string nome;
		vector <Jogo *> jogos;
		unsigned int ano;

	public:
		Campeonato(unsigned int cod, string name, vector <Jogo *> games, unsigned int year); //Construtor
		~Campeonato(); //Destrutor

		//Getters e Setters
		unsigned int getid();
		void setid(unsigned int cod);
        string getnome();
        void setnome(string name);
        vector <Jogo *> getjogos();
        void setjogos(vector <Jogo *> games);
        unsigned int getano();
        void setano(unsigned int year);

        //Imprime
        void imprime();
};

#endif /* CAMPEONATO_H_ */

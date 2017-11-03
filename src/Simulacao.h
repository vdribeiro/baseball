/*
 * Simulacao.h
 *
 *  Created on: 2009/12/25
 *      Author: Vitor
 */

#ifndef SIMULACAO_H_
#define SIMULACAO_H_

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include "Jogo.h"

#include "BinaryTree.h"

class Base
{
    protected:
		unsigned int idb;
		queue <Jogador *> jogadores;

    public:
		//Construtores
        Base(unsigned int num, queue <Jogador *> jogasim);
        Base(unsigned int num);
        ~Base(); //Destrutor

		//Getters e Setters
        unsigned int getnum();
		void setnum(unsigned int num);
		queue <Jogador *> getjogasim();
		void setjogasim(queue <Jogador *> jogasim);

        //Imprime
        void imprime();

        //Operacoes na queue
        //-Front
		Jogador *jogfront();
		//-Pop/Remove Jogador
		void jogpop();
		//-Adiciona jogador
        void addply(Jogador * plysim);
        //-Limpa jogadores
        void clearjog();

        //Operadores
		bool operator ==(const Base & b) const;
		bool operator <(const Base & b) const;
		bool operator >(const Base & b) const;
};
//---------------------------------------------------------------------

class Simulacao
{
    protected:
		unsigned int pontoh;
		unsigned int pontog;
		stack <Jogador *> home;
		stack <Jogador *> guest;
		BinaryTree <Base> bases;

    public:
		//Construtores
        Simulacao(stack <Jogador *> homep, stack <Jogador *> guestp);
        Simulacao(vector <Jogador *> homep, vector <Jogador *> guestp);
        ~Simulacao(); //Destrutor

		//Getters e Setters
		unsigned int getscoreh();
		void setscoreh(unsigned int scoreh);
		unsigned int getscoreg();
		void setscoreg(unsigned int scoreg);
		stack <Jogador *> gethomet();
		void sethomet(stack <Jogador *> homet);
		stack <Jogador *> getguestt();
		void setguestt(stack <Jogador *> guestt);
		BinaryTree <Base> getbases();
		void setbases(BinaryTree <Base> arv);

        //Imprime
        void imprime();

        //Operacoes nas stacks
        //-Top
        Jogador *hometop();
        Jogador *guesttop();
        //-Pop
        void homepop();
        void guestpop();

        //Operacoes na Arvore
        //-Inicializa/Reset Arvore
        BinaryTree<Base> iniciaBT(unsigned int ini, unsigned int fim);
        //-Adiciona/Remove Jogador na fila do Nodo
        bool addjogadornodo(unsigned int nodo, Jogador *run);
        bool rmvjogadornodo(unsigned int nodo);
        //-Simula corrida entre bases (Nodos)
        unsigned int corre(unsigned int tempo);
        //-Simula Homerun
        void homerun(unsigned int equipa);
        //-Limpa ultima base contabilizando os pontos
        void flushhomebase(unsigned int equipa);

        //Simular
        //-Funcao Central
        bool simula(int modo, unsigned int innings);
        //-Pausa
        void pause(int modo);
};

#endif /* SIMULACAO_H_ */

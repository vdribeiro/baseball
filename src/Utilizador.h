#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include "Pessoa.h"

class Utilizador : public Pessoa
{
    protected:
        unsigned int prioridade;
        string pass;

    public:
        Utilizador(unsigned int cod, string name, string dn, string nac, string senha, unsigned int pri); //Construtor
        ~Utilizador(); //Destrutor

		//Getters e Setters
        unsigned int getpri();
		void setpri(unsigned int pri);
        string getpass();
        void setpass(string pword);

        //Imprime
        void info();
};

#endif

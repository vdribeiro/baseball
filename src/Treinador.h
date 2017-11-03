#ifndef TREINADOR_H_
#define TREINADOR_H_

#include "Pessoa.h"

class Treinador : public Pessoa
{
    protected:
		string detalhes;

    public:
		Treinador(unsigned int cod, string name, string dn, string nac, string det); //Construtor
        ~Treinador(); //Destrutor

		//Getters e Setters
        string getdet();
        void setdet(string det);

        //Imprime
        void info();
};

#endif /* TREINADOR_H_ */

#ifndef UMPIRE_H_
#define UMPIRE_H_

#include "Pessoa.h"

class Umpire : public Pessoa
{
    protected:
		string detalhes;

    public:
		Umpire(unsigned int cod, string name, string dn, string nac, string det); //Construtor
        ~Umpire(); //Destrutor

		//Getters e Setters
        string getdet();
        void setdet(string det);

        //Imprime
        void info();
};

#endif /* UMPIRE_H_ */

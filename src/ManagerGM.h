#ifndef MANAGERGM_H_
#define MANAGERGM_H_

#include "Pessoa.h"

class ManagerGM : public Pessoa
{
    protected:
		string detalhes;

    public:
		ManagerGM(unsigned int cod, string name, string dn, string nac, string det); //Construtor
        ~ManagerGM(); //Destrutor

		//Getters e Setters
        string getdet();
        void setdet(string det);

        //Imprime
        void info();
};

#endif /* MANAGERGM_H_ */

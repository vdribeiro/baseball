#ifndef PREPFISICO_H_
#define PREPFISICO_H_

#include "Pessoa.h"

class PrepFisico : public Pessoa
{
    protected:
		string detalhes;

    public:
		PrepFisico(unsigned int cod, string name, string dn, string nac, string det); //Construtor
        ~PrepFisico(); //Destrutor

		//Getters e Setters
        string getdet();
        void setdet(string det);

        //Imprime
        void info();
};

#endif /* PREPFISICO_H_ */

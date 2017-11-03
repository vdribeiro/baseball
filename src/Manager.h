#ifndef MANAGER_H_
#define MANAGER_H_

#include "Pessoa.h"
#include "Treinador.h"

class Manager : public Pessoa
{
    protected:
		vector <Treinador *> trn;
		string detalhes;

    public:
		Manager(unsigned int cod, string name, string dn, string nac, vector <Treinador *> coa, string det); //Construtor
        ~Manager(); //Destrutor

		//Getters e Setters
        vector <Treinador *> gettrn();
        void settrn(vector <Treinador *> coa);
        string getdet();
        void setdet(string det);

        //Imprime
        void info();
};

#endif /* MANAGER_H_ */

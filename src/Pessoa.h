#ifndef PESSOA_H_
#define PESSOA_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Pessoa
{
    protected:
		unsigned int id;
		string nome, data_nasc, nacionalidade;

	public:
		Pessoa(unsigned int cod, string name, string dn, string nac); //Construtor
		virtual ~Pessoa(); //Destrutor

		//Getters e Setters
		unsigned int getid();
		void setid(unsigned int cod);
        string getnome();
        void setnome(string name);
        string getdn();
        void setdn(string dn);
		string getnac();
        void setnac(string nac);

        //Imprime
        virtual void info();

        //Operadores
        bool operator ==(const Pessoa & pe) const;
        bool operator <(const Pessoa & pe) const;
        bool operator >(const Pessoa & pe) const;
};

#endif

#ifndef ESTADIO_H_
#define ESTADIO_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Estadio
{
    protected:
		unsigned int id;
		string nome;
		unsigned int capacidade;

    public:
		Estadio(unsigned int cod, string name, unsigned int cap); //Construtor
		~Estadio(); //Destrutor

		//Getters e Setters
		unsigned int getid();
		void setid(unsigned int cod);
		string getnome();
		void setnome(string name);
		unsigned int getcap();
		void setcap(unsigned int cap);

		//Imprime
		void imprime();
};

#endif /* ESTADIO_H_ */

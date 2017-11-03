#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Pessoa.h"

/* Posicoes
	* P: Pitcher
	* C: Catcher
    * 1B: First Base
    * 2B: Second Base
    * 3B: Third Base
    * SS: Shortstop
    * LF: Left Field
    * CF: Center Field
    * RF: Right Field
 */

class Jogador : public Pessoa
{
	 protected:
		unsigned int peso;
		float altura;
        string posicao;
        double salario;
        string bio;

    public:
        Jogador(unsigned int cod, string name, string dn, string nac,
        		unsigned int kg, float ht, string pos, double sal, string det); //Construtor
        ~Jogador(); //Destrutor

        //Getters e Setters
        unsigned int getpeso();
        void setpeso(unsigned int kg);
        float getaltura();
        void setaltura(float ht);
        string getpos();
        void setpos(string pos);
        double getsal();
        void setsal(double sal);
        string getbio();
        void setbio(string det);

        //Imprime
        void info();
};

#endif /* JOGADOR_H_ */

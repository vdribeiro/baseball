#include "Simulacao.h"

Base::Base(unsigned int num, queue <Jogador *> jogasim)
: idb(num), jogadores(jogasim) {}

Base::Base(unsigned int num) : idb(num)
{
	while (!jogadores.empty())
		jogadores.pop();
}

Base::~Base() {}

unsigned int Base::getnum()
{return idb;}

void Base::setnum(unsigned int num)
{idb=num;}

queue <Jogador *> Base::getjogasim()
{return jogadores;}

void Base::setjogasim(queue <Jogador *> jogasim)
{jogadores=jogasim;}

void Base::imprime()
{
	cout << "Id: " << idb << endl;
	queue <Jogador *> jogatemp = jogadores;
	while (!jogatemp.empty())
	{
		jogatemp.front()->info();
		jogatemp.pop();
	}
}

Jogador *Base::jogfront()
{
	return jogadores.front();
}

void Base::jogpop()
{
	jogadores.pop();
}

void Base::addply(Jogador * plysim)
{
	jogadores.push(plysim);
}

void Base::clearjog()
{
	while (!jogadores.empty())
	{
		jogadores.pop();
	}
}

bool Base::operator ==(const Base & b) const
{
	if (idb==b.idb)
		return true;
	return false;
}

bool Base::operator <(const Base & b) const
{
	if (idb<b.idb)
		return true;
	return false;
}

bool Base::operator >(const Base & b) const
{
	if (idb>b.idb)
		return true;
	return false;
}
//---------------------------------------------------------------------

Simulacao::Simulacao(stack <Jogador *> homep, stack <Jogador *> guestp)
: pontoh(0), pontog(0), home(homep), guest(guestp) {}

Simulacao::Simulacao(vector <Jogador *> homep, vector <Jogador *> guestp)
: pontoh(0), pontog(0)
{
	vector <Jogador *>::iterator it;
	for (it = homep.begin(); it != homep.end(); it++)
	{
		home.push(*it);
	}
	for (it = guestp.begin(); it != guestp.end(); it++)
	{
		guest.push(*it);
	}
}

Simulacao::~Simulacao() {}

unsigned int Simulacao::getscoreh()
{return pontoh;}

void Simulacao::setscoreh(unsigned int scoreh)
{pontoh=scoreh;}

unsigned int Simulacao::getscoreg()
{return pontog;}

void Simulacao::setscoreg(unsigned int scoreg)
{pontog=scoreg;}

stack <Jogador *> Simulacao::gethomet()
{return home;}

void Simulacao::sethomet(stack <Jogador *> homet)
{home=homet;}

stack <Jogador *> Simulacao::getguestt()
{return guest;}

void Simulacao::setguestt(stack <Jogador *> guestt)
{guest=guestt;}

BinaryTree <Base> Simulacao::getbases()
{return bases;}

void Simulacao::setbases(BinaryTree <Base> arv)
{bases=arv;}

void Simulacao::imprime()
{
	cout << "Pontuacao: " << endl << pontoh << " - " << pontog << endl;
	cout << "Equipa da casa: " << endl;
	stack <Jogador *> temp=home;
	while (!temp.empty())
	{
		temp.top()->info();
		temp.pop();
	}
	cout << endl << "Equipa visitante: " << endl;
	temp=guest;
	while (!temp.empty())
	{
		temp.top()->info();
		temp.pop();
	}
	cout << endl;
}

Jogador *Simulacao::hometop()
{return home.top();}

Jogador *Simulacao::guesttop()
{return guest.top();}

void Simulacao::homepop()
{home.pop();}

void Simulacao::guestpop()
{guest.pop();}

BinaryTree<Base> Simulacao::iniciaBT(unsigned int ini, unsigned int fim)
{
	Base *b = new Base(ini);
	if (ini==fim) return BinaryTree<Base>(*b);
	BinaryTree<Base> filhoEsq=iniciaBT(ini+1,fim);
	return BinaryTree<Base>(*b, filhoEsq);
}

bool Simulacao::addjogadornodo(unsigned int nodo, Jogador *run)
{
	BTItrPre<Base> it(bases);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getnum() == nodo)
		{
			it.retrieve().addply(run);
			return true;
		} else
		{
			it.advance();
		}
	}
	return false;
}

bool Simulacao::rmvjogadornodo(unsigned int nodo)
{
	BTItrPre<Base> it(bases);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getnum() == nodo)
		{
			it.retrieve().jogpop();
			return true;
		} else
		{
			it.advance();
		}
	}
	return false;
}

unsigned int Simulacao::corre(unsigned int tempo)
{
	unsigned int numbase, outs, corre, rnd, tmp;
	Jogador *run=NULL;
	BTItrIn<Base> it(bases);
	outs=0;
	corre=0;
	if (tempo==0)
	{
		cout << "Jogadores permanecem nas mesmas bases" << endl;
		return 0;
	}
	cout << "Jogadores correm bases" << endl;
	it.advance();
	while (!it.isAtEnd())
	{
		numbase=it.retrieve().getnum();
		if ( (numbase>0) && (numbase<4) )
		{
			corre=0;
			if (!it.retrieve().getjogasim().empty())
			{
				run=it.retrieve().jogfront();
				it.retrieve().jogpop();
				while (corre<tempo)
				{
					corre++;
					tmp=numbase+corre;
					if (corre==tempo)
					{
						rnd = (rand()%3)+1;
						if (rnd==1)
						{
							cout << "Apanhado! " << endl <<
									run->getnome() << " esta fora!" << endl;
							outs++;
						} else
						{
							cout << run->getnome() << " chegou a base " << tmp << endl;
							Simulacao::addjogadornodo(tmp, run);
						}
					} else
					{
						cout << run->getnome() << " chegou a base " << tmp << endl;
						if (tmp==4)
						{
							corre=tempo;
							Simulacao::addjogadornodo(4, run);
						}
					}
				}
			}
		}
		it.advance();
	}
	return outs;
}

void Simulacao::homerun(unsigned int equipa)
{
	BTItrPre<Base> it(bases);
	queue <Jogador *> filajog;
	while (!it.isAtEnd())
	{
		filajog=it.retrieve().getjogasim();
		if (equipa == 1)
		{
			pontoh=pontoh+filajog.size();
		} else
		{
			pontog=pontog+filajog.size();
		}
		while (!filajog.empty())
		{
			cout << filajog.front()->getnome() << " marca ponto" << endl;
			filajog.pop();
		}
		it.retrieve().clearjog();
		it.advance();
	}
}

void Simulacao::flushhomebase(unsigned int equipa)
{
	BTItrIn<Base> it(bases);
	while (!it.retrieve().getjogasim().empty())
	{
		cout << it.retrieve().jogfront()->getnome() << " marca ponto" << endl;
		if (equipa == 1)
		{
			pontoh++;
		} else
		{
			pontog++;
		}
		it.retrieve().jogpop();
	}
}

bool Simulacao::simula(int modo, unsigned int innings)
{
	unsigned int sorte=0, n=1, vez=1, out=0, entrada=1;
	stack <Jogador *> homebat=home;
	stack <Jogador *> guestbat=guest;
	Jogador *batter;
	bases = Simulacao::iniciaBT(1,4);
	pontoh=0;
	pontog=0;
	cout << "Entrada " << entrada << endl << endl;
	cout << "Equipa da casa a jogar" << endl;
	srand((unsigned)time(0));
	while (innings>0)
	{
		//BATTER UP!
		if (vez==1)
		{
			batter=homebat.top();
			homebat.pop();
			if (homebat.empty())
				homebat=home;
		}else
		{
			batter=guestbat.top();
			guestbat.pop();
			if (guestbat.empty())
					guestbat=guest;
		}
		cout << "Batedor: " << batter->getnome() << endl <<
				"Batedor pronto!" << endl;
		Simulacao::pause(modo);
		n=1;
		do
		{
			sorte = (rand()%2)+1;
			cout << "Strike " << n << endl;
			if (sorte==1)
			{
				cout << "Acertou!" << endl;
			} else
			{
				cout << "Falhou!" << endl;
				Simulacao::pause(modo);
				if (n==3)
				{
					//OUT!
					cout << "Esta Fora!" << endl;
					out++;
					break;
				} else
				{
					n++;
				}
			}
		} while (sorte!=1);
		Simulacao::pause(modo);
		if (sorte==1)
		{
			sorte = (rand()%10)+1;
			if (sorte==10)
			{
				cout << "HOMERUN!!!" << endl;
				Simulacao::pause(modo);
				cout << batter->getnome() << " marca ponto" << endl;
				if (vez==1)
				{
					pontoh++;
				}else
				{
					pontog++;
				}
				Simulacao::homerun(vez);
			} else
			{
				cout << "Corre Batedor!" << endl;
				Simulacao::pause(modo);
				if ((sorte>=1) && (sorte<=3))
				{
					out = out + Simulacao::corre(1);
					Simulacao::addjogadornodo(1, batter);
					cout << batter->getnome() << " chegou a base 1" << endl;
					Simulacao::flushhomebase(vez);
				} else
				{
					if ((sorte>=4) && (sorte<=5))
					{
						out = out + Simulacao::corre(2);
						Simulacao::addjogadornodo(2, batter);
						cout << batter->getnome() << " chegou a base 2" << endl;
						Simulacao::flushhomebase(vez);
					} else
					{
						if (sorte==6)
						{
							out = out + Simulacao::corre(3);
							Simulacao::addjogadornodo(3, batter);
							cout << batter->getnome() << " chegou a base 3" << endl;
							Simulacao::flushhomebase(vez);
						} else
						{
							if ((sorte>=7) && (sorte<=8))
							{
								cout << "Apanhado! " << endl <<
										batter->getnome() << " esta fora!" << endl;
								out++;
							} else
							{
								if (sorte==9)
								{
									cout << "Bola apanhada antes de tocar no chao!" << endl <<
											batter->getnome() << " esta fora!" << endl;
									out++;
								}
							}
							out = out + Simulacao::corre(0);
						}
					}
				}
			}
			Simulacao::pause(modo);
		}
		if (out>=3)
		{
			out=0;
			if (vez==1)
			{
				vez=2;
				cout << "Equipa visitante a jogar" << endl;
				bases = Simulacao::iniciaBT(1,4);
			}else
			{
				vez=1;
				entrada++;
				cout << "Entrada " << entrada << endl << endl;
				cout << "Equipa da casa a jogar" << endl;
				bases = Simulacao::iniciaBT(1,4);
				innings--;
			}
		}
	}
	cout << "RESULTADO: " << pontoh << " - " << pontog << endl;
	Simulacao::pause(modo);
	return true;
}

void Simulacao::pause(int modo)
{
	if (modo==1)
	{
		string c;
		cout << endl << "Pressione enter para continuar..." << endl;
		getline (cin, c);
	}
	//c = getchar();
	//cout << c << endl;
}

//============================================================================
// Name        : Baseball.cpp
// Author      : Vitor & Tomy
// Version     : 2.0
// Copyright   : FEUP
// Description : Baseball in C++, Ansi-style
//============================================================================

#include "Baseball.h"

//MAIN
int main()
{
    int op, pri = -1;
    char rsp, fexo = 'n';
	unsigned int log;
	string senha;
	Baseball *base;

	try {
		//Cria Classe Mae
		base = new Baseball(1, "Baseball", "2.0");
		//Ler do ficheiro
		if (base->ledados())
		{cout << "Programa Pronto" << endl << endl;}
	} catch (ErroFx erro) {
		cout << "Erro a ler o ficheiro " << erro.ficheiro << endl;
		//Limpa os dados ja lidos
		//para nao ficarem a ocupar memoria
		cout << "A terminar aplicacao";
		if (base->resetdados())
		{cout << "..." << endl;}
		return 0;
	}

	//Inicializa o sistema
	if (base->init())
	{cout << ":::::::::::::::::::: Sistema de Gestão de Campeonatos de BASEBALL ::::::::::::::::::::" << endl << endl;}
	else
	{return 0;}

    do {
    	//Faz Login
    	cout << "Por favor faca login. Se nao estiver registado insira 0 para entrar como Visitante." << endl;
        do {
            cout << "Login: ";
            cin >> log;
            if (log!=0)
            {
            	cout << "Senha: ";
            	cin >> senha;
            	pri=base->login(log, senha);
            } else {
            	pri = 0;
            }
        } while (pri<0);

		cout << endl << "Bem vindo ";
		switch (pri)
		{
			case 0: cout << "Visitante";
				break;
			case 1: cout << "Administrador";
				break;
			case 2: cout << "Utilizador";
				break;
			default: cout << "Visitante";
				break;
		}
		cout << endl;

		//Menu
		do {op1:
			cout << endl << "Por favor selecione uma das seguintes opcoes:" << endl;

			cout << "1 - Gestão de atletas e equipas" << endl;
			cout << "2 - Gestão do campeonato " << endl;
			cout << "3 - Consulta de informações sobre equipas" << endl;
			cout << "4 - Consulta de informações sobre campeonatos" << endl;
			cout << "5 - Simulacao" << endl;
			if (pri==1)
			{cout << "6 - Gestão do sistema" << endl;}
			cout << "------------------------------------------------------------" << endl;
			cout << "9 - Help" << endl;
			cout << "0 - Logout" << endl;
			op=-1;
			cout << "Opção: ";
			cin >> op;
			cout << endl;
			if (op == 0)
			{
				cout << "Tem a certeza que deseja sair? (s/n)" << endl;
				cin >> rsp;
				if ((rsp == 'n') || (rsp == 'N'))
					{op = -1;}
			}
			else
			{
				while (op == 1)
				{
                     op2:
					  cout << "1- Equipas" << endl;
					  cout << "2- Jogadores" << endl;
					  cout << "3- Treinadores" << endl;
					  cout << "4- Medicos" << endl;
					  cout << "5- GM's" << endl;
					  cout << "6- Estadios" << endl;
					  cout << "7- Managers" << endl;
					  cout << "0- Voltar ao menu " << endl;
						 int es=-1;
					  cout << "Opção:";
					  cin >> es;
					  cout<< endl;
					  while (es == 0)
					  { goto op1;
					  }
					  while (es == 1)
					  {   if (pri == 0)
					  {
						cout<< "1- Visualizar Equipas" << endl;
						cout<< "0- Voltar ao menu"<< endl;
					   int se=-1;
					   cout << "Opção:";
					   cin>> se;
					   cout<< endl;
					   if (se== 0)
					   { goto op2;}
					   else {
					   while (se == 1)
					  {base->infoequ();

					  goto op2;}

					   }} else
						 {cout<< "1- Adicionar Equipa"<< endl;
						 cout << "2- Editar Equipa " << endl;
						 cout<< "3- Remover Equipa " << endl;
						 cout<< "4- Visualizar Equipas" << endl;
						 cout<< "0- Voltar ao menu"<< endl;
						 int se=-1;
						 cout << "Opção:";
						  cin>> se;
						  cout<< endl;
						  if (se== 0)
					 { goto op2;}
						 else { while (se== 1)
						 { base->addequ();
						 break;
							}
						while (se == 2)
						  { base->edtequ();
						  break;}

						 while (se== 3)
						   {base->rmvequ();
							 break;}

							 while (se == 4)
							  {base->infoequ();

							 break;}

												   }
						 }}

					  while (es== 2)
					  {  if (pri==0)
					  { cout<< "1- Visualizar Jogadores" << endl;
					  cout<< "0- Voltar ao menu"<< endl;
					  int jo=-1;
					  cout << "Opção:";
						cin>> jo;
					   cout<< endl;
					   if (jo== 0)
						{ goto op2;}
					   else { while (jo== 1)
						{ base->infoply();
						break;
													   }
						}}
						  else
						 {cout<< "1- Adicionar Jogador"<< endl;
						 cout << "2- Editar Jogador " << endl;
						 cout<< "3- Remover Jogador " << endl;
						 cout<< "4- Visualizar Jogadores" << endl;
						 cout<< "0- Voltar ao menu"<< endl;
						 int jo=-1;
						 cout << "Opção:";
						 cin>> jo;
						 cout<< endl;
						  if (jo== 0)
						   { goto op2;}
						  else { while (jo== 1)
							{ base->addply();
							  break;
								 }
						  while (jo == 2)
							 {base->edtply();
							break;}

						  while (jo== 3)
						   { base->rmvply();
							break;}
						  while (jo == 4)
						 { base->infoply();
						 break;}}}
						 }

					  while (es == 3)
					  {   if (pri==0)
					  { cout<< "1- Visualizar Treinadores" << endl;
						cout<< "0- Voltar ao menu"<< endl;
						int tr=-1;
						cout << "Opção:";
						  cin>> tr;
						cout<< endl;
						 if (tr== 0)
						{ goto op2;}
					   else { while (tr== 1)
					   { base->infotrn();
					   break;
								}
												  }}
						  else
						 {cout<< "1- Adicionar Treinador"<< endl;
						 cout << "2- Editar Treinador " << endl;
						 cout<< "3- Remover Treinador " << endl;
						 cout<< "4- Visualizar Treinadores" << endl;
						 cout<< "0- Voltar ao menu"<< endl;
						 int tr=-1;
						 cout << "Opção:";
						  cin>> tr;
						  cout<< endl;
						  if (tr== 0)
						  { goto op2;}
						  else { while (tr== 1)
						  { base->addtrn();
							break;
						  }
						  while (tr == 2)
						  {base->edttrn();
						  break;}

						  while (tr== 3)
						  {base->rmvtrn();
						  break;}

						  while (tr == 4)
						  {base->infotrn();
						 break;}

					  }
					  }

					  }

					  while (es == 4)
				  {

						  if (pri==0)
					  { cout<< "1- Visualizar Medicos" << endl;
						cout<< "0- Voltar ao menu"<< endl;
						int me=-1;
						cout << "Opção:";
						  cin>> me;
						cout<< endl;
						 if (me== 0)
						{ goto op2;}
					   else { while (me== 1)
					   { base->infoprp();
					   break;
																				 }
												  }}
						  else
				  {cout<< "1- Adicionar Medico"<< endl;
				  cout << "2- Editar Medico " << endl;
				  cout<< "3- Remover Medico " << endl;
				  cout<< "4- Visualizar Medicos" << endl;
				  cout<< "0- Voltar ao menu"<< endl;
					   int me=-1;
					   cout << "Opção:";
					  cin>> me;
					  cout<< endl;
					if (me== 0)
					 { goto op2;}
					else { while (me== 1)
					  {base->addfis();
						 break;
						  }
				   while (me == 2)
					  {base->edtfis();
						break;}

					   while (me== 3)
						{base->rmvfis();
						 break;}
					   while (me == 4)
						 {base->infoprp();
						 break;}

							}
						 }
				   }

					  while (es == 5)
					  {if (pri==0)
					  {cout<< "1- Visualizar GM's" << endl;
					  cout<< "0- Voltar ao menu"<< endl;
					  int gm=-1;
					  cout << "Opção:";
						cin>> gm;
						cout<< endl;
						if (gm== 0)
						{ goto op2;}
						else while (gm == 1)
						{base->infomgm();
						 break;}
					  }

						  else
					   {cout<< "1- Adicionar GM's"<< endl;
					   cout << "2- Editar GM's " << endl;
					   cout<< "3- Remover GM's " << endl;
					   cout<< "4- Visualizar GM's" << endl;
					   cout<< "0- Voltar ao menu"<< endl;
							 int gm=-1;
							 cout << "Opção:";
							 cin>> gm;
							 cout<< endl;
							 if (gm== 0)
						   { goto op2;}
						 else { while (gm== 1)
								{base->addmgm();
								break;
							  }
							while (gm == 2)
							  { base->edtmgm();
								break;}

							  while (gm== 3)
							   {base->rmvmgm();
								 break;}
							  while (gm == 4)
							 {base->infomgm();
							  break;}

									  }
								}

					  }
					  while (es == 6)
					   {   if (pri==0)
					   {cout<< "1- Visualizar Estadios" << endl;
					   cout<< "0- Voltar ao menu"<< endl;
					   int st=-1;
					   cout << "Opção:";
						cin>> st;
						cout<< endl;
						if (st== 0)
						{ goto op2;}
						 else while (st == 4)
						 {base->infoest();
						   break; }
					   }

						  else
						  {cout<< "1- Adicionar Estadio"<< endl;
						  cout << "2- Editar Estadio " << endl;
						  cout<< "3- Remover Estadio" << endl;
						  cout<< "4- Visualizar Estadios" << endl;
						  cout<< "0- Voltar ao menu"<< endl;
						   int st=-1;
						   cout << "Opção:";
						  cin>> st;
						  cout<< endl;
						   if (st== 0)
							{ goto op2;}
							  else { while (st== 1)
									{base->addest();
									  break;
												   }
								while (st == 2)
								  {base->edtest();
									  break;}

								 while (st== 3)
								   {base->rmvest();
									break;}
								 while (st == 4)
								 {base->infoest();
								   break; }
								  }
								  }

					   }
					  while (es == 7)
					   {   if (pri== 0)
					   {cout<< "1- Visualizar Managers" << endl;
						cout<< "0- Voltar ao menu"<< endl;
							 int ma=-1;
							 cout << "Opção:";
							cin>> ma;
						   cout<< endl;
						 if (ma== 0)
						  { goto op2;}
					   else while (ma == 1)
					 {base->infoman();
					 break;
					 }

					   }

						  else

					   {cout<< "1- Adicionar Manager"<< endl;
					   cout << "2- Editar Manager " << endl;
					   cout<< "3- Remover Manager" << endl;
					   cout<< "4- Visualizar Managers" << endl;
					   cout<< "0- Voltar ao menu"<< endl;
							 int ma=-1;
							 cout << "Opção:";
							cin>> ma;
						   cout<< endl;
						 if (ma== 0)
						  { goto op2;}
					   else { while (ma== 1)
						   {base->addman();
						   break;
							 }
						 while (ma == 2)
							 {base->edtman();
							   break;}

						  while (ma== 3)
							{base->rmvman();
							  break;}
						  while (ma == 4)
							 {base->infoman();
							 break;
							 }
							   }
							  }

						}}
				while (op == 2)
					{op3: cout<< "1- Gestão do Campeonato "<<endl;
					 cout << "2- Gestão dos jogos"<< endl;
					 cout << "3- Gestão dos arbitros"<<endl;
					 cout<< "0- Voltar ao menu"<< endl;
					 int ges=-1;
					 cout<< "Opção: ";
					 cin>> ges;
					 while (ges==0)
					 {goto op1;}
					 while (ges==1)
					  {if (pri==0)
						{ cout<< "1- Visualizar campeonato" << endl;
						  cout<< "0- Voltar ao menu" << endl;
						  int cp=-1;
						  cout << "Opção:";
						  cin >> cp;
						  cout<< endl;
						 if  (cp == 0)
						 { goto op3;}
						else {  while (cp == 1)
						 {   base->infocmp();
						goto op3;
												  }}}

						 else
					  {

					   cout << "1- Adicionar campeonato " << endl;
					   cout << "2- Editar campeonato" << endl;
					   cout << "3- Remover campeonato" << endl;
					   cout<< "4- Visualizar campeonato" << endl;
					   cout<< "0- Voltar ao menu" << endl;
					   int cp=-1;
					   cout << "Opção:";
					   cin >> cp;
						cout<< endl;
					   if  (cp == 0)
					   { goto op3;}
					   else {  while (cp == 1)
					   {   base->addcmp();
					   break;
					  }
					   while (cp == 2)
					   {base->edtcmp();
					   break;}
					   while (cp == 3)
					   {base->rmvcmp();
					   break;}

					   while (cp == 4)
					   {base->infocmp();
						   break;
					   }
												}}

					}
					 while (ges== 2)
						 { if (pri==0)
							{ cout<< "1- Visualizar jogos" << endl;
							  cout<< "0- Voltar ao menu" << endl;
							  int jo=-1;
							  cout << "Opção:";
							  cin >> jo;
							  cout<< endl;
							 if  (jo == 0)
							 { goto op3;}
							else {  while (jo == 1)
							 {   base->infojog();
							break;
													  }}}

						 else
				 { cout << "1- Adicionar jogo " << endl;
				   cout << "2- Editar jogo" << endl;
				   cout << "3- Remover jogo" << endl;
				   cout<< "4- Visualizar jogos" << endl;
				   cout<< "0- Voltar ao menu" << endl;
				   int jo=-1;
				   cout << "Opção:";
				   cin >> jo;
					cout<< endl;
				   if  (jo == 0)
				   { goto op3;}
				   else {  while (jo == 1)
				   {   base->addjgo();
					break;
				   }
				   while (jo == 2)
				   {base->edtjgo();
				   break;}
				   while (jo == 3)
				   {base->rmvjgo();
				   break;}

				   while (jo == 4)
				   {base->infojog();
					   break;
				   }
											}}
				}
			  while (ges == 3)
			  {{ if (pri==0)
				{ cout<< "1- Visualizar arbitros" << endl;
				  cout<< "0- Voltar ao menu" << endl;
				  int ar=-1;
				  cout << "Opção:";
				  cin >> ar;
				  cout<< endl;
				 if  (ar == 0)
				 { goto op3;}
				else {  while (ar == 1)
				 {   base->infoarb();
				break;
										  }}}

				  else
			  {

			   cout << "1- Adicionar arbitro " << endl;
			   cout << "2- Editar arbitro" << endl;
			   cout << "3- Remover arbitro" << endl;
			   cout<< "4- Visualizar arbitros" << endl;
			   cout<< "0- Voltar ao menu" << endl;
			   int ar=-1;
			   cout << "Opção:";
			   cin >> ar;
				cout<< endl;
			   if  (ar == 0)
			   { goto op3;}
			   else {  while (ar == 1)
			   {   base->addarb();
			   break;
			  }
			   while (ar == 2)
			   {base->edtarb();
			   break;}
			   while (ar == 3)
			   {base->rmvarb();
			   break;}

			   while (ar == 4)
			   {base->infoarb();
				   break;
			   }
										}}

			}}}

			  while (op == 3)
			  {op5: cout<< "1- Pesquisar Equipa"<< endl;
			   cout<<"2- Pesquisar Estadio "<<endl;
			   cout << "3- Pesquisar Jogadores " << endl;
			   cout<< "4- Pesquisar Jogo" << endl;
			   cout << "0- Voltar ao menu "<< endl;
				int res=-1;
				cout << "Opção:";
				cin>>res;
				while (res==0)
				{ goto op1;}
				while (res==1)
					{  cout<< "1- Visualizar todas as Equipas"<< endl;
					   cout<< "2- Pesquisar Equipas de um pais"<< endl;
					   cout<< "0- Voltar ao menu "<< endl;
					   int equ=-1;
					   cout<< "Opção: ";
					   cin>>equ;
					   while (equ==0)
					   {goto op5;}
					   while (equ==1)
					   {base->infoequ();
						break;}
					   while (equ==2)
					   { cout<< "Introduza o pais: " ;
					   string pais1;
					   getline (cin, pais1);
					   getline (cin, pais1);
					   base->infoequ(pais1);
					   break;
					   }

					}
				while (res==2)
				{ cout<< "1- Visualizar todos os Estadios"<< endl;
				   cout<< "2- Pesquisar Estadio de uma Equipa"<< endl;
				   cout<< "0- Voltar ao menu "<< endl;
				   int est=-1;
				   cout<< "Opção: ";
				   cin>>est;
				   while (est==0)
				   {goto op5;}
				   while (est==1)
				   {base->infoest();
					break;}
				   while (est==2)
				   { cout << "Introduza o nome da Equipa: " ;
				   string team;
				  getline (cin, team);
				  getline (cin, team);
				   cout << endl;
				   base->infoest(team);
				   break;
				   }

				}
				while (res==3)
				{ cout<< "1- Visualizar todos os Jogadores"<< endl;
				 cout<< "2- Pesquisar Jogadores dada uma posição"<< endl;
			     cout<< "0- Voltar ao menu "<< endl;
								   int ply=-1;
								   cout<< "Opção: ";
								   cin>>ply;
								   while (ply==0)
								   {goto op5;}
								   while (ply==1)
								   {base->infoply();
									break;}
								   while (ply==2)
								   {
								   cout << "P: Pitcher" << endl;
								   cout << "C: Catcher" << endl;
								   cout << "1B: First Base" << endl;
								   cout << "2B: Second Base " << endl;
								   cout << "3B: Third Base " << endl;
								   cout << "SS: Shortstop" << endl;
								   cout << "LF: Left Field " << endl;
								   cout << "CF: Center Field " << endl;
								   cout << "RF: Right Field " << endl;  ;
								   cout << "Introduza a posição: ";
								   string pos;
								   cin >> pos;
								   base->infoply(pos);
								   break;
								   }



								}
				while (res==4)
			{ cout<< "1- Visualizar todos os Jogos"<< endl;
			 cout<< "2- Pesquisar Jogo"<< endl;
			 cout<< "0- Voltar ao menu "<< endl;
				   int gam=-1;
				   cout<< "Opção: ";
				   cin>>gam;
				   while (gam==0)
				   {goto op5;}
				   while (gam==1)
				   {base->infojog();
					break;}
				   while (gam==2)
				   {
				   cout<< "Introduza o nome da Equipa visitante: ";
				    string guest1;
				    string home1;
				   getline (cin,guest1);
				   getline (cin,guest1);
				   cout<< "Introduza o nome da Equipa visitada:";

				  getline (cin, home1);
				   base->infojog(home1, guest1);
				   break;
				   }

												}
			  }

			 while (op == 4)
					{cout<< "1- Visualizar todos os campeonatos"<<endl;
					cout<< "2- Pesquisar campeonato por ano"<<endl;
					cout<< "0- Voltar ao menu"<< endl;
					 int cmp=-1;
					 cout<< "Opção: ";
					 cin>>cmp;
					 if (cmp==0)
					 { goto op1;}

					 while (cmp==1)

					 { base->infojog();
						break;
					}
					 while (cmp==2)
					 {cout<<"Introduza o ano do campeonato: "<< endl;
					  unsigned int ano;
					  cin>>ano;
					 base->infocmp(ano);
					  break;
					 }}

			while (op == 5)
			{
				cout << "1- Simulacao Completa" << endl;
				cout << "2- Simulacao Passo a Passo" << endl;
				cout << "3- Ajuda" << endl;
				cout << "0- Voltar ao menu" << endl;
				int sim=-1;
				cout << "Opção: ";
				cin >> sim;
				if (sim==0)
				{ goto op1;}
				if (sim==1)
				{ base->simulacao(0);}
				if (sim==2)
				{ base->simulacao(1);}
				if (sim==3)
				{ base->simhelp();}
			}

			 if ((op == 6) && (pri==1))
			 { cout << "1- Gestão dos Utilizadores "<<endl;
			   cout << "2- Visualizar as pessoas todas do sistema"<< endl;
			   cout << "0- Voltar ao menu" << endl;
			   int ges=-1;
			   cin>>ges;
			   while (ges==0)
			   {goto op1;}

               while (ges==1){
			   cout << "1- Adicionar Utilizador " << endl;
			   cout << "2- Editar Utilizador" << endl;
			   cout << "3- Remover Utilizador" << endl;
			   cout<< "4- Visualizar Utilizadores" << endl;
			   cout<< "5- Pesquisar Utilizadores dada uma prioridade"<< endl;
			   cout<< "0- Voltar ao menu" << endl;
				  int ut=-1;
				  cout << "Opção:";
				 cin>> ut;
				 cout<< endl;
				  if (ut== 0)
				 { break;}
				  else { while (ut== 1)
				  { base->adduti();
					break;
					}
					while (ut == 2)
					{ base->edtuti();
					 break;}

					 while (ut== 3)
					 {base->rmvuti();
					 break;}

					 while (ut == 4)
					 {base->infouti();
							break;}
					 while (ut==5)
					 {
					   cout<< "Introduza a prioridade (administrador ou utilizador): ";
					   string pri;
					   cin>> pri;
					   base->infouti(pri);
					   break;
					 }}

							  }
			 while (ges==2)
			 {
				 base->infoppl();
				 break;
			 }
			 }
			 while (op==9)
			 { cout << "1- Funcionamento do sistema" << endl ;
			   cout << "2- Info sistema" << endl;
			   cout << "0- Voltar ao menu" << endl;
			   int sis=-1;
			   cin >> sis;
			   while (sis==0)
			   { goto op1;}
			   while (sis==1)
			   {
			   base->help();
			     break;}
			   while(sis==2)
			   { base ->imprime();
			   break;}

			 }
			   while (op < 0 || op > 6)
			   { cout << "Opcao invalida" << endl;
			   break;

			}
			}
		} while (op != 0);

		cout << "Logout..." << endl << endl;
		cout << "Fechar aplicacao (s/n)?" << endl;
		cin >> fexo;
	} while ((fexo == 'n') || (fexo == 'N'));
    cout << endl;

	//Escreve no ficheiro
    if (base->guardadados())
    {cout << "Dados Guardados" << endl << endl;}
    cout << "Programa Terminado" << endl;
	return 0;
}

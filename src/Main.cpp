//============================================================================
// Name        : Baseball.cpp
// Author      : Vitor & Tomy
// Version     : 1.0
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
		base = new Baseball(1, "Baseball", "1.0");
		//Ler do ficheiro
	} catch (ErroFx erro) {
		cout << "Erro a ler o ficheiro " << erro.ficheiro << endl;
		cout << "A terminar aplicacao";
		base->resetdados();
		cout << "..." << endl;
		return 0;
	}

	if (base->init())
	{
		cout << ":::::::::::::::::::Sistema de Gestão de Campeonatos de BASEBALL :::::::::::::::" << endl << endl;
	}
	else
	{
		return 0;
	}

    do {
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

		do {op1:
			cout << endl << "Por favor selecione uma das seguintes opcoes:" << endl;

			cout << "1 - Gestão de atletas e equipas" << endl;
			cout << "2 - Gestão do campeonato " << endl;
			cout << "3 - Consulta de resultados, parciais e finais, ao longo do campeonato" << endl;
			cout << "4 - Consulta de informações sobre campeonatos anteriores" << endl;
			if (pri== 1)
			{
			cout << "5 - Utilizadores" << endl;}

			/*
			 * Gestão de atletas e equipas;
			 * Gestão do campeonato, com calendarização das diversas fases, jogos, local, etc.;
			 * Consulta de resultados, parciais e finais, ao longo do campeonato;
			 * Consulta de informações sobre campeonatos anteriores;
			 * Outras funcionalidades que julgarem necessárias.
			*/

			cout << "0 - logout." << endl;
			op=-1;
			cout << "Opção:";
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
						break;
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
				   {base->rmvjgo();
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
			  {cout<< "1- Visualizar resultados do campeonato"<< endl;
			   cout<<"2- Pesquisar resultados obtidos por uma equipa fora "<<endl;
			   cout << "3- Pesquisar resultados obtidos por uma equipa em casa " << endl;
			   cout << "0- Voltar ao menu "<< endl;
				int res=-1;
				cout << "Opção:";
				cin>>res;
				while (res==0)
				{ goto op1;}
				while (res==1)
					{ base->infocmp();
						break;
					}
				while (res==2)
				{ cout<<"Intruduza o nome da equipa para vizualizar os resultados: ";
				  string fora;
				cin>> fora ;
				// base->infojog1(fora);
				  break;

				}
				while (res==3)
			cout<<"Intruduza o nome da equipa para vizualizar os resultados: ";
				string casa;
				cin>>casa ;
				// base->infojog2(casa);
				  break;
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
			 { cout << "1- Adicionar Utilizador " << endl;
			   cout << "2- Editar Utilizador" << endl;
			   cout << "3- Remover Utilizador" << endl;
			   cout<< "4- Visualizar Utilizadores" << endl;
			   cout<< "0- Voltar ao menu" << endl;
				  int ut=-1;
				  cout << "Opção:";
				 cin>> ut;
				 cout<< endl;
				  if (ut== 0)
				 { goto op1;}
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

							  }}


			   while (op < 0 || op > 5)
			   { cout << "Opcao invalida" << endl;

			}
			}
		} while (op != 0);

		cout << "Logout..." << endl << endl;
		cout << "Fechar aplicacao (s/n)?" << endl;
		cin >> fexo;
	} while ((fexo == 'n') || (fexo == 'N'));

	cout << "Ate a proxima" << endl;
 return 0;

	//Passa para o ficheiro
    cout << "Ate a proxima" << endl;
	return 0;
}

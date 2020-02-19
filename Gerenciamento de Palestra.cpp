/*
Nome: Sistema de Gerenciamento de Auditório
Data: 05/12/2018

Pablo Victor Simões de Lima - N3480F1 - Líder / Analista de Software
Matheus Silas Mendes dos Santos - D8238J0 - Analista de Software
Mateus Marques de Souza - D8231F6 - Programador
Juliano Santos Ribeiro - D82GJC6 - Programador
Ronaldo José da Silva - N360AF5 - Documentador
Paulo Henrique Alvez de Oliveira - D836226 - Documentador
*/
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include <ctype.h>

//Definindo Valores para COL e LIN
#define COL 10
#define LIN 25

//Funções de Telas
int telaReserva();
void telaLogin();
void telaSorteio();
int telaMenu();

//Funções de Cabecalho e Rodape
void cabecalho(int tela);
void rodape();

//Funções para Sorteio
int sorteioLin();
int sorteioCol();

//Funções da Matriz de Assentos
void inicializa(char matriz[LIN][COL]);
void mostrarPainel(char matriz[LIN][COL]);
void reservar(char matriz[LIN][COL]);
void legenda();
int colunaY();
int linhaX();

//Struct para Usuario
typedef struct Usuario{
	
	char nome[30];
	int idade;
	char email[60];
	char ra[6];
	int ocupacao;
	int nav;
	
}Usuario;

int main (){

 	char matriz[LIN][COL];
 	int opcao;
  	int nav = 72;
  	double registro = false;
  	int tela = 0;

  	char nome[30];
	int idade;
	char email[60];
	char ra[6];
	int ocupacao;
	int id;

	char data[12];
	char hora[9];

	setlocale(LC_ALL, "Portuguese");

  	inicializa(matriz);

  	setbuf(stdin, NULL);        //Limpa Memoria
  	
  	tela = telaMenu();
	  
	//Verifica o Retorno da TelaMenu() para exibir os assentos  
	while(tela == 1){
	 	
		mostrarPainel(matriz);
		reservar(matriz);
		setbuf(stdin, NULL);
		
		_strdate(data);

		printf("\n\n\t\t Data: %s ", data);

		printf("Hora: %s", __TIME__);

		printf("\n\n\t\tDigite 'Esc' para voltar ao Menu!");
		rodape();	
		setbuf(stdin, NULL);
		nav = getch();
			
		//Retorna ao Menu	
		if (nav == 27){
	 		
	 		tela = telaMenu();
	 		
		}
	}
	 	
	while(tela == 2 || tela == 3){
		
		
		mostrarPainel(matriz);
		printf("\n\n\n\t\t\t\t\tATENÇÃO!!");
		printf("\n\n\t\t\t       Você já passui assentos reservados!!");
		printf("\n\n\t\t\t\tVerifique o painel e os assentos!");
		
		//Exibição de Data e Hora
		_strdate(data);
		printf("\n\n\t\t Data: %s ", data);
		printf("Hora: %s", __TIME__);

		printf("\n\n\t\tDigite 'Esc' para voltar ao Menu!");
		rodape();	
		setbuf(stdin, NULL);
		nav = getch();
			
		//Retorna ao Menu	
		if (nav == 27){
	 		
	 		tela = telaMenu();		
		
		} 
	}
	 
}
  
//Função respónsavel pelo direcionamento á outras funções principais 	
int telaMenu(){

	int nav = 72;
	int tela = 1;
	int ocupacao;

	setbuf(stdin, NULL);

	do{
		
		system("cls");
		cabecalho(1);
		printf("\n\n\t\t    USE AS SETAS DO TECLADO PARA NAVEGAR E ENTER PARA SELECIONAR!");
		printf("\n\n\n\n\n\t\t\t\t\t  >>| RESERVAR |<<");
		printf("\n\n\n\n\n\t\t\t\t\t      | LOGIN |");
		printf("\n\n\n\n\n\t\t\t\t\t     | SORTEIO |");
		rodape();
		setbuf(stdin, NULL);
		nav = getch();

		while(nav == 80 && tela == 1){

			system("cls");
			cabecalho(1);
			printf("\n\n\t\t    USE AS SETAS DO TECLADO PARA NAVEGAR E ENTER PARA SELECIONAR!");
			printf("\n\n\n\n\n\t\t\t\t\t    | RESERVAR |");
			printf("\n\n\n\n\n\t\t\t\t\t    >>| LOGIN |<<");
			printf("\n\n\n\n\n\t\t\t\t\t     | SORTEIO |");
			rodape();
			tela = 2;
			setbuf(stdin, NULL);
			nav = getch();
	
		}
		
		while(nav == 80 && tela == 2){

			system("cls");
			cabecalho(1);
			printf("\n\n\t\t    USE AS SETAS DO TECLADO PARA NAVEGAR E ENTER PARA SELECIONAR!");
			printf("\n\n\n\n\n\t\t\t\t\t    | RESERVAR |");
			printf("\n\n\n\n\n\t\t\t\t\t      | LOGIN |");
			printf("\n\n\n\n\n\t\t\t\t\t   >>| SORTEIO |<<");
			rodape();
			tela = 3;
			setbuf(stdin, NULL);
			nav = getch();
				
		}
		
		while(nav == 80 && tela == 3){

			system("cls");
			cabecalho(1);
			printf("\n\n\t\t    USE AS SETAS DO TECLADO PARA NAVEGAR E ENTER PARA SELECIONAR!");
			printf("\n\n\n\n\n\t\t\t\t\t  >>| RESERVAR |<<");
			printf("\n\n\n\n\n\t\t\t\t\t      | LOGIN |");
			printf("\n\n\n\n\n\t\t\t\t\t     | SORTEIO |");
			rodape();
			tela = 1;
			setbuf(stdin, NULL);
			nav = getch();
	
		}
		
		while(nav == 72 && tela == 1){

			system("cls");
			cabecalho(1);
			printf("\n\n\t\t    USE AS SETAS DO TECLADO PARA NAVEGAR E ENTER PARA SELECIONAR!");
			printf("\n\n\n\n\n\t\t\t\t\t    | RESERVAR |");
			printf("\n\n\n\n\n\t\t\t\t\t      | LOGIN |");
			printf("\n\n\n\n\n\t\t\t\t\t   >>| SORTEIO |<<");
			rodape();
			tela = 3;
			setbuf(stdin, NULL);
			nav = getch();
			
		}
		
		while(nav == 72 && tela == 2){

			system("cls");
			cabecalho(1);
			printf("\n\n\t\t    USE AS SETAS DO TECLADO PARA NAVEGAR E ENTER PARA SELECIONAR!");
			printf("\n\n\n\n\n\t\t\t\t\t  >>| RESERVAR |<<");
			printf("\n\n\n\n\n\t\t\t\t\t      | LOGIN |");
			printf("\n\n\n\n\n\t\t\t\t\t     | SORTEIO |");
			rodape();
			tela = 1;
			setbuf(stdin, NULL);
			nav = getch();
	
		}
		
		while(nav == 72 && tela == 3){

			system("cls");
			cabecalho(1);
			printf("\n\n\t\t    USE AS SETAS DO TECLADO PARA NAVEGAR E ENTER PARA SELECIONAR!");
			printf("\n\n\n\n\n\t\t\t\t\t    | RESERVAR |");
			printf("\n\n\n\n\n\t\t\t\t\t    >>| LOGIN |<<");
			printf("\n\n\n\n\n\t\t\t\t\t     | SORTEIO |");
			rodape();
			tela = 2;
			setbuf(stdin, NULL);
			nav = getch();
			
		}

		//Verifica em qual opção o usuário selecionou Enter
		if (nav == 13 && tela == 1){

			system("cls");
			setbuf(stdin, NULL);
			ocupacao = telaReserva();
			return ocupacao;

		}else if(nav == 13 && tela == 2){

			system("cls");
			setbuf(stdin, NULL);
			telaLogin();
			return 2;

		}else if(nav == 13 && tela == 3){

			system("cls");
			setbuf(stdin, NULL);
			telaSorteio();
			return 3;
		}	

	}while(nav != 0);
}

//Função responsável pela reserva de assentos de cada participante da palestra
int telaReserva(){
	
	Usuario usuario;
	int nav = 1;
			
	system("cls");
	//Setas Cima: 38 / Baixo: 40 / Esquerda: 37 / Direita: 39 / Delete: 46
	//Criando e abrindo o arquivo "usuario", responsável por armazenar os dados cadastrados
	FILE *arquivoDeUsuario;
	arquivoDeUsuario = fopen("usuario.txt", "a+");

	cabecalho(2);

	printf("\t\t\t\tAperte 'Esc' para voltar ao Menu Principal \n\n\t\t\t      Olá! Irei fazer a sua reserva para a palestra!\n\n");
	printf("\t\tPrimeiro, me informe sua ocupação: ");
	printf("\n\n\t\t1) Aluno \n\n\t\t2) Convidado \n\n\t\t3) Professor\n\n");
	rodape();
	setbuf(stdin, NULL);
	nav = getch();
			
	switch(nav){
				
		case 49:
			usuario.ocupacao = 1;
			setbuf(stdin, NULL);
			break;
					
		case 50:
			usuario.ocupacao = 2;
			setbuf(stdin, NULL);
			break;
					
		case 51:
			usuario.ocupacao = 3;
			setbuf(stdin, NULL);
			break;
					
		case 27:
			telaMenu();
			break;			
				
	}

	//Verifica se a ocupação digitada é válida
	if(usuario.ocupacao != 1 && usuario.ocupacao != 2 && usuario.ocupacao != 3){

		printf("\n\n\t\tDigite uma ocupação valida!");
		setbuf(stdin, NULL);
		scanf("\t\t\t %d", &usuario.ocupacao);

	}

	setbuf(stdin, NULL);

	system("cls");
	cabecalho(2);
	printf("\n\n\t\t\tAgora me informe o seu nome!");
	printf("\n\t\t\tDigite o seu nome: ");
	scanf("\t\t\t %[^\n]s", &usuario.nome);
	strupr(usuario.nome); //converte Nome para Maiusculo.
	setbuf(stdin, NULL);

	system("cls");
	cabecalho(2);
	printf("\n\n\t\t\tCerto %s digite agora sua idade: ", usuario.nome);
	scanf("\t\t\t %d", &usuario.idade);

	system("cls");
	cabecalho(2);
	printf("\n\n\t\t\tDigite o seu e-mail: ");
	scanf("\t\t\t %s", &usuario.email);
	strlwr(usuario.email);

	system("cls");

	if(usuario.ocupacao == 1){

		cabecalho(2);
		printf("\n\n\t\t\tAgora digite seu R.A: ");
		scanf("\t\t\t %s", &usuario.ra);
		system("cls");
		fprintf(arquivoDeUsuario, " Aluno | Nome: %s | Idade: %d | E-Mail: %s | R.A: %s |\n", usuario.nome, usuario.idade, usuario.email, usuario.ra);
		fclose(arquivoDeUsuario); //fecha a entrada dos dados.
		return 1;

	}else if (usuario.ocupacao == 2){

		setbuf(stdin, NULL);
		system("cls");
		fprintf(arquivoDeUsuario, " Convidado | Nome: %s | Idade: %d | E-Mail: %s |\n", usuario.nome, usuario.idade, usuario.email);
		fclose(arquivoDeUsuario); //fecha a entrada dos dados.
		return 2;


	}else if (usuario.ocupacao == 3){
		
		setbuf(stdin, NULL);
		system("cls");
		fprintf(arquivoDeUsuario, " Professor | Nome: %s | Idade: %d | E-Mail: %s |\n", usuario.nome, usuario.idade, usuario.email);
		fclose(arquivoDeUsuario); //fecha a entrada dos dados.
		return 3;

	}
	
			
}

//Função responsável pelo controle de cadastro de palestrantes
void telaLogin(){
	
	char senha[] = {'P', 'A', 'L', 'E', 'S', 'T', 'R', 'A', 'N', 'T', 'E', 'U', 'N', 'I', 'P'};
	char senhaDigitada[15];
	char nomePalestrante[50];
	char emailPalestrante[30];
	char temaPalestra[100];
	int i, j, k,diaPalestra, mesPalestra;
	int nav;
	char data[12];
	
	cabecalho(3);

	FILE *arquivoPalestrante;
	arquivoPalestrante = fopen("palestrante.txt", "a+");

	printf("\n\n\n\t\t\t\t\t\tATENÇÃO!!\n");
	printf("\n\n\n\t\tÁrea restrita á Palestrantes! \n\n\t\tSe você tem a senha de Palestrante pressione 'Enter' ou 'Esc' para retornar ao Menu\n");
	rodape();
	nav = getch();
	setbuf(stdin, NULL);
				
	if (nav == 13){
					
		system("cls");
		cabecalho(3);
		printf("\n\n\n\t\t\t\tCerto! Digite a senha do Palestrante!\n");
		scanf("\t\t\t %s", &senhaDigitada);
		strupr(senhaDigitada);
					
	}else if(nav == 27){
				
		telaMenu();
				
	}

	strupr(senhaDigitada);
	for(i = 0; i<15; i++)
		if(senhaDigitada > senha){
					
			printf("\n\n\t\t\t\tSenha incorreta! Digite 'Esc' para voltar ao Menu ou 'Enter' para tentar novamente!!");
			rodape();
			nav = getch();
			
			switch(nav){
						
				case 27:
					telaMenu();
					break;
							
				case 13:
								
					printf("\n\n\t\t\t\tDigite a senha novamente: ");
					scanf("%s", &senhaDigitada);
					strupr(senhaDigitada);
					break;
			}
					
		}
		for(i = 0; i<15; i++){
		
		if(senhaDigitada[i] == senha[i]){

		 	system("cls");
		 	cabecalho(3);
		 	setbuf(stdin, NULL);
		 	printf("\n\n\t\tBem vindo palestrante!");
		 	printf("\n\t\tMe informe seu nome: ");
		 	scanf("%[^\n]s", &nomePalestrante);
		 	strupr(nomePalestrante);
		 	setbuf(stdin, NULL);

		 	system("cls");
		 	cabecalho(3);
		 	printf("\n\n\t\tMe informe seu e-mail: ");
		 	scanf("%[^\n]s", &emailPalestrante);
		 	strlwr(emailPalestrante);
		 	setbuf(stdin, NULL);

		 	system("cls");
		 	cabecalho(3);
		 	printf("\n\n\t\tQual o tema da sua palestra?\n\t\t");
		 	scanf("\t\t %[^\n]s", &temaPalestra);
		 	strupr(temaPalestra);
		 	setbuf(stdin, NULL);

		 	system("cls");
		 	cabecalho(3);
		 	printf("\n\n\t\tQue dia será sua palestra?\n\t\t");
		 	scanf("\t\t %d", &diaPalestra);

			system("cls");
		 	cabecalho(3);
		 	printf("\n\n\t\tSerá dia %d de que mês?\n\t\t", diaPalestra);
			scanf("\t\t %d", &mesPalestra);

		 	fprintf(arquivoPalestrante, "Nome: %s | E-Mail: %s | Tema: %s | Data: %d / %d \n", nomePalestrante, emailPalestrante, temaPalestra, diaPalestra,
			mesPalestra);

			fclose(arquivoPalestrante);

			system("cls");
			cabecalho(3);
			printf("\n\n\t\tSeu cadastro foi concluído com sucesso!");
			_strdate(data);

			printf("\n\n\t\t Data: %s ", data);
	
			printf("Hora: %s", __TIME__);
	
			printf("\n\n\t\tDigite 'Esc' para voltar ao Menu!");
			rodape();	
			setbuf(stdin, NULL);
			nav = getch();
			
			if (nav == 27){
		 		
		 		telaMenu();
	 		
			}		
			
		}else{

			system("cls");
		 	cabecalho(3);
		 	printf("\n\n\t\tSenha incorreta!");
		 	printf("\n\t\tDigite 'Enter' para tentar novamente ou 'Esc' para retornar ao Menu Principal\n");
		 	rodape();
		 	setbuf(stdin, NULL);
		 	nav = getch();

		 	if(nav == 13){

		 		system("cls");
		 		cabecalho(3);
		 		setbuf(stdin, NULL);
		 		printf("\n\n\t\tDigite a senha novamente: \n\t\t");
				scanf("%s", &senha);
				setbuf(stdin, NULL);

			}else if(nav == 27){

			 	fclose(arquivoPalestrante);
			 	setbuf(stdin, NULL);
			 	telaMenu();
			 		
			}
	}

		}
	
	i = 0;
	setbuf(stdin, NULL);	
	
}

//Função responsável pelo sorteio de brindes
void telaSorteio(){
	
	char senha[] = {'S', 'O', 'R', 'T', 'E', 'I', 'O', 'U', 'N', 'I', 'P'};
	char senhaDigitada[11]; 
	int nav = 0, i;
	
	system("cls");
	cabecalho(4);
	printf("\n\n\n\t\t\t\t\t\tATENÇÃO!!\n");
	printf("\n\n\t\t\t\t É necessário uma senha para realizar o sorteio! \n\n\t\t\tDigite 'Enter' para inserir a senha ou 'Esc' para voltar ao Menu!");
	rodape();
	nav = getch();
	
	switch (nav){
		
		case 13:
			system("cls");
			cabecalho(4);
			printf("\n\n\n\t\t\t\tDigite a senha: ");
			setbuf(stdin, NULL);
			scanf("%s", &senhaDigitada);
			strupr(senhaDigitada);
			
			for(i = 0; i<11; i++){
				while (senhaDigitada > senha){
					
					printf("\n\n\t\t\tSenha incorreta! Digite 'Esc' para voltar ao Menu ou 'Enter' para tentar novamente!!");
					nav = getch();
					switch(nav){
						
						case 27:
							
							telaMenu();
							break;
							
						case 13:
								
							printf("\n\n\t\t\t\tDigite a senha novamente: ");
							scanf("%s", &senhaDigitada);
							strupr(senhaDigitada);
							break;
					}
					
				}
				
				if(senhaDigitada[i] == senha[i]){
					
					system("cls");
					cabecalho(4);
					printf("\n\n\n\t\t\t\tA linha sorteada é: %d", sorteioLin());
					printf("\n\n\n\t\t\t\tA Coluna sorteada é: %d\n\n", sorteioCol());
					
					printf("Pressione 'Esc' para voltar ao Menu ou 'R' para realizar um novo sorteio!");
					nav = getch();
					
					switch(nav){
						
						case 27:
							telaMenu();
							break;
						
						case 52:
									
							system("cls");
							cabecalho(4);
							printf("\n\n\n\t\t\t\tA linha sorteada é: %d", sorteioLin());
							printf("\n\n\n\t\t\t\tA Coluna sorteada é: %d\n\n", sorteioCol());
					
							printf("\n\n\t\t\tPressione 'Esc' para voltar ao Menu ou 'R' para realizar um novo sorteio!");
							rodape();
							i = i + 1;
							nav = getch();
							break;
							
					}
				
				}else{
					
					printf("\n\n\t\t\t\tSenha incorreta! Digite 'Esc' para voltar ao Menu ou 'Enter' para tentar novamente!!");
					nav = getch();
					switch(nav){
						
						case 27:
							
							telaMenu();
							break;
							
						case 13:
								
							printf("\n\n\t\t\t\tDigite a senha novamente: ");
							scanf("%s", &senhaDigitada);
							strupr(senhaDigitada);
							break;
					}
					
				}
				
			}
			break;
		
		//Retorna á função Menu	
		case 27:
			telaMenu();	
			break;
		
	}
	
	
}

//Função responsável pela inicialização da matriz de assentos
void inicializa(char matriz[LIN][COL]){

	int auxI, auxJ;
     int i,j;
     for(i=1;i<=LIN;i++)
       for(j=1;j<=COL;j++)
          matriz[i][j] = '.';

    for(auxI = 1; auxI<=2; auxI++)
		for(auxJ = 1; auxJ<=10; auxJ++)
			matriz[auxI][auxJ] = 'R';

	for(auxI = 3; auxI<=8; auxI++)
		for(auxJ = 1; auxJ<= 1; auxJ++)
			matriz[auxI][auxJ] = 'D';

	for(auxI = 3; auxI<=9; auxI++)
		for(auxJ = 10; auxJ<= 10; auxJ++)
			matriz[auxI][auxJ] = 'D';
}

//Função responsável por exibir o painel de Assentos
void mostrarPainel(char matriz[LIN][COL]){

  int i,j;
  printf("\n\n\t\t\t         %c   PAINEL DE OCUPACOES   %c\n\n",16,17);
  printf("          ");

  for(i=1;i<=COL;i++)
    printf("\t %d     ",i);

  for(i=1;i<=LIN;i++){
     printf("\t\n\n\t   %d",i);
     for(j=1;j<=COL;j++)
       printf("\t(%c)",matriz[i][j]);
  }
  //apresenta o menu na tela
  legenda();
}

//apresenta  a legenda na tela
void legenda(){
   printf("\n\n\n\t  .-Livre  X-Ocupado  R-Reservado Para Professores e Convidados  D-Reservado Para Deficientes");

}
//efetica a reserva da cadeira
void reservar(char matriz[LIN][COL]){
   int lin, col;
   printf("\n           RESERVA DE CADEIRAS\n\n");
   lin = linhaX();
   col = colunaY();

            while (matriz[lin][col]=='X'){

                printf("\n\n\t\t      CADEIRA JA OCUPADA!! ESCOLHA OUTRA !!\n\n");
                lin = linhaX();
                col = colunaY();

                } 
				while(matriz[lin][col]=='R' || matriz[lin][col]=='D'){

                           printf("\n\n\t\t    CADEIRA JA RESERVADA!! ESCOLHA OUTRA !!\n\n");
                           lin = linhaX();
                           col = colunaY();
                }
                
				while(matriz[lin][col]=='.'){
					
                   matriz[lin][col] = 'X';
                   printf("\n\n\t\t      Reserva Feita com Sucesso !!");
               
               }
				
				
			
    }


//ler a linha oferecida pelo usuario
int linhaX(){
   int lin;
   printf("          Linha: ");
   scanf("%d", &lin);
   
   
        while(lin<0 || lin>25){
        	
        	setbuf(stdin, NULL);
            printf("\t\t\n Esta cadeira nao existe, digite um assento válido!!\n");
            lin = linhaX(); // Se o if for execultado mensagem é exibida e função é rechamada.
            setbuf(stdin, NULL);
        }
	
   return lin;

}
//ler a coluna oferecida pelo usuario
int colunaY(){
   int col;
   printf("          Coluna: ");
   scanf("%d", &col);
        while(col<0 || col>10){
        	
        	setbuf(stdin, NULL);
            printf("     \t\t\n Esta cadeira nao existe, digite um assento válido!!\n");
            col = colunaY(); // Se o if for execultado mensagem é exibida e função é rechamada.
       }
   return col;
}

//Função que realiza o sorteio de um número aleatorio de linhas
int sorteioLin(){
	
	unsigned int lin, i = 0;
	int nav;
	
	srand(time(NULL));
	lin = rand() % 25;
	
	while(lin < 2){
	
		lin = rand() % 25;
		
	}
	
	return lin;
	
}

//Função que realiza o sorteio de um número aleatorio de colunas
int sorteioCol(){
	
	unsigned int col;
	
	srand(time(NULL));
	col = rand() % 10;
	
	while(col<=0){
		
		col = rand() % 10;
		
	}
	
	return col;
	
}

//Função responsável pelo controle de cabecalhos a ser exibido
void cabecalho(int tela){

	if (tela == 1){

			printf("\n\n\t\t================================MENU===============================\n\n\n");

	}else if(tela == 2){

		printf("\n\n\t\t================================RESERVA===============================\n\n\n\n");

	}else if(tela == 3){

		printf("\n\n\t\t================================LOGIN===============================\n\n\n");

	}else if(tela == 4){

		printf("\n\n\t\t================================SORTEIO===============================\n\n\n");

	}

}

//Função responsável por exibir o rodapé 
void rodape(){

	printf("\n\n\n\n\t\t=========================================================================\n");

}



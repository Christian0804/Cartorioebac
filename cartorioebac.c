#include <stdio.h> //Biblioteca de comunica��o com o usuario
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca responsalvel por cuidar dos string

int registro() //Fun��o reponsalvel por cadastrar os usuarios no istema
{
	//Inicio da cria��o de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variavel/string

	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s", cpf); //%s redere-se a string cpf

	strcpy(arquivo, cpf); //Responsalvel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo (w) escrever
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo

	file = fopen(arquivo, "a"); //Abre o arquivo (a) atualizar
	fprintf(file,","); //Inclui (,) para separar informa��es no banco de dados
	fclose(file); //Fecha o arquivo

	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s", nome); //%s redere-se a string nome
	
	file = fopen(arquivo, "a"); //Abre o aqruivo (a) atualizar
	fprintf(file,nome); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo

	file = fopen(arquivo, "a"); //Abre o aqruivo (a) atualizar
	fprintf(file,","); //Inclui (,) para separar informa��es no banco de dados
	fclose(file); //Fecha o arquivo

	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s", sobrenome); //%s redere-se a string sobrenome
	
	file = fopen(arquivo, "a"); //Abre o aqruivo (a) atualizar
	fprintf(file,sobrenome); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo

	file = fopen(arquivo, "a"); //Abre o aqruivo (a) atualizar
	fprintf(file,","); //Inclui (,) para separar informa��es no banco de dados
	fclose(file); //Fecha o arquivo

	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s", cargo); //%s redere-se a string cargo
	
	file = fopen(arquivo, "a"); //Abre o aqruivo (a) atualizar
	fprintf(file,cargo); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo

	system("pause"); //Pausa o sistema para o que o usuario tenta tempo de ler no sistema

}

int consulta()
{

	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	//Inicio da cria��o de variavel/string
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de variavel/string

	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usuario
	scanf("%s",cpf); //%s redere-se a string cpf

	FILE *file; // Cria o arquivo
	file = fopen(cpf,"r"); //Le o arquivo (r) ler

	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Infoma��o ao usuario
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: "); //Infoma��o ao usuario
		printf("%s", conteudo); //%s redere-se a string conteudo
		printf("\n\n");
	}

	system("pause"); //Pausa o sistema para o que o usuario tenta tempo de ler no sistema

}

int deletar()
{
	//Inicio da cria��o de variavel/string
	char cpf[40];
	//Final da cria��o de variavel/string

	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��o do usuario
	scanf("%s",cpf); //%s redere-se a string cpf

	remove(cpf); //Remove o usuario

	FILE *file; // Cria o arquivo
	file = fopen(cpf,"r"); //Le o arquivo (r) ler

	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n\n"); //Infoma��o ao usuario
		system("pause"); //Pausa o sistema para o que o usuario tenta tempo de ler no sistema
	}
}


int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;	
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: "); //Coletando informa��o do usuario
	scanf("%s",senhadigitada); //%s redere-se a string senhadigitada
	
	comparacao = strcmp(senhadigitada, "admin"); //fazendo a compara��o da senha digitada
	
	if(comparacao == 0)
	{
		system("cls");
		
		for(laco=1;laco=1;)
		{

			system("cls"); //Comando para apagar a tela

			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

			printf("### Cart�rio da EBAC ###\n\n"); //Ininio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");		
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");//Final do menu

			scanf("%d", &opcao); //Armazenado a escolha do usuario
	
			system("cls"); //Responsalvel por limpar a tela
		
			switch(opcao) //Inicio da sele��o do menu
			{
				case 1:
				registro(); //Chamada de fun��es
				break;

				case 2:
				consulta(); //Chamada de fun��es
				break;

				case 3:
				deletar(); //Chamada de fun��es
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0; //Quebrando a fu��o para sair do sistema
				break;
				
				default:
				printf("Essa op��o n�o est� disponivel\n"); //Infoma��o ao cliente
				system("pause");
				break;
			}	// Fim da sele��o
		}
	}	
	
	else
		printf("Senha incorreta");
		
}


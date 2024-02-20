#include <stdio.h> // Biblioteca de comunicaçãoo com o usuario (teclado)
#include <stdlib.h> // Biblioteca de alocação de memoria
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsavel por cuidar das strings
#include <Windows.h> // Biblioteca da função Sleep

int portugues(){ // Função que altera o idioma para incluir caracteres PT-BR
	setlocale(LC_ALL, "Portuguese");
}

int voltaMenu(){ // Função que paralisa o programa por um momento para que o usuario possa ler a mensagem e em seguida uma mensagem voltando ao menu aparece e se encerra automaticamente
	Sleep(900); // Para o programa por 0.9s
	system("cls"); // Apaga a tela 
	printf("Voltando ao menu.");
	Sleep(400);
	system("cls");
	printf("Voltando ao menu..");
	Sleep(400);
	system("cls");
	printf("Voltando ao menu...");
	Sleep(400);
	system("cls");
}

int cache(){ // Função necessaria para apagar o cache que fica nas variaveis quando vai realizar a mesma função seguidamente. Caso não use, o programa buga e insere variaveis automaticamente
	fflush(stdin);
}

int registraNomes(){ // Função que cria o cadastro de cada usuario em um arquivo novo salvando um .txt na pasta em que o programa se encontra

	portugues();
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	strcpy(arquivo, cpf); // Copia os valores das strings similar a (arquivo = cpf)
	
	FILE *file; // Cria um arquivo na pasta em que o programa se encotnra
	file = fopen(arquivo, "w"); // Abre o  arquivo na modalidade Write (Sobrescrever)
	fprintf(file, cpf); // Salva o valor da variavel
	fclose(file); // FECHA o arquivo!! Nunca esquecer
	cache();
	
	file = fopen(arquivo, "a"); // Abre o  arquivo na modalidade Append (Adiciona informações sem apagar as anteriores)
	fprintf(file, ", ");
	fclose(file);
	cache();
	
	printf("Primeiro Nome: ");
	scanf("%s", nome);	
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fprintf(file, " "); // Adiciona um espaço separador do nome
	fclose(file);
	cache();
	
	printf("Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);	
	fprintf(file, ", "); // Adiciona uma virgula separadora
	fclose(file);
	cache();
	
	
	printf("Digite o cargo ocupado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	cache();
	
	printf("Usuário cadastrado com sucesso!!");
	voltaMenu();
	
}

int consultaNomes(){ // Função que faz a consulta de algum nome no sistema pelo CPF

	portugues();
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abre o arquivo na modalidade Read (Leitura)
	
	if(file == NULL) // Faz a verificação se o arquivo é existente na pasta
	{
		printf("Usuário não localizado!");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario:\n\n");
		printf(conteudo);
	}
	fclose(file);
	cache();
	voltaMenu();
	
}

int deletaNomes(){ // Função que deleta usuarios a partir do CPF
	
	char cpf[12];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file; 
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\tUsuário não localizado no sistema!\n");
		
	}
	else
	{
	remove(cpf);
	printf("Usuário removido do sistema...\n\n");
	cache();
	voltaMenu();
	
	}
	
}

int main(){ // Programa principal
	portugues();
	int opcao = 99;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\n\t ###  Cartório da EBAC  ###\n\n");
	printf("Login de administrador!\n\n\tDigite a senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0){
		
		while (opcao!=0){
		
	
		printf("\n\t ###  Cartório da EBAC  ###\n\n");
		//printf("Escolha a opção desejada do Menu:  \n");
		printf("\t 1 - Registrar Nomes\n");
		printf("\t 2 - Consultar Nomes\n");
		printf("\t 3 - Deletar Nomes\n");
		printf("\t 0 - Sair\n");
		printf("\t     ALTERAÇÃO PARA ILUSTRAR NO GITHUB");
		printf("\n\n\tDigite uma opção: ");
		scanf("%d",&opcao);
		system("cls");
	
		switch(opcao){
	
		case 1:
			registraNomes();
			break;
		case 2:
			consultaNomes();
			break;
		case 3: 
			deletaNomes();
			break;
		case 0:
			printf("\n\n________Programa Encerrado________\n\n");
			exit (0);
		default:
			printf("\n\tOpção Incorreta.. Tente novamente!\n\n");
 		}
 	  }		
	}
	
	else 
		printf("---- Senha incorreta ----");
		

	

	printf("\n\n\n--------------------------------\n");
	printf("*** Esse software é de livre uso ***");
}

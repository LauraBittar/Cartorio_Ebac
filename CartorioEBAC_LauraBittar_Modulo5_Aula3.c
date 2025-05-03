#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca de string

int registrar() //Funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio da criacao das variaveis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//final da criacao das variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string
	strcpy(arquivo, cpf); //copiando a string cpf para a string arquivo
	
	FILE *file; //criando um arquivo
	
	file = fopen(arquivo, "w"); //definindo a variavel file como arquivo e modo write; abrindo o arquivo
	fprintf(file,cpf); //escrevendo a variavel cpf no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //definindo a variavel file como arquivo e modo append; abrindo o arquivo
	fprintf(file,","); //inserindo uma vírgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("\nDigite o nome a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //definindo a variavel file como arquivo e modo append; abrindo o arquivo
	fprintf(file,nome); //escrevendo a variavel nome no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //definindo a variavel file como arquivo e modo append; avrindo o arquivo
	fprintf(file,","); //inserindo uma virgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("\nDigite o sobrenome a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //definindo a variavel file como arquivo e modo append; abrindo o arquivo
	fprintf(file,sobrenome); //escrevendo a variavel sobrenome no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //definindo a variavel file como arquivo e modo append; abrindo o arquivo
	fprintf(file,","); //inserindo uma virgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("\nDigite o cargo a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //definindo a variavel file como arquivo e modo append; abrindo o arquivo
	fprintf(file,cargo); //escrevendo a variavel cargo no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //definindo a variavel file como arquivo e modo append; abrindo o arquivo
	fprintf(file,","); //inserindo uma virgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("\n"); //pulando linha na tela
	system("pause"); //inserindo pausa no sistema ate usuario pressionar alguma tecla
		
}


int consultar()
{
	//declaracao das variaveis
	char cpf[40];
	char conteudo[200];
	int contador;
	
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	contador = 0; //definindo valor inicial da variavel contador
	
	printf("Digite o CPF a ser consultado: "); //coletando dados do usuario
	scanf("%s", cpf);
	
	FILE *file; //criando um arquivo
	file = fopen(cpf, "r"); //abrindo o arquivo em modo read
	
	if(file==NULL) //checando existencia de arquivo e informando ao usuario
	{
		printf("\nCPF não encontrado/cadastrado. Confira o CPF.\n\n"); //informando usuario de arquivo inexistente
	}
	else //procedimentos em caso de arquivo existente
	{
		fgets(conteudo, 200, file); //coletando do sistema o conteudo escrito no arquivo
		printf("\n\n"); //pulando 2 linhas na tela
		printf("Dados encontrados!\n\n"); //informando o usuario da existencia do arquivo
		printf("CPF: %s", cpf); //informando conteudo do arquivo ao usuario (CPF)
		printf("\nNome: "); //inserindo especificacao da informacao na tela

		while (conteudo[contador] != ',') //varrer conteudo do início ao final do CPF para encontrar posição da primeira virgula
		{
			contador++; //incrementando contador para varrer o string
		}
	
		contador++; //incrementando contador para posicao de inicio do nome
	
		while (conteudo[contador] != ',') //varrer e imprimir conteudo do início ao final do nome e encontrar posicao da segunda virgula
		{
			printf("%c", conteudo[contador]); //informando conteudo do arquivo ao usuario (nome)
			contador++; //incrementando contador para varrer o string
		}
	
		contador++; //incrementando contador para posicao de inicio do sobrenome
		printf("\nSobrenome: "); //inserindo especificacao da informacao na tela
	
		while (conteudo[contador] != ',') //varrer e imprimir conteudo do início ao final do sobrenome e encontrar posicao da terceira virgula
		{
			printf("%c", conteudo[contador]); //informando conteudo do arquivo ao usuario (sobrenome)
			contador++; //incrementando contador para varrer o string
		}
	
		contador++; //incrementando contador para posicao de inicio do cargo
		printf("\nCargo: "); //inserindo especificacao da informacao na tela
	
		while (conteudo[contador] != ',') //varrer e imprimir conteudo do início ao final do cargo e encontrar posicao da ultima virgula
		{
			printf("%c", conteudo[contador]); //informando conteudo do arquivo ao usuario (cargo)
			contador++; //incrementando contador para varrer o string
		}
	
		printf("\n\n");	//pulando 2 linhas na tela
	}
	system("pause"); //inserindo pausa no sistema ate usuario pressionar alguma tecla
}
		

int deletar()
{
	char cpf[40];
	int r;
	
	r = 1;
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "w");
	
	if (file == NULL)
	{
		printf("\nCPF não encontrado/cadastrado. Confira o CPF.\n\n");
	}
	else
	{
		r = remove(cpf);
		printf("%d", r);
		if (file == NULL)
		{
			printf("O cadastro do usuário %s foi deletado com sucesso!", cpf);
		}
	}
	
	system("pause");
	
}


int main() 
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for (laco=1;laco=1;) //implementando laco para que menu do programa volte a ficar ativo apos as funcoes
	{
		system("cls"); //limpando a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); //final do menu
		printf("Digite a sua opção: "); //escolha da opcao do usuario
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system("cls"); //limpando a tela
	
		switch(opcao) //verificacao da escolha do usuario e chamada de funcoes
		{
			case 1:
			registrar(); //chamando a funcao registrar
			break;
			
			case 2:
			consultar(); //chamando a funcao consultar
			break;
			
			case 3:
			deletar(); //chamando a funcao deletar
			break;
			
			default: 
			printf("Essa opção não está disponível!\n\n"); //informando o usuario em caso de escolha nao disponivel
			system("pause"); //inserindo pausa no sistema ate usuario pressionar alguma tecla
			break;
		}
	}
	
}

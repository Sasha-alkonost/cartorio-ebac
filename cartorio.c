#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //acabei por não usar mas deixari incluido por via de duvidas
#include <string.h> // biblioteca que cuida das strings


int registro()//função de registro de usuarios
{
	//inicio de criação de variaveis/strings
	char arquivo[40];
	char cpf[40];	
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis
	
	
	printf("digite o cpf a ser registrado:    ");//coletando info
	scanf("%s", cpf);//%s se refere a strings
	
	strcpy(arquivo,cpf); //responsavel por copiar valor da string
	
	FILE *file; //cria arquivo no banco de dados
	file = fopen(arquivo,"w"); //tambem cria o arquivo e "w" significa write
	fprintf(file, cpf);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("digite o nome a ser cadastrado:   ");
	scanf("%s",nome);
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:   ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:    ");
	scanf("%s",cargo);

	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system ("pause");//fim da função

}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	//pegando informação sobre o perfil de usuario
	printf("digite o cpf a ser consultado:  ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	
	printf("este usuario nao localizado.\n");
	//perfil de usuario nao existe mais ou não encontrado	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n essas são as informações do usuario");
		printf("%s", conteudo);
		printf("\n\n");
		//perfil de usuario encontrado e mostrado ao usuario
	}
	
	system ("pause");
	//fim da função de cosulta
}

int deletar()
{
	//pegando informação de qual usuario deve ser deletado
	char cpf[40];
	
	printf("digite o CPF a ser deletado:  ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	//nao tem um usuario ou ja foi deletado
	{
		printf("o usuario não existe :/ \n");
		system("pause");
	}
	
	while(file != cpf);
	//tem o usuario no banco de dados e sera eliminado >:3
	{	
		remove(cpf);
		printf("o usuario foi deletado :D yay \n");
		system("pause");
	}
	//fim do deletar
	
}


int main()
{
	int opcao=0;//definindo veriaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); 
			
		setlocale(LC_ALL, "Portuguese");//definindo linguaguem
	
		printf("### registro de usuario da EBAC ###\n\n");//menu inicio
		printf("escolha a opção desejada do menu:\n\n");
		printf("\t1 -registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\t4 - sair do sistema\n\n");
		printf("Opção");//menu fim

		
			scanf("%d", &opcao);//armazenando escolha do usuario
	
		system("cls");
		
		switch(opcao)
		{
			case 1:	
			registro();//chamada de função registrar
			break;	
			
			case 2:
			consultar();//chamada de função consultar
			break;
			
			case 3:
			deletar();//chamda de função de deletar
			break;
			
			case 4:
			printf("Obrigada por usar o sistema :)");
			return 0;
			break;
			
			default:
			printf("essa opção não esta disponivel\n");
			system("pause");
			break;
			
		}
		
   }
	
}

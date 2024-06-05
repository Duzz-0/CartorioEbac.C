#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //bibiloteca de alocações de texto por região
#include <string.h> //biblioteca das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	    //Começo da criação das variáveis/strings
	    
        char arquivo[40];
		char cpf[40];
        char nome[40];
        char sobrenome[40];
        char cargo[40];
        
        //Fim da criação das variáveis/strings
        
        printf("Insira o CPF a ser cadastrado: "); //Coleta de informação do usuário
        scanf("%s", cpf); //o %s se refere a string
        
        strcpy (arquivo, cpf); //Responsavel pela copia dos valores da string
        
        FILE * file; //Criação de arquivo
        file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
        fprintf (file, cpf); //Salvo o valor da variavel
        fclose (file); //Fecha o arquivo
        
        file = fopen(arquivo, "a");
        fprintf (file, ",");
        fclose (file);
        
        printf("Insira o nome a ser cadastrado: ");
        scanf("%s",nome);
        
        file = fopen(arquivo, "a");
        fprintf (file,nome);
        fclose (file);
        
        file = fopen (arquivo, "a");
        fprintf (file, ",");
        fclose (file);
        
        printf("Insira o sobronome a ser cadastrado: ");
        scanf("%s",sobrenome);
        
        file = fopen(arquivo, "a");
        fprintf (file,sobrenome);
        fclose (file);
        
        file = fopen(arquivo, "a");
        fprintf (file, ",");
        fclose (file);
        
        printf("Digite o Cargo a ser cadastrado: ");
        scanf("%s", cargo);
        
        file = fopen(arquivo, "a");
        fprintf (file,cargo);
        fclose (file);
}

int consulta() //Responsavel pela consulta dos dados do usuário
{
	   //Começo das variáveis/string
	    
	   char cpf[40];
	   char conteudo[200];
	   
	   //Fim das variáveis/string
	   
	   printf ("Digite o CPF a ser cadastrado");
	   scanf("%s", cpf );
	   
	   FILE * file;
	   file = fopen (cpf, "r");
	   
	   if (file == NULL)
       {
	    printf ("Arquivo não foi localizado!.\n");
       }
    
       while(fgets(conteudo, 200, file) != NULL)
       {
        printf ("\nSuas informações de usuário: ");
        printf ("%s", conteudo);
        printf ("\n\n");
	   }
        system ("pause");
}

int deletar() //Responsavel por deletar os dados do usuário
{
	    char cpf[40];
	    
	    printf("Digite o CPF a ser deletado: ");
	    scanf("%s", cpf);
	    
	    remove(cpf);
	    
	    FILE * file;
	    file = fopen(cpf, "r");
	    
	    if(file == NULL)
	    {
	    	printf("Usuário não encontrado no sistema!. \n");
	    	system("pause");
		}
		
		fclose(file);
}


int main() //Responsavel pela execução do programa
{
	int opcao=0; //Definindo varíaveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da Ebac ###\n\n");	//Começo do menu
	    printf("Escolha a opção desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); 
	    printf("\t4 - Sair do sistema\n");
	    printf("\nOpção: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenamento
	
	    system("cls"); //Responsavel para limpar a tela
	    
	    switch(opcao) //Inicio da selção do menu
	    {
	    	case 1:
	    	registro(); //Chamada da função de registro
	    	break;
	    	
	    	case 2:
	        consulta(); //Chamada da função de consulta 
	    	break;
	    	
	    	case 3:
	        deletar(); //Chamada da função deletar
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
	    	return 0;
	    	break;
	    	
	    	default:
	    	printf("Essa opção não está disponivel!\n");
	    	system ("pause");
	    	break;	
		}	
    	} //Fim da seleção
    }
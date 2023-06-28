#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

typedef struct horario HORARIO;

struct horario
{
	int hora;
	int minuto;
};

typedef struct contato CONTATO;

struct contato
{
	char nome[20];
	char sobrenome[20];
	char fone[15];
	char placa[8];
	char marca[20];
	char modelo[20];
	
	HORARIO tempo;
	
};

float caixa;

float fixo, variavel;

void msgApresentacao();

void msgValor();

void msgCaixa();

void msgInicial();

void msgInclusao();

void msgSaida();

void msgListar();

void msgPagamento();

void msgAtencao();

void msgEdicao();

void msgAlterarValor();

void inserirDado(); 

void listar();

void buscarNome();

void excluir();

void editar();

void valorEstacionamento();

void pagamento(int horai, int minutoi, int horaf, int minutof);

void validacao();

void exclusaoTotal();

float totalCaixa(int horai, int minutoi, int horaf, int minutof); 

int menu();


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int inic;
	
	msgApresentacao();
	
	printf("Digite 1 para iniciar o programa ou qualquer outra tecla para sair.\n");
	
	scanf("%d", &inic);

	if(inic == 1)
	{
		menu();
	}
	else
	{
		msgSaida();
		getch();
	}

return 0;
}

void msgApresentacao()
{
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("BEM-VINDO, PROJETO DESENVOLVIDO NA DISCIPLINA INTRODUÇÃO A PROGRAMAÇÃO.\n");
	printf("O PROJETO E UMA CRUD QUE CONSISTE EM UM SISTEMA PARA CONTROLE DE CLIENTES DE UM ESTACIONAMENTO.\n");
	printf("NESSE APLICATIVO VOCÊ PODE INCLUIR UM CLIENTE, LISTAR TODOS OS CLIENTES, FILTRAR POR NOME OU \nPLACA DO VEÍCULO, EXCLUIR TODO O REGISTRO E VER O TOTAL A SER PAGO POR CADA CLIENTE. \n");
	printf("NESSE PROGRAMA O VALOR DO ESTACIONAMENTO É DADO POR UM VALOR FIXO + UM VALOR QUE VARIA DE ACORDO \nCOM A QUANTIDADE DE HORAS EM QUE O CLIENTE PERMANECEU NO ESTACIONAMENTO.\n");
	printf("\n\n");
	printf("EM CASO DE PRIMEIRO ACESSO IR DIRETAMENTE PARA A OPCAO 7 DO MENU PARA DEFINIR OS VALORES DO ESTACIONAMENTO\n");
	printf("--------------------------------------------------------------------------\n\n");
}

void msgCaixa()
{
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("            VALOR TOTAL EM CAIXA R$ = %.2f\n", caixa);
	
	printf("--------------------------------------------------------------------------\n\n");
	
	getch();
}

void msgValor()
{
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("      INSERCAO DOS VALORES DO ESTACIONAMENTO\n");
	
	printf("--------------------------------------------------------------------------\n\n");
}

void msgInicial()
{

	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("      MENU DE OPÇÕES // SISTEMA PARA CLIENTES DE ESTACIONAMENTO\n");
	
	printf("--------------------------------------------------------------------------\n\n");
	
}

void msgInclusao()
{
	
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("                        INCLUSÃO DE CLIENTES\n");
	
	printf("--------------------------------------------------------------------------\n\n");
	
}

void msgSaida()
{
	
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("                OBRIGADO POR UTILIZAR NOSSO SERVIÇO\n");
	
	printf("--------------------------------------------------------------------------\n\n");
	
}

void msgListar()
{
	
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("                LISTA DE CLIENTES ATIVOS\n");
	
	printf("--------------------------------------------------------------------------\n\n");
	
}

void msgAtencao()
{
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("   ATENÇÃO! VOCE ESTÁ PRESTES A EXCLUIR TODOS OS REGISTROS DO ARQUIVO!\n");
	
	printf("--------------------------------------------------------------------------\n\n");
}

void msgPagamento()
{
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("                       TELA DE PAGAMENTO\n");
	
	printf("--------------------------------------------------------------------------\n\n");
}



void msgEdicao()
{
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("                    TELA DE EDIÇÃO DE REGISTRO\n");
	
	printf("--------------------------------------------------------------------------\n\n");
}

void msgAlterarValor()
{
	system("cls");
	
	printf("--------------------------------------------------------------------------\n");
	
	printf("                    ALTERAR VALOR DO ESTACIONAMENTO\n");
	printf("                        F[x, y, z] = x + y*z\n");
	printf("            x = Valor fixo\n");
	printf("            y = Valor variavel\n");
	printf("            z = Tempo total de uso do estabelecimento (calculado automaticamente)\n");
	printf("--------------------------------------------------------------------------\n\n");
	
}

int menu()
{
	int menu;
	
	do
	{
		msgInicial();
		
		printf("\n1. Adicionar cliente.\n");
		printf("\n2. Editar cliente.\n");
		printf("\n3. Buscar cliente pelo nome ou placa.\n");
		printf("\n4. Listar todos os clientes.\n");
		printf("\n5. Pagamentos.\n");
		printf("\n6. Reiniciar arquivo.\n");
		printf("\n7. Definir valores para o estacionamento.\n");
		printf("\n8. Mostrar na tela o valor total em caixa.\n");
		printf("\n0. Sair.\n\n");
		
		printf("Escolha uma das opções: \n\n");
		scanf("%d", &menu);
	
		
		switch(menu)
		{
			case 1:
				//inserir
				inserirDado();
				
				break;
				
			case 2:
				//editar
				editar();
				
				break;
				
			case 3:
				//buscar pela placa ou nome
				buscarNome();
				
				break;
				
			case 4:
				//listagem
				listar();
				
				break;
				
			case 5:
				//remover
				excluir();
				
				break;
				
			case 6:
				
				exclusaoTotal();
				
				break;
				
			case 7:
				
				valorEstacionamento();
				
				break;
				
			case 8:
				
				msgCaixa();
				
				break;
				
			case 0:
				
				msgSaida();
				
				return 0;
				
				break;
				
			default:
				
				printf("\nSelecione uma opção válida: \n");
				
				break;
		}
		
	}while (menu != 0);
}

int validacao(const char* testePlaca)
{
	FILE* arqv;
	
	CONTATO ctt;
	
	arqv = fopen("clientes.txt", "rb");
	
	if(arqv == NULL)
	{
		printf("Problemas com abertura do arquivo!\n");
		return 0;
	}
	else
	{
		while(fread(&ctt, sizeof(CONTATO), 1, arqv) == 1)
		{
			if(strcmp(testePlaca, ctt.placa) == 0)
			{
				fclose(arqv);
				return 1;
			}
		}
	}

	fclose(arqv);
	
	return 0;
	
}


void inserirDado()
{
	FILE* arqv;
		
	CONTATO ctt;
	
	arqv = fopen("clientes.txt", "ab");
	
	int op;
	
	if (arqv == NULL)
	{
		printf("Problemas com abertura do arquivo!\n");
	}
	else
	{
		do
		{
			msgInclusao();
			
			fflush(stdin);
			printf("NOME: \n");
			gets(ctt.nome);
			
			fflush(stdin);
			printf("SOBRENOME: \n");
			gets(ctt.sobrenome);
			
			fflush(stdin);
			printf("TELEFONE PARA CONTATO: \n");
			gets(ctt.fone);
			
			int teste;
			
			do
			{
				fflush(stdin);
				printf("PLACA DO VEÍCULO: \n");
				gets(ctt.placa);
				
				teste = validacao(ctt.placa);
				
				if(teste)
				{
					printf("Placa já inserida no sistema! Digite novamente:\n");
				}
				
			}
			while(teste);
			
			fflush(stdin);
			printf("MARCA DO VEÍCULO: \n");
			gets(ctt.marca);
			
			fflush(stdin);
			printf("MODELO DO VEÍCULO: \n");
			gets(ctt.modelo);
			
			fflush(stdin);
			printf("HORÁRIO DE ENTRADA: (24H)\n");
			printf("HORA:\n");
			scanf("%d", &ctt.tempo.hora);
			printf("MINUTOS:\n");
			scanf("%d", &ctt.tempo.minuto);
			
			fwrite(&ctt, sizeof(CONTATO), 1, arqv);
			
			printf("Deseja adicionar outro cliente? (1- Sim / 0- Não)\n\n");
			
			scanf("%d", &op);
			
			
		}while(op == 1);
		
		
		fclose(arqv);
	}
}


void listar()
{
	FILE* arqv;
	
	CONTATO ctt;
	
	arqv = fopen("clientes.txt", "rb");
	
	msgListar();
	
	
	if (arqv == NULL)
	{
		printf("Problemas com abertura do arquivo!\n");
	}
	else
	{
		while(fread(&ctt, sizeof(CONTATO), 1, arqv) == 1)
		{			
			
			printf("NOME: %s\n", ctt.nome);
			printf("SOBRENOME: %s\n", ctt.sobrenome);
			printf("FONE: %s\n", ctt.fone);
			printf("PLACA: %s\n", ctt.placa);
			printf("MARCA: %s\n", ctt.marca);
			printf("MODELO: %s\n", ctt.modelo);
			printf("HORÁRIO DE ENTRADA: %d:%d\n", ctt.tempo.hora, ctt.tempo.minuto);
			
			printf("---------------------------------------------------------------------\n\n");
		}
	}
	
	fclose(arqv);
	
	getch();
}

void buscarNome()
{
    FILE* arqv;
    CONTATO ctt;
    char nome[20];
    int encontrado = 0;

    arqv = fopen("clientes.txt", "rb");

	msgListar();
	
    if (arqv == NULL)
    {
        printf("Problemas com a abertura do arquivo!\n");
    }
    else
    {
        fflush(stdin);
        printf("\nPesquise pelo nome ou placa: \n\n");
        fgets(nome, 20, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        while(fread(&ctt, sizeof(CONTATO), 1, arqv) == 1)
        {
            if(strcmp(nome, ctt.nome) == 0 || strcmp(nome, ctt.placa) == 0)
            {
                printf("NOME: %s\n", ctt.nome);
                printf("SOBRENOME: %s\n", ctt.sobrenome);
                printf("FONE: %s\n", ctt.fone);
                printf("PLACA: %s\n", ctt.placa);
                printf("MARCA: %s\n", ctt.marca);
                printf("MODELO: %s\n", ctt.modelo);
                printf("HORÁRIO DE ENTRADA: %d:%d\n", ctt.tempo.hora, ctt.tempo.minuto);

                printf("---------------------------------------------------------------------\n\n");

                encontrado = 1; 
            }
        }

        if (!encontrado)
        {
            printf("\nCliente não encontrado.\n");
        }
    }

    fclose(arqv);
    getch();
}

void valorEstacionamento()
{
		
		msgValor();
		
		int op;
		
		printf("O valor do estacionamento e calculado a partir da funcao f[x,y,z] = x + y*z, onde \nx = valor fixo, \ny = valor de acrescimo que e multiplicado pelo tempo de horas utilizadas,\nz = tempo total de uso do estacionamento (em horas (calculado automaticamente)).\n\n");
		printf("\n\n");
		printf("Pressione qualquer tecla para prosseguir");
		getch();

		
		do
		{
			msgAlterarValor();
			
			printf("Escolha o valor que deseja alterar. \n");
			printf("1. Alterar o valor fixo.\n");
			printf("2. Alterar o valor variavel. \n");
			printf("0. Sair\n\n");
			
			printf("Escolha uma opcao:\n");
			
			scanf("%d", &op);
			
			switch(op)
			{
				case 1:
					printf("Digite o valor fixo: \n");
					scanf("%f", &fixo);
					break;
				case 2:
					printf("Digite o valor variavel: \n");
					scanf("%f", &variavel);
					break;
				default:
					printf("Opcao invalida.\n\n");
					break;
			}
			
		}while(op != 0);
		
}

void pagamento(int horai, int minutoi, int horaf, int minutof) {
    
	CONTATO ctt;
    int tempoTotal, difhoras, totFinal, totInicial;
    float total;
    
    totInicial = ((horai*60) + minutoi);
	totFinal = ((horaf*60) + minutof);
	
	difhoras = totFinal - totInicial;
    
    if (difhoras < 0)
    {
    	difhoras = (1440 - totInicial) + totFinal;
	}

	tempoTotal = difhoras/60;

    total = fixo + (variavel*tempoTotal);

    printf("\nTotal a pagar R$ = %.2f\n", total);
    
}

float totalCaixa(int horai, int minutoi, int horaf, int minutof) 
{
    
	CONTATO ctt;
    int tempoTotal, difhoras, totFinal, totInicial;
    float total;
    
    totInicial = ((horai*60) + minutoi);
	totFinal = ((horaf*60) + minutof);
	
	difhoras = totFinal - totInicial;
    
    if (difhoras < 0)
    {
    	difhoras = (1440 - totInicial) + totFinal;
	}

	tempoTotal = difhoras/60;

    total = fixo + (variavel*tempoTotal);
	
}

void excluir() {
    FILE* arqvorigem;
    FILE* arqvtemp;

    CONTATO ctt;
	
	int encontrado = 0;
    char placa[8];
    int hf, mf, pgt;

    arqvorigem = fopen("clientes.txt", "rb");

    arqvtemp = fopen("clientestemp.txt", "ab");
    
    msgPagamento();

    if ((arqvorigem == NULL) || (arqvtemp == NULL)) 
	{
        printf("\nProblemas com a abertura do arquivo.\n");
    } else 
	{
		
        fflush(stdin);
        printf("Digite a placa do veículo: \n");
        fgets(placa, sizeof(placa), stdin);
        placa[strcspn(placa, "\n")] = '\0';
        

        while (fread(&ctt, sizeof(CONTATO), 1, arqvorigem)) 
		{
            if (strcmp(placa, ctt.placa) == 0) 
			{
                printf("NOME: %s\n", ctt.nome);
                printf("SOBRENOME: %s\n", ctt.sobrenome);
                printf("FONE: %s\n", ctt.fone);
                printf("PLACA: %s\n", ctt.placa);
                printf("MARCA: %s\n", ctt.marca);
                printf("MODELO: %s\n", ctt.modelo);
                printf("HORÁRIO DE ENTRADA: %d:%d\n", ctt.tempo.hora, ctt.tempo.minuto);
                printf("\n");
                printf("DIGITE O HORÁRIO DE SAÍDA: (24H)\n");
				printf("HORA\n");
                scanf("%d", &hf);
                printf("MINUTO\n");
                scanf("%d", &mf);

                pagamento(ctt.tempo.hora, ctt.tempo.minuto, hf, mf);
				printf("\n");
                printf("O valor foi pago? (1- Sim / 0- Não)\n");
                scanf("%d", &pgt);
                
                encontrado = 1;

                if (pgt == 1) 
				{
					caixa += totalCaixa(ctt.tempo.hora, ctt.tempo.minuto, hf, mf);
					printf("\nPagamento efetuado com sucesso!\n");
                    
                } 
				else 
				{
					printf("Pagamento não efetuado.\n");
                    fwrite(&ctt, sizeof(CONTATO), 1, arqvtemp);
                }
            } 
			else 
			{	
				fwrite(&ctt, sizeof(CONTATO), 1, arqvtemp);
            }
        }
        
        if(!encontrado)
        {
        	printf("Cliente não encontrado.\n");
		}
    
    }

    fclose(arqvorigem);
    fclose(arqvtemp);

    remove("clientes.txt");
    rename("clientestemp.txt", "clientes.txt");

    getch();
}

void editar()
{
	FILE* arqv;
	
	CONTATO ctt;
	
	arqv = fopen("clientes.txt", "rb+");
	
	int i = 1;
	int indice;
	
	msgEdicao();
	
	if (arqv == NULL)
    {
        printf("Problemas com a abertura do arquivo!\n");
    }
    else
    {
    	while(fread(&ctt, sizeof(CONTATO), 1, arqv) == 1)
    	{
    		printf("\n----------- %d -----------\n", i);
			printf("NOME: %s\n", ctt.nome);
    		printf("SOBRENOME: %s\n", ctt.sobrenome);
    		printf("TELEFONE: %s\n", ctt.fone);
    		printf("--------------------------\n\n");
    		i++;	
		}
		if(i>1)
		{
    		do{
				printf("Que contato deseja alterar? (Digite o índice)\n");
	    		
	    		scanf("%d", &indice);
	    		fflush(stdin);
	    		
	    		
	    		printf("\n");
	    		
	    		if(indice<0 || indice>i)
	    		{
	    			printf("Opcao invalida. Tente novamente.\n");
				}
				
				
	    		
			}while(indice<0 || indice>i);
    		
    		indice--;
    		
    		if((indice >= 0) && (indice < i-1))
    		{
    			int op;
    			do
				{
					printf("1. Editar nome\n");
					printf("2. Editar sobrenome\n");
					printf("3. Editar telefone\n");
					printf("0. Sair.\n\n");
					
					printf("Escolha uma opção:\n");
					scanf("%d", &op);
					
					if(op == 1)
					{
						printf("Digite o novo nome:\n");
						fflush(stdin);
						scanf("%s", ctt.nome);
						printf("\n");
						
						fseek(arqv, indice * sizeof(CONTATO), SEEK_SET);
						fwrite(&ctt, sizeof(CONTATO), 1, arqv);
					}
					else if(op == 2)
					{
						printf("Digite o novo sobrenome:\n");
						fflush(stdin);
						scanf("%s", ctt.sobrenome);
						printf("\n");
						
						fseek(arqv, indice * sizeof(CONTATO), SEEK_SET);
						fwrite(&ctt, sizeof(CONTATO), 1, arqv);
					}
					else if(op == 3)
					{
						printf("Digite o novo telefone:\n");
						fflush(stdin);
						scanf("%s", ctt.fone);
						printf("\n");
						
						fseek(arqv, indice * sizeof(CONTATO), SEEK_SET);
						fwrite(&ctt, sizeof(CONTATO), 1, arqv);
					}
					else if(op == 0)
					{
						break;
					}
					else
					{
						printf("Digite uma opção válida.\n");
					}
					
				}
				while(op != 0);
			}
		}
		else
		{
			printf("Sem clientes para editar.\n");
			getch();	
		}
    		fclose(arqv);
		
    }
    
    fclose(arqv);
	
}

void exclusaoTotal() {
    FILE* arqv;
    FILE* arqvtemp;
    CONTATO ctt;

    arqv = fopen("clientes.txt", "rb");
    arqvtemp = fopen("clientestemp.txt", "ab");
	
    int op;
	
	msgAtencao();
	
    if ((arqv == NULL) || (arqvtemp == NULL)) 
	{
        printf("\nProblemas com a abertura do arquivo.\n");
    } 
	else 
	{
        printf("Tem certeza que deseja excluir todos os clientes inseridos? (1- Sim / 0- Não) \n");
        scanf("%d", &op);

        if (op == 1) 
		{
            while (fread(&ctt, sizeof(CONTATO), 1, arqv) == 1) 
			{
            }
        } 
		else 
		{
            fclose(arqv);
            fclose(arqvtemp);
            return;
        }
    }

    fclose(arqv);
    fclose(arqvtemp);

    remove("clientes.txt");
    rename("clientestemp.txt", "clientes.txt");

    printf("----------------------------------------------------\n");
    printf("         Clientes excluídos com sucesso!\n");
    printf("----------------------------------------------------\n");
    getch();
}




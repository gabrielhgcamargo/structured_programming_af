/*
GRUPO 1:
Enrico Pezato Acquaviva Carrano 150993
Gabriel Henrique Garcia Camargo - 190375
Marcelo Zaguette Junior - 180998
Suele Cristine Treska - 163130
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct endereco { 
 char logradouro[80]; 
 char bairro[15]; 
 char CEP[10]; 
 char cidade[15]; 
 char estado[3]; 
 char fone[12]; 
 char email[40]; 
}endereco;
 
typedef struct infocarro { 
 char sigla; 
 int regcarro; 
}infocarro; 

typedef union dadoscarro { 
 char sigla; 
 infocarro reservado; 
}dadoscarro; 

typedef struct loja { 
 int regloja; //gerar autom�tico 
 char nome[30]; 
 char CNPJ[19]; 
 endereco end; 
 int sold; 
 int reserved; 
 dadoscarro  tabela[3]; 
}loja; 

typedef struct infoloja { 
 char sigla; 
 char CNPJ[19]; 
}infoloja; 

typedef union dadosloja { 
 char sigla; 
 infoloja reserva; 
}dadosloja; 

typedef struct montadora { 
 int regcarro; //gerar autom�tico 
 char modelo[20]; 
 char cor[10]; 
 float  valor; 
 dadosloja status; 
}montadora;

//Menu
int printMenu(int *ptrTamLoja);
//Alocacao Dinamica
void alocaInt(int **p, int tam);
void alocaEndereco(endereco **p, int tam);
void alocaInfoCarro(infocarro **p, int tam);
void alocaDadosCarro(dadoscarro **p, int tam);
void alocaLoja(loja **p, int tam);
void alocaInfoLoja(infoloja **p, int tam);
void alocaDadosLoja(dadosloja **p, int tam);
void alocaMontadora(montadora **p, int tam);
//Cadastros
void cadastrarLoja(loja *ptrLoja);

int main(){
	
	endereco *ptrEndereco=NULL;
	int *ptrTamEndereco = NULL;
	alocaInt(&ptrTamEndereco,1);
	*ptrTamEndereco = 0;

	infocarro *ptrInfoCarro=NULL;
	int *ptrTamInfoCarro = NULL;
	alocaInt(&ptrTamInfoCarro,1);
	*ptrTamInfoCarro = 0;
	
	dadoscarro *ptrDadosCarro=NULL;
	int *ptrTamDadosCarro = NULL;
	alocaInt(&ptrTamDadosCarro,1);
	*ptrTamDadosCarro = 0;

	loja *ptrLoja=NULL;
	int *ptrTamLoja=NULL;
	alocaInt(&ptrTamLoja,1);
	*ptrTamLoja= 0;
	
	infoloja *ptrInfoLoja=NULL;
	int *ptrTamInfoLoja = NULL;
	alocaInt(&ptrTamInfoLoja,1);
	*ptrTamInfoLoja = 0;

	dadosloja *ptrDadosLoja=NULL;
	int *ptrTamDadosLoja = NULL;
	alocaInt(&ptrTamDadosLoja,1);
	*ptrTamDadosLoja = 0;

	montadora *ptrMontadora=NULL;
	int *ptrTamMontadora = NULL;
	alocaInt(&ptrTamMontadora,1);
	*ptrTamMontadora = 0;
	
	char menuStop = 's';
	int menuAux = 0;
	
	do{
		menuAux = printMenu(ptrTamLoja);
		printf("\nValor menuAux = %i\n",menuAux);
		switch(menuAux)
		{
		case 1:
			*(ptrTamLoja) = *(ptrTamLoja) + 1;
			alocaLoja(&ptrLoja, *ptrTamLoja);
			printf("case 1 - cadastro de concessionaria\n");
			break;
		case 2:
			printf("\nEntrou no case 2\n");
			printf("\ncase 2\n");
			break;
		}
		printf("\nDeseja parar? <s/n>\n");
		scanf("%c",&menuStop);
		fflush(stdin);
	}while(menuStop!='s' && menuStop !='S');
//	int tam = 1;
//	alocaEndereco(&ptrEndereco, *ptrTamEndereco);
//	alocaInfoCarro(&ptrInfoCarro, *ptrTamInfoCarro);
//	alocaDadosCarro(&ptrDadosCarro, *ptrTamDadosCarro);
//	alocaLoja(&ptrLoja, *ptrTamLoja);
//	alocaInfoLoja(&ptrInfoLoja, *ptrTamInfoLoja);
//	alocaDadosLoja(&ptrDadosLoja, *ptrTamDadosLoja);
//	alocaMontadora(&ptrMontadora, *ptrTamMontadora);
	return 0;
}

int printMenu(int *ptrTamLoja){
	int aux=0;
	do{
		printf("\tMenu:\n");
		printf("\t1- Cadastro de Concessionaria (atual = %d | max = 5)",*ptrTamLoja);
		printf("\n");
		printf("\t2- Consulta de Concessionaria");
		printf("\n");
		scanf("\t%i",&aux);
		fflush(stdin);
		printf("\n");
		printf("Valor auxiliar: %i",aux);
		printf("\n");
	}while(aux != 1 && aux != 2);
	return aux;
}

void alocaInt(int **p, int tam){
	if((*p = (int*)realloc(*p,tam*sizeof(int)))==NULL){
		exit(1);
	}
	printf("\nAlocacao feita\n");
}

void alocaEndereco(endereco **p, int tam){
	if((*p = (endereco*)realloc(*p,tam*sizeof(endereco))) == NULL){
		exit(1);
	}
}

void alocaInfoCarro(infocarro **p, int tam){
	if((*p = (infocarro*)realloc(*p,tam*sizeof(infocarro)))==NULL){
		exit(1);
	}
}

void alocaDadosCarro(dadoscarro **p, int tam){
	if((*p = (dadoscarro*)realloc(*p,tam*sizeof(dadoscarro)))==NULL){
		exit(1);
	}
}

void alocaLoja(loja **p, int tam){
	if((*p = (loja*)realloc(*p,tam*sizeof(loja)))==NULL){
		exit(1);
	}
}

void alocaInfoLoja(infoloja **p, int tam){
	if((*p = (infoloja*)realloc(*p,tam*sizeof(infoloja)))==NULL){
		exit(1);
	}
}
void alocaDadosLoja(dadosloja **p, int tam){
	if((*p = (dadosloja*)realloc(*p,tam*sizeof(dadosloja)))==NULL){
		exit(1);
	}
}
void alocaMontadora(montadora **p, int tam){
	if((*p = (montadora*)realloc(*p,tam*sizeof(montadora)))==NULL){
		exit(1);
	}
}

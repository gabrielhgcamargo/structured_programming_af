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
	*ptrTamEndereco = 0;

	infocarro *ptrInfoCarro=NULL;
	int *ptrTamInfoCarro = NULL;
	*ptrTamInfoCarro = 0;
	
	dadoscarro *ptrDadosCarro=NULL;
	int *ptrTamDadosCarro = NULL;
	*ptrTamDadosCarro = 0;

	loja *ptrLoja=NULL;
	int *ptrTamLoja = NULL;
	*ptrTamLoja = 0;

	infoloja *ptrInfoLoja=NULL;
	int *ptrTamInfoLoja = NULL;
	*ptrTamInfoLoja = 0;

	dadosloja *ptrDadosLoja=NULL;
	int *ptrTamDadosLoja = NULL;
	*ptrTamDadosLoja = 0;

	montadora *ptrMontadora=NULL;
	int *ptrTamMontadora = NULL;
	*ptrTamMontadora = 0;

	char menuStop = 's';
	int menuAux = 0;
	
	do{
		menuAux = printMenu(ptrTamLoja);
		switch (menuAux)
		{
		case 1:
			*ptrTamLoja++;
			alocaLoja(&ptrLoja, *ptrTamLoja);
			printf("case 1 - cadastro de concessionaria");
		case 2:
			printf("case 2");
		}
	}while(menuStop!='s' || menuStop != 'S');
	int tam = 1;
	alocaEndereco(&ptrEndereco, *ptrTamEndereco);
	alocaInfoCarro(&ptrInfoCarro, *ptrTamInfoCarro);
	alocaDadosCarro(&ptrDadosCarro, *ptrTamDadosCarro);
	alocaLoja(&ptrLoja, *ptrTamLoja);
	alocaInfoLoja(&ptrInfoLoja, *ptrTamInfoLoja);
	alocaDadosLoja(&ptrDadosLoja, *ptrTamDadosLoja);
	alocaMontadora(&ptrMontadora, *ptrTamMontadora);
	printf("Hello World\n");
	system("pause");
	return 0;
}

int printMenu(int *ptrTamLoja){
	int aux=0;
	do{
		printf("\tMenu:\n");
		printf("\t1- Cadastro de Concessionaria (atual = %d | max = 5)",*ptrTamLoja);
		printf("\t2- Consulta de Concessionaria");
		scanf("%i",&aux);
	}while(aux != 1 || aux!= 2);
	return aux;
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

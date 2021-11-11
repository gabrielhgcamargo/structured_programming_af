/*
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
 struct infocarro reservado; 
}dadoscarro; 

typedef struct loja { 
 int regloja; //gerar autom�tico 
 char nome[30]; 
 char CNPJ[19]; 
 struct endereco end; 
 int sold; 
 int reserved; 
 union  dadoscarro  tabela[3]; 
}loja; 

typedef struct infoloja { 
 char sigla; 
 char CNPJ[19]; 
}infoloja; 

typedef union dadosloja { 
 char sigla; 
 struct infoloja reserva; 
}dadosloja; 

typedef struct montadora { 
 int regcarro; //gerar autom�tico 
 char modelo[20]; 
 char cor[10]; 
 float  valor; 
 union dadosloja status; 
}montadora;

void alocaEndereco(endereco **p, int tam);
void alocaInfoCarro(infocarro **p, int tam);
void alocaDadosCarro(dadoscarro **p, int tam);
void alocaLoja(loja **p, int tam);
void alocaInfoLoja(infoloja **p, int tam);
void alocaDadosLoja(dadosloja **p, int tam);
void alocaMontadora(montadora **p, int tam);

int main(){
	endereco *ptrEndereco=NULL;
	infocarro *ptrInfoCarro=NULL;
	dadoscarro *ptrDadosCarro=NULL;
	loja *ptrLoja=NULL;
	infoloja *ptrInfoLoja=NULL;
	dadosloja *ptrDadosLoja=NULL;
	montadora *ptrMontadora=NULL;
	
	int tam = 1;
	alocaEndereco(&ptrEndereco, tam);
	alocaInfoCarro(&ptrInfoCarro, tam);
	alocaDadosCarro(&ptrDadosCarro, tam);
	alocaLoja(&ptrLoja, tam);
	alocaInfoLoja(&ptrInfoLoja, tam);
	alocaDadosLoja(&ptrDadosLoja, tam);
	alocaMontadora(&ptrMontadora, tam);
	printf("Hello World\n");
	system("pause");
	return 0;
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

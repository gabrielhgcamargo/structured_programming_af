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
 //int sold;
 //int reserved;
 //dadoscarro  tabela[3];
}loja;

typedef struct infoloja {
 char sigla;
 char CNPJ[19];
}infoloja;

typedef union dadosloja {
 char sigla[5];
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
int printMenu(int qtde);
//Alocacao Dinamica
void alocaInt(int **p, int tam);
void alocaEndereco(endereco **p, int tam);
void alocaInfoCarro(infocarro **p, int tam);
void alocaDadosCarro(dadoscarro **p, int tam);
void alocaLoja(loja **p, int tam);
void alocaInfoLoja(infoloja **p, int tam);
void alocaDadosLoja(dadosloja **p, int tam);
void alocaMontadora(montadora **p, int tam);
//Cadastros loja
void cadastrarLoja(loja *p, int qtde);
void grava(loja *p);
//mostra cadastro loja
void mostra(loja *p, int qtde);
// verificar quantidade de elementos no arquivo concessionaria.bin
int verifica();
//--------------------------------
//--------------------------------
//Cadastros carro
void cadastrarCarro(montadora *p, int qtde);
void gravaCarro(montadora *p);
//mostra cadastro loja
void mostraCarro(montadora *p, int qtde);
// verificar quantidade de elementos no arquivo concessionaria.bin
int verificaCarro();

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

    //Novas variaveis para arquivo de concessionaria
    loja *pl = NULL;
    char op; // se deseja ou não continuar o cadastro.
    int qtde;
    alocaLoja(&pl,1);
    qtde = verifica();

    //----------------------------------------------------

    //Novas variaveis para arquivo de carros
    montadora *pm = NULL;
    char opcarro;
    int qtdecarro;
    alocaMontadora(&pm,1);
    qtdecarro = verificaCarro();



	do{
		menuAux = printMenu(qtde);
		switch(menuAux)
		{
		case 1:
		    printf("\n");
			if(qtde < 5){
                do{

                cadastrarLoja(pl,qtde+1);
                qtde++;
                printf("\nDeseja continuar ? <s/n>\n ");
                scanf("%c", &op);
                fflush(stdin);
			}while(op != 'n' && op != 'N');
			break;
        }
			else{
                    printf("Limite excedido de concessionarias");
			break;
			}
		case 2:
		    printf("\n");
			mostra(pl,qtde);
			break;
        case 3:
            printf("\n");
			printf("case 3 - cadastro de carro\n");
			do{
                cadastrarCarro(pm,qtdecarro+1);
                qtdecarro++;
                printf("\nDeseja continuar ? <s/n>\n ");
                scanf("%c",&opcarro);
                fflush(stdin);
			}while(opcarro != 'n' && opcarro != 'N');
			break;
        case 4:
            printf("\n");
			printf("case 4 - consulta de carro total\n");
			mostraCarro(pm,qtdecarro);
			break;
        case 5:
            printf("\n");
			printf("case 5 - consulta de carro parcial\n");
			break;
		}

		printf("\nDeseja parar? <s/n>\n");
		scanf("%c",&menuStop);
		fflush(stdin);
	}while(menuStop!='s' && menuStop !='S');
	return 0;
}

int printMenu(int qtde){
	int aux=0;
	do{
		printf("\tMenu:\n");
		printf("\t1- Cadastro de Concessionaria (atual = %i | max = 5)", qtde);
		printf("\n");
		printf("\t2- Consulta de Concessionaria");
		printf("\n");
		printf("\t3- Cadastro de Carro");
		printf("\n");
		printf("\t4- Consulta de Carro TOTAL");
		printf("\n");
		printf("\t5- Consulta de Carro PARCIAL");
		printf("\n");
		scanf("\t%i",&aux);
		fflush(stdin);
		printf("\n");
		if(aux == 1)
            printf("OPCAO 1 - CADASTRO CONCESSIONARIA");
        else if (aux == 2)
            printf("OPCAO 2 - CONSULTA CONCESSIONARIA");
		else if (aux == 3)
            printf("OPCAO 3 - CADASTRO CARRO");
        else if (aux == 4)
            printf("OPCAO 4 - CONSULTA CARRO TOTAL");
        else if (aux == 5)
            printf("OPCAO 5 - CONSULTA CARRO PARCIAL");

	}while(aux < 1 && aux > 5);
	return aux;
}

//FUNCOES PARA ARMAZENAMENTO E CONSULTA DE LOJA

int verifica()
{
    long int cont = 0; //contador
    FILE *fptr=NULL;   //PONTEIRO PARA FILE
    if((fptr = fopen("concessionaria.bin","rb"))==NULL)
        return cont; // cont é 0, então arquivo não existe
    else
    {
       fseek(fptr,0,2); //posiciona no fim
       cont = ftell(fptr)/sizeof(loja);//retorna a quantidade de elementos do tipo endereco armazenados no arquivo.
       fclose(fptr); // dentro do else pois foi aberto com rb
       return cont;
}

}

void cadastrarLoja(loja *p, int qtde)
{
    p->regloja = qtde;
    printf("\nRegisto %i", p->regloja);
    printf("\nNome da Loja = ");
    gets(p->nome);
    fflush(stdin);

    printf("\nCNPJ da Loja = ");
    gets(p->CNPJ);
    fflush(stdin);

   printf("\nLogradouro: ");
    gets(p->end.logradouro);
    fflush(stdin);

    printf("\nBairro: ");
    gets(p->end.bairro);
    fflush(stdin);

    printf("\nCEP: ");
    gets(p->end.CEP);
    fflush(stdin);

    printf("\nCidade: ");
    gets(p->end.cidade);
    fflush(stdin);

    printf("\nEstado: ");
    gets(p->end.estado);
    fflush(stdin);

    printf("\nTelefone: ");
    gets(p->end.fone);
    fflush(stdin);

    printf("\nEmail: ");
    gets(p->end.email);
    fflush(stdin);

    grava(p);
}

void grava(loja *p)
{
FILE *fptr = NULL;
if((fptr = fopen("concessionaria.bin","ab"))==NULL)
    printf("Erro ao abrir o arquivo!");
else
    fwrite(p,sizeof(loja),1,fptr);
fclose(fptr); // fora do else pq abriu com "ab"
}


void mostra(loja *p, int qtde)
{
    int i;
    FILE *fptr = NULL;
    system("cls"); // limpa tela
    if((fptr = fopen("concessionaria.bin","rb"))==NULL)
        printf("\nErro ao abrir o arquivo!");
    else{
        for(i = 0; i < qtde; i++ )
        {
            fseek(fptr,i*sizeof(loja),0); //0 =  início!!!
            fread(p,sizeof(loja),1,fptr);
            printf("\nREGISTRO: %i\n\nNOME: %s\n\nCNPJ: %s\nLogradouro: %s\nBairro: %s\nCEP: %s\nCidade: %s\nEstado: %s\nTelefone: %s\nEmail: %s\n\n", p->regloja, p->nome, p->CNPJ, p->end.logradouro, p->end.bairro, p->end.CEP, p->end.cidade, p->end.estado, p->end.fone, p->end.email);
        }//for
        fclose(fptr); // dentro do else , pois abriu com rb
        }
    printf("\n\n\n");
    system("pause");
}// mostra






//FUNÇÕES PARA ARMAZENAMENTO E CONSULTA DE CARROS(TOTAL E PARCIAL)


int verificaCarro()
{
    long int  cont = 0;
    FILE *fptr = NULL;
    if((fptr=fopen("carros.bin","rb"))== NULL)
        return cont;
    else
    {
        fseek(fptr,0,2); //posiciona no fim do arquivo
        cont = ftell(fptr)/sizeof(montadora);
        fclose(fptr);
        return cont;
    }
} // abre o arquivo e descobre quantos arquivos ja estão armazenados

void cadastrarCarro(montadora *p, int qtde)
{
    p->regcarro=qtde;
    printf("\nRegistro do carro : %i",p->regcarro);

    printf("\nModelo do carro: ");
    gets(p->modelo);
    fflush(stdin);

    printf("Cor do carro: ");
    gets(p->cor);
    fflush(stdin);

    printf("Valor: ");
    scanf("%f",&(p->valor));
    fflush(stdin);

    printf("Sigla: ");
    gets(p->status.sigla);
    fflush(stdin);

    printf("CNPJ :");
    gets(p->status.reserva.CNPJ);
    fflush(stdin);

    gravaCarro(p);
}


void gravaCarro(montadora *p)
{
    FILE *fptr=NULL;
    if((fptr=fopen("carros.bin","ab"))==NULL)
        printf("\nErro ao abrir o arquivo");
    else
        fwrite(p,sizeof(montadora),1,fptr);
    fclose(fptr);
}


void mostraCarro(montadora *p, int qtde)
{
    int i;
    FILE *fptr=NULL;
    system("cls");
    if((fptr=fopen("carros.bin","rb"))==NULL)
        printf("\nErro ao abrir o arquivo");
    else
    {
        for(i=0;i<qtde;i++)
        {
         fseek(fptr,i*sizeof(montadora),0);
         fread(p,sizeof(montadora),1,fptr);
         printf("\n\n\n");
         printf("\nRegistro Carro: %i\nModelo do carro: %s\nCor do carro: %s\nValor: %2.f\nCNPJ: %s",p->regcarro, p->modelo, p->cor, p->valor, p->status.reserva.CNPJ);
        }
        fclose(fptr);
    }
    printf("\n\n\n");
    system("pause");
}





void alocaInt(int **p, int tam){
	if((*p = (int*)realloc(*p,tam*sizeof(int)))==NULL){
		exit(1);
	}
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

void alocaMontadora(montadora **p, int tam)
{
    if((*p=(montadora*)realloc(*p,tam*sizeof(montadora)))== NULL)
        exit(1);

}//aloca montadora



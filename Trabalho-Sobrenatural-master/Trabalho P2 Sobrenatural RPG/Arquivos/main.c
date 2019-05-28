#include <stdio.h>
#include <stdlib.h>
#define TAM 50
typedef struct Cidades{
	char nome_city[TAM];
	int num_city, num_hab;
}Cidades;

typedef struct Demonios{
  char nome[TAM],cidade[TAM];
  float escuridao, visao;
  int numhab;
}Demonios;

typedef struct Anjos{
  char nome[TAM],cidade[TAM];
  float capfly, peso, altura;
  int numhab;
}Anjos;

typedef struct Humanos{
  char nome[TAM],cidade[TAM];
  float forca;
  int numhab;
}Humanos;

void leranjos (struct Anjos *Anjos){
	FILE* arq;
	arq = fopen("anjos.txt", "r");
	int i, j, k, num_cidades = 0;
	fscanf(arq, "%i", &num_cidades);
	fscanf(arq, "%s %i", Anjos[0].cidade, &Anjos[0].numhab);
	for(i=1; i<=Anjos[0].numhab; i++){
		fscanf(arq,"%s %f %f %f", Anjos[i].nome,
		                          &Anjos[i].capfly,
                                  &Anjos[i].peso,
		                          &Anjos[i].altura);
	}
	fscanf(arq, "%s %i", Anjos[i].cidade, &Anjos[i].numhab);
	j=i;
	i++;
	k=Anjos[j].numhab;
    for(k==Anjos[j].numhab; k<=Anjos[j].numhab; i++){
		fscanf(arq,"%s %f %f %f", Anjos[i].nome,
		                          &Anjos[i].capfly,
                                  &Anjos[i].peso,
		                          &Anjos[i].altura);
        k++;
	}
	fclose(arq);
  //tentar colocar matriz para fazer a leitura das cidades
}//Colocar aqui dentro para ler os arquivos

void lerdemonios (Demonios *Demonios){
	FILE* arq;
	arq = fopen("demonios.txt", "r");
	int i,j,k, num_cidades = 0;
	fscanf(arq, "%i", &num_cidades);
	fscanf(arq, "%s %i", Demonios[0].cidade, &Demonios[0].numhab);
	for(i=1; i<=Demonios[0].numhab; i++){
		fscanf(arq,"%s %f %f", Demonios[i].nome,
		                       &Demonios[i].escuridao,
                               &Demonios[i].visao);
	}
	fscanf(arq, "%s %i", Demonios[i].cidade, &Demonios[i].numhab);
	j=i;
	i++;
	k=Demonios[j].numhab;
    for(k==Demonios[j].numhab; k<=Demonios[j].numhab; i++){
		fscanf(arq,"%s %f %f", Demonios[i].nome,
		                       &Demonios[i].escuridao,
                               &Demonios[i].visao);
        k++;
	}
	fscanf(arq, "%s %i", Demonios[i].cidade, &Demonios[i].numhab);
	j=i;
	i++;
	k=Demonios[j].numhab;
    for(k==Demonios[j].numhab; k<=Demonios[j].numhab; i++){
		fscanf(arq,"%s %f %f", Demonios[i].nome,
		                       &Demonios[i].escuridao,
                               &Demonios[i].visao);
        k++;
	}
	fclose(arq);
}//Colocar aqui dentro para ler os arquivos

void lerhumanos (Humanos *Humanos){
	FILE* arq;
	arq = fopen("humanos.txt", "r");
	int i, num_cidades = 0;
	fscanf(arq, "%i", &num_cidades);
	fscanf(arq, "%s %i", Humanos[0].cidade, &Humanos[0].numhab);
	for(i=1; i<=3; i++){
		fscanf(arq,"%s %f", Humanos[i].nome,
		                    &Humanos[i].forca);
	}
	fclose(arq);
}//Colocar aqui dentro para ler os arquivos

void printaranjos (Anjos *anjos){
	int i, j, k;
    printf("\n%s %d\n", anjos[0].cidade,
                        anjos[0].numhab);
	for(i=1; i<=anjos[0].numhab;i++){
		printf("%s %f %f %f\n", anjos[i].nome,
                            anjos[i].capfly,
                            anjos[i].peso,
                            anjos[i].altura);
	}
	printf("\n%s %d\n", anjos[i].cidade,
                        anjos[i].numhab);
    j=i;
    i++;
    k=anjos[j].numhab;
    for(k==anjos[j].numhab; k<=anjos[j].numhab; i++){
		printf("%s %f %f %f\n", anjos[i].nome,
                                anjos[i].capfly,
                                anjos[i].peso,
                                anjos[i].altura);
        k++;
	}
}

void printardemonios (Demonios *demonios){
	int i,k,j;
    printf("\n%s %d\n", demonios[0].cidade,
                        demonios[0].numhab);
	for(i=1; i<=demonios[0].numhab;i++){
	printf("\n%s %f %f\n", demonios[i].nome,
                           demonios[i].escuridao,
                           demonios[i].visao);
	}
	printf("\n%s %d\n", demonios[i].cidade,
                        demonios[i].numhab);
    j=i;
    i++;
    k=demonios[j].numhab;
    for(k==demonios[j].numhab; k<=demonios[j].numhab; i++){
		printf("\n%s %f %f\n", demonios[i].nome,
                           demonios[i].escuridao,
                           demonios[i].visao);
        k++;
	}
	printf("\n%s %d\n", demonios[i].cidade,
                        demonios[i].numhab);
    j=i;
    i++;
    k=demonios[j].numhab;
    for(k==demonios[j].numhab; k<=demonios[j].numhab; i++){
		printf("\n%s %f %f\n", demonios[i].nome,
                           demonios[i].escuridao,
                           demonios[i].visao);
        k++;
	}
}

void printarhumanos (Humanos *humanos){
	int i;
    printf("\n%s %d\n", humanos[0].cidade,
                        humanos[0].numhab);
	for(i=1; i<=3;i++){
	printf("\n%s %f\n",humanos[i].nome,
                       humanos[i].forca);
	}
}

int main(){
  Demonios *demonios = (Demonios*)calloc(TAM,sizeof(Demonios));
  Humanos *humanos = (Humanos*)calloc(TAM,sizeof(Humanos));
  Anjos *anjos = (Anjos*)calloc(TAM,sizeof(Anjos));
  leranjos(anjos);
  lerdemonios(demonios);
  lerhumanos(humanos);
  printf("==================Anjos===================");
  printaranjos(anjos);
  printf("==================Demonios===================");
  printardemonios(demonios);
  printf("==================Humanos===================");
  printarhumanos(humanos);
  return(0);
}

void calchumanos (){
	
}

void calchumanos (){
	
}

void calchumanos (){
	
}

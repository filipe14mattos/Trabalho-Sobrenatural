#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 50

typedef struct Demonios{
  char nome[TAM];
  float escuridao, visao;
}Demonios;

typedef struct Anjos{
  char nome[TAM];
  float capfly, peso, altura;
}Anjos;

typedef struct Humanos{
  char nome[TAM];
  float forca;
}Humanos;

void leranjos (Anjos *Anjos){
	FILE* arq;
	arq = fopen("anjos.txt", "r");
	struct Anjos anjo;
	char nome_cidade[50];
	int i, j, n=0, num_cidades = 0, num_habitantes = 0;
	float calcforcacidades = 0.0;
	fscanf(arq, "%i", &num_cidades);
	printf("ANJOS\n");
	for(i=0; i<num_cidades; i++){
		fscanf(arq,"\t%s\t%i",nome_cidade, &num_habitantes);
		//como no arquivo existe um tab entre as informações uso o \t psra fazer essa leitura
		for(j=0; j<num_habitantes; j++){
			fscanf(arq,"%s %f %f %f", anjo.nome,&anjo.capfly,&anjo.peso,&anjo.altura);
			//printf("%s %f %f %f", Anjos.nome, Anjos.capfly, Anjos.peso, Anjos.altura);
			calcforcacidades = calcforcacidades + (anjo.capfly*(anjo.altura * anjo.altura)*anjo.peso);
			Anjos[n] = anjo;
			n++;
		}
		printf("\nA cidade %s tem um total de foca de: %.2f",nome_cidade, calcforcacidades );
		calcforcacidades = 0.0;
    }
	fclose(arq);
    //colocar essa mesma logica nas demais funcoes
}


void lerdemonios (Demonios *Demonios){
	FILE* arq;
	arq = fopen("demonios.txt", "r");
	int i,j, num_cidades = 0, num_habitantes = 0, n = 0;
	char nome_cidade[50];
	float calcforcacidades  = 0.0, dens = 0.0;
	struct Demonios demonio;
	
	fscanf(arq, "%i", &num_cidades);
	//fscanf(arq,"\t%s\t%i",nome_cidade, &num_habitantes);
	//fscanf(arq, "%s %i", Demonios[0].cidade, &Demonios[0].numhab);
	printf("\n\nDEMONIOS\n");
	for(i=0; i<num_cidades; i++){
		fscanf(arq,"\t%s\t%i",nome_cidade, &num_habitantes);
		
		for(j=0; j<num_habitantes; j++){
			fscanf(arq,"%s %f %f", demonio.nome,
		                       &demonio.escuridao,
                               &demonio.visao);

			dens = (demonio.escuridao - (demonio.visao/2));				   
			//calcforcacidades = calcforcacidades + (pow(demonio.escuridao - (demonio.visao/2)), 2);	
			calcforcacidades = calcforcacidades + (pow(dens,2));
			Demonios[n] = demonio;
			n++;				   
		}
		printf("\nA cidade %s tem um total de foca de: %.2f",nome_cidade, calcforcacidades );
		calcforcacidades = 0.0;
	
	}
	printf("\n\n");
	fclose(arq);
}//Colocar aqui dentro para ler os arquivos

void lerhumanos (Humanos *humanos){
	FILE* arq;
	arq = fopen("humanos.txt", "r");
	int i, num_cidades = 0, num_habitantes = 0;
	char nome_cidade[50];
	float calcforcacidades = 0.0;
	
	fscanf(arq, "%i", &num_cidades);
	//fscanf(arq, "%s %i", Humanos[0].cidade, &Humanos[0].numhab);
	fscanf(arq,"\t%s\t%i",nome_cidade, &num_habitantes);
	printf("\n\nHUMANOS\n");
	for(i=0; i<num_habitantes; i++){
		fscanf(arq,"%s %f", humanos[i].nome,
		                    &humanos[i].forca);
	
		calcforcacidades = calcforcacidades + (humanos[i].forca);
	}
	printf("\nA cidade %s tem um total de foca de: %.2f",nome_cidade, calcforcacidades);
	//calcforcacidades = 0.0;
	
	fclose(arq);
}//Colocar aqui dentro para ler os arquivos

/*
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
*/
/*
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
*/
int main(){
  Demonios *demonios = (Demonios*)calloc(TAM,sizeof(Demonios));
  Humanos *humanos = (Humanos*)calloc(TAM,sizeof(Humanos));
  Anjos *anjos = (Anjos*)calloc(TAM,sizeof(Anjos));
  leranjos(anjos);
  //lerdemonios(demonios);
  lerhumanos(humanos);
  lerdemonios(demonios);
  
  //printf("==================Anjos===================");
   //printf("\n\n");
  //printaranjos(anjos);
  //printf("==================Humanos===================");
   //printf("\n\n");
  //printardemonios(demonios);
  //printf("==================Demonios===================");
   //printf("\n\n");
  //printarhumanos(humanos);
  return(0);
}

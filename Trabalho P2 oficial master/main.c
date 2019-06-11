#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 50

typedef struct Forcas{
	char nome[TAM];
	float forca;
}Forcas;

typedef struct Mundo
{
	int numhabdem;
	int numhabhum;
	int numhabanj;
	float forcaanj, forcadem, forcahum;
} Mundo;

typedef struct Demonios
{
	char nome[TAM];
	float escuridao, visao;
} Demonios;

typedef struct Anjos
{
	char nome[TAM];
	float capfly, peso, altura;
} Anjos;

typedef struct Humanos
{
	char nome[TAM];
	float forca;
} Humanos;

void leranjos (Anjos *Anjos, Mundo *m, Forcas *f, int *n)
{
	FILE* arq;
	arq = fopen("anjos.txt", "r");
	m->numhabanj = 0;
	m->forcaanj = 0.0;
	struct Anjos anjo;
	char nome_cidade[50];
	int i, j, num_cidades = 0, num_habitantes = 0, k = 0;
	float calccidades = 0.0, calccind = 0.0;
	fscanf(arq, "%i", &num_cidades);
	printf("ANJOS\n");
	for(i = 0; i < num_cidades; i++){
		fscanf(arq, "%s %i", nome_cidade, &num_habitantes);
		for(j = 0; j < num_habitantes; j++)
		{
			fscanf(arq, "%s %f %f %f", anjo.nome, &anjo.capfly, &anjo.peso, &anjo.altura);
			calccidades += (anjo.capfly * (anjo.altura * anjo.altura) * anjo.peso);
			calccind = (anjo.capfly * (anjo.altura * anjo.altura) * anjo.peso);
			f[*n].forca = calccind;
			Anjos[k] = anjo;
			strcpy(f[*n].nome, Anjos[k].nome);
			(*n)++;
			
			k++;
			calccind = 0.0;
		}
        m->forcaanj += calccidades;
		m->numhabanj += num_habitantes;
		printf("\nA cidade %s tem um total de foca de: %.2f", nome_cidade, calccidades );
		calccidades = 0.0;
	}
	fclose(arq);
}

void lerdemonios (Demonios *Demonios, Mundo *m, Forcas *f, int *n)
{
	FILE* arq;
	arq = fopen("demonios.txt", "r");
	m->numhabdem = 0;
	m->forcadem = 0.0;
	int i, j, num_cidades = 0, num_habitantes = 0,k = 0;
	char nome_cidade[50];
	float subforca = 0.0, calccidades = 0.0, calccind = 0.0;
	struct Demonios demonio;
	fscanf(arq, "%i", &num_cidades);
	printf("\n\nDEMONIOS\n");
	for(i = 0; i < num_cidades; i++)
	{
		fscanf(arq, "%s %i", nome_cidade, &num_habitantes);
		for(j = 0; j < num_habitantes; j++)
		{
			fscanf(arq, "%s %f %f", demonio.nome,
				   &demonio.escuridao,
				   &demonio.visao);
			subforca = (demonio.escuridao - (demonio.visao / 2));
			calccidades += (pow(subforca, 2));
			calccind = (pow(subforca, 2));
			f[*n].forca = calccind;
			Demonios[k] = demonio;
			strcpy(f[*n].nome, Demonios[k].nome);
			
			(*n)++;
			
			k++;
			calccind = 0.0;
		}
		m->forcadem += calccidades;
		printf("\nA cidade %s tem um total de foca de: %.2f", nome_cidade, calccidades );
		calccidades = 0.0;
		m->numhabdem += num_habitantes;
	}
	printf("\n\n");
	fclose(arq);
}

void lerhumanos (Humanos *Humanos, Mundo *m, Forcas *f, int *n)
{
	FILE* arq;
	arq = fopen("humanos.txt", "r");
	m->numhabhum = 0;
	m->forcahum = 0.0;
	int i, j, num_cidades = 0, num_habitantes = 0, k = 0;
	char nome_cidade[50];
	float calccidades = 0.0, calccind = 0;
	struct Humanos human;
	fscanf(arq, "%i", &num_cidades);
	printf("\n\nHUMANOS\n");
	for(i = 0; i < num_cidades; i++)
	{
		fscanf(arq, "%s %i", nome_cidade, &num_habitantes);
		for(j = 0; j < num_habitantes; j++)
		{
			fscanf(arq, "%s %f", human.nome,
  	   	   	                     &human.forca);
			calccidades += human.forca;
			m->forcahum += human.forca;
			calccind = human.forca;
			f[*n].forca = calccind;
			Humanos[k] = human;
			strcpy(f[*n].nome, Humanos[k].nome);
			(*n)++;
			
			k++;
			calccind = 0.0;
		}
		m->numhabhum += num_habitantes;
		printf("\nA cidade %s tem um total de foca de: %.2f", nome_cidade, calccidades);
		calccidades = 0.0;
	}
	fclose(arq);
}

void somaAanjo(Anjos *Anjos, Mundo m, float *c)
{
	int i = 0, j;
	int quantA = 0;
	int tam = strlen(Anjos[0].nome);
	for(i = 0; i < m.numhabanj; i++)
	{
		for(j = 0; j < tam; j++)
		{
			if(Anjos[i].nome[j] == 'a')
			{
				quantA++;
			}
		}
		if(quantA == 2)
		{
			*c += (Anjos[i].capfly * (Anjos[i].altura * Anjos[i].altura) * Anjos[i].peso);
		}
		quantA = 0;
	}
}

void somaAhumano(Humanos *Humanos, Mundo m, float * c)
{
	int i = 0, j;
	int quantA = 0;
	int tam = strlen(Humanos[0].nome);
	for(i = 0; i < m.numhabhum; i++)
	{
		for(j = 0; j < tam; j++)
		{
			if(Humanos[i].nome[j] == 'a')
			{
				quantA++;
			}
		}
		if(quantA == 2)
		{
			*c += Humanos[i].forca;
		}
		quantA = 0;
	}
}

void somaAdemonios(Demonios *Demonios, Mundo m, float *c)
{
	int i = 0, j;
	int quantA = 0;
	int tam = strlen(Demonios[0].nome);
	float subforca = 0.0;
	for(i = 0; i < m.numhabanj; i++)
	{
		for(j = 0; j < tam; j++)
		{
			if(Demonios[i].nome[j] == 'a')
			{
				quantA++;
			}
		}
		if(quantA == 2)
		{
			subforca = (Demonios[i].escuridao - (Demonios[i].visao / 2));
			*c += (pow(subforca, 2));
		}
		quantA = 0;
	}
}

void swapbubble(Forcas *f, int i){

	Forcas forca;
					
	forca = f[i];
	f[i] = f[i+1];
	f[i+1] = forca;
		   	
}

void ordenacao(Forcas *f, int qtd){
	int i;
	int trocou;
	
	
	do{
		qtd--;
		trocou = 0;
		for(i = 0; i<qtd;i++){
				   if(f[i].forca >f[i+1].forca){	
				
					swapbubble(f, i);
					trocou = 1;
		
			    }
		
		}			
	}while(trocou);
}

void escreverVetor(Forcas *f, int n){
	int i=0;
	float menor = f[0].forca;
	float maior = f[n].forca;
	printf("O menores valores sao:\n ");
	printf("%s\n", f[0].nome);
	for(i = 1;i<n;i++){
		if(f[i].forca == menor){
			printf("%s\n", f[i].nome);
		}
	  }	
	
	printf("O maiores valores sao:\n ");
	printf("%s\n", f[n].nome);
	for(i = 0;i<n-1;i++){
		if(f[i].forca == maior){
			printf("%s\n", f[i].nome);
 
		}
	}
	
}	

/*
void escreverVetor1(Forcas *f, int n){
	int i;
	for(i = 0;i<n;i++){
		printf("NOME:%s\n", f[i].nome);
		printf("Forca:%f\n", f[i].forca);
	}
}
*/

void crescente(Mundo *f){
	if((f->forcahum<f->forcadem) && (f->forcahum<f->forcaanj)){
		if(f->forcaanj<f->forcadem){
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nHumanos com %.2f\n\nAnjos com %.2f\n\nDemonios com %.2f\n", 
            f->forcahum, f->forcaanj, f->forcadem);
		}else{
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nHumanos com %.2f\n\nDemonios com %.2f\n\nAnjos com %.2f\n", 
			f->forcahum, f->forcadem, f->forcaanj);
		}
	}else if((f->forcaanj<f->forcahum) && (f->forcaanj<f->forcadem)){
		if(f->forcahum<f->forcadem){
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nAnjos com %.2f\n\nHumanos com %.2f\n\nDemonios com %.2f\n",
			f->forcaanj, f->forcahum, f->forcadem);
		}else{
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nAnjos com %.2f\n\nDemonios com %.2f\n\nHumanos com %.2f\n",
            f->forcaanj, f->forcadem, f->forcahum);
		}
	}else if((f->forcadem<f->forcaanj) && (f->forcadem<f->forcahum)){
		if(f->forcaanj<f->forcahum){
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nDemonios com %.2f\n\nAnjos com %.2f\n\nHumanos com %.2f\n",
			f->forcadem, f->forcaanj, f->forcahum);
		}else{
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nDemonios com %.2f\n\nHumanos com %.2f\n\nAnjos com %.2f\n",
			f->forcadem, f->forcahum, f->forcaanj);
		}
	}
		
}

int main()
{
	int n = 0;
	float calcA = 0.0;
	Demonios *demonios = (Demonios*)calloc(TAM, sizeof(Demonios));
	Humanos *humanos = (Humanos*)calloc(TAM, sizeof(Humanos));
	Anjos *anjos = (Anjos*)calloc(TAM, sizeof(Anjos));
	Forcas *forcas = (Forcas*)calloc(TAM,sizeof(Forcas));
	Mundo mundo;
	leranjos(anjos, &mundo,forcas, &n);
	lerhumanos(humanos, &mundo, forcas, &n);
	lerdemonios(demonios, &mundo, forcas, &n);
	somaAanjo(anjos, mundo, &calcA);
	somaAhumano(humanos, mundo, &calcA);
	somaAdemonios(demonios, mundo, &calcA);
	printf("\nA forca dos individuos com duas letras a no nome e: %.2f\n\n", calcA);
	ordenacao(forcas, n);
	//escreverVetor1(forcas, n);
	escreverVetor(forcas, n-1);
	crescente(&mundo);
	return(0);
}
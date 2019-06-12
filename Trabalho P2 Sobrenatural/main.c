#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 50
typedef struct Forcas{
	char nome[50];
	float forca;
}Forcas;

typedef struct Mundo{
	int numhabdem,numhabhum,numhabanj;
	float forcaanj, forcadem, forcahum;
} Mundo;

typedef struct Demonios{
	char nome[50];
	float escuridao, visao;
} Demonios;

typedef struct Anjos{
	char nome[50];
	float capfly, peso, altura;
} Anjos;

typedef struct Humanos{
	char nome[50];
	float forca;
} Humanos;

void lerAnjos (Anjos *Anjos, Mundo *m, Forcas *f, int *n){
	FILE* arq;
	arq = fopen("anjos.txt", "r");
	m->numhabanj = 0;
	m->forcaanj = 0.0;
	struct Anjos anjo;
	char nome_cidade[50];
	int i, j, num_cidades = 0, num_habitantes = 0, k = 0;
	float calcforca = 0.0;
	fscanf(arq, "%i", &num_cidades);
	printf("ANJOS\n");
	for(i = 0; i < num_cidades; i++){
		fscanf(arq, "%s %i", nome_cidade, &num_habitantes);
		for(j = 0; j < num_habitantes; j++)
		{
			fscanf(arq, "%s %f %f %f", anjo.nome, &anjo.capfly, &anjo.peso, &anjo.altura);
			calcforca += (anjo.capfly * (anjo.altura * anjo.altura) * anjo.peso);
			f[*n].forca = (anjo.capfly * (anjo.altura * anjo.altura) * anjo.peso);
			Anjos[k] = anjo;
			strcpy(f[*n].nome, Anjos[k].nome);
			(*n)++;
			k++;
		}
        m->forcaanj += calcforca;
		m->numhabanj += num_habitantes;
		printf("\nA cidade %s tem um total de forca de: %.2f\n", nome_cidade, calcforca );
		calcforca = 0.0;
	}
	fclose(arq);
}

void lerDemonios (Demonios *Demonios, Mundo *m, Forcas *f, int *n){
	FILE* arq;
	arq = fopen("demonios.txt", "r");
	m->numhabdem = 0;
	m->forcadem = 0.0;
	int i, j, num_cidades = 0, num_habitantes = 0,k = 0;
	char nome_cidade[50];
	float subforca = 0.0, calcforcas = 0.0;
	struct Demonios demonio;
	fscanf(arq, "%i", &num_cidades);
	printf("\nDEMONIOS\n");
	for(i = 0; i < num_cidades; i++){
		fscanf(arq, "%s %i", nome_cidade, &num_habitantes);
		for(j = 0; j < num_habitantes; j++){
			fscanf(arq, "%s %f %f", demonio.nome,
                                    &demonio.escuridao,
				                    &demonio.visao);
			subforca = (demonio.escuridao - (demonio.visao / 2));
			calcforcas += (pow(subforca, 2));
			f[*n].forca = (pow(subforca, 2));
			Demonios[k] = demonio;
			strcpy(f[*n].nome, Demonios[k].nome);
			(*n)++;
			k++;
		}
		m->forcadem += calcforcas;
		printf("\nA cidade %s tem um total de forca de: %.2f\n", nome_cidade, calcforcas );
		calcforcas = 0.0;
		m->numhabdem += num_habitantes;
	}
	printf("\n\n");
	fclose(arq);
}

void lerHumanos (Humanos *Humanos, Mundo *m, Forcas *f, int *n){
	FILE* arq;
	arq = fopen("humanos.txt", "r");
	m->numhabhum = 0;
	m->forcahum = 0.0;
	int i, j, num_cidades = 0, num_habitantes = 0, k = 0;
	char nome_cidade[50];
	float calcforcas = 0.0;
	struct Humanos human;
	fscanf(arq, "%i", &num_cidades);
	printf("\nHUMANOS\n");
	for(i = 0; i < num_cidades; i++){
		fscanf(arq, "%s %i", nome_cidade, &num_habitantes);
		for(j = 0; j < num_habitantes; j++){
			fscanf(arq, "%s %f", human.nome,
  	   	   	                     &human.forca);
			calcforcas += human.forca;
			m->forcahum += human.forca;
			f[*n].forca = human.forca;
			Humanos[k] = human;
			strcpy(f[*n].nome, Humanos[k].nome);
			(*n)++;
			k++;
		}
		m->numhabhum += num_habitantes;
		printf("\nA cidade %s tem um total de forca de: %.2f\n", nome_cidade, calcforcas);
		calcforcas = 0.0;
	}
	fclose(arq);
}

void somaAanjo(Anjos *Anjos, Mundo m, float *c){
	int i, j;
	int quantA = 0,tam = strlen(Anjos[0].nome);
	for(i = 0; i < m.numhabanj; i++){
		for(j = 0; j < tam; j++){
			if(Anjos[i].nome[j] == 'a'){
				quantA++;
			}
		}
		if(quantA == 2){
			*c += (Anjos[i].capfly * (Anjos[i].altura * Anjos[i].altura) * Anjos[i].peso);
		}
		quantA = 0;
	}
}

void somaAhumano(Humanos *Humanos, Mundo m, float * c){
	int i, j,quantA = 0,tam = strlen(Humanos[0].nome);
	for(i = 0; i < m.numhabhum; i++){
		for(j = 0; j < tam; j++){
			if(Humanos[i].nome[j] == 'a'){
				quantA++;
			}
		}
		if(quantA == 2){
			*c += Humanos[i].forca;
		}
		quantA = 0;
	}
}

void somaAdemonios(Demonios *Demonios, Mundo m, float *c){
	int i, j,quantA = 0,tam = strlen(Demonios[0].nome);
	float subforca = 0.0;
	for(i = 0; i < m.numhabanj; i++){
		for(j = 0; j < tam; j++){
			if(Demonios[i].nome[j] == 'a'){
				quantA++;
			}
		}
		if(quantA == 2){
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
	int i,trocou;
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
	int i;
	float menor = f[0].forca,maior = f[n].forca;
	printf("O(s) individuo(s) com a(s) menor(es) forca(s) sao:\n");
	printf("%s\n", f[0].nome);
	for(i = 1;i<n;i++){
		if(f[i].forca == menor){
			printf("%s\n", f[i].nome);
		}
	  }
	printf("O(s) individuo(s) com a(s) maior(es) forca(s) sao:\n");
	printf("%s\n", f[n].nome);
	for(i = 0;i<n-1;i++){
		if(f[i].forca == maior){
			printf("%s\n", f[i].nome);
		}
	}
}

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

int main(){
	int n = 0;
	float calcA = 0.0;
	Demonios *demonios = (Demonios*)calloc(TAM, sizeof(Demonios));
	Humanos *humanos = (Humanos*)calloc(TAM, sizeof(Humanos));
	Anjos *anjos = (Anjos*)calloc(TAM, sizeof(Anjos));
	Forcas *forcas = (Forcas*)calloc(TAM,sizeof(Forcas));
	Mundo mundo;
	lerAnjos(anjos, &mundo,forcas, &n);
	lerHumanos(humanos, &mundo, forcas, &n);
	lerDemonios(demonios, &mundo, forcas, &n);
	somaAanjo(anjos, mundo, &calcA);
	somaAhumano(humanos, mundo, &calcA);
	somaAdemonios(demonios, mundo, &calcA);
	printf("A forca dos individuos com duas letras a no nome e: %.2f\n\n", calcA);
	free(demonios);
	free(humanos);
	free(anjos);
	ordenacao(forcas, n);
	escreverVetor(forcas, n-1);
	free(forcas);
	crescente(&mundo);
	return(0);
}
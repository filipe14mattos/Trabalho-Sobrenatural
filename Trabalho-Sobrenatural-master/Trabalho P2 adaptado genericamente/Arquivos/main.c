#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 50

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

void leranjos (Anjos *Anjos, Mundo *m)
{
	FILE* arq;
	arq = fopen("anjos.txt", "r");
	m->numhabanj = 0;
	m->forcaanj = 0.0;
	struct Anjos anjo;
	char nome_cidade[50];
	int i, j, n = 0, num_cidades = 0, num_habitantes = 0;
	fscanf(arq, "%i", &num_cidades);
	printf("ANJOS\n");
	for(i = 0; i < num_cidades; i++)
	{
		fscanf(arq, "%s %i", nome_cidade, &num_habitantes);
		for(j = 0; j < num_habitantes; j++)
		{
			fscanf(arq, "%s %f %f %f", anjo.nome, &anjo.capfly, &anjo.peso, &anjo.altura);
			m->forcaanj += (anjo.capfly * (anjo.altura * anjo.altura) * anjo.peso);
			Anjos[n] = anjo;
			n++;
		}
		m->numhabanj += num_habitantes;
		printf("\nA cidade %s tem um total de foca de: %.2f", nome_cidade, m->forcaanj );
		m->forcaanj = 0.0;
	}
	fclose(arq);
}

void lerdemonios (Demonios *Demonios, Mundo *m)
{
	FILE* arq;
	arq = fopen("demonios.txt", "r");
	m->numhabdem = 0;
	m->forcadem = 0.0;
	int i, j, num_cidades = 0, num_habitantes = 0, n = 0;
	char nome_cidade[50];
	float subforca = 0.0;
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
			m->forcadem += (pow(subforca, 2));
			Demonios[n] = demonio;
			n++;
		}
		printf("\nA cidade %s tem um total de foca de: %.2f", nome_cidade, m->forcadem );
		m->forcadem = 0.0;
		m->numhabdem += num_habitantes;
	}
	printf("\n\n");
	fclose(arq);
}

void lerhumanos (Humanos *Humanos, Mundo *m)
{
	FILE* arq;
	arq = fopen("humanos.txt", "r");
	m->numhabhum = 0;
	m->forcahum = 0.0;
	int i, j, num_cidades = 0, num_habitantes = 0;
	char nome_cidade[50];
	fscanf(arq, "%i", &num_cidades);
	printf("\n\nHUMANOS\n");
	for(i = 0; i < num_cidades; i++)
	{
		fscanf(arq, "%s %i", nome_cidade, &num_habitantes);
		for(j = 0; j < num_habitantes; j++)
		{
			fscanf(arq, "%s %f", Humanos[j].nome,
				   &Humanos[j].forca);

			m->forcahum += (Humanos[j].forca);
			calccidades = m->forcahum
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

void maior(Anjos *anjo, Demonios *demonios, Humanos *humanos)
{
	int i, j;

	//colocar os calculos de forca e comparar eles entre maior e menor

}

void crescente(Mundo *f)
{
	if((f->forcaanj > f->forcadem) && (f->forcaanj > f->forcahum)){
		if(f->forcadem > f->forcahum){
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nAnjos com %.2f\n\nDemonios com %.2f\n\nHumanos com %.2f\n", f->forcaanj, f->forcadem, f->forcahum);
		}else{
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nAnjos com %.2f\n\nHumanos com %.2f\n\nDemonios com %.2f\n", f->forcaanj, f->forcahum, f->forcadem);
		}
	}else if((f->forcadem > f->forcaanj)&&(f->forcadem > f->forcahum)){
		if(f->forcaanj>f->forcahum){
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nDemonios com %.2f\n\nAnjo com %.2f\n\nHumanos com %.2f\n", f->forcadem, f->forcaanj, f->forcahum);
		}else{
			printf("\nA ordem crescente das racas de acordo com a forca de cada e: \nDemonios com %.2f\n\nAnjo com %.2f\n\nHumanos com %.2f\n", f->forcadem, f->forcahum, f->forcaanj);
		}
		
}
	//colocar as ra�as na ordem crescente a partir da soma das cidades de cada ra�a
}

int main()
{
	float calcA = 0.0;
	Demonios *demonios = (Demonios*)calloc(TAM, sizeof(Demonios));
	Humanos *humanos = (Humanos*)calloc(TAM, sizeof(Humanos));
	Anjos *anjos = (Anjos*)calloc(TAM, sizeof(Anjos));
	Mundo mundo;
	leranjos(anjos, &mundo);
	lerhumanos(humanos, &mundo);
	lerdemonios(demonios, &mundo);
	somaAanjo(anjos, mundo, &calcA);
	somaAhumano(humanos, mundo, &calcA);
	somaAdemonios(demonios, mundo, &calcA);
	crescente(&mundo);
	printf("\nA forca dos individuos com duas letras a no nome e: %.2f\n", calcA);
	return(0);
}

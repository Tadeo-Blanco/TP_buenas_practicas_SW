#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>
struct semaforo{
char calle1[40];
char calle2[40];
int trafico;
int cantidad;
};
void ingresardatos(struct semaforo *S);
void mostrar(struct semaforo *S);
void comparador(struct semaforo *S);
void comptrafico(struct semaforo *S);
int main() {
	struct semaforo *S;
	S =(struct semaforo*)malloc(1*sizeof(struct semaforo));
	int inicializar=0,opcion=0;
	S->cantidad=0;
	do{
		printf("1. Ingresar semaforo\n");
		printf("2. Mostrar\n");
		printf("3. Busqueda por nombre de calle\n");
		printf("4.Busqueda por trafico \n");
		printf("5. salir\n");
		scanf("%d",&opcion);
		if(opcion==1){
			inicializar++;
			S->cantidad++;
			S=(struct semaforo*)realloc((S),(S->cantidad+1)*sizeof(struct semaforo));
		}
		if(inicializar>=1 || opcion==5){
			switch(opcion){
			case 1:
				ingresardatos(S);
			break;
			case 2:
				mostrar(S);
			break;
			case 3:
				comparador(S);
			break;
			case 4:
				comptrafico(S);
			break;
			case 5:
				printf("saliendo..");
				break;
			}
		}
	}
	while(opcion!=5);
}
void ingresardatos(struct semaforo *S){

	printf("ingrese una de las calles donde esta el semaforo\n ");
	scanf("%39s",S[S->cantidad-1].calle1);
	printf("ingrese la otra calle\n");
	scanf("%39s",S[S->cantidad-1].calle2);
	printf("la interseccion es entre las calles %s y %s \n",S[S->cantidad-1].calle1,S[S->cantidad-1].calle2);
	printf("Ingrese la intensidad de trafico que tiene esa interseccion, entre 1 y 100\n");
	do{
	scanf("%d",&S[S->cantidad-1].trafico);
	if(S[S->cantidad-1].trafico<1 || S[S->cantidad-1].trafico>100){
	printf("valor incorrecto ingrese otro");	
	}
	}
	while(S[S->cantidad-1].trafico<1 || S[S->cantidad-1].trafico>100);
	printf("la interseccion tiene un trafico %d \n",S[S->cantidad-1].trafico);
	}
void mostrar(struct semaforo *S){
	int i;
	printf("SEMAFOROS:\n");
	for(i=0;i<(S->cantidad);i++)
	{
		printf("semaforo de las calles %s y %s \n",S[i].calle1,S[i].calle2);
		printf("tiene una intensidad de trafico de: %d \n",S[i].trafico);
	}
}
void comparador(struct semaforo *S){
	char calle[40];
	int i;
	printf("\nIngrese la calle del semaforo a buscar:\n");
	scanf("%39s",calle);
	for(i=0;i<(S->cantidad);i++)
	{
		if ( strcmp(S[i].calle1,calle) == 0 )
		{                                              
			printf("\ncalle 1: %s\ncalle 2: %s\n trafico: %d\n",S[i].calle1,S[i].calle2,S[i].trafico);
		}
		if ( strcmp(S[i].calle2,calle) == 0 )
		{                                              
			printf("\ncalle 1: %s\ncalle 2: %s\n trafico: %d\n",S[i].calle1,S[i].calle2,S[i].trafico);
		}
	}
}
void comptrafico(struct semaforo *S){
	int aux,i;
	printf("ingrese el nro de trafico que quiere ubicar");
	do{
	scanf("%d",&aux);
	if(aux<1 || aux>100){
		printf("valor invalido ingrese otro entre 1 y 100");
	}
	}
	while(aux<1 || aux>100);
	for(i=0;i<(S->cantidad);i++)
	{
	if ( (S[i].trafico) == aux )
	{                                              
		printf("\ncalle 1: %s\ncalle 2: %s\n trafico: %d\n",S[i].calle1,S[i].calle2,S[i].trafico);
	}
	}
}

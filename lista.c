#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

#define TAMANHO_NOME 20

struct no{
char nome[TAMANHO_NOME];
int linhas;
int colunas;
float **mat;
struct no *prox;
};

typedef struct no matriz;

matriz *encontra_matriz (char nome[], matriz *inicio)
{
	if (!strcmp(nome, inicio->nome))
		return inicio;
	if(!inicio->prox)
		return NULL;
	return encontra_matriz (inicio->prox->nome, inicio->prox);
}

void nova_matriz (char nome[], int linhas, int colunas, matriz **inicio)
{
	matriz *aux;
	aux = (matriz *) malloc (sizeof(matriz));
	strcpy (aux->nome, nome);
	aux->linhas = linhas;
	aux->colunas = colunas;
	aux->mat = criarMatriz (linhas, colunas, 0);//
	if(!inicio) *inicio = aux;
	else{
		matriz *aux2 = *inicio;
		while(aux2->prox) aux2 = aux2->prox;
		aux2->prox = aux;
	}
	
}

void exclui_matriz (char nome[], matriz **inicio)
{
	matriz *aux = *inicio;
	if(!aux){	
		printf("ERRO\n");
	}
	if (!strcmp(nome, aux->nome)){
		destruirMatriz (aux->mat, aux->linhas);//
		*inicio = aux->prox;
		free(aux);
	}
	do{
		if (!strcmp(nome, aux->prox->nome)){
			destruirMatriz (aux->prox->mat, aux->prox->linhas);//
			aux->prox = aux->prox->prox;
			free(aux);
			break;
		}
		aux = aux->prox;
	}while (aux);
	printf("ERRO\n");
}

void imprime_matriz (char nome[], matriz *inicio)
{
	matriz *aux;
	if(!(aux = encontra_matriz (nome, inicio))) printf("Não existe esta matriz!\n");
	imprimirMatriz (aux->mat, aux->linhas, aux->colunas);//
}

void atribui_valor (char nome[], matriz *inicio, float valor, int linha, int coluna)
{
	matriz *aux = encontra_matriz (nome, inicio);
	atribuirValor (aux->mat, valor, linha, coluna, aux->linhas, aux->colunas);//
}

void atribui_linha (char nome[], matriz *inicio, int linha)
{
	matriz *aux = encontra_matriz (nome, inicio);
	atribuirLinha (aux->mat, aux->linhas, aux->colunas, linha);//
}

void atribui_coluna (char nome[], matriz *inicio, int coluna)
{
	matriz *aux = encontra_matriz (nome, inicio);
	atribuirColuna (aux->mat, aux->linhas, aux->colunas, coluna);//
}

void transpor_matriz (char nome[], matriz *inicio)
{
	matriz *aux = encontra_matriz (nome, inicio);
	aux->mat = transporMatriz (aux->mat, aux->linhas, aux->colunas);//
}

void somar_matriz (char nome1[], char nome2[], char nome[], matriz **inicio)
{
	matriz *aux1 = encontra_matriz (nome1, *inicio);
	matriz *aux2 = encontra_matriz (nome2, *inicio);
	matriz *aux = (matriz *) malloc (sizeof(matriz));
	strcpy (aux->nome, nome);
	aux->linhas = aux1->linhas;
	aux->colunas = aux1->colunas;
	aux->mat = criarMatriz (aux->linhas, aux->colunas, 1);//
	aux->prox = *inicio;
	*inicio = aux;
	(*inicio)->mat = somarMatriz (aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
}

void dividir_matriz (char nome1[], char nome2[], char nome[], matriz **inicio)
{
	matriz *aux1 = encontra_matriz (nome1, *inicio);
	matriz *aux2 = encontra_matriz (nome2, *inicio);
	matriz *aux = (matriz *) malloc (sizeof(matriz));
	strcpy (aux->nome, nome);
	aux->linhas = aux1->linhas;
	aux->colunas = aux1->colunas;
	aux->mat = criarMatriz (aux->linhas, aux->colunas, 1);//
	aux->prox = *inicio;
	*inicio = aux;
	(*inicio)->mat = divideMatriz (aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
}

void MElista(char nome1[], char nome2[], char nome[], matriz **inicio)
{
	matriz *aux1 = encontra_matriz (nome1, *inicio);
	matriz *aux2 = encontra_matriz (nome2, *inicio);
	matriz *aux = (matriz *) malloc (sizeof(matriz));
	strcpy (aux->nome, nome);
	aux->linhas = aux1->linhas;
	aux->colunas = aux1->colunas;
	aux->mat = criarMatriz (aux->linhas, aux->colunas, 1);//
	aux->prox = *inicio;
	*inicio = aux;
	(*inicio)->mat = MultElemMat(aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
}

void MMlista(char nome1[], char nome2[], char nome[], matriz **inicio)
{
	matriz *aux1 = encontra_matriz (nome1, *inicio);
	matriz *aux2 = encontra_matriz (nome2, *inicio);
	matriz *aux = (matriz *) malloc (sizeof(matriz));
	strcpy (aux->nome, nome);
	aux->linhas = aux1->linhas;
	aux->colunas = aux2->colunas;
	aux->mat = criarMatriz (aux->linhas, aux->colunas,1);//
	aux->prox = *inicio;
	*inicio = aux;
	(*inicio)->mat = MultMat(aux1->mat, aux2->mat, aux1->linhas, aux1->colunas, aux2->linhas, aux2->colunas);
}

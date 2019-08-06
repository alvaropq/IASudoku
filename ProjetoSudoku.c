#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Médio
//int matriz[9][9] = {{1,0,6,0,0,5,3,8,7},{0,0,5,0,3,2,1,0,9},{3,0,0,1,0,8,0,0,0},{0,0,0,0,0,0,7,3,5},{0,5,3,0,0,0,2,1,0},{2,1,7,0,0,0,0,0,0},{0,0,0,8,0,4,0,0,1},{5,0,1,3,2,0,4,0,0},{7,8,4,6,0,0,9,0,3}};
//Dificil++
//int matriz[9][9] = {{0,1,0,0,0,5,0,0,0},{0,8,0,0,0,1,0,7,0},{0,0,2,0,0,0,0,0,3},{0,0,6,2,0,0,4,0,0},{0,2,0,0,0,8,0,1,0},{0,0,7,0,0,0,5,0,0},{2,0,0,0,0,0,6,0,0},{0,6,0,3,0,0,0,8,0},{0,0,0,4,0,0,0,9,0}};
//Dificil++
//int matriz[9][9] = {{0,0,0,0,4,7,0,0,0},{0,0,0,9,0,0,0,0,2},{0,0,3,0,8,5,0,0,9},{8,3,0,4,0,0,6,0,0},{2,0,9,0,0,0,3,0,5},{0,0,6,0,0,3,0,2,8},{9,0,0,7,5,0,1,0,0},{4,0,0,0,0,1,0,0,0},{0,0,0,8,9,0,0,0,0}};
//Sudoku mais dificil do mundo
int matriz[9][9] = {{8,0,0,0,0,0,0,0,0},{0,0,3,6,0,0,0,0,0},{0,7,0,0,9,0,2,0,0},{0,5,0,0,0,7,0,0,0},{0,0,0,0,4,5,7,0,0},{0,0,0,1,0,0,0,3,0},{0,0,1,0,0,0,0,6,8},{0,0,8,5,0,0,0,1,0},{0,9,0,0,0,0,4,0,0}};

int comp[9][9];
int cont = 0;

typedef struct lista{
	int info;
	int l;
	int c;
	struct lista* prox;
}Lista;

typedef struct pilha{
	Lista* topo;
}Pilha;


Lista* Pos = NULL;
Lista* Log = NULL;

Lista* insereInicio(Lista* L, int valor,int l,int c){
	
		Lista* novo = (Lista*) malloc(sizeof(Lista));
		novo->info = valor;
		novo->l = l;
		novo->c = c;
		novo->prox = L;
		
		return novo;
	
}

Lista* removeInicio(Lista* L){
	Lista* aux = L;
	L = aux->prox;
	if(aux != NULL){
		free(aux);
	}
	return L;
}

void inserePilha(Pilha* P, int valor,int l,int c){
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;
	novo->l = l;
	novo->c = c;
	novo->prox = P->topo;
	P->topo = novo;
	
}

void removePilha(Pilha* P){
	
	Lista* aux = P->topo;
	P->topo = aux->prox;
	free(aux);

}

void imprimePilha(Pilha* P){	
	Lista* aux = P->topo;
	
	while(aux!=NULL){
		
		printf("%d\n",aux->info);
		aux = aux->prox;
	}
	
}

void imprimeLista(Lista* L){
	
	while(L != NULL){
		printf("%d --- coluna %d e linha %d \n",L->info,L->c,L->l);
		L = L->prox;
	}
	
}

void imprimeSudoku(){
	int i=0;
	int j =0;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			
			if(matriz[i][j] == 0){
				printf("-\t");
			}
			else{
				printf("%d\t",matriz[i][j]);
			}
		}
		printf("\n");
		
	}
}

int verificaBloco(int l,int c,int valor){
	int i=0;
	int j=0;
	int flag=0;
	
	if(l<3){
		if(c<3){//bloco 1;
			
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
		}
		
		else if(c>2 && c<6){
			
			for(i=0;i<3;i++){
				for(j=3;j<6;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
			
		}
		
		else{
			
			for(i=0;i<3;i++){
				for(j=6;j<9;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
		}
	}
	
	else if(l>2 && l<6){
		if(c<3){
			
			for(i=3;i<6;i++){
				for(j=0;j<3;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
		}
		
		else if(c>2 && c<6){
			
			for(i=3;i<6;i++){
				for(j=3;j<6;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
		}
		
		else{
			
			for(i=3;i<6;i++){
				for(j=6;j<9;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
			
		}
	}
	
	else{
		if(c<3){
			
			for(i=6;i<9;i++){
				for(j=0;j<3;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
		}
		
		else if(c>2 && c<6){
			
			for(i=6;i<9;i++){
				for(j=3;j<6;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
		}
		
		else{
			
			for(i=6;i<9;i++){
				for(j=6;j<9;j++){
					
					if(matriz[i][j] == valor){
						flag = 1; //já possui valor
					}
					
				}
			}
			
			
		}
	}
	
	if(flag == 0){
		return 1;
	}
	else{
		return 0;
	}
	
}

int verificaLinha(int l,int c,int valor){
	int i=0;
	int flag = 0;
	
	for(i=0;i<9;i++){
		
		if(matriz[l][i] == valor){
			flag = 1;
		}
		
	}
	
	if(flag == 0){
		return 1; // nao tem o valor
	}
	
	else{
		return 0; // tem o valor
	}
	
}

int verificaColuna(int l,int c,int valor){
	int i=0;
	int flag = 0;
	
	for(i=0;i<9;i++){
		
		if(matriz[i][c] == valor){
			flag = 1;
		}
		
	}
	
	if(flag == 0){
		return 1; // nao tem o valor
	}
	
	else{
		return 0; // tem o valor
	}
	
}

Lista* removeL(Lista* L, int valor, int l, int c){
	Lista* aux = L;
	Lista* ant = NULL;
	int flag = 0;
	
	if( aux == NULL){
		return NULL;
	}
	
	else{
		
		while(flag == 0){
			
			if(aux != NULL){
				
					
					if(aux->info != valor){
						ant = aux;
						aux = aux->prox;
					}
					
					else{// valor igual
						
						if(aux->c != c){
							ant = aux;
							aux = aux->prox;	
						}
						
						else{// coluna igual
							
							if(aux->l != l){
								ant = aux;
								aux = aux->prox;	
							}
							
							else{// achou o valor
								flag = 1;
							}
							
						}
					}
				}
			else{
				flag = 1;
			}
		}
		
		if(aux == NULL){
			return L;
		}
		
		else if(ant == NULL){
			ant = aux;
			aux = aux->prox;
			free(ant);
			return aux;
		}
		
		else{
			ant->prox = aux->prox;
			free(aux);
			return L;
		}	
		
	}

}


Lista* achaLinha(int l,Pilha* P){
	
	Lista* aux = P->topo;
	
	while(aux!=NULL && aux->l != l){
		
		aux = aux->prox;
		
	}
	
	if(aux == NULL){//Não achou nenhuma linha
		return NULL;
	}
	
	else{
		
		while(P->topo!= NULL && P->topo->l != l){
			matriz[P->topo->l][P->topo->c] = 0;
			Log = removeL(Log,P->topo->info,P->topo->l,P->topo->c);
			removePilha(P);
		}		
		
	}
	
	return P->topo;
	
}


int verificaNumero(int i,int j,int k){
	Lista* aux = Log;
	int flag = 0;
	
	while(flag == 0){
			
			if(aux != NULL){
				
					
					if(aux->info != k){
						aux = aux->prox;
					}
					
					else{// valor igual
						
						if(aux->c != j){
							aux = aux->prox;	
						}
						
						else{// coluna igual
							
							if(aux->l != i){
								aux = aux->prox;	
							}
							
							else{// achou o valor
								flag = 1;
							}
							
						}
					}
				}
			else{
				flag = 1;
			}
		}
	
	if(aux == NULL){ // numero ainda nao foi testado
		return 1;
	}
	
	else if( flag == 1){
		return 0; // numero já testado
	}
	
	else{
		return 1; //numero não testado;
	}
	
	
}

Lista* apagaTentativaFalha(Lista* L,Pilha* P){
	
	Lista* aux = L;
	
	while(aux != NULL){
		
		if(aux->l == P->topo->l){
			
			if(aux->c >= P->topo->c){
				L = removeL(L,aux->info,aux->l,aux->c);
				aux = L;
			}
			
			else{
				aux = aux->prox;
			}
		}
		
		else{
			aux = aux->prox;
		}
		
	}
	return L;
	
}

void refazSudoku(int i, int j,Pilha* P){
	Lista* aux = NULL;
	int k = 0;
	int flag = 0;
	
	aux = achaLinha(i,P);
	if(aux != NULL){
		j = aux->c;
		matriz[i][j]=0;
		
		
							
		for(k=1;k<=9;k++){
			if(verificaBloco(i,j,k) == 1 && verificaLinha(i,j,k) == 1 && verificaColuna(i,j,k) == 1 && k != aux->info && verificaNumero(i,j,k) ==1){ // numero livre para colocar
				matriz[i][j] = k;
				removePilha(P);
				inserePilha(P,k,i,j);
				Log = insereInicio(Log,k,i,j);
				flag = 1;
				k = 9; // sair do laço
			}
			
		}
		
		if(flag == 0){// volta para uma jogada anterior	
			Log = apagaTentativaFalha(Log,P); // apaga todas as jogadas realizadas até a jogada anterior
			removePilha(P);
			flag = 0;
			refazSudoku(i,j,P);
		}
		
		if(flag == 1){
			Pos = aux;
		}
		
	}
	else{
		refazSudoku(P->topo->l,P->topo->c,P);
	}
}


void resolveSudoku(Pilha* P){
	
	int i=0;
	int j=0;
	int k = 0;
	
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			
			if(matriz[i][j] == 0){ // campo vazio
				
				for(k=1;k<=9;k++){
					
					if(verificaBloco(i,j,k) == 1 && verificaLinha(i,j,k) == 1 && verificaColuna(i,j,k) == 1 && verificaNumero(i,j,k) == 1){ // numero livre para colocar
						matriz[i][j] = k;
						inserePilha(P,k,i,j);
						Log = insereInicio(Log,k,i,j);
						k = 9; // sair do laço	
					}
					
					if(matriz[i][j] == 0 && k == 9){
						//Caso não tenha mais possibilidades, refaz as jogadas anteriores...
						refazSudoku(i,j,P);
						i = Pos->l;
						j= Pos->c;
						
					}
						
						
						
					}
				
					
				}
			//imprimeSudoku();
			//printf("\n");	
			}
			
		}
}

int VerificaResolvido(){
	
	int i = 0;
	int j = 0;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			
			if(matriz[i][j] == 0){
				return 0; // nao resolvida
			}
			
		}
	}
	
	return 1; // resolvida
	
	
}


int main(){
	Pilha* P =(Pilha*)malloc(sizeof(Pilha));
	P->topo = NULL;
	
	printf("--------Estado Inicial----------\n\n");
	
	imprimeSudoku();
	getchar();
	
	while(VerificaResolvido() != 1){
		resolveSudoku(P);
	}
	
	printf("----------Sudoku Resolvido-------\n\n");
	imprimeSudoku();
	
}

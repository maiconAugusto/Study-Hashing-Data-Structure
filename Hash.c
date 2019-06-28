#include<stdio.h>
#include<stdlib.h>


typedef struct no{
  int valor;
  int position;
  struct no* prox;
}No;

// Função insere Lista
No* insere(No* lista, int num,int element){
	
  // Criando um novo no
  No* novo = (No*)malloc(sizeof(No));
  novo->valor = num; 
  novo->position = element;
  novo->prox = NULL;
  
  // Se a lista estiver NULL, lista aponta para novo
  if(lista == NULL){
      lista = novo;
    }
    // Se não listaProx aponta para novo
  else{
  	// No auxiliar aponta para lista
    No* aux = lista;
    while(aux->prox !=NULL){
       aux = aux->prox;
      }
      aux->prox = novo;
    }
  return lista;
  }

// Segudna função chamada para tratar a colisão
int hashTwo(int tam, int vetor){
  return (vetor + 1) % tam;
  }
// Primeira função chamada para buscar o indice a ser inserido
int hashOne(int tam, int vetor){
  return vetor % tam;
  }
  
// Alocando o valore em suas posiçoes  
void TratandoColisao(No* lista, int tam, int vet[tam] ){
	
    int indice = 0; // controle do laço
    int element;  // recebe o indice da tabela hash
    No* aux = lista;
    int indice_2 = 0; // controle do laço
    int vets[tam]; // vetor auxiliar
    
    
    while(indice < tam){
    	
        element = hashOne(tam,aux->valor);
        if(vet[element] == '\0'){
            vet[element] = aux->valor;
            vets[element] = aux->position;}
          
        else{ element = hashTwo(tam,aux->valor);
          
          	if(vet[element] == '\0'){
                vet[element] = aux->valor;
                vets[element] = aux->position;
          	}
          	
            else{
            	
	            while( indice_2 < tam){
	                if(vet[indice_2] == '\0'){
	                  	if(vet[indice_2] == '\0'){
	                  	vet[indice_2] = aux->valor;
	                  	vets[indice_2] = aux->position;
	                  	}
	                }
                    indice_2++;
               }
            }
		}
        aux = aux->prox;
        indice++;
    }
    // Zerando o indice
	indice_2 = 0;  
	
	// Imprimindo a tabela
    while(indice_2 < tam){
        printf("%i-[%i(%i)]\n",indice_2,vet[indice_2],vets[indice_2]);
        indice_2++;
    }    
  }

int main() {
  
  No * lista = NULL;
  int tam;
  int vet[tam];
  int count = 0;
  int element;
  int i = 0;
  
  scanf("%i",&tam);
  
  while(i < tam){
    scanf("%i",&vet[i]);
    i++;
    }
  
  	// chama a tabela hash e insere na lista
  while(count < tam){
    element = hashOne(tam,vet[count]);
    lista = insere(lista,vet[count], element);
    count++;
    }
    count = 0;
   
   // limpando vetor
  while(count < tam){
     vet[count] = '\0';
     count++;
     }
    
    // Chamando a função de tratamento e print na tela
	TratandoColisao(lista,tam,vet);

  
  return 0;
}

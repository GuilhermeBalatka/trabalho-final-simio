#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_DIR 999

typedef struct{
	char nome[500];
	char data_nascimento[10];
	int resultado;
	char cidade[500];
	
} pessoa;


//cabecalho das funcoes
void imprimir_menu();
void imprimir_matriz(char ***matriz, int tamanho);
int ler_tamanho_matriz();
void criar_matriz(char ***matriz, int tamanho);
void criar_arquivo_matriz(char ***matriz, int tamanho);
int is_simian(char ***matriz, int tamanho);
int verificar_linhas(char ***matriz, int tamanho);
int verificar_colunas(char ***matriz, int tamanho); 
int verificar_diagonais_principais(char ***matriz, int tamanho);
int verificar_diagonais_secundarias(char ***matriz, int tamanho);
void visualizar_resultado(pessoa Pessoas[], int resultado, int id);
void liberar_memoria(char **matriz, int tamanho);
int criar_matriz_com_arquivo(char *nome_arquivo, char ***matriz);
int cadastrar_dados_pessoa(pessoa Pessoas[], int total_id);
void ler_dados_pessoa(pessoa Pessoas[], int id_pessoa);



int main(){
	int tam_matriz=0, resultado=0, opcao=0;
	char **matriz_sequencia_DNA, *nome_arquivo;
	char continuar;
	pessoa Pessoas[10];	
	int total_id=0;
	int id_pessoa;

	//criacao do menu
	do{
		
		imprimir_menu();
		scanf("%d" , &opcao);
		
		switch(opcao){
			case 1:
				total_id = cadastrar_dados_pessoa(Pessoas, total_id);
				break;
			case 2:
				tam_matriz = ler_tamanho_matriz();
				criar_matriz(&matriz_sequencia_DNA, tam_matriz);
				imprimir_matriz(&matriz_sequencia_DNA, tam_matriz);
				resultado=is_simian(&matriz_sequencia_DNA, tam_matriz);
				printf("Qual e o id da pessoa:");
				scanf("%i", &id_pessoa);
				visualizar_resultado(Pessoas, resultado, id_pessoa);
				break;
			case 3:
				criar_arquivo_matriz(&matriz_sequencia_DNA, tam_matriz);
				break;
			case 4:
				nome_arquivo=(char *)malloc (TAM_DIR*sizeof(char));	
				printf("Digite o nome do arquivo selecionado\n");
				scanf("%s" , nome_arquivo);
				tam_matriz= criar_matriz_com_arquivo(nome_arquivo, &matriz_sequencia_DNA);
				if(tam_matriz!=-1){
					imprimir_matriz(&matriz_sequencia_DNA, tam_matriz);
					resultado=is_simian(&matriz_sequencia_DNA, tam_matriz);
					printf("Qual e o id da pessoa:");
					scanf("%i", &id_pessoa);
					visualizar_resultado(Pessoas, resultado, id_pessoa);
				}			
				break;
			case 5:
				liberar_memoria(matriz_sequencia_DNA, tam_matriz);
				break;
			case 6:
				printf("Saindo...\n");
				break;
			default:
				printf("Opcao invalida\n");
				printf("Saindo...\n");
				opcao=6;
		};
		
		if(opcao>=1 && opcao<=5){
			printf("Continuar?(s ou n)");
			scanf(" %c" , &continuar);	
			
			if(continuar!='s'){
				printf("Saindo...\n");
				opcao=6;
			}
		}
			
	}while(opcao!=6);
	
	return 0;	
}

//impressão do menu
void imprimir_menu(){ 
	printf("|_________________________________________________|\n");
	printf("|               Verificacao de DNA                |\n");
	printf("|_________________________________________________|\n");
	printf("| Escolha uma das funcionalidades abaixo          |\n");
	printf("| (1) => Criacao do cadastro da pessoa            |\n");		
	printf("| (2) => Criacao da matriz e verificacao          |\n");
	printf("| (3) => Salvar arquivo da matriz armazenada      |\n");
	printf("| (4) => Leitura do arquivo escolhido             |\n");
	printf("| (5) => Liberacao de memoria da matriz           |\n");
	printf("| (6) => Sair                                     |\n");
	printf("|_________________________________________________|\n\n");

}

//cadastro das pessoas
int cadastrar_dados_pessoa(pessoa Pessoas[], int total_id){
	printf("ID: %i\n", total_id);
	printf("Digite o nome da pessoa:\n");
	scanf("%s", Pessoas[total_id].nome);
	printf("Digite a data de nascimento da pessoa:\n");
	scanf("%s", Pessoas[total_id].data_nascimento);
	printf("Digite a cidade da pessoa:\n");
	scanf("%s", Pessoas[total_id].cidade);
	
	return total_id+1;	
}
//ler cadastro das pessoas
void ler_dados_pessoa(pessoa Pessoas[], int id_pessoa){
	printf("Nome da pessoa: %s\n", Pessoas[id_pessoa].nome);
	printf("Data de nascimento da pessoa: %s\n", Pessoas[id_pessoa].data_nascimento);
	printf("Cidade da pessoa: %s\n", Pessoas[id_pessoa].cidade);
	printf("Resultado: %i\n", Pessoas[id_pessoa].resultado);
	
}

//ler tamanho da matriz
int ler_tamanho_matriz(){
	int tam_matriz=0;
		 
	printf("Passo (1) => Digite o tamanho da matriz (quadrada) de DNA: ");
	scanf("%i" ,&tam_matriz);
	
	return tam_matriz;
}

//criar matriz dinamicamente com ponteiro,e preenchimento da matriz alocando em cada posicao
void criar_matriz(char ***matriz, int tamanho){
	//criando as linha matriz
	*matriz = (char **) malloc (tamanho*sizeof(char *));
	
	//em cada linha criando as suas colunas
	for(int i=0; i<tamanho; i++){
		(*matriz)[i]=(char *)malloc (tamanho*sizeof(char));	
	}
	
	//leitura dos dados
	for(int i=0; i<tamanho; i++){
		for(int j=0; j<tamanho; j++){
			scanf(" %c" , &(*matriz)[i][j]);	
			
			while(tolower((*matriz)[i][j]) != 'a' && tolower((*matriz)[i][j]) != 't' && tolower((*matriz)[i][j]) != 'c' && tolower((*matriz)[i][j]) != 'g'){
				printf("Letra invalida\n");
				printf("Digite a letra novamente:\n");
				scanf(" %c" , &(*matriz)[i][j]);	
			}
		}
	}
	printf("Matriz criada com sucesso\n");	
} 

//impressão da matriz
void imprimir_matriz(char ***matriz, int tamanho){
	printf("Matriz de sequencia de DNA: \n");
	
	for(int i=0; i<tamanho; i++){
		printf("\n");
		for(int j=0; j<tamanho; j++){
			printf("%c\t" , (*matriz)[i][j]);
		}
	}
	
	printf("\n");
	
}

//criar arquivo para alocar a matriz 
void criar_arquivo_matriz(char ***matriz, int tamanho){
	FILE *arquivo;
	
	if ((arquivo = fopen("C:\\Users\\gui_b\\Desktop\\algoritmos\\arquivo\\arquivo.txt", "w")) == NULL){
    	printf("Nao foi possivel criar o arquivo de DNA\n");
    }else{
    	fprintf(arquivo, "%i %i\n" , tamanho, tamanho);
		
		for(int i = 0; i < tamanho; i++){
	       	for (int j = 0; j<tamanho; j++){
	       		if(j!=0){
	       			fprintf(arquivo, " ");
				}
				   
	       	    fprintf(arquivo, "%c", (*matriz)[i][j]);
	        }
	        fprintf(arquivo, "\n");
	    }
	    fclose(arquivo);
	    printf("Arquivo criado com sucesso\n");
    }
}

//comparacao para saber se é simio 
int is_simian(char ***matriz, int tamanho){

	if(verificar_linhas(matriz, tamanho)==1){
		return 1;
	}
	
	if(verificar_colunas(matriz, tamanho)==1){
		return 1;
	}
	
	if(verificar_diagonais_principais(matriz, tamanho)==1){
		return 1;
	}
	
	if(verificar_diagonais_secundarias(matriz, tamanho)==1){
		return 1;
	}
	
	return 0;	
}


int verificar_linhas(char ***matriz, int tamanho){
	int elementos_corretos;
	char elemento_anterior;
	
	
	for(int i=0; i<tamanho; i++){
		elemento_anterior=(*matriz)[i][0];
		elementos_corretos=1;
		for(int j=1; j<tamanho; j++){
			if((*matriz)[i][j]==elemento_anterior){
				elementos_corretos+=1;
				if(elementos_corretos==4){
					return 1;
				}
			}else{
				elemento_anterior=(*matriz)[i][j];
				elementos_corretos=1;
			}
		}
	}
	
	return 0;
}

int verificar_colunas(char ***matriz, int tamanho){
	int elementos_corretos;
	char elemento_anterior;
	
	//verifica colunas
	for(int i=0; i<tamanho; i++){
		elemento_anterior=(*matriz)[i][0];
		elementos_corretos=1;
		for(int j=1; j<tamanho; j++){
			if((*matriz)[j][i]==elemento_anterior){
				elementos_corretos+=1;
				if(elementos_corretos==4){
					return 1;
				}
			}else{
				elemento_anterior=(*matriz)[j][i];
				elementos_corretos=1;
			}
		}
	}
	return 0;
} 

int verificar_diagonais_principais(char ***matriz, int tamanho){
	int elementos_corretos;
	char elemento_anterior;
	
	//verifica diagonais principais
	for(int i=3; i<(tamanho*2-1)-3; i++){
		if(i<tamanho){
			elemento_anterior=(*matriz)[tamanho-1-i][0];
			elementos_corretos=1;
			
			for(int j=0; j<i+1; j++){
				if((*matriz)[tamanho-1-i+j][j]==elemento_anterior){
					elementos_corretos+=1;
					if(elementos_corretos==4){
						return 1;
					}
				}else{
					elemento_anterior=(*matriz)[tamanho-1-i+j][j];
					elementos_corretos=1;
				}		
			}	
		}else{
			elemento_anterior=(*matriz)[0][i+1-tamanho];
			elementos_corretos=1;
			
			for(int j=i+1-tamanho; j<2*tamanho-1-i; j++){
				if((*matriz)[j][j+1+i-tamanho]==elemento_anterior){
					elementos_corretos+=1;
					if(elementos_corretos==4){
						return 1;
					}
				}else{
					elemento_anterior=(*matriz)[j][j+1+i-tamanho];
					elementos_corretos=1;
				}	
			}
		}	
	}
	return 0;
}

int verificar_diagonais_secundarias(char ***matriz, int tamanho){
	int elementos_corretos;
	char elemento_anterior;
	
	//verifica diagonais secundarias
	for(int i=3; i<(tamanho*2-1)-3; i++){
		if(i<tamanho){
			elemento_anterior=(*matriz)[i][0];
			elementos_corretos=1;
			
			for(int j=0; j<i+1; j++){
				if((*matriz)[i-j][j]==elemento_anterior){
					elementos_corretos+=1;
					if(elementos_corretos==4){
						return 1;
					}
				}else{
					elemento_anterior=(*matriz)[i-j][j];
					elementos_corretos=1;
				}		
			}	
		}else{
			elemento_anterior=(*matriz)[tamanho-1][i+1-tamanho];
			elementos_corretos=1;
			
			for(int j=i+1-tamanho; j<2*tamanho-1-i; j++){
				if((*matriz)[tamanho-1-j][j+1+i-tamanho]==elemento_anterior){
					elementos_corretos+=1;
					if(elementos_corretos==4){
						return 1;
					}
				}else{
					elemento_anterior=(*matriz)[tamanho-1-j][j+1+i-tamanho];
					elementos_corretos=1;
				}	
			}
		}	
	}

	return 0;
}

//compara o resultado e mostra a resposta
void visualizar_resultado(pessoa Pessoas[], int resultado, int id){
	Pessoas[id].resultado=resultado;
	ler_dados_pessoa(Pessoas, id);
	if(Pessoas[id].resultado==1){
		printf("A matriz apresenta uma ou mais sequencias de quatro letras iguais\n");
		printf("Simio\n");
	}else{
		printf("A matriz nao apresenta uma ou mais sequencias de quatro letras iguais\n");	
		printf("Humano\n");
	}
}

//libera a memoria
void liberar_memoria(char **matriz, int tamanho){
	
	for(int i=0; i<tamanho; i++){
		free(matriz[i]);	
	}
	
	free(matriz);
	printf("Memoria liberada com sucesso\n");
	
}

//realiza a criacao da matriz dinamicamente com o diretorio do arquivo existente 
int criar_matriz_com_arquivo(char *nome_arquivo, char ***matriz){
	FILE *arquivo;
	int tamanho=-1, linha=0;
	char c;
	
	if ((arquivo = fopen(nome_arquivo, "r")) == NULL){
    	printf("Nao foi possivel ler o arquivo selecionado\n");
    	return -1;
    }else{
    	fscanf(arquivo ,"%d", &tamanho);
    	*matriz = (char **) malloc (tamanho*sizeof(char *));
		
		for(int i=0; i<tamanho; i++){
			(*matriz)[i]=(char *)malloc (tamanho*sizeof(char));	
		}
		//depois de fazer a leitura do tamanho da matriz e alocala dinamincamento foi movido o ponteiro de leitura do arquivo 
		//para o inicio da linha 1 (considerando que o arquivo comeca na linha 0)	
		while(linha<1 &&(c=fgetc(arquivo))!=EOF){
			if(c=='\n'){
				linha++;
			}
		}
		for(int i=0; i<tamanho; i++){
			for(int j=0; j<tamanho; j++){
				if(j!=0){
	       			fscanf(arquivo, " ", &c);
				}
				fscanf(arquivo, "%c" , &(*matriz)[i][j]);	
			
				if(tolower((*matriz)[i][j]) != 'a' && tolower((*matriz)[i][j]) != 't' && tolower((*matriz)[i][j]) != 'c' && tolower((*matriz)[i][j]) != 'g'){
					printf("Letras invalidas no arquivo\n");
					printf("Arquivo invalido\n");
					return -1;
				}
			}
			
			while(linha<i+2 &&(c=fgetc(arquivo))!=EOF){
				if(c=='\n'){
					linha++;
				}	
			}
		}	
		printf("Matriz criada com sucesso\n");		
	    fclose(arquivo);
	    
    }

	return tamanho;
}









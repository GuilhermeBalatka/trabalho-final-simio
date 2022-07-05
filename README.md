# trabalho-final-simio
	
	Para executar o programa siga o passo-a-passo abaixo
		Passo (1) - Realize o cadastro de pelo menos uma pessoa no sistema utilizando a respectiva(1) função no menu;
		Passo (2) - Realiza a criacao da matriz com os valores desejaveis(A, T, G, C) utilizando a funcao(2) no menu;
		Passo (3) - Opcional, caso queira criar um arquivo com os valores armazenados na matriz ultilize a funcao(3),
			    o nome do arquivo salvo sera arquivo.txt e sera salvo na pasta \arquivo onde esta localizado o diretorio do aquivo ;
		Passo (4) - Opcional, caso ja tenho um arquivo txt digite o diretorio do arquivo, entao sera armazenado na matriz;
		Passo (5) - Para criar outra matriz e importante liberar a memoria alocada da matriz atual;
		Passo (6) - Sair do programa;
		
		
  	Exemplos para fazer teste com facilidade, numero do tamanho da matriz quadrada e cada elemento da matriz;
		linha
		->errado = 6 A T G C G A C A G T G C T T A T T T A G A C G G G C G T C A T C A C T G
		->certo = 6 C T G A G A C T A T G C T A T T G T A G A G G G C C C C T A T C A C T G

		coluna
		->errado = 6 A T G C G A C A G T G C T T G T T T A G A C G G G C A T C A T C A C T G
		->certo = 6 A T G C G A C A G T G C T T A T T T A G A C G G G C A T C A T C A C T G
		->certo2 = 6 A T G C G A C A G T G C T T G T T T A G A T G G G C A T C A T C A C T G

		diagonal principal
		->certo = 6 A T G C G A C A G T G C T T G T T T A G T C G G G C A T C A T C A C T G
		->errado = 6 A T G C G A C A G T G C T T G T T T A G T C G G G C A T C A T C A C T G 


		diagonal secundaria
		->certo = 6 A T G C T A C A G G G C T T G T T T A G A C G G G C A T C A T C A C T G
		->errado =6 A T G C G A C A G T G C T T G T T T A G A C G G G C A T C A T C A C T G
		
	Exemplo de diretorio onde arquivo ficara salvo
		"C:\\Users\\gui_b\\Desktop\\algoritmos\\arquivo\\arquivo.txt"
		
		

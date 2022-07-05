##Para executar o programa siga o passo-a-passo abaixo

	Passo (1) - Realize o cadastro de pelo menos uma pessoa no sistema utilizando a respectiva(1) função no menu;
	Passo (2) - Realiza a criação da matriz com os valores desejáveis(A, T, G, C) utilizando a função(2) no menu;
	Passo (3) - Opcional, caso queira criar um arquivo com os valores armazenados na matriz utilize a função(3),
		    o nome do arquivo salvo será arquivo.txt e será salvo na pasta \arquivo onde esta localizado o diretório do arquivo ;
	Passo (4) - Opcional, caso já tenho um arquivo txt digite o diretório do arquivo, então será armazenado na matriz;
	Passo (5) - Para criar outra matriz é importante liberar a memória alocada da matriz atual;
	Passo (6) - Sair do programa;
	

##Exemplos para fazer teste com facilidade, numero do tamanho da matriz quadrada e cada elemento da matriz;
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


	diagonal secundária
	->certo = 6 A T G C T A C A G G G C T T G T T T A G A C G G G C A T C A T C A C T G
	->errado =6 A T G C G A C A G T G C T T G T T T A G A C G G G C A T C A T C A C T G
	
##Exemplo de diretório onde arquivo ficará salvo
	"C:\\Users\\gui_b\\Desktop\\algoritmos\\arquivo\\arquivo.txt"


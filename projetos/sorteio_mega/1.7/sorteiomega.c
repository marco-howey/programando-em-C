/* 	
	Autor: Marco Antonio Alves Duarte - howey
	projeto: sorteio de numeros da mega -sena
	descrição: um software que sorteia 6 numeros distintos entre 1 a 60, de forma aleatoria.

	versão: 1.7.0
	data:07/10/2026
*/

#include<stdio.h>		// bibliotecas para o funcionamento do programa.
#include<stdlib.h>		
#include<stdbool.h>
#include<time.h>		// Biblioteca para puxar a hora do computador.
#include<conio.h>		// Biblioteca para ler a tecla sem scanf().
#include<windows.h>		// para as janelas de pop-up.

void sorteio();			// função do sorteio.
void fechar();			// função para fechar o programa.
void sorteio_p(int p_min,int p_max,int p_qtd, int p_repete, int p_ord); 

int main(void) {
	srand((unsigned int) time(NULL));	// sorteio de seed do rand.

	int menu_init = 0;		// variavel para seleção de menu principal.
	
	while(1) {		// inicia um loop.
		if(menu_init == 0) {		// exibição do menu 1 vez sem loop.
			system("cls");			// fazendo a limpeza da tela.
			printf("[1] Sorteio unico \n[2] varios sorteios \n[3] Sorteios Personalizado \n[ESC] Para sair\n\n");
			menu_init = 1;		// Declara que nao precisa mais imprimir na tela as opções.
		}
		
		int opc = getch();	// faz a leitura da tecla e armazena em OPC.
		
		if (opc == '1') {		// se a opção for 1.
			system("cls");
			printf("Sorteio Unico : \n");
			sorteio();		//Chama o sorteio. 
			printf("\n\n\n[1] Para voltar ao menu inicial \n[ESC] para sair \n");
			int b = 0;
			while (b == 0) {	// Aguarda uma resposta do teclado.
				int opc1 = getch();
				if (opc1 == '1') {
					menu_init = 0;
					b = 1;
				} else if(opc1 == 27) {
					fechar();
				} else {
					printf("Digite uma opcao valida!\n");
				}
			}
		} else if (opc == '2') {		// Se a opção for 2.
			system("cls");
			printf("Multiplos sorteios: [SPACE] para um novo sorteio [ESC] Para sair\n\n");
			int c = 0;
			
			while(c == 0) {		// inicia um loop.
				int opc3 = getch();
				if (opc3 == 32) {		// Espera a tecla SPACE para sortear.
				 	sorteio();
				} else if (opc3 == 27) {	// Espera a tecla ESC para fechar o programa.
					fechar();
				}
			}
		} else if (opc == '3') {
			system("cls");
			
			int v_minimo;		// Range minimo do sorteio.
			int v_maximo;		// Range Maximo do sorteio.
			int qtd_sorteio;	// Quantidade de numeros sorteados.
			bool repete;		// O sorteio se repete entre eles? 0 = repete, 1 = nao se repete.
			char temp_c;		// variavel temporaria 
			int ordem; 			// define a ordem 0 = crescente, 1 = decrescente, 2 = aleatorio.
			
			printf(" [Sorteio Personalizado] \n");
			printf(" Digite o numero inicial (o menor e 0) : ");
			scanf("%d", &v_minimo);
			printf("\n Digite o numero maximo (o limite e 9999) : ");
			scanf("%d", &v_maximo);
			printf("\n Digite a quantidade de pares de sorteio (o limite e 10) : ");
			scanf("%d", &qtd_sorteio);
			printf("\n Os pares se repetem em valores? \n [S] para repetir [N] nao repetir: ");
			while(1) {
				scanf(" %c", &temp_c);
				if (temp_c == 's' || temp_c == 'S') {
					repete = 1;
					break;
				} else if(temp_c == 'n' || temp_c == 'N') {
					repete = 0;
					break;
				} else {
					MessageBox(NULL, "Digite uma opcao valida!","Aviso do sistema",MB_OK);
				}
			}
			printf("\n Qual a ordem de apresentacao? [C] para crescente [D] para decrescente [A] para aleatorio: ");
			while(1) {
				scanf(" %c", &temp_c);
				if (temp_c == 'C' || temp_c == 'c') {
					ordem = 0;
					break;
				} else if (temp_c == 'D' || temp_c == 'd') {
					ordem = 1;
					break;
				} else if (temp_c == 'A' || temp_c == 'a') {
					ordem = 2;
					break;
				} else {
					MessageBox(NULL, "Digite uma opcao valida!","Aviso do sistema",MB_OK);
				}
			}
			system("cls");
			printf("Sorteio minimo %d maximo %d com %d numeros por sorteio e eles", v_minimo, v_maximo, qtd_sorteio);
			if (repete == 1) {
				printf(" se repetem.\n");
			} else {
				printf(" nao se repetem.\n");
			}
			printf("Aperte [SPACE] para novo sorteio [ESC] para sair.\n");
			while(1) {
				int opc4 = getch();
				if (opc4 == 32) {		// Espera a tecla SPACE para sortear.
				 	sorteio_p(v_minimo, v_maximo, qtd_sorteio, repete, ordem);
				} else if (opc4 == 27) {	// Espera a tecla ESC para fechar o programa.
					fechar();
				}
			}
		} else if (opc == 27) {		// se a opção for ESC.
			fechar();
		}
	}
	
	return 0;
}

void sorteio() {
	int i;
	int numeros[7];
	for (i = 0; i <= 6; i++) {
		numeros[i] = 0;
	}
	
	for (i = 1; i <= 6; i++) {
		if(numeros[i] == 0) {
			numeros[i] = (rand() % 60) + 1;
			for (int a = 1; a < i; a++) {
				if(numeros[i] == numeros[a]) {
					numeros[i] = (rand() % 60) + 1;
					a = 0;
				}
			}
		}
	}
	int temporario;
	int j;
	for (i = 1; i <= 6; i++) {
		for (j = i + 1; j <= 6; j++) {
			if (numeros[i] > numeros[j]) {
		 		temporario = numeros[i];
		 		numeros[i] = numeros[j];
		 		numeros[j] = temporario;
			}
		}
	}
	
	printf("Sorteio: %02d : %02d : %02d : %02d : %02d : %02d \n", numeros[1], numeros[2], numeros[3], numeros[4], numeros[5], numeros[6]);
}

void sorteio_p(int p_min, int p_max, int p_qtd, int p_repete, int p_ord) {
	int p_numeros[p_qtd + 1];
	int espaco_numeros = snprintf(NULL, 0, "%d", p_max);

	char prefix_p[] = "Sorteio:  ";
	char divisor_p[4] = {' ',':',' '};
	char quebra_p = '\n';
	
	int i;
	int p;
	int temporario;
	
	// É OBRIGATÓRIO zerar o array antes de iniciar o sorteio!
	for (i = 0; i <= p_qtd; i++) {
		p_numeros[i] = 0;
	}
		
	for (i = 1; i <= p_qtd; i++) { // Corrigido para i <= p_qtd
		if (p_numeros[i] == 0) {
			p_numeros[i] = (rand() % (p_max - p_min + 1)) + p_min;
			for (int a = 1; a < i; a++) {
				if (p_repete == 0) {
					if (p_numeros[i] == p_numeros[a]) {
						p_numeros[i] = (rand() % (p_max - p_min + 1)) + p_min;
						a = 0;
					}
				}
			}
		}
	}
	
	if (p_ord == 0) {
		for (i = 1; i <= p_qtd; i++) {
			for (p = i + 1; p <= p_qtd; p++) {
				if(p_numeros[i] > p_numeros[p]) {
					temporario = p_numeros[i];
					p_numeros[i] = p_numeros[p];
					p_numeros[p] = temporario;
				}
			}
		}
	} else if (p_ord == 1) {
		for (i = 1; i <= p_qtd; i++) {
			for (p = i + 1; p <= p_qtd; p++) {
				if(p_numeros[i] < p_numeros[p]) {
					temporario = p_numeros[i];
					p_numeros[i] = p_numeros[p];
					p_numeros[p] = temporario;
				}
			}
		}
	}
	
	printf("\nSorteio: %0*d", espaco_numeros, p_numeros[1]);
	for (i = 2; i <= p_qtd; i++) {
		printf(" : %0*d", espaco_numeros, p_numeros[i]);
	}
	printf("\n");
}

void fechar() {
	system("cls");
	printf("Saindo...\n");
	exit(0);
}

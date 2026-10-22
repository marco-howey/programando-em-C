/* 	
	Autor: Marco Antonio Alves Duarte - howey
	projeto: sorteio de numeros da mega -sena
	descrição: um sofware que sorteia 6 numeros distindos entre 1 a 60, de forma aleatoria.

	versão: 1.5.0
	data:04/10/2026
*/

#include<stdio.h>		// bibliotecas para o funcionamento do programa.
#include<stdlib.h>		
#include<time.h>		// Biblioteca para puxar a hora do computador.
#include<conio.h>		// Biblioteca para ler a tecla sem scanf().

void sorteio();		// função do sorteio.
void fechar();		// função para fechar o programa.

main(void) {
	srand((unsigned int) time(NULL));	// sorteio de seed do rand.

	int menu_init;		// variavel para seleção de menu principal.
	menu_init = 0;
	
	while(1)	{		// inicia um loop.
		if(menu_init == 0) {		// exibição do menu 1 vez sem loop.
			system("cls");			// fazendo alimpesa da tela.
			printf("[1] Sorteio unico \n[2] varios sorteios  \n[ESC] Para sair \n\n");		// texto informativo de opções.
			menu_init = 1;		// Declara que nao ´recisa mais imprimir na tela as opções.
		}
		int opc = getch();	// faz a leitura da tecla e armazena em OPC.
		
		if (opc == '1')	{		// se a opção for 1.
			system("cls");
			printf("Sorteio Unico : \n");
			sorteio();		//Chama o sorteio. 
			printf("\n\n\n[1] Para voltar ao menu inicial \n[ESQ] para sair \n");
			int b = 0;
			while (b  == 0){	// Aguarda uma resposta do tecaldo.
				int opc1 = getch();
				if (opc1 == '1')	{
					menu_init = 0;
					b = 1;
				}else if(opc1 == 27)	{
					fechar();
				}else {
					printf("Digite uma opção valida!\n");
				}
			}
		}else if (opc == '2'){		// Se a opção for 2.
			system("cls");
			printf("Multiplos sorteios: [SPACE] para um novo sorteio [ESC] Para sair\n\n");
			int c = 0;
			
			while(c == 0)	{		// inicia um loop.
				int opc3 = getch();
				 if ( opc3 == 32)	{		// Espera a tecla SPACE para sortear.
				 	sorteio();
				}else if (opc3 == 27)	{	// Espera a tecla ESC para fechar o programa.
					fechar();
				}
				
			}
		}else if (opc == 27)	{		// se a opção for ESC.
			fechar();
		}
	}
	
	
	
	return 0;
}
sorteio()	{
	int i;
	int numeros[7];
	for (i = 0;i <=6;i ++){
		numeros[i] = 0;
	}
	
	for ( i = 1;i <= 6; i++)	{
		if(numeros[i] == 0) {
			numeros[i] = (rand() % 60) +1;
			for (int a = 1;a < i; a++) {
				if(numeros[i] == numeros[a])	{
					numeros[i] = (rand() %60) + 1;
					a = 0;
				}
			}
		}
	}
	int temporario;
	int j;
	for (i = 1; i <= 6	; i++)	{
		for (j = i + 1; j <= 6; j++)	{
				if (numeros[i] > numeros[j])	{
			  		temporario = numeros[i];
			  		numeros[i] = numeros[j];
			  		numeros[j] = temporario;
				}
			}
		}
	
	printf("Sorteio: %02d : %02d : %02d : %02d : %02d : %02d \n",numeros[1],numeros[2],numeros[3],numeros[4],numeros[5],numeros[6]);
}
fechar()	{
	system("cls");
	system("pause");
	exit(0);
}

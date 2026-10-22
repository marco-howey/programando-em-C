/* 	
	Autor: Marco Antonio Alves Duarte - howey
	projeto: sorteio de numeros da mega -sena
	descrição: um sofware que sorteia 6 numeros distindos entre 1 a 60, de forma aleatoria.

	versão: 1.0.0
	data:04/10/2026
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



main(void) {
	srand((unsigned int) time(NULL));
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
	
	printf("Sorteio: %d : %d : %d : %d :%d : %d \n",numeros[1],numeros[2],numeros[3],numeros[4],numeros[5],numeros[6]);
	system("pause");
	return 0;
}

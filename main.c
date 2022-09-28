#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main() {
	
	Contato *agenda[LIMIT];
	char arquivo[] = {"agenda.txt"};
	int tam = LIMIT, quant = 0, opcao;

	do {
		showMenu();

		scanf("%d", &opcao);
		getchar();

		switch (opcao) {
			case 1:
				quant += cadastrar_contato(agenda, quant, tam);
				break;
			case 2:
				alterar_contato(agenda, quant);
				break;
			case 3:
				imprimir(agenda, quant);
				break;
			case 4:
				salvar(agenda, quant, arquivo);
				break;
			case 5:

				break;
			default:
				if( opcao != 0 ) {
					printf("\nOpção inválida!\n");
				}	
		}
	} while (opcao != 0);
	
	return 0;
}
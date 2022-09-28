#ifndef FUNCS
#define FUNCS

#define LIMIT 50

typedef struct{
	char nome[50];
	int dia, mes, ano;
}Contato;

void imprimir( Contato **c, int quant ){
	
	printf("\n\t\tLista de Contatos:\n");
	printf("\t--------------------------------\n");
	for( int i = 0; i < quant; ++i){
		printf("\t%d = %2d/%2d/%4d\t%s\n", i + 1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
	}
	printf("\t--------------------------------\n");
}

int cadastrar_contato( Contato **c, int quant, int tam ){

	if(quant < tam){
		
		Contato *novo = malloc(sizeof(Contato));
		printf("\nDigite o nome do contato: ");
		scanf("%50[^\n]", novo->nome);
		printf("\nDigite a data de aniversário [dd mm aaaa]: ");
		scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();
		c[quant] = novo;
		
		return 1;
	} else{
		printf("\nNão foi possível realizar novo cadastro");
		printf("\nVetor cheio!");
		return 0;

	}
}

void alterar_contato( Contato **c, int quant ){

	int id;
	imprimir(c, quant);
	printf("\n\tDigite o código do contato que deseja alterar:\n");
	scanf("%d", &id);
	getchar();
	id--;

	if( id >= 0 && id < quant ){
		Contato *novo = malloc(sizeof(Contato));

		printf("\nDigite o nome do contato: ");
		scanf("%50[^\n]", novo->nome);
		printf("\nDigite a data de aniversário [dd mm aaaa]: ");
		scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();
		c[id] = novo;

	}else{
		printf("\n\tCódigo inválido\n");
	}
}

void salvar( Contato **c, int quant, char arq[] ){
	FILE *file = fopen(arq, "w");
	int i;
	if( file ){
		fprintf(file, "%d\n", quant);
		for( i = 0; i < quant; i++ ){
			fputs(c[i]->nome, file);
			fputc('\n', file);
			fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
		}
		fclose(file);
	}else{
		printf("\n\tNão possível abrir/criar o arquivo!\n");
	}
}

#endif

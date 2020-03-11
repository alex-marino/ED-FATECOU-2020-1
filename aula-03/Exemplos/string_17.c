char* lelinha (void){
	char linha[121]; /* variável auxiliar para ler linha */
	printf("Digite um nome: ");
	scanf(" %120[^\n]",linha);
	return duplica(linha);
}

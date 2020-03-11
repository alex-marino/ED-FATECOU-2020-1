void concatena (char* dest, char* orig){
	int i = 0; 	/* índice usado na cadeia destino, inicializado com zero */
	int j; 		/* índice usado na cadeia origem */
	/* acha o final da cadeia destino */
	i = 0;
	while (dest[i] != '\0')
		i++;
		/* copia elementos da origem para o final do destino */
	for (j=0; orig[j] != '\0'; j++){ 
		dest[i] = orig[j]; i++; 
	}
	/* fecha cadeia destino */
	dest[i] = '\0';
}

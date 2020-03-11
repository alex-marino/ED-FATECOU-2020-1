void copia (char* dest, char* orig){
	int i;
	for (i=0; orig[i] != '\0'; i++)
	dest[i] = orig[i];
	/* fecha a cadeia copiada */
	dest[i] = ’\0’;
}
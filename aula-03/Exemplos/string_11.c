int compara (char* s1, char* s2){
	int i;
	/* compara caractere por caractere */
	for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++) {
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	/* compara se cadeias têm o mesmo comprimento */
	if (s1[i]==s2[i])
		/* cadeias iguais */
		return 0;
	else if (s2[i]!= '\0')
		/* s1 é menor, pois tem menos caracteres */
		return -1;
	else
	/* s2 é menor, pois tem menos caracteres */
		return 1;
}

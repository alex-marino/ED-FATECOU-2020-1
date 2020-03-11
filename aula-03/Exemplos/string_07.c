int comprimento (char* s){
	int i;
	int n = 0; /* contador */
	for (i=0; s[i] != '\0'; i++)
	n++;
	return n;
}
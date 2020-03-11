int lenomes (char** alunos){ 
	int i, n;
	do { 
		printf("Digite o numero de alunos: ");
		scanf("%d",&n);
	} while (n>MAX);
	for (i=0; i<n; i++)
		alunos[i] = lelinha();
	return n;
}

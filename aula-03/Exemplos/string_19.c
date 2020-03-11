void liberanomes (int n, char** alunos){
	int i;
	for (i=0; i<n; i++)
		free(alunos[i]);
}

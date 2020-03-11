#define MAX 50

int main (void){
	char* alunos[MAX];
	int n = lenomes(alunos);
	imprimenomes(n,alunos);
	liberanomes(n,alunos);
	return 0;
}

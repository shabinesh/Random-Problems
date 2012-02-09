int main()
{
	int testcase;
	char string1[10][100000], substr1[10][100000];
	char *string, *substr;
	int slen, tlen, found;
	int i, j, error = 0, quit = 0, k;

	scanf("%d\n", &testcase);
	for (i = 0; i < testcase; i++) {
		string = string1[i], substr = substr1[i];
		scanf("%s\n%s\n", string, substr);
	}

	for (k = 0; k < testcase; k++) {
		string = string1[k], substr = substr1[k];
		slen = strlen(string);
		tlen = strlen(substr);
		quit = 0;
		for (i = 0; i < slen && !quit; i++) {
			found = 1;
			error = 0;
			for (j = 0; j < tlen; j++) {
				if (i + j >= slen) {
					quit = 1;
					break;
				}
				if (string[i + j] != substr[j])
					error++;
				if (error > 2) {
					found = 0;
					break;
				}
			}
			if (found && error < 2 && j == tlen) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}

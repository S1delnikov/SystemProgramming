#include <stdio.h>
#include <pthread.h>

void* shifr(void *file_name)
{
	FILE *src, *dest;
	src = fopen(file_name, "r");
	dest = fopen("ON.txt", "w");
	int c;
	
	while((c = fgetc(src)) != EOF)
	{	
		if (c != '\n')
			fputc(c + 8, dest);
		else
			fputc(c, dest);
	}
	fclose(src);
	fclose(dest);
}

void* deshifr(void *file_name)
{
	FILE *src, *dest;
	src = fopen(file_name, "r");
	dest = fopen("OFF.txt", "w");
	int c;
	
	while((c = fgetc(src)) != EOF)
	{
		if(c != '\n')
			fputc(c - 8, dest);
		else
			fputc(c, dest);
	}
	fclose(src);
	fclose(dest);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Need 1 more argument\n");
		return 1;
	}	
		
	pthread_t to, from;
	
	pthread_create(&to, NULL, shifr, argv[1]);
	pthread_join(to, NULL);
	
	pthread_create(&from, NULL, deshifr, "ON.txt");
	pthread_join(from, NULL);
	
	FILE *src, *fst, *scd, *results;
	
	src = fopen(argv[1], "r");
	fst = fopen("ON.txt", "r");
	scd = fopen("OFF.txt", "r");
	results = fopen("results.txt", "w");
	
	fputs("SOURCE FILE:\n\n", results);
	
	int c;

	while((c = fgetc(src)) != EOF)
		fputc(c, results);
	
	fputs("\n_____________________________________\n", results);
	fputs("ENCRYPTED FILE:\n\n", results);
	
	while((c = fgetc(fst)) != EOF)
		fputc(c, results);
	
	fputs("\n_____________________________________\n", results);
	fputs("DECRYPTED FILE:\n\n", results);

	while((c = fgetc(scd)) != EOF)
		fputc(c, results);
	
	fclose(src);
	fclose(fst);
	fclose(scd);
	fclose(results);
	
	results = fopen("results.txt", "r");
	
	while((c = fgetc(results)) != EOF)
		printf("%c", c);
		
	fclose(results);
	
	return 0;
}

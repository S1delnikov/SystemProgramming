#include <stdio.h>

int main()
{
	char info[][30] = {"Misha", "Sidelnikov", "POKS-31", "18 y.o"};
	char buff[1000];

	FILE *fp;

	fp = fopen("WhoAmI.txt", "w");
	for(int i = 0; i <= sizeof(info)/sizeof(*info); i++)
		fprintf(fp, "%s\n", info[i]);

	fclose(fp);
	
	fp = fopen("WhoAmI.txt", "r");

	while(!feof(fp))
	{
		if (fgets(buff, 1000,  fp) != NULL)
			printf("%s", buff);
	}
	fclose(fp);
	return 0;
}

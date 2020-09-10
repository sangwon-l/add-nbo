#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("argv error \n");
		return 0;
	}
	
	FILE *pFile1, *pFile2;
	uint32_t pval1, pval2;
	size_t result;
	
	pFile1 = fopen(argv[1], "r");
	pFile2 = fopen(argv[2], "r");

	if((pFile1 == NULL) || (pFile2 == NULL)){
		printf("File error \n");
		return 0;
	}

	result = fread(&pval1, 1, sizeof(uint32_t), pFile1);
	if(result != sizeof(uint32_t)){
		printf("file read error \n");
		return 0;
	}

	result = fread(&pval2, 1, sizeof(uint32_t), pFile2);
	if(result != sizeof(uint32_t)){
		printf("file read error \n");
		return 0;
	}

	pval1 = ntohl(pval1);
	pval2 = ntohl(pval2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x) \n", pval1, pval1, pval2, pval2, pval1+pval2, pval1+pval2);
	
	fclose(pFile1);
	fclose(pFile2);
	return 0;
}


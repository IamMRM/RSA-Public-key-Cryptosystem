/*

Author : Muhammad Roshan Mughees
Section: BSCS-6A
Registration no.: 193590

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<math.h>

int ef = 17;
int n = 3233;
int d = 2753;

int alphabet(char a);
char alpha(int a);
int encrypt_decrypt(unsigned long long int base, unsigned long long int exp, unsigned long long int n);

int main()
{
	printf("+-----------------------------+\n");
	printf("| RSA Public-key Cryptosystem |\n");
	printf("+-----------------------------+\n\n\n");
	printf("+-------------------+\n");
	printf("| I. Key Generation |\n");
	printf("+-------------------+\n\n\n");
	printf(" Public key. (e,n) = (17,3233)\n Private key. (d,n) = (2753,3233)\n\n");
	printf("+-------------------------+\n");
	printf("| II. Cipher and Decipher |\n");
	printf("+-------------------------+\n\n\n");
	int i,b;
	printf("Enter the code\n");
	char a[30];
	gets(a);
	int k = 2;
/**************************************************************************/
	int we;
	int w = 0;
	int m[30][30];
	int y = strlen(a);
	if (strlen(a) % 2 != 0) { y++; }
	printf("Input. \n|");
	for (i = 0; i<(y/k); i++)
	{
		for (we = 0; we<k; we++)
		{
			m[i][we] = a[w];
			printf("'%c'|",m[i][we]);
			w++;
		}
	}



/*************************************************************************/
	int j[30][30];
	printf("\n|");
	for(i=0; i<y/k;i++){
		for(b=0;b<k;b++){
			j[i][b] = alphabet(m[i][b]);
			printf(" %d|", j[i][b]);
		}
	}

	/****************************just for printing*********************************************/
	printf("\n\nM.    |");
	for (i = 0; i < (y / k); i++)
	{
		for (we = 0; we < k; we++)
		{
			printf("%c", m[i][we]);
		}printf(" |");
	}
	printf("\nP(M). |");
	for (i = 0; i < y / k; i++) {
		for (b = 0; b < k; b++) {
			printf("%d", j[i][b]);
		}printf(" |");
	}printf("\n");
/**************************************************************************/	
	int P[30];
	for (i = 0; i < (y/k); i ++) {
		P[i] = j[i][0] * 100 + j[i][1];
	}
	
/*************************************************************************/
	int c[30];

	for (i = 0; i < strlen(a); i++) {
		c[i] = encrypt_decrypt(P[i], ef, n);
	}
	
/*************************************************************************/
	printf("C(P). | ");
	for (i = 0;  i < (y / k); i++) {
		printf("%d |", c[i]);
	}
	printf("\nD(C). | ");
/********************************decryption****************************************/
	for (i = 0; i < (y / k); i++) {
		printf("%d | ", P[i]);
	}
/***************************just for printing*******************************************/ 
	printf("\nM.    |");
	for (i = 0; i < (y / k); i++)
	{
		for (we = 0; we < k; we++)
		{
			printf("%c", m[i][we]);
		}printf(" |");
	}
	printf("\n\nOutput. \n");
	printf("\n|");
	for (i = 0; i<y / k; i++) {
		for (b = 0; b<k; b++) {
			j[i][b] = alphabet(m[i][b]);
			printf(" %d|", j[i][b]);
		}
	}
	printf("\n| ");
	for (i = 0; i<(y / k); i++)
	{
		for (we = 0; we<k; we++)
		{
			printf("'%c'|", m[i][we]);
		}
	}


	printf("\n");

	system("pause");
	return 0;
}

int alphabet(int a) {
	int i,j;
	int alphabetArray[28];
	for (i = 0,j=65; i < 26 && j<91 ; i++,j++) {
		alphabetArray[i] = j;
	}
	alphabetArray[26] = 32;  
	alphabetArray[27] = 46;
	for (i = 0; i <= 27 && alphabetArray[i] != a; i++) {}
	return i;
  }


char alpha(int a) {
	int i,j;
	int alphabetArray[28];
	for (i = 0,j=65; i < 26 && j<91 ; i++,j++) {
		alphabetArray[i] = j;
	}
	alphabetArray[26] = 32;  
	alphabetArray[27] = 46;

	return alphabetArray[a];
}

int encrypt_decrypt(unsigned long long int base, unsigned long long int exp, unsigned long long int n)
{
	unsigned long long int eM = 1;

	int count = 1;
	while (count <= exp)
	{
		eM = eM*base;
		eM = eM%n;
		count++;
	}

	return eM;
}

/*
Author: Magi Joy S. Larin
		2013-56443
Subject: CMSC 128 AB-3:
Date Created: March 9, 2016
Description: 	A library that will implement the following functionalities using the C programming language:
	1. Get Hamming Distance
	2. Count Substring Pattern
	3. Checks Validity of String
	4. Get Skew
	5. Get Maximum Skew N
	6. Get Minimum Skew N
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

/*
	1 Returns Hamming Distance
		The Hamming Distance of two strings is the number of characters that differ in ith position from position 1 to strlen(str1)
		Example:
			getHammingDistance(“AACCTT”,”GGCCTT”) returns 2
			getHammingDIstance(“TCGGA”,”AAAAG”) returns 5
			getHammingDistance(“A”,”AG”) returns “Error! Strings are not equal!”
*/
int getHammingDistance(char str1[], char str2[]){
	int count=0, i;
	for(i=0;i<strlen(str1); i++){
		if(str1[i] != str2[i]) count++;	//count different letters
	}
	return count;
}

/*
	2 Count Substring Pattern
		Given a string original and pattern, we will count the number of occurrence of pattern in original.
		Example:
		countSubstrPattern(“AATATATAGG”,”GG”) returns 1
		countSubstrPattern(“AATATATAGG”,”ATA”) returns 3
		countSubstrPattern(“AATATATAGG”,”ACTGACTGACTG”) returns 0
*/
int countSubstrPattern(char original[], char pattern[]){
	int count=0, i, j;

	for(i=0; i<strlen(original); i++){
		if(original[i] == pattern[0]){
			j=0;
			while(j < strlen(pattern)){
				if(original[i+j] != pattern[j]){
					break;
				}
				j++;
			}
			//previous while loop has found a substring similar to pattern
			if(j==strlen(pattern)) count++;
		}
	}

	return count;
}

/*
	3 Check if String is ValidS
		Given an alphabet string where all letters are assumed to be unique, this function returns true if the string str is a valid string based on the letters of alphabet.
		Example:
		isValidString(“AAGGCTATGC”,”ACGT”) returns true
		isValidString(“AAGGCTATGa”,”ACGT”) returns false
		isValidString(“ACGT”,”ACGT”) returns true
		isValidString(“ACGT101_”,”ACGT”) returns false
		isValidString(“091212345”,”0123456789”) returns true
*/
int isValidString(char str[], char alphabet[]){
	int i, j, temp=0;
	for(i=0; i<strlen(str); i++){
		temp = 0;
		for(j=0; j<strlen(alphabet); j++){
			if(str[i] == alphabet[j]){
				temp = 1;
				break;
			}
		}
		if(temp==0) return 0;	//a letter was not found in the alphabet
	}
	return 1;	//all the letters of the string is valid
}

/*
	4 Get Skew
		Given a genome str of some length q (where q>0), it returns the number of Gs minus the number of Cs in the first n nucleotides (q>=n). The value can be zero, negative or positive. The first position is one (1) not zero(0) as we typically associate with string implementations.
		Example:
		getSkew(“GGCCAC”, 1) returns 1
		getSkew(“GGCCAC”, 2) returns 2
		getSkew(“GGCCAC”, 3) returns 1
		getSkew(“GGCCAC”, 4) returns 0
		getSkew(“GGCCAC”, 5) returns 0
*/
int getSkew(char str[], int n){
	int i, count=0;
	for(i=0; i<n; i++){
		if(str[i] == 'G') count++;
		if(str[i] == 'C') count--;
	}
	return count;	//count of Gs minus Cs
}

/*
	5 Get Maximum Skew N
		Given a genome str of some length q (where q>0), it returns the maximum value of the number of Gs minus the number of Cs in the first n nucleotides (q>=n). The value can be zero, negative or positive. The first position is one (1) not zero(0) as we typically associate with string implementations.
		Example:
		getMaxSkewN(“GGCCAC”, 1) returns 1
		getMaxSkewN(“GGCCAC”, 2) returns 2
		getMaxSkewN(“GGCCAC”, 3) returns 2
		getMaxSkewN(“GGCCAC”, 4) returns 2
		getMaxSkewN(“GGCCAC”, 5) returns 2
*/
int getMaxSkewN(char str[], int n){
	int i, count=0;
	for(i=0; i<n; i++){
		if(str[i] == 'G') count++;
	}
	return count;  //count of Gs
}

/*
	6 Get Mininum Skew N
		Given a genome str of some length q (where q>0), it returns the minimum value of the number of Gs minus the number of Cs in the first n nucleotides (q>=n). The value can be zero, negative or positive. The first position is one (1) not zero(0) as we typically associate with string implementations.
		Example:
		getMinSkewN(“GGCCAC”, 1) returns 1
		getMinSkewN(“GGCCAC”, 2) returns 1
		getMinSkewN(“GGCCAC”, 3) returns 1
		getMinSkewN(“GGCCAC”, 4) returns 0
		getMinSkewN(“GGCCAC”, 5) returns 0

*/
int getMinSkewN(char str[], int n){
	int i, count=0;
	for(i=0; i<n; i++){
		if(str[i] == 'G') count++;
		if(str[i] == 'C') count--;
	}
	
	if(count >= 1)return 1; //minimum count of Gs minus Cs
	else return count; 	//0 or negative
}

main(){
	char str1[50], str2[50];
	int num;

	/* 	1. Hamming Distance
	printf("Input 2 Strings:\n");
	scanf("%s", str1);
	scanf("%s", str2);
	if(strlen(str2) != strlen(str1)){
		printf("Error! Strings are not equal!");
	}else{
		printf("%d", getHammingDistance(str1, str2));
	}
	*/

	/*	2. Count Substring Pattern
	printf("Input Original:\n");
	scanf("%s", str1);
	printf("Input Pattern:\n");
	scanf("%s", str2);
	if(strlen(str2) > strlen(str1)){
		printf("Error! Pattern's length is longer than Original's!");
	}else{
		printf("%d", countSubstrPattern(str1, str2));
	}
	*/

	/* 	3. Validate String
	printf("Input String:\n");
	scanf("%s", str1);
	printf("Input Alphabet:\n");
	scanf("%s", str2);
	if(isValidString(str1, str2)) printf("TRUE!");
	else printf("FALSE!");
	*/

	/*	4. Get Skew
	printf("Input String:\n");
	scanf("%s", str1);
	printf("Input Position:\n");
	scanf("%d", &num);
	if(strlen(str1) < num){
		printf("Error! Position exceeds String length!");
	}else{
		printf("%d", getSkew(str1, num));
	}
	*/

	/*	5. Get Max Skew
	printf("Input String:\n");
	scanf("%s", str1);
	printf("Input Position:\n");
	scanf("%d", &num);
	if(strlen(str1) < num){
		printf("Error! Position exceeds String length!");
	}else{
		printf("%d", getMaxSkewN(str1, num));
	}
	*/

	/*	6. Get Min Skew
	printf("Input String:\n");
	scanf("%s", str1);
	printf("Input Position:\n");
	scanf("%d", &num);
	if(strlen(str1) < num){
		printf("Error! Position exceeds String length!");
	}else{
		printf("%d", getMinSkewN(str1, num));
	}
	*/
}

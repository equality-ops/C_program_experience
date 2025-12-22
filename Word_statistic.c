//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<ctype.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define N 100
//#define LEN 10
//
//int Extract_words(char words[][N], char English_string[]);
//void Read_word_size(char words[][N], int word_size_record[], int word_count);
//int main() {
//	char English_string[N];
//	char words[N/LEN][N];
//	int* word_size_record = NULL;
//	int word_count = 0;
//	int dif_sum = 0;
//	gets(English_string);
//	word_count = Extract_words(words, English_string);
//	word_size_record = (int*)calloc(word_count, sizeof(int));
//	if (word_size_record == NULL) {
//		printf("No enough memory to allocate!");
//		exit(0);
//	}
//	Read_word_size(words, word_size_record, word_count);
//	for (int i = 0; i < word_count; i++) {
//		dif_sum += word_size_record[i];
//	}
//	printf("%d", dif_sum);
//	return 0;
//}
//
//int Extract_words(char words[][N], char English_string[]) {
//	int i = 0;
//	int word_count = 0;
//	int word_lenth = 0;
//	while (English_string[i] != '\0') {
//		while (!isalpha((unsigned char)English_string[i])) {
//			if (English_string[i] == '\0') {
//				goto out;
//			}
//			i++;
//		}
//		while (isalpha((unsigned char)English_string[i])) {
//			English_string[i] = tolower(English_string[i]);
//			words[word_count][word_lenth++] = English_string[i++];
//		}
//		words[word_count][word_lenth] = '\0';
//		word_count++;
//		word_lenth = 0;
//	}
//	out:
//	return word_count;
//}
//
//void Read_word_size(char words[][N], int word_size_record[], int word_count) {
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < word_count; i++) {
//		word_size_record[i] = 1;
//	}
//	for (i = 0; i < word_count - 1; i++) {
//		for (j = i + 1; j < word_count; j++) {
//			if (word_size_record[i] == 0) {
//				break;
//			}
//			if (strcmp(words[i], words[j]) == 0) {
//				word_size_record[j] = 0;
//			}
//		}
//	}
//}
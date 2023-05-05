#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getCharCount(FILE *fp){
    int count = 0;
    char c = fgetc(fp);
    while(c != EOF){
        count++;
        c = fgetc(fp);
    }
    return count;
}

int getWordCount(FILE *fp){
    int count = 0;
    char c = fgetc(fp);
    while(c != EOF){
        if(c == ' ' || c == '\n' || c == '\t' || c == ','){
            count++;
        }
        c = fgetc(fp);
    }
    return count;
}

int main(int argc, char* argv[]) {
    if(argc > 3){
        printf("�����������\n");
        return 0;
    }
    char* fileName = "input.txt";
    if(argc == 3){
        fileName = argv[2];
    }
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("���ļ�ʧ�ܣ�\n");
        return 0;
    }
    int count;
    if(strcmp(argv[1], "-c") == 0){
        count = getCharCount(fp);
        printf("�ַ�����%d\n", count);
    }else if(strcmp(argv[1], "-w") == 0){
        count = getWordCount(fp);
        printf("��������%d\n", count);
    }else{
        printf("�����������\n");
    }
    fclose(fp);
    return 0;
}

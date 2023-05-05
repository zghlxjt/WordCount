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
        printf("输入参数错误！\n");
        return 0;
    }
    char* fileName = "input.txt";
    if(argc == 3){
        fileName = argv[2];
    }
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("打开文件失败！\n");
        return 0;
    }
    int count;
    if(strcmp(argv[1], "-c") == 0){
        count = getCharCount(fp);
        printf("字符数：%d\n", count);
    }else if(strcmp(argv[1], "-w") == 0){
        count = getWordCount(fp);
        printf("单词数：%d\n", count);
    }else{
        printf("输入参数错误！\n");
    }
    fclose(fp);
    return 0;
}

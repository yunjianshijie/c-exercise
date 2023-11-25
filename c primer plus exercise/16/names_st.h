#include<stdio.h>
#include<string.h>
#define slen 32

typedef struct names_st{
    char first[32];
    char last[32];
} names;

void get_names(names *);
void show_names(const names *);
char * s_gets(char * st ,int n);


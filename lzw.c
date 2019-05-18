#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INVALID_VALUE -1

typedef struct {
    char **item;
    int *code;
    int size;
    int max_size;
} Dict;

void insertDict(Dict *dict, char *item)
{
    dict->item[dict->size] = (char *)malloc(sizeof(char) * (strlen(item) + 1));
    sprintf(dict->item[dict->size], item);
    dict->code[dict->size] = dict->size;
    (dict->size)++;
}
void initDict(Dict *dict, int max_size)
{
    int i;
    char item[2] = "A";
    dict->max_size = max_size;
    dict->item = (char **)malloc(sizeof(char *) * max_size);
    dict->code = (int *)malloc(sizeof(int) * max_size);
    dict->size = 0;
    insertDict(dict, "#");
    for (i = 0; i < 26; i++) {
        insertDict(dict, item);
        item[0]++;
    }
}

void showDict(Dict *dict)
{
    int i;
    printf("code    item\n");
    for (i = 0; i < dict->size; i++) {
        printf("%4d    %4s\n", dict->code[i], dict->item[i]);
    }
}
void cleanDict(Dict *dict)
{
    int i;
    for (i = 0; i < dict->max_size; i++) {
        free(dict->item[i]);
    }
    free(dict->item);
}
int main()
{
    Dict dict;
    initDict(&dict, 1000);
    showDict(&dict);
    cleanDict(&dict);
    return 0;
}

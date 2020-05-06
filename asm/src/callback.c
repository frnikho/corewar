/*
** EPITECH PROJECT, 2020
** callback.c
** File description:
** callback function
*/

typedef struct code_s {
    char *key;
    int (*function)(char *params);
}code_t;

int jump(char *pute);
int add(char *pute);
int sub(char *pute);
int zjump(char *pute);

const code_t instruction[] = {{"jump", jump}, {"add", add}, {"sub", sub}, {"zjump", zjump}, {0, 0}};

int call_function(char *code, char *params)
{
    for (int i = 0; instruction[i].key != 0; i++) {
        if (strcmp(code, instruction[i].key) == 0) {
            instruction[i].function(params);
            return (0);
        }
    }
    return (-1);
}

int main()
{
    if (call_function("add", "5 + 2") == -1)
        return ;
}

int jump(char *pute)
{
    printf("writing from jump: %s\n", pute);
}

int add(char *pute)
{
    printf("writing from add: %s\n", pute);
}

int sub(char *pute)
{
    printf("writing from sub: %s\n", pute);
}

int live(char *params)
{
    
}

int zjump(char *pute)
{

}
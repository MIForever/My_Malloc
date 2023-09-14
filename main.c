#include "./include/funcs.h"

int main()
{
    char* ptr = my_malloc(sizeof(char) * 6);
    strcpy(ptr, "hello");
    printf("%p\n", ptr);
    printf("%s\n", ptr);
    return 0;
}
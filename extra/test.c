#include <stdio.h>

void change_val(int *i, int *j)
{
    *i = 10;
    *j = 15;
}

int main()
{
    int i = 1;
    int j = 2;
    printf("%d %d\n", i, j);
    change_val(&i, &j);
    printf("%d %d\n", i, j);
}
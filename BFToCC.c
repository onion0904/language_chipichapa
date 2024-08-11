#include <stdio.h>
#include <string.h>

int main()
{
    while (1)
    {
        char token;

        if (scanf("%c", &token) == EOF)
            break;
        if (token == '>')
            printf("chipi chipi ");
        if (token == '<')
            printf("chapa chapa ");
        if (token == '+')
            printf("dubi dubi ");
        if (token == '-')
            printf("daba daba ");
        if (token == ',')
            printf("boom boom ");
        if (token == '.')
            printf("chipi chapa ");
        if (token == '[')
            printf("dubi daba ");
        if (token == ']')
            printf("happy happy ");
    }
}
#include <stdio.h>
#include <string.h>
int main(void)
{
    int freq[10] = {0};
    char str[100];
    printf("Enter String : ");
    gets(str);
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i] >='0' && str[i]<= '9')
            freq[str[i]-'0']++;
    }
    for(int i=0; i<10; i++)
        printf("%d\t", freq[i]);
    return 0;
}

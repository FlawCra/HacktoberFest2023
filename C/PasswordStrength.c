#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void printStrongNess(char* input)
{
    int n = strlen(input);
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;

    char normalChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

    for (int i = 0; i < n; i++) 
    {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;
        size_t special = strcspn(input, normalChars);
        if (special != n)
            specialChar = true;
    }
    
    printf("Strength of your password:- ");
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8))
        printf("Strong\n");
    else if ((hasLower || hasUpper) &&
             specialChar && (n >= 6))
        printf("Moderate\n");
    else
        printf("Weak\n");
}

int main()
{
    char input[100];
    printf("Enter your password: ");
    scanf("%s", input);
    printStrongNess(input);
    return 0;
}

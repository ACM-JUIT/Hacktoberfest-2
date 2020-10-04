#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int x = 0;
    int j = 1;
    char* caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* shor = "abcdefghijklmnopqrstuvwxyz";
    //CHECKING INPUT FROM COMMAND LINE
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

// Checking for 26 letters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }


    //Checking for weird stuff(input)

    {
        if (argc != 2)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        //checking for weird characters

        else
        {

            for (j = 1; j < argc; j++)
            {
                for (int k = 0; k < strlen(argv[j]); k++)
                    if (((argv[j][k] >= 65) && (argv[j][k] <= 90)) || ((argv[j][k] >= 97) && (argv[j][k] <= 122)))
                        ;
                    else
                    {
                        printf("Usage: ./substitution key\n");
                        return 1;
                    }
            }

        }

    }

    //Checking for Duplicates in Key

    {
        for (int v = 0; v < 26; v++)
            for (int z = v + 1; z < 27; z++)
            {
                if (argv[1][v] == argv[1][z])
                {
                    printf("Duplicates found in Key, exiting with code 1...\n");
                    return 1;
                }
            }
    }

    //end of check input function
    printf("plaintext:");
    char t[1000];
    scanf("%[^\n]%*c", t);
    //gets input
    printf("ciphertext:");
    //Run Main function
    {
        for (int u = 0; u < strlen(t); u++)
        {
            if ((t[u] >= 97) && (t[u] <= 122))
            {
                for (int g = 0; g < 26; g++)
                {
                    if (t[u] == shor[g])
                    {
                        t[u] = argv[1][g];
                        if (t[u] <= 96)
                        {
                            printf("%c", t[u] + 32);
                        }
                        else
                        {
                            printf("%c", t[u]);
                        }
                    }
                }
            }

            else if ((t[u] >= 65) && (t[u] <= 90))
            {
                for (int h = 0; h < 26; h++)
                {
                    if (t[u] == caps[h])
                    {
                        t[u] = argv[1][h];
                        if (t[u] > 90)
                        {
                            printf("%c", t[u] - 32);
                            break;
                        }
                        else
                        {
                            printf("%c", t[u]);
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("%c", t[u]);
            }
        }
    }
    printf("\n");
}
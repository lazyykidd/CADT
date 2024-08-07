#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f1, *f2, *f;
    char file1[30], file2[30], ccfile[60];
    char str[90], str2[90];
    char line[90];
    printf("Enter first file name: ");
    scanf("%s", &file1);
    f1 = fopen(file1, "r");
    if (f1 == NULL)
    {
        printf("\"Error! No source file\"");
        exit(8);
    }
    printf("File_1 open successfully!! \n");

    printf("Enter second file name: ");
    scanf("%s", &file2);
    f2 = fopen(file2, "r");
    if (f2 == NULL)
    {
        printf("\"Error! No source file\"");
        exit(8);
    }
    printf("File_2 open successfully!! \n");

    ;
    if (strcmp(file1, file2) == 0)
    {
        printf("Error !!");
        exit(8);
    }
    printf("\nCreate a new file : ");
    scanf("%s", &ccfile);
    f = fopen(ccfile, "w");
    printf("File created sucessfully!! \n");

    if (f == NULL)
        exit(8);

    while (fgets(line, sizeof(line), f1) != NULL)
    {
        fputs(line, f);
    }
    fputs("\n", f);
    while (fgets(line, sizeof(line), f2) != NULL)
    {
        fputs(line, f);
    }
    fclose(f1);
    fclose(f2);
    fclose(f);

    return 0;
}
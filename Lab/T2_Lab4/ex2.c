#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f;
    char file_name[30], new_file[30];
    char str[90];

    printf("Enter the file name : ");
    scanf("%s", &file_name);
    f = fopen(file_name, "r");
    if (f == NULL)
    {
        printf("\"Error!No source file\"");
        exit(8);
    }
    printf("File open successfully!! \n");

    FILE *fp;
    printf("\nCreate a new file : ");
    scanf("%s", &new_file);
    if (strcmp(new_file, file_name) == 0)
    {
        printf("Error !!");
        exit(8);
    }
    printf("File created sucessfully!! \n");
    fp = fopen(new_file, "w");
    if (fp == NULL)
        exit(8);
    while (fgets(str, 100, f) != NULL)
    {
        printf("%s", str);
        fputs(str, fp);
    }
    fclose(f);
    fclose(fp);
    return 0;
}

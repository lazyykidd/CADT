#include <stdio.h>
#include <string.h>

struct product
{
    int id;
    char name[20];
    char p_date[15];
    char exp_date[15];
    char color[5];
} p[5];

int main()
{
    int color;
    for (int i = 0; i < 5; i++)
    {
        printf("\nProduct %d's ID: ", i + 1);
        scanf("%d", &p[i].id);
        printf("\nEnter the Product name : ");
        scanf("%s", &p[i].name);
        printf("\nEnter the Producion date (DD/MM/YYYY): ");
        scanf("%s", &p[i].p_date);
        printf("\nEnter the product expiration date (DD/MM/YYYY): ");
        scanf("%s", &p[i].exp_date);
        printf("\nColor Picker\n1. Red\n2. Yellow\n3. Blue\n4. White\n5. Black");
        printf("\nEnter the color of the product: ");
        do
        {
            scanf("%d", &color);
            if (color != 1 && color != 2 && color != 3 && color != 4 && color != 5)

            {
                printf("Invalid");
            }
        } while (color != 1 && color != 2 && color != 3 && color != 4 && color != 5);
        switch (color)
        {
        case 1:
            strcpy(p[i].color, "Red");
            break;
        case 2:
            strcpy(p[i].color, "Yellow");
            break;
        case 3:
            strcpy(p[i].color, "Blue");
            break;
        case 4:
            strcpy(p[i].color, "White");
            break;
        case 5:
            strcpy(p[i].color, "Black");
            break;
        default:
            printf("Invalid color");
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nProduct %d", i + 1);
        printf("\nName: %s", p[i].name);
        printf("\nProduction Date: %s", p[i].p_date);
        printf("\nExpiration Date: %s", p[i].exp_date);
        printf("\nColor: %s\n", p[i].color);
    }

    return 0;
}
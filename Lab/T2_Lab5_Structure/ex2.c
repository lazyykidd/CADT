#include <stdio.h>
#include <string.h>

struct Seller_add
{
    char h_num[5];
    char road[20];
    char city[20];
};

struct Seller
{
    char seller_name[20];
    struct Seller_add address;
} s[5];

struct product
{
    int id;
    char name[20];
    char p_date[15];
    char exp_date[15];
    char color[5];
    struct Seller seller;
} p[5];

int main()
{

    int color;
    for (int i = 0; i < 5; i++)
    {
        printf("\nProduct %d's ID: ", i + 1);
        scanf("%d", &p[i].id);
        printf("\nEnter the Product name: ");
        scanf("%s", &p[i].name);
        printf("\nEnter the Production date: ");
        scanf("%s", &p[i].p_date);
        printf("\nEnter the Product Expiration date: ");
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
        printf("\nSeller %d", i + 1);
        printf("\nEnter Seller name: ");
        scanf("%s", &p[i].seller.seller_name);
        printf("\nEnter Seller House number: ");
        scanf("%d", &p[i].seller.address.h_num);
        printf("\nEnter Seller Road name: ");
        while ((getchar()) != '\n');
        scanf("%s", &p[i].seller.address.road);
        printf("\nEnter Seller City: ");
        scanf("%s", &p[i].seller.address.city);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\n|       [Product %d]", i + 1);
        printf("\n|Name           : %s", p[i].name);
        printf("\n|Production Date: %s", p[i].p_date);
        printf("\n|Expiration Date: %s", p[i].exp_date);
        printf("\n|Color          : %s", p[i].color);
        printf("\n|");

        printf("\n|       [Seller %d]", i + 1);
        printf("\n|Name           : %s", p[i].seller.seller_name);
        printf("\n|House Number   : %s", p[i].seller.address.h_num);
        printf("\n|Road           : %s", p[i].seller.address.road);
        printf("\n|City           : %s", &p[i].seller.address.city);
        printf("\n|\n");

        printf("\n====================================\n");
    }

    return 0;
}
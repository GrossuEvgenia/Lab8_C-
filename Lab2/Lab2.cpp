﻿// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN 100
#define standart "no_name"
typedef struct {
    char name[LEN];
    int age;
    int wheit;
    double price;
}pets;
typedef struct 
{
    int col;
    double income;
    double damages;
    double price_feed;
    pets pet;
}zooshop;


zooshop init_shop( )
{
    zooshop check;
    check.col = 0;
    check.income = 0;
    check.damages = 0;
    check.price_feed = 10;
    strcpy_s(check.pet.name,standart);
    check.pet.age = 0;
    check.pet.wheit = 0;
    check.pet.price = 0;
    return check;
}
zooshop input()
{
    zooshop pety;
    pety = init_shop();
    printf("Enter pet name: \n");
    rewind(stdin); gets_s(pety.pet.name, LEN);
    printf("Enter pet age : \n");
    scanf_s("%d", &pety.pet.age);
    printf("Enter pet weit: \n");
    scanf_s("%d", &pety.pet.wheit);
    printf("Enter pet price: \n");
    scanf_s("%lf", &pety.pet.price);
    pety.col++;
    return pety;
}
void output_shop(zooshop check)
{
    printf("The numbers of pets : %d\n", check.col);
    printf("Store profit is %lf\n", check.income);
    printf("Store damages is %lf\n", check.damages);
    printf("Food price is %lf\n", check.price_feed);
    printf("Pet's name %s\n", check.pet.name);
    printf("Pet's age %d\n", check.pet.age);
    printf("Pet's wheit %d\n", check.pet.wheit);
    printf("pet's price %lf\n", check.pet.price);
}

void add_price(zooshop pet1, zooshop pet2)
{
    double sum;
    sum = pet1.pet.price + pet2.pet.price;
    printf("Total price of pets: %lf", sum);
}
zooshop feeding( zooshop check)
{
    check.pet.wheit += 1;
    check.damages = check.damages + check.price_feed * check.col;
    printf("Pet is fed\n");
    return check;
}
zooshop sale(zooshop check)
{
    check.col -= 1;
    check.income += check.pet.price;
    check.damages -= check.price_feed * check.col;
    strcpy_s(check.pet.name,standart);
    check.pet.age = 0;
    check.pet.wheit = 0;
    check.pet.price = 0;
    printf("Pet sold\n");
    return check;
}

int main()
{
    zooshop check;
    check=init_shop();
    printf("Initialization: \n");
    output_shop(check);
    check = input();
    printf("\nAfter entering: \n");
    output_shop(check);
    check=feeding( check); 
    printf("\nAfter feeding: \n");
    output_shop(check);
    check=sale(check);
    printf("\nAfter sale: \n");
    output_shop(check);
    zooshop pet1;
    pet1 = input(); 
    add_price(check, pet1);
    zooshop* c;
    printf("\nWorking with dinamic variables\n");
    c = (zooshop*)malloc(LEN * sizeof(zooshop));
    c = &(init_shop());
    printf("\nInitialization: \n");
    output_shop(*c);
    c = &(input());
    printf("\n After edding: \n");
    output_shop(*c);
   c=&( feeding(*c));
    printf("\nAfter feeding:\n");
    output_shop(*c);
    c=&(sale(*c));
    printf("\nAfter sale:\n");
    output_shop(*c);
    zooshop* c1;
    c1 = (zooshop*)malloc(LEN * sizeof(zooshop));
    c1 = &(input());
    add_price(*c, *c1);
    printf("\nDynanmic variable addresses:\n");
    printf("%p", c);
}

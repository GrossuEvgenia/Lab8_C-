// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Разработка программного модуля, описывающего работу зоомагазина с использованием структур языка C.
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include<malloc.h>
#include<string.h>

#define LEN 100
#define standart "no_name"
using namespace std;

class pets;
class zooshop
{
public:
    zooshop()
    {
        col = 0;
        income = 0;
        damages = 0;
        price_feed = 10;
    }
    zooshop(int col, double income, double damages, double price_feed)
    {
        this->col = col;
        this->income = income;
        this->damages = damages;
        this->price_feed = price_feed;

    }
    int get_col()
    {
        return col;
    }
    void set_col(int col)
    {
        this->col = col;
    }
    double get_income() {

        return income;
    }
    void set_income(double income)
    {
        this->income = income;
    }
    double get_damages() {

        return damages;
    }
    void set_damages(double damages)
    {
        this->damages = damages;
    }
    double get_price_feed() {

        return price_feed;
    }

    void read()
    {
        cout << "The numbers of pets : " << col << endl;
        cout << "Store profit is " << income << endl;
        cout << "Store damages is " << damages << endl;
        cout << "Food price id " << price_feed << endl;
    }
    friend pets;

private:
    int col;
    double income;
    double damages;
    double price_feed;

};
class pets : public zooshop
{
public:
    pets() {
        strcpy_s(name, standart);
        age = 0;
        wheit = 0;
        price = 0;
    }
    pets(int col, double income, double damages, double price_feed, char name[LEN], int age, int wheit, double price) :zooshop(col, income, damages, price_feed)
    {
        strcpy_s(this->name, name);
        this->age = age;
        this->wheit = wheit;
        this->price = price;
    }


    /*  void setname(string name)
      {
          this->name = name;
      }
      void setage(int age)
      {
          this->age = age;
      }
      void setweith(int wheit)
      {
          this->wheit = wheit;
      }
      void setprice(double price)
      {
          this->price = price;
      }*/
    string getname()
    {
        cout << "Pet's name: " << name << endl;
        return name;
    }
    int getage()
    {
        cout << "pet's age: " << age << endl;
        return age;
    }
    int get_wheit()
    {
        cout << "Pet's wheit: " << wheit << endl;
        return wheit;
    }
    void input()
    {
        cout << "Enter pet name: \n";
        rewind(stdin); gets_s(name, LEN);
        cout << "Enter pet age : \n";
        cin >> age;
        cout << "Enter pet weit: \n";
        cin >> wheit;
        cout << "Enter pet price: \n";
        cin >> price;
        col++;
    }
    void output()
    {
        cout << "The numbers of pets : " << col << endl;
        cout << "Store profit is " << income << endl;
        cout << "Store damages is " << damages << endl;
        cout << "Food price is " << price_feed << endl;
        cout << "Pet's name " << name << endl;
        cout << "Pet's age " << age << endl;
        cout << "Pet's wheit " << wheit << endl;
        cout << "Pet's price " << price << endl;
    }
    void feeding()
    {
        wheit += 1;
        damages = damages + price_feed;
        cout << "Pet is fed\n";
    }
    void sale()
    {

        income += price;
        damages = damages - price_feed;
        col -= 1;
        strcpy_s(name, standart);
        age = 0;
        wheit = 0;
        price = 0;
        cout << "Pet sold\n";

    }
    double add_price(double sum)
    {

        sum += price;
        cout << "Total price of pets: " << sum << endl;
        return sum;
    }
private:
    char name[LEN];
    int age;
    int wheit;
    double price;
};



zooshop init_shop(int c, double i, double d, int ag, int wh, int p)
{
    zooshop check;
    check.col = c;
    check.income = i;
    check.damages = d;
    check.price_feed = 10;
    strcpy_s(check.pet.name,standart);
    check.pet.age = ag;
    check.pet.wheit = wh;
    check.pet.price = p;
    return check;
}
zooshop input()
{
    zooshop pety;
    pety = init_shop(0,0,0,0,0,0);
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
    int col = 0;
    check=init_shop(col,0,0,0,0,0);
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
    c = &(init_shop(col,0,0,0,0,0));
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
    return 0;
}


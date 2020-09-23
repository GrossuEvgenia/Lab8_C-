// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Разработка программного модуля, описывающего работу зоомагазина с использованием классов языка C++.
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include<malloc.h>
#include<string.h>

#define LEN 100
#define price_food 10
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
        price_feed = price_food;
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
    void set_price_food(double price_feed)
    {
        this->price_feed = price_feed;
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


      void setname(char name[LEN])
      {
          strcpy_s(this->name,name);
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
      }
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



int main()
{
    double sum = 0;
    char st[LEN] = "no_name";
    pets pet(0, 0, 0, 10, st, 0, 0, 0);
    cout << "Working with static  class object:" << endl;
    cout << "After initialization" << endl;
    pet.output();
    pet.input();
    cout << "After input value:" << endl;
    pet.output();
    cout << "After feeding:" << endl;
    pet.feeding();
    pet.output();
    cout << "After sale:" << endl;
    pet.sale();
    pet.output();
    sum = pet.add_price(sum);
    pets* pet1 = new pets(0, 0, 0, 10, st, 0, 0, 0);
    cout << "\n" << "Working with dinamic class object:" << endl;
    cout << "After initialization" << endl;
    pet1->output();
    pet1->input();
    cout << "After input value:" << endl;
    pet1->output();
    cout << "After feeding:" << endl;
    pet1->feeding();
    pet1->output();
    cout << "After sale:" << endl;
    pet1->sale();
    pet1->output();
    sum = pet1->add_price(sum);
    delete pet1;
    cout << "\n" << "Working with array" << endl;
    pets** pety = new pets * [LEN];
    int size = 0;
    cout << "Enter numbers of pets" << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        pety[i] = new pets(i, 0, 0, 10, st, 0, 0, 0);

        pety[i]->input();
    }
    for (int i = 0; i < size; i++)
    {
        pety[i]->set_col(size);
    }
    for (int j = 0; j < size; j++)
    {
        pety[j]->output();
        cout << "\n";
    }

    for (int j = 0; j < size; j++)
    {
        sum = pety[j]->add_price(sum);
    }
    cout << "After feeding" << endl;
    for (int j = 0; j < size; j++)
    {
        pety[j]->feeding();
        if (j + 1 != size)
        {
            pety[j + 1]->set_damages(pety[j]->get_damages());
        }
        pety[j]->getname();
        pety[j]->get_wheit();
        cout << endl;
    }
    for (int j = 0; j < size; j++)
    {
        pety[j]->set_damages(pety[size - 1]->get_damages());
    }
    pety[size - 1]->read();
    cout << "After sale" << endl;
    for (int j = 0; j < size; j++)
    {
        pety[j]->sale();
        if (j + 1 != size)
        {
            pety[j + 1]->set_damages(pety[j]->get_damages());
            pety[j + 1]->set_income(pety[j]->get_income());
            pety[j + 1]->set_col(pety[j]->get_col());
        }
    }
    pety[size - 1]->read();
    delete[] pety;
    cout << "Working with static array" << endl;
    cout << "Enter numbers of pets" << endl;
    cin >> size;
    pets* pety2 = (pets*)calloc(size, sizeof(pets));

    for (int i = 0; i < size; i++)
    {
        pety2[i].input();
        pety2[i].set_price_food(price_food);
    }
    for (int i = 0; i < size; i++)
    {
        pety2[i].set_col(size);
    }
    for (int j = 0; j < size; j++)
    {
        pety2[j].output();
        cout << "\n";
    }

    for (int j = 0; j < size; j++)
    {
        sum = pety2[j].add_price(sum);
    }
    cout << "After feeding" << endl;
    for (int j = 0; j < size; j++)
    {
        pety2[j].feeding();
        if (j + 1 != size)
        {
            pety2[j + 1].set_damages(pety2[j].get_damages());
        }
        pety2[j].getname();
        pety2[j].get_wheit();
        cout << endl;
    }
    for (int j = 0; j < size; j++)
    {
        pety2[j].set_damages(pety2[size - 1].get_damages());
    }
    pety2[size - 1].read();
    cout << "After sale" << endl;
    for (int j = 0; j < size; j++)
    {
        pety2[j].sale();
        if (j + 1 != size)
        {
            pety2[j + 1].set_damages(pety2[j].get_damages());
            pety2[j + 1].set_income(pety2[j].get_income());
            pety2[j + 1].set_col(pety2[j].get_col());
        }
    }
    pety2[size - 1].read();
    free(pety2);
    return 0;
}

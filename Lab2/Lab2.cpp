// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Разработка программного модуля, описывающего работу зоомагазина с использованием классов языка C++.
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include<malloc.h>
#include<string.h>

#define LEN 100
#define standart "no_name"
using namespace std;
#define prices 10
#define pr 0.2
class pets
{
public:
    pets() {
        name=standart;
        age = 0;
        wheit = 0;
        price = 0;
    }
    pets(string name, int age, int wheit, double price)
    {
        this->name=name;
        this->age = age;
        this->wheit = wheit;
        this->price = price;
    }


    void setname(string name)
    {
        this->name=name;
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

        return name;
    }
    int getage()
    {

        return age;
    }
    int get_wheit()
    {

        return wheit;
    }
    double get_price()
    {
        return price;
    }
    void input()
    {
        cout << "Enter pet name: \n";
        cin >> name;
        cout << "Enter pet age : \n";
        cin >> age;
        cout << "Enter pet weit: \n";
        cin >> wheit;
        cout << "Enter pet price: \n";
        cin >> price;

    }

    void output()
    {
        // cout << "The numbers of pets : " << col << endl;
        // cout << "Store profit is " << income << endl;
        // cout << "Store damages is " << damages << endl;
        // cout << "Food price is " << price_feed << endl;
        cout << "Pet's name " << name << endl;
        cout << "Pet's age " << age << endl;
        cout << "Pet's wheit " << wheit << endl;
        cout << "Pet's price " << price << endl;
    }
    /* */
    double add_price(double sum)
    {

        sum += price;
        cout << "Total price of pets: " << sum << endl;
        return sum;
    }
private:
    string name;
    int age;
    int wheit;
    double price;
};

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
    zooshop(int col, double income, double damages, double price_feed, pets pet[LEN])
    {
        this->col = col;
        this->income = income;
        this->damages = damages;
        this->price_feed = price_feed;
        for (int i = 0; i < col; i++)
        {
            this->pet[i] = pet[i];
        }
    }
    zooshop(int col, double income, double damages, double price_feed, pets pet)
    {
        this->col = col;
        this->income = income;
        this->damages = damages;
        this->price_feed = price_feed;
        for (int i = 0; i < col; i++)
        {
            this->pet[i] = pet;
        }
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
        cout << "Food price is " << price_feed << endl;
    }
    void output()
    {
        cout << "The numbers of pets : " << col << endl;
        cout << "Store profit is " << income << endl;
        cout << "Store damages is " << damages << endl;
        cout << "Food price is " << price_feed << endl;
        for (int i = 0; i < col; i++)
        {
            cout << "Pet's name " << pet[i].getname() << endl;
            cout << "Pet's age " << pet[i].getage() << endl;
            cout << "Pet's wheit " << pet[i].get_wheit() << endl;
            cout << "Pet's price " << pet[i].get_price() << endl;
            cout << endl;
        }
    }
    void feeding()
    {
        int w;
        for (int i = 0; i < col; i++)
        {
            w = pet[i].get_wheit() + 1;
            pet[i].setweith(w);
            damages = damages + price_feed;
        }

        cout << "Pet is fed\n";
    }
    void sale()
    {
        for (int i = 0; i <= col; i++)
        {
            income += pet[i].get_price();
            col -= 1;
            cout << "Pet sold\n" << endl;
        }

    }

    void tax(double &taxa)
    {
        taxa = income * pr;
        cout << "Store tax is" << taxa << endl;
        return;
    }
    void this_profit(double *profit)
    {
        *profit = income - damages;
        cout << "Store profit this month" << *profit << endl;
        return;
    }
    friend void check(zooshop sale);
    
    friend zooshop operator+(zooshop s,zooshop s1);
    zooshop& operator++()
    {
        this->price_feed++;
        return *this;
    }
    zooshop operator++(int)
    {
        zooshop s = *this;
        ++*this;
        return s;

    }
     void found_pet(string names)
    {
        int res = 0; 
        for (int i = 0; i < col; i++)
        {
            if (names == pet[i].getname())
            {
                cout << "Pet found" << endl;
            }
        }
        if (res == 1)
        {
            cout << "Pet didn't found" << endl;
        }

    }
private:
    int col;
    double income;
    double damages;
    double price_feed;
    pets pet[LEN];
};

void check(zooshop sale)
{
    for (int i = 0; i <= sale.col; i++)
    {
        if (sale.pet->get_wheit() < 1)
        {
            sale.col--;
            
        }
    }
    cout << "Checked ended" << endl;
}
zooshop operator+(zooshop s, zooshop s1)
{
  s1.set_col( s.col + s1.col);
  return s1;
}

int main()
{

    int col;
    double sum = 0;
    double taxa = 0;
    double profit = 0;
    string st = "no_name";
    cout << "Working with static object" << endl;
    pets pet(st, 0, 0, 0);
    pet.input();
    sum = pet.add_price(sum);
    zooshop store(1, 0, 0, prices, pet);
    store.output();
    store.feeding();
    store.output();
    store.sale();
    store.output();
    store.tax(taxa);
    store.this_profit(&profit);

    check(store);
    zooshop store10(1, 0, 0, prices, pet);
    store10 = store + store10;
    store10.output();
    store10 = store++;
    store10.output();
    store10 = ++store;
    store10.output();




    cout << "\nWorking with dinamic object" << endl;
    pets* pet1 = new pets(st, 0, 0, 0);
    pet1->input();
    sum = pet1->add_price(sum);
    zooshop* store1 = new zooshop(1, 0, 0, prices, pet1);
    store1->output();
    store1->feeding();
    store1->output();
    store1->sale();
    store1->output();
    delete pet1;
    delete store1;
    pets pet2[LEN];
    cout << "\nWorking with an array of static object" << endl;
    cout << "Enter nunber of pets in shoop" << endl;
    cin >> col;
    for (int i = 0; i < col; i++)
    {
        pet2[i].input();
        sum = pet2[i].add_price(sum);
    }
    zooshop* store2 = new zooshop(col, 0, 0, prices, pet2);
    store2->output();
    store2->feeding();
    string names;
    cout << "Enter pet's name" << endl;
    cin >> names;
    store2->found_pet(names);
    store2->output();
    store2->sale();
    store2->output();
    
    cout << "\nWorking with an array of dynamic objects" << endl;
    cout << "Enter nunber of pets in shoop" << endl;
    cin >> col;
    pets** pet3 = new pets * [LEN];
    for (int i = 0; i < col; i++)
    {
        pet3[i] = new pets(st, 0, 0, 0);
        pet3[i]->input();
        sum = pet3[i]->add_price(sum);
    }
    zooshop store3(col, 0, 0, prices, **pet3);
    store3.output();
    store3.feeding();
    store3.output();
    store3.sale();
    store3.output();
    delete store2;
    delete[] pet3;
    return 0;
}

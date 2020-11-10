// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Разработка программного модуля, описывающего работу зоомагазина с использованием классов языка C++.
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include<malloc.h>
#include<string.h>
#pragma warning(disable:4996)
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
    pets(char* t, string name, int age, int wheit, double price)
    {
        
            if (age < 0 || wheit < 0 || price < 0)
            {
                throw 1;
            }
        
        type_pets = new char[20];
        strcpy(type_pets, t);
        this->name = name;
        this->age = age;
        this->wheit = wheit;
        this->price = price;
    }
    pets(const pets& p)
    {
        this->type_pets=p.type_pets;
        this->name = p.name;
        this->age = p.age;
        this->wheit = p.wheit;
        this->price = p.price;

    }
    pets(string name)
    {
        this->name = name;
        age = 0;
        wheit = 0;
        price = 0;
    }
    pets(string name, int age, int wheit, double price)
    {
        if (age < 0 || wheit < 0 || price < 0)
        {
            throw 1;
        }
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
        //10 lab rab
        int f = 0;
        while (f == 0) {
            cout << "Enter pet age : \n";
            try {
                if (cin >> age) f = 1;
              else throw - 1;
            }
            catch (int c)
            {
                cout << "NOT DIGIT!!!\n" << "Enter value again" << endl;
                f = 0;
                cin.clear();
                while (cin.get() != '\n');
            }
        }
        f = 0;
        while (f == 0) {
            try {
                cout << "Enter pet weit: \n";
                if (cin >> wheit) f = 1;

                else  throw - 1;
            }
            catch (int c)
            {
                cout << "NOT DIGIT!!!\n" << "Enter value again" << endl;
                f = 0;
                cin.clear();
                while (cin.get() != '\n');
            }
        }
        f = 0;
        while (f == 0)
        {

            try {
                cout << "Enter pet price: \n";
                if (cin >> price)f = 1;
                else throw - 1;

            }
            catch (int c)
            {
                cout << "NOT DIGIT!!!\n" << "Enter value again" << endl;
                f = 0;
                cin.clear();
                while (cin.get() != '\n');
            }

        }
    }

    void output()
    {
        cout << "Pet's name- " << name << " age- " << age << " wheit- " << wheit << " price- " << price << endl;
    }
    void output_for_copy()
    {
        cout << "Pet's type"<<type_pets<<" name- " << name << " age- " << age << " wheit- " << wheit << " price- " << price << endl;
    }
    /* */
    double add_price(double sum)
    {

        sum += price;
        cout << "Total price of pets: " << sum << endl;
        return sum;
    }
private:
    char* type_pets;
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
    }
    zooshop(char *n, int col, double income, double damages, pets pet)
    {
        names = new char[10];
        strcpy(this->names, n);
        this->col = col;
        this->income = income;
        this->damages = damages;
        for (int i = 0; i < col; i++)
        {
            this->pet[i] = pet;
        }
    }
    zooshop &operator = (zooshop &s)
    {
        if (names)
        {
            delete names;    
        }
        names  = NULL;
        this->col = s.col;
        int l = strlen(s.names) + 1;
        names = new char[l];
        strcpy(this->names, s.names);
        
        this->income = s.income;
        this->damages = s.damages;
        for (int i = 0; i < col; i++)
        {
            this->pet[i] = s.pet[i];
        }
        return *this;
    }
    zooshop(int col, double income, double damages, pets pet[LEN])
    {
        this->col = col;
        this->income = income;
        this->damages = damages;
        for (int i = 0; i < col; i++)
        {
            this->pet[i] = pet[i];
        }
    }
    zooshop(int col, double income, double damages,  pets pet)
    {
        this->col = col;
        this->income = income;
        this->damages = damages;
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
  static  double get_price_feed() {

        return price_feed;
    }
  static void set_price_feed(double pricess)
  {
      price_feed = pricess;

  }

    void read()
    {
        cout << "The numbers of pets : " << col << " store profit is " << income << " store damages is " << damages<< " food price is " << price_feed << endl;
    }
    void output()
    {
        cout << "The numbers of pets : " << col << " store profit is " << income << " store damages is " << damages << " food price is " << price_feed << endl;
        for (int i = 0; i < col; i++)
        {
            cout << "Pet's name- " << pet[i].getname() << " age- " << pet[i].getage()<< " wheit- " << pet[i].get_wheit() << " price- " << pet[i].get_price() << endl;
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
    
    /*friend zooshop operator+(zooshop s,zooshop s1);
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

    }*/
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
     //change fo 8 labaratory
     static void compare(zooshop s1, zooshop s2)
     {
         if (s1.get_col() > s2.get_col())
         {

             cout << "more animals in the first store" << endl;
         }
         else if (s1.get_col() == s2.get_col())
         {
             cout << "stores is equal" << endl;
         }
         else 
         { cout << "more animals in the second store" << endl; }
     }
     void copy()
     {
         cout << "The store names"<<names<<" the numbers of pets : " << col << " store profit is " << income << " store damages is " << damages << " food price is " << price_feed << endl;
     }
private:
    char* names;
    int col;
    double income;
    double damages;
    static double price_feed;//for 8 lab
    pets pet[LEN];
};
double zooshop::price_feed = prices;
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
/*zooshop operator+(zooshop s, zooshop s1)
{
  s1.set_col( s.col + s1.col);
  return s1;
}*/

int main()
{
    try {
        pets pet10("error", -1, 0, 0);
    }
    catch (int k)
    {
        cout << "Error, negative value in konstruktor" << endl;
    }
    int col;
    double sum = 0;
    double taxa = 0;
    double profit = 0;
    string st = "no_name";
    cout << "Working with static object" << endl;

    pets pet(st, 0, 0, 0);//constructor call with all value
    cout << "for class pet: with all value" << endl;
    pet.output();
    pets pet9("dogy");//constructor call with one value
    cout << "for class pet: with one value" << endl;
    pet9.output();
    pets pet9_1;//constructor call without value
    cout << "for class pet: without value" << endl;
    pet9_1.output();
    string cat = "cat";
    string dog = "dog";
    pets pet9_2[2] = {cat,dog};//constructor call with one value and array 
    char* type;
    type = new char[10];
    strcpy(type, "cat");
    //overload
    pets pet93(type, "bar", 1, 1, 1);
    pets pet933 = pet93;
    cout << "overload" << endl;
    pet933.output_for_copy();
    

    pet.input();
    sum = pet.add_price(sum);
    zooshop store(1, 0, 0, pet);//constructor with one value 
    cout << "for class zooshop : wit all value (one value pet)" << endl;
    store.output();
    cout << "for class zooshop : without value" << endl;
    zooshop store9;//constructor without value
    store9.output();
    cout << "for class zooshop : with all value (array's pet)" << endl;
    zooshop store91(1, 0, 0, pet9_2);//constructor with array
    store91.output();
    
  
   


    store.feeding();
    store.output();
    store.sale();
    store.output();
    store.tax(taxa);
    store.this_profit(&profit);

    check(store);
    /*zooshop store10(1, 0, 0,  pet);
    store10 = store + store10;
    store10.output();
    store10 = store++;
    store10.output();
    store10 = ++store;
    store10.output();*/

    pets pet2[LEN];
    cout << "\nWorking with dinamic object" << endl;

    //constructor for dynamic object
    pets* pet99 = new pets();
    pets* pet991 = new pets("cota");
    pets* pet992 = new pets("cata", 1, 1, 5);
    cout << "for class pet: with all value" << endl;
    pet992->output();
    cout << "for class pet: with one value" << endl;
    pet991->output();
    cout << "for class pet: without value" << endl;
    pet99->output();
    
    cout << "Enter nunber of pets in shoop" << endl;
    cin >> col;
    for (int i = 0; i < col; i++)
    {
        pet2[i].input();
        sum = pet2[i].add_price(sum);
    }
    //constructor call with array
    zooshop* store2 = new zooshop(col, 0, 0, pet2);
    zooshop* store99 = new zooshop(1, 0, 0, pet992);
    zooshop* store991 = new zooshop();
    cout << "for class zooshop : wit all value (one value pet)" << endl;
    store99->output();
    cout << "for class zooshop : without value" << endl;
    store991->output();
    cout << "for class zooshop : with all value (array's pet)" << endl;
    store2->output();
    char* namess;
    namess = new char[10];
    strcpy(namess, "names");
    zooshop* store992 = new zooshop(namess, 1, 0, 0, pet);
    zooshop* store993 = store992;
    cout << "deep copy" << endl;
    store993->copy();
    cout << endl;
    store2->feeding();
    //for 8 lab
    pets pet8(st, 0, 0, 0);
    
    col = 1;
    zooshop store8(col, 0, 0, pet8);
    zooshop::compare(*store2, store8);
    zooshop::set_price_feed(15);
    cout << "New price feed "<< zooshop::get_price_feed()<< endl;
    string names1;
    cout << "Enter pet's name" << endl;
    cin >> names1;
    store2->found_pet(names1);
    store2->output();
    store2->sale();
    store2->output();
    delete store2;
    return 0;
}

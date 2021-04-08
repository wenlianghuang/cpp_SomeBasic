#include<iostream>
#include<vector>
using namespace std;

class Account{
private: 
    int _balance;
public:
    Account(double d){
        _balance = d;
    }

    virtual ~Account(){}
    virtual double GetBalance(){
        return _balance;
    }
    virtual void PrintBalance() { cerr << "Error. Balance not available for base type" << endl;}
};
class CheckingAccount : public Account {
public:
   CheckingAccount(double d) : Account(d) {}
   void PrintBalance() { cout << "Checking account balance: " << GetBalance() << endl; }
};
class SavingAccount : public Account {
public:
    SavingAccount(double d): Account(d){}
    void PrintBalance(){ cout << "Saving account balance: " << GetBalance() << endl;}
};

//static variable,which is deleted after the main function, but can change in this scope
int staticvalue(){
    static int y = 1;
    std::cout << y << std::endl;
    y++;
}

int pointertest(int *y){
    int z = 1;
    y = &z;
    std::cout << "reference in the pointertest y: " << y << std::endl;
}

//Ready for the operator overloading by the class Date!!!
class Date{
public:
    int da,mo,yr;

public:
    //constructor
    Date(){};
    Date(int d,int m,int y){
        da = d;
        mo = m;
        yr = y;
    }

    //operator ostream <<, and define this method function into the class
    friend ostream& operator <<(ostream& os, const Date &dt);
    void operator=(Date obj2){
        this->da = obj2.da;
        this->mo = obj2.mo;
        this->yr = obj2.yr;
    }
    //oprator+ with one parameter in this class
    /*Date operator+(const Date &d){
        Date date;
        date.da = da + d.da;
        date.mo = mo + d.mo;
        date.yr = yr + d.yr;
        return date;
    }*/
    
    //operator== with one parameter in this class
    bool operator==(const Date &d){
        return(this->da == d.da) && (this->mo == d.mo) && (this->yr == d.yr);
    }
};


//define the operator<< method function outside the class
ostream& operator<<(ostream& os, const Date &dt){
    os << dt.da << "/" << dt.mo << "/" << dt.yr;
    return os;
}

//define the operator+ method function outside the class
Date operator+(Date obj1, Date obj2){
    int totda = obj1.da + obj2.da;
    int totmo = obj1.mo + obj2.mo;
    int totyr = obj1.yr + obj2.yr;
    //return Date(obj1.da + obj2.da,obj1.mo+obj2.mo, obj1.yr + obj2.yr);
    return Date(totda,totmo,totyr);
}




int main(){
    CheckingAccount check(100);
    Account *acc = &check;
    acc->PrintBalance();

    SavingAccount save(100);
    acc = &save;
    acc->PrintBalance();

    Account adefault(100);  //virtaul in Account still can be implement, but it show the result in class Account's PrintBalance
    adefault.PrintBalance();

    for(int i = 0; i < 10; i++){
        //static variable in this function
        staticvalue();
    }

    //About pointer
    int x = 0;
    int *y;
    y = &x;
    pointertest(y);
    std::cout << "Pointer value: " << *y << std::endl;
    std::cout << "Pointer reference: " << y << std::endl;

    
    //Something about the overloading operator
    //The reference of tutorial is https://www.csie.ntu.edu.tw/~r95116/CA200/slide/C3_Overloading.pdf
    Date dt(8,4,2021);
    cout << dt << endl;;
    Date d1(1,1,2010);
    Date d2(1,1,2020);
    Date d3;
    Date d4;
    d3 = d1 + d2;
    cout << d3.yr << endl;
    d1 == d2 ? std::cout <<"True" << std::endl : std::cout << "Flase" << std::endl; 
    d4 = d1;
    std::cout << "da: " << d4.da << " mo: " << d4.mo << " yr: " << d4.yr << endl;
}
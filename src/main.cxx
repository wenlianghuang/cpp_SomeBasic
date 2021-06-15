#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<iterator>
#include<list>
#include<math.h>
#include "../inc/TemplateClass.h"
#include<set>
#include<unordered_map>
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

//define the operaotor - method function outside the class
Date operator-(Date obj1,Date obj2){
    int totda = obj1.da - obj2.da;
    int totmo = obj1.mo - obj2.mo;
    int totyr = obj1.yr - obj2.yr;

    return Date(totda,totmo,totyr);
}
//define the operator * method function outsiide the class

//define the operaotr
//template function with its type of parameter
template<typename T>
void printTemplate(T &arr){
    for(auto elem: arr){
        cout << elem << " ";
    }
    cout << endl;
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
    //The pointer in parameters is acctually "copy", the pointer is different in the
    //function region or not.
    pointertest(y);//pointer reference in "pointertest" region
    std::cout << "Pointer value: " << *y << std::endl;
    std::cout << "Pointer reference: " << y << std::endl; //pointer reference in global region
    

    
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

    //tempalte
    //The first one is to set the "T" variable to "int" variable
    //The second one is to set the "T" varible to "string" variable
    TemplateClass<int> intStack;
    TemplateClass<string> stringStack;

    // manipulate int stack 
    intStack.push(7); 
    cout << intStack.top() <<endl; 

    // manipulate string stack 
    stringStack.push("hello"); 
    cout << stringStack.top() << std::endl; 
    stringStack.pop();

    //template of function, typename is the type that you can decide by your self
    //even
    int arr1[] = {2,3};
    int arr2[] = {4,5,6};
    string arr3[] = {"Matt","Jack","John"};

    printTemplate(arr1);
    printTemplate(arr2);
    printTemplate(arr3);
      
    //queue
    queue<int> myqueue;
    int myint;
    cout << "Please enter some integers (enter 0 to end):\n";
    do{
        cin >> myint;
        myqueue.push(myint);
    }while(myint);
    cout << "myqueue contains: ";
    
    while(!myqueue.empty()){
        cout << ' ' << myqueue.front();
        myqueue.pop();
    }

    cout << endl;
    //stack
    stack<int> mystack;
    cout << "Please enter some integers (enter 0 to end):\n";
    do{
        cin >> myint;
        mystack.push(myint);
    }while(myint);
    cout << "mystack contains: ";
    while(!mystack.empty()){
        cout << " " << mystack.top();
        mystack.pop();
    }
    cout << endl;

    //Iterator
    list<int> mylist;
    for(int i = 0; i < 10; i++) mylist.push_back(i*10);
    cout << "The last element is: " << *prev(mylist.end()) << endl;
    
    int foo[] = {10,20,30,40,50};
    std::vector<int> bar;

    //auto variable
    for(auto it = begin(foo); it != end(foo); ++it) bar.push_back(*it);
    cout << "bar contains: ";
    for(auto it = begin(bar); it != end(bar); ++it)
        cout << " " << *it;
    cout << endl;


    //get the whole vector at once in the for loop
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    for(int &i : vec){
        i++;
    }

    for(int i : vec){
        cout << i << endl;
    }


    //c++ set, the differences of set and vector are:
    //1.唯一性 2.不可修改性 3.順序性 ref: https://shengyu7697.github.io/std-set/ 
    set<int> myset;
    set<int>::iterator itset;
    pair<set<int>::iterator,bool> ret;

    for(int i = 1; i <= 5; ++i){
        myset.insert(i*10);
    }
    ret = myset.insert(20);

    if(ret.second == false) itset = ret.first;

    myset.insert(itset,24);
    myset.insert(itset,25);
    myset.insert(itset,26);

    int myints [] = {5,10,15};
    myset.insert(myints,myints+3);
    cout << "myset containers: ";
    for(itset = myset.begin();itset != myset.end(); ++itset)
        cout << " " << *itset;
    cout<< endl;

    //unordered_map::bucket
    unordered_map<string,string> mymap = {
        {"us","United State"},
        {"uk","Uniked Kingdon"},
        {"fr","France"},
        {"de","Germeny"}
    };
    for(auto &x: mymap){
        cout << "Element [" << x.first << ":" << x.second << "]";
        cout << " is in bucket # " << mymap.bucket(x.first) << endl;
    }
}
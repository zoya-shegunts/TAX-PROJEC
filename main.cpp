#include <iostream>
#include <cstring>
using namespace std;

char status[8];
int childNum;
int grossSalary;
int pensionFund;
 

double taxAmount(const char* status, int children, int salary, int pensionFund);
void getData();


int main() {

 getData();
 double taxIncome=grossSalary - taxAmount(status, childNum, grossSalary, pensionFund);
 cout<<' '<<endl;
 cout<<taxIncome;
 
    return 0;
}

void getData(){
    
 cout<<"Marital status: ";
 cin>>status; 
 
 if(strcmp(status, "married")==0){
     cout<<"The number of children under the age of 14: ";
      cin>>childNum;
           cout<<"the total gross salary of the 2 of you: ";
           cin>>grossSalary;
 }
else{
    childNum=0;
    cout<<"The amount of your gross salary: ";
    cin>>grossSalary;
}
 cout<<"Percentage of gross income contributed to a pension fund: ";
 cin>>pensionFund;
 return;
}

double taxAmount(const char* status, int children, int salary, int pensionFund){
    double tax=0;
    if(strcmp(status, "married")==0 && children == 2){
        tax=7000+1500*(2+children);
    }
    else{
    tax=4000+1500;
    }
    tax+=salary*pensionFund/100;
        if (salary>=0 && salary<=15000){
            tax+=salary*15/100;
        }
        else if (salary>=15001 && salary<=40000){
            tax+=2250;
            tax+=(salary-15000)*25/100;
        }
        else if (salary>=40000){
            tax+=8460;
            tax+=(salary-40000)*35/100;
        }
    return tax;
}

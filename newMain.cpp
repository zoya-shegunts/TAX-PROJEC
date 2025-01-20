#include <iostream>
#include <cstring>
using namespace std;

class User{
    public:
    char status[8];
    int childNum;
    int grossSalary;
    int pensionFund;
};


double taxAmount(const char* status, int children, int salary, int pensionFund);
User getData();


int main() {

User user = getData();

 double taxIncome = user.grossSalary - taxAmount(user.status, user.childNum, user.grossSalary, user.pensionFund);
 cout<<' '<<endl;
 cout<<taxIncome;
 
    return 0;
}

User getData()
{
    User user;
    
    cout<<"Marital status: ";
    cin>>user.status;
 
    if(strcmp(user.status, "merried")==0){
    cout<<"The number of children under the age of 14: ";
    cin >> user.childNum;
    cout << "the total gross salary of the 2 of you: ";
    cin >> user.grossSalary;
    }
    else{
    user.childNum=0;
    cout<<"The amount of your gross salary: ";
    cin >> user.grossSalary;
    }
    
    cout << "Percentage of gross income contributed to a pension fund: ";
    cin >> user.pensionFund;
 
    return user;
}

double taxAmount(const char* status, int children, int salary, int pensionFund){
    double tax=0;
    if(strcmp(status, "merried")==0 && children == 2){
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

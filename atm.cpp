#include<iostream>
#include<fstream>
using namespace std;

class atm
{
public:
    atm()
    {
        cout<<"Welcome to ATM\n";
    };
    ~atm()
    {
        cout<<"Thanks for using our service\n";
    };
};


int readpin()
{
    int pin;
    ifstream read("pin.txt");
    read>>pin;
    return pin;
    read.close();
}
int readamount()
{
    int Amount;
    ifstream read("amount.txt");
    read>>Amount;
    return Amount;
    read.close();
}
void writepin(int y)
{
    ofstream write("pin.txt");
    write<<y;
    write.close();

}
int writeamount(int x)
{
    ofstream write("amount.txt");
    write<<x;
    write.close();
}

int main()
{
    atm obj;
    int press,pin,n,amount,Balance,currentbalance,npin;
    cout<<"Press the button\n";
    cout<<"1 - Withdraw money\n";
    cout<<"2 - Check Balance\n";
    cout<<"3 - Change pin\n";
    cout<<"4 - Deposit money\n";
    cin>>press;
    switch (press)
    {
    case 1:
        cout<<"Enter a pin\n";
        cin>>pin;
        n=readpin();
        if(n==pin)
        {   
            int amount;
            cout<<"Enter Amount : \n";
            cin>>amount;
            Balance=readamount();
            if(amount<=Balance)
            {
                cout<<"Transiction Successful!\n";
                currentbalance=Balance-amount;
                cout<<"Current Balance is : Rs. "<<currentbalance<<endl;
                writeamount(currentbalance);
            }
            else
            {
                cout<<"Low Balance\n";
            }
        }
        else
        {
            cout<<"wrong pin !\n";
        }
       
        break;
    case 2:
        cout<<"Enter a pin\n";
        cin>>pin;
        n=readpin();
        if(n==pin)
        {
            Balance=readamount();
            cout<<"Current Balance is : Rs. "<<Balance<<endl;
        }
         else
        {
            cout<<"wrong pin !\n";
        }
       
        break;
    case 3:
        cout<<"Enter a pin\n";
        cin>>pin;
        n=readpin();
        if(n==pin)
        {
            cout<<"Enter New Pin\n";
            cin>>npin;
            int cpin;
            cout<<"Confirm New Pin\n";
            cin>>cpin;
            if(npin==cpin)
            {
                writepin(npin);
                cout<<"Pin changed successesfully !\n";
            }
            else
            {
                cout<<"Pin doesn't matched Try again\n";
            }
        }
        else
        {
            cout<<"wrong pin !\n";
        }
       
        break;
    case 4:
        cout<<"Enter a pin\n";
        cin>>pin;
        n=readpin();
        if(n==pin)
        {
            int amount;
            cout<<"Enter Amount : \n";
            cin>>amount;
            Balance=readamount();
            cout<<"Transiction Successful!\n";
            currentbalance=Balance+amount;
            cout<<"Current Balance is : Rs. "<<currentbalance<<endl;
            writeamount(currentbalance);
        }
        else
        {
            cout<<"Wrong Pin !\n";
        }
           
        break;
    
    default:
        cout<<"Invalid input\n";
        break;
    }
    return 0;
}
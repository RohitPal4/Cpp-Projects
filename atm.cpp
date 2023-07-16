#include <iostream>
#include <string>

using namespace std;

class ATM{
    private:
    string account_number;
    string pin;
    double balance;
    public:
    
    ATM(){}
    void set_AccountNumber(string a) {
        account_number = a;
    }

    void set_Pin(string p){
        pin = p;
    }

    void set_Balance(int b) {
        balance = b;
    }

    void check_totalbalance() {
       cout << "your total balance is: ";
       cout << balance << endl;;
    }
  
    bool verify_AccountNumber(string a){
        return account_number == a;
    }
    bool verify_Pin(string p){
        return pin == p;
    }

    void deposit_money(int m){
        balance += m;
    }

    void withdraw_money(int w) {
        balance -= w;
    }

    void reset_pin(string new_pin) {
        pin = new_pin;
    }
    void login_with_newpin() {
    login();
    }
    void login(){
        while (true)
        {
            string new_accountNumber;
            string new_pin;
            cout << "\nPlease enter your account number: ";
            cin >> new_accountNumber;
            cout << "Please enter your pin: ";
            cin >> new_pin;

            if (verify_AccountNumber(new_accountNumber) && verify_Pin(new_pin))
            {
                cout << "\nLogin succesfull!..."<<endl;
                break;
            }
            else{
                cout << "Invalid account number or pin. please try again, "<<endl;
            }

            
        }
        
    }
    void task(){
        while (true)
        {   
            int choice;
            cout << "\npress 1. to check total balance, "<<endl;
            cout << "press 2. to deposit money, " << endl;
            cout << "press 3. to withdraw money, " << endl;
            cout << "press 4. to reset pin, " << endl;
            cout << "press 5. to Login with new pin, " << endl;
            cout << "press 6. to exit program, \n" << endl;
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice == 1) {
                check_totalbalance();
            }
            else if (choice == 2) {
           double money;
            cout << "Enter amount for deposit: ";
            cin >> money;
            deposit_money(money);
           }
           else if (choice == 3) {
            double money;
            cout << "Enter amount for withdraw: ";
            cin >> money;
            withdraw_money(money);
           }
           else if (choice == 4) {
            string new_pin;
            cout << "Enter your new pin: ";
            cin >> new_pin;
            reset_pin(new_pin);
           }
           else if (choice == 5)
           {
            login_with_newpin();
           }
           else if (choice == 6) {
            cout << "Goodbye! Ta c u fir milenge ab main ja rha hoon Sone, "<<endl;
            break;
           }
         
            else {
                cout << "invalid choice please choose valid choice, " << endl;
            }

        }
        
    }

};

int main() {
    ATM account;
    string account_number;
    string pin;
    double balance;
  cout << "\n*******************************************\n"
              << "*   Welcome to my ATM Management System   *\n"
              << "*******************************************\n";
  cout << "Create Account number for your account: ";
  cin >> account_number;
  cout << "Create Pin for your account: ";
  cin >> pin;
  cout << "\nSet your balance for your account: ";
  cin >> balance;
  account.set_AccountNumber(account_number);
  account.set_Pin(pin);
  account.set_Balance(balance);
  cout << "\n*******************************\n"
              << "*   Login your Bank account   *\n"
              << "******************************\n";
  account.login();
  account.task();
  return 0;
}
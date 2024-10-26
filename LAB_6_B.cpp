#include <string>
#include <vector>
#include <iostream>
// Here is the declaration of the User and Bank
using namespace std;
class User {
private:
    string name;
    int deposit;
public:
    User(string name, int deposit);
    User(string name);
    string getName() const;
    int getDeposit() const;
    void setDeposit(int deposit);
    void depositMoney(int money);
    void withdrawMoney(int money);
};

class Bank {
private:
    vector<User> users;
    string name;

public:
    bool addUser(User user);
    bool depositMoney(string name, int money);
    bool withdrawMoney(string name, int money);
    bool transferMoney(string name1, string name2, int money);
};

User::User(string name, int deposit):name(name), deposit(deposit) {}
User::User(string name):name(name), deposit(0) {}
string User::getName() const {
	return name;
}
int User::getDeposit() const {
  	return deposit;
}
void User::setDeposit(int deposit) {
	this->deposit = deposit;
}
void User::depositMoney(int money) {
  	this->deposit += money;
}
void User::withdrawMoney(int money) {
  	this->deposit -= money;
}

bool Bank::addUser (User u) {
  	for (User user : users)
    { if (user.getName() == u.getName())
      return false;}
  	this->users.push_back(u);
  	return true;
}
bool Bank::depositMoney(string name, int money) {
  	for (User user : users)
    { 
        if (user.getName() == name) 
        {
            user.depositMoney(money);
            return true;
        }
    }
    return false;
}
bool Bank::withdrawMoney(string name, int money) {
    for (const auto & user : users)
    { 
        if (user.getName() == name&& user.getDeposit() >= money) 
        {
            user.withdrawMoney(money);
            return true;
        }
    }
    return false;
 }
bool Bank::transferMoney(string name1, string name2, int money)
{
    User * user_1 = nullptr;
    User * user_2 = nullptr;
    for (User user1 : users)
  	    for (User user2 : users)
    {
        if (user1.getName() == name1 && user2.getName() == name2 && user1.getDeposit() >= money && name1 != name2)
        {
            user_1 = & user1;
            user_2 = & user2;
            user_1->withdrawMoney(money);
            user_2->depositMoney(money);
            return true;
        } 
    }
    return false;
}

int main()
{
    using namespace std;
    User Marry("Marry",100);
    User Bruce("Bruce", 30);
    Bank bank;
    bank.addUser(Marry);
    bank.addUser(Bruce);
    cout << bank.transferMoney("Marry", "Bruce", 20)<< endl;
    cout << Marry.getDeposit() << endl;
    return 0;
}
bool Bank::transferMoney(string name1, string name2, int money) {
 User* user1 = nullptr;
 User* user2 = nullptr;

 for (auto& user : users) {
 if (user.getName() == name1) {
 user1 = &user;
 }
 if (user.getName() == name2) {
 user2 = &user;
 }
 }
if (user1 == nullptr || user2 == nullptr|| user1 == user2) {
return false;
 }

if (user1->getDeposit() >= money) {
 user1->withdrawMoney(money);
 user2->depositMoney(money);
 return true;
 } else {
 return false;
 }
}
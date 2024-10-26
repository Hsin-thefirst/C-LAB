#include <iostream>

int remain_wrappers(int wrappers_remain, int required_wrappers, int amount)
{
    using namespace std;
    int temp_amount;
    temp_amount = wrappers_remain/required_wrappers;
    wrappers_remain = temp_amount + wrappers_remain % required_wrappers;
    amount += temp_amount;
    if (wrappers_remain < required_wrappers)
    return amount;
    return remain_wrappers(wrappers_remain, required_wrappers, amount);
}
int main()
{
    using namespace std;
    int money, price, required_wrappers, totol;
    cin >> money >> price >> required_wrappers;
    int amount, wrappers;
    wrappers = money/price;
    amount = remain_wrappers(wrappers, required_wrappers, wrappers);
    cout << amount;
    return 0;
}
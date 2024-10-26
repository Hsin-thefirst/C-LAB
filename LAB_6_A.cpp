#include <iostream>
int count = 0;
void Hanoi(int n, int start, int inter, int end)
{
    static int amount = n;
    using namespace std;
    if (n == 1)
    {
        cout << "move disk "<< n << " from rod "<<start<<" to rod "<< end << endl;
        return;
    }
    Hanoi(n-1, start, end, inter);
    cout << "move disk "<< n <<" from rod "<<start<<" to rod "<< end << endl;
    Hanoi(n-1, inter, start, end);
}

void Hanoitemp(int n, int start, int inter, int end)
{
    static int amount = n;
    using namespace std;
    if (n == 1)
    {
        count++;
        return;
    }
    Hanoitemp(n-1, start, end, inter);
    count++;
    Hanoitemp(n-1, inter, start, end);
}

int main()
{
    using namespace std;
    int num;
    cin >> num;
    Hanoitemp(num, 1, 2, 3);
    cout << count << endl;
    Hanoi(num, 1, 2 ,3);
    return 0;
}
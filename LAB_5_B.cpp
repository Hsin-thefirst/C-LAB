#include <iostream>
#include <string>
class Time
{
    public:
    Time() {
        std::cout << "Time has been set!\n";
    }
    void print() const {
            std::cout << "HEllo world.";
        }
    int hh = 23;
    int mm = 59;
    int ss = 59;
};
int main() {
    using namespace std;
    Time mytime;
    cout << mytime.hh <<endl;
    cout << mytime.mm <<endl;
    cout << mytime.ss <<endl;
    mytime.print();

return 0;

}
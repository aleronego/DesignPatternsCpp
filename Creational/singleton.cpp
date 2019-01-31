#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton(){ cout << "---Creating instance---\n"; };
    Singleton(const Singleton& root) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    static Singleton& instance()
    {
        static Singleton onlyOne;
        return onlyOne;
    }
};

int main()
{
    cout << "Run first time\n";
    Singleton& s = Singleton::instance();

    cout << "Run second time\n";
    Singleton& s2 = Singleton::instance();
    return 0;
} 
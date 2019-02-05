#include <iostream>
using namespace std;

class Subj
{
public: 
    add(int a, int b) { return a+b; }
};

class Proxy
{
private:
    Subj* s;
public:
    Proxy(){ s = new Subj; }
    add(int a, int b) { return s->add(a,b); }
};

int main(int argc, char const *argv[])
{
    Proxy p;
    cout << p.add(5,7);
    return 0;
}
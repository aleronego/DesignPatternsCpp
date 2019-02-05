#include <iostream>
using namespace std;

class A
{
public:
    virtual void doit() = 0;
    virtual ~A() = default;
};

class Core : public A
{
public:
    void doit()
    {
        cout << "Core";
    }
};

class FirstDec : public A
{
A* comp;
public:
    FirstDec(A* a) : comp(a){}
    ~FirstDec(){ delete comp; }
    void doit()
    {
        cout << "First ";
        comp->doit();
    }
};

class SecondDec : public A
{
A* comp;
public:
    SecondDec(A* a) : comp(a){}
    ~SecondDec(){ delete comp; }
    void doit()
    {
        cout << "Second ";
        comp->doit();
    }
};

int main(int argc, char const *argv[])
{
    SecondDec obj(new FirstDec(new Core()));
    obj.doit();
    return 0;
}
#include <iostream>
using namespace std;

class Obj
{
public:
    virtual int action(int) = 0;
};

class Multiplication : public Obj
{
public:
    int action(int num) override
    {
        return num*2;
    }
};


class Division : public Obj
{
public:
    int action(int num) override
    {
        return num/2;
    }
};

class Bridge
{
private:
    Obj* obj;
    int num;
public:
    Bridge(int n, Obj* o) : num(n), obj(o) { }
    ~Bridge(){ delete obj; }
    void out()
    {
        cout << obj->action(num) << endl;
    }
};

int main(int argc, char const *argv[])
{
    const int num = 100;
    Bridge* arr[] = {new Bridge(num, new Division()),
                     new Bridge(num, new Multiplication())
                    };

    for(auto&& it: arr)
    {
       it->out();
       delete it;
    }
    return 0;
}
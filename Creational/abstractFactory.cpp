#include <iostream>
using namespace std;

class AbstractProductA
{
public:
    virtual void doStuff() = 0;
    ~AbstractProductA() = default;
};

class ProductA1 : public AbstractProductA
{
public:
    void doStuff() override
    {
        cout << "ProductA1\n";
    }
};


class ProductA2 : public AbstractProductA
{
public:
    void doStuff() override
    {
        cout << "ProductA2\n";
    }
};

//////////////////////////////

class AbstractProductB
{
public:
    virtual void doStuff() = 0;
    ~AbstractProductB() = default;
};

class ProductB1 : public AbstractProductB
{
public:
    void doStuff() override
    {
        cout << "ProductB1\n";
    }
};

class ProductB2 : public AbstractProductB
{
public:
    void doStuff() override
    {
        cout << "ProductB2\n";
    }
};

//////////////////////////////

class AbstractFactory
{
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    ~AbstractFactory() = default;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA* createProductA() override
    {
        return new ProductA1;
    }
    
    AbstractProductB* createProductB() override
    {
        return new ProductB1;
    }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA* createProductA() override
    {
        return new ProductA2;
    }
    
    AbstractProductB* createProductB() override
    {
        return new ProductB2;
    }
};

int main()
{
    ConcreteFactory1 f1;
    ConcreteFactory2 f2;

    AbstractFactory* factory[]={&f1, &f2};
    for(auto&& product : factory)
    {
        AbstractProductA* A = product->createProductA();
        A->doStuff();
        delete A;

        AbstractProductB* B = product->createProductB();
        B->doStuff();
        delete B;
    }

    return 0;
}
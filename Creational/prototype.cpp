#include <iostream>
using namespace std;

class Product
{
public:
    virtual Product* clone() = 0;
    virtual void info() = 0;
    virtual ~Product() = default;
};

class CurrentProduct : public Product
{
    friend class Factory;
private:
    CurrentProduct()
    {
        cout << "Create CurrentProduct\n";
    };
public:
    Product* clone() override
    {
        return new CurrentProduct(*this);
    }
    void info() override
    {
        cout << "This is Current product\n";
    }
};

class Factory
{
public:
    Product* createProduct()
    {
        static CurrentProduct prototype;
        return prototype.clone();
    }
};

int main()
{
    Factory f;
    Product* p = f.createProduct();
    p->info();

    Product* p2 = f.createProduct();
    p2->info();

    return 0;
}
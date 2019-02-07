#include <iostream>
#include <string>
using namespace std;

class Colleague;// error: 'Colleague' has not been declared

class Mediator
{
public:
    virtual void send(string, Colleague*) = 0;
};

class Colleague
{
protected:
    Mediator* mediator;
public:
    explicit Colleague(Mediator* m) : mediator(m) {}
};

class ConcreteA : public Colleague
{
public:
    explicit ConcreteA(Mediator* me) : Colleague(me) {}
    void notify(string s) 
    {
        cout << "Colleague A gets message " << s << endl;
    }
    void sendMsg(string s)  { mediator->send(s, this); }
};

class ConcreteB : public Colleague
{
public:
    explicit ConcreteB(Mediator* me) : Colleague(me) {}
    void notify(string s) 
    {
        cout << "Colleague B gets message " << s << endl;
    }
    void sendMsg(string s)  { mediator->send(s, this); }
};

class ConcreteMediator : public Mediator
{
protected:
    ConcreteA* cA;
    ConcreteB* cB;
public:
    void setA(ConcreteA* c) { cA = c; }
    void setB(ConcreteB* c) { cB = c; }
    void send(string s, Colleague* c) override
    {
        if(c==cA)
            cA->notify(s);
        else if(c==cB)
            cB->notify(s);
        else
            cout << "Wrong Colleague\n";
    }
};

int main(int argc, char const *argv[])
{
    ConcreteMediator m;
    ConcreteA A(&m);
    ConcreteB B(&m);

    m.setA(&A);
    m.setB(&B);

    A.sendMsg("Hello!");
    B.sendMsg("Hi too");

    return 0;
}
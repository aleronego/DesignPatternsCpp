#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Action
{
    friend class Chain;
    int difficulty;
    string name;
public:
    Action(int d, string n) : difficulty(d), name(n) {}
};

class Chain
{
    int skill;
    string name;
    shared_ptr<Chain> next;
    void doWork(string s) { 
        cout << name << " can handle " << s << endl; 
    }
public:
    Chain(int s, string n) : skill(s), name(n) {};

    shared_ptr<Chain> setNext(shared_ptr<Chain> n)
    {
        next = move(n);
        return next;
    }

    void process(shared_ptr<Action> action)
    {
        if(skill < action->difficulty)
        {
            if(next)
                next->process(move(action));
            else
                cout << "No one can handle " << action->difficulty << endl;
        } else {
            doWork(action->name);
        }
    }
};
 
int main(int argc, char const *argv[])
{
    shared_ptr<Chain> handle = make_shared<Chain>(3, "First 3");
    handle->setNext(make_shared<Chain>(5, "Second 5"))
          ->setNext(make_shared<Chain>(9, "Third 9"));

    shared_ptr<Action> arr[] {
            make_shared<Action>(2, "two"),
            make_shared<Action>(5, "five"),
            make_shared<Action>(11, "eleven"),
            make_shared<Action>(8, "eight") 
    };

    for(auto&& act : arr)
        handle->process(act);
    
    return 0;
}
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
    weak_ptr<Chain> next = weak_ptr<Chain>();
    void doWork(string s) { 
        cout << name << " can handle " << s << endl; 
    }
    
public:
    //Chain(int s) : skill(s);
    Chain(int s, string n) : skill(s), name(n) {};
    //~Chain() { if(next) delete next; }

    shared_ptr<Chain> setNext(shared_ptr<Chain> n)
    {
        next = move(n);
        return move(next);
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
    // Chain* handle = new Chain(3, "First 3");
    // handle->setNext(new Chain(5, "Second 5"))
    //   ->setNext(new Chain(9, "Third 9"));

    // Action* arr[] {
    //         new Action(2, "two"),
    //         new Action(5, "five"),
    //         new Action(11, "eleven"),
    //         new Action(8, "eight") 
    // };


    shared_ptr<Chain> handle(new Chain(3, "First 3"));
    handle->setNext(make_shared<Chain>(5, "Second 5"))
      ->setNext(make_shared<Chain>(9, "Third 9"));

    Action* arr[] {
            new Action(2, "two"),
            new Action(5, "five"),
            new Action(11, "eleven"),
            new Action(8, "eight") 
    };
    for(auto&& act : arr)
    {
        handle->process(act);
        delete act;
    }
    return 0;
}
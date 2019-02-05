#include <iostream>
#include <memory>
using namespace std;

class Timer
{
    string time;
public:
    Timer(string t) : time(t){}
    void doit() { cout << time << " "; }
};

class PomodoroFacade
{
unique_ptr<Timer> pomodoro;
unique_ptr<Timer> shortPause;
unique_ptr<Timer> longPause;
public:
    PomodoroFacade()
    {
        pomodoro = make_unique<Timer>("25");
        shortPause = make_unique<Timer>("5");
        longPause = make_unique<Timer>("15");
    }

    void start()
    {
        cout << "Start Pomodoro cycle\n";
        pomodoro->doit();
        shortPause->doit();
        pomodoro->doit();
        shortPause->doit();
        pomodoro->doit();
        shortPause->doit();
        pomodoro->doit();
        shortPause->doit();
        longPause->doit();
        cout << "\nEnd Pomodoro cycle\n";
    }
};

int main(int argc, char const *argv[])
{
    unique_ptr<PomodoroFacade> timer(new PomodoroFacade);
    timer->start();
    return 0;
}
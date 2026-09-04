#include "standard.h"
using namespace std;

// A functor is an object that behaves like a function.
// It becomes callable by overloading operator().
struct Greeting
{

    // This function is called when a Greeting object is followed by (...).
    // const means calling the functor does not modify its state.
    void operator()(const string &name) const
    {
        cout << "Hello there: " << name << " " << endl;
    }
};

struct Multiplier
{

    int operator()(int a, int b)
    {
        return a * b;
    }
};

int main()
{
    // Create an instance of the functor, just like creating any other object.
    Greeting g1;

    // The object can now be used with function-call syntax.
    string name;
    cout << "Enter your name: ";
    cin >> name;
    g1(name);

    Multiplier multiply;
    int result = multiply(3, 7);
    cout << result;

    return 0;
}
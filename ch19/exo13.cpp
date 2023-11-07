#include "iostream"

/*
 * Tracer class which prints string in constructor & destructor.
 * Strings are constructor arguments.
 * Experiment where RAII management objects do their job -->
 * Look at: local objects, member objects, global objects, allocated by new etc.
 * Add copy constructor and copy assignment to use Tracer when copying is done
 */

class Tracer
{
public:
    Tracer(std::string str) { std::cout<<str<<std::endl; }
    ~Tracer() { std::cout<<"Deleting..."<<std::endl; }
private:
};

struct Foo
{
    // member object
    Tracer member_tracer{"This is a member tracer"};
};

// Global object
Tracer global_tracer {"This is a global tracer"};

// Local object
void f()
{
    Tracer local_tracer {"This is a local tracer"};
    Foo foo;
}

// Object allocated by new
Tracer* f2()
{
    return new Tracer{"This is a heap tracer"};
}

int main()
{
    f();
    std::cout<<"Now the heap...\n";
    Tracer* heap_tracer = f2();
    heap_tracer->~Tracer();
    std::cout<<"After the heap...\n";
    return 0;
}

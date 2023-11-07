#include "iostream"
#include "stdexcept"

// Implement a simple unique_ptr
// Supports: constructor, destructor, ->, *, and release()
// Don't implement an assignment of copy constructor

// Unique ptr:
//  Object that holds a pointer
//  Initialise with pointer we get from new
//  Owns the object it points to (when destroyed, deletes object pointed to)
//  p.release() extracts contained pointer from p, and makes p hold nullptr
//  RESTRICTION: cannot assigne one unique_ptr to another

template<typename T>
class unique_ptr
{
public:
    unique_ptr() : ptr{nullptr} {}  // default constructor
    unique_ptr(T* p) : ptr{p} {}    // constructor
    ~unique_ptr() { delete ptr; }   // destructor
    
    T operator*() { return *ptr; };

    T* release() { T* p = ptr; ptr = nullptr; return p; }   // extracts and returns pointer
private:
    T* ptr;
};

unique_ptr<int> f1(int n)
{
    unique_ptr<int> p {new int{n}};
    return p;
}

double* f2(double n)
{
    unique_ptr<double> p {new double{n}};
    return p.release();
}

int main()
try {
    std::cout << "Start of main\n";

    unique_ptr<int> p1 = f1(11);

    std::cout << "Pointer contents: " << *p1 << '\n';

    //throw std::runtime_error("Was u_p destructed?");

    double* p2 = f2(2.71828);

    std::cout << "Pointer contents: " << *p2 << '\n';
    delete p2;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

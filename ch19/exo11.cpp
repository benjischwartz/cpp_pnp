#include "iostream"
#include "stdexcept"

/*
 * Counted_ptr<T> that holds a pointer to an object of type T and a pointer to a "use count"(int)
 * shared by all counted pointers to the same object of type T.
 * Use count should hold number of counted pointers pointing to a given T.
 * Let counted_ptr's constructor allocate a T object & use count on free store.
 * Let counted_ptr's constructor take an argument to be used as initial value of the T elements.
 * When last counted_ptr for a T is destroyed, destructor should delete T.
 * Give counted_ptr operations that allow us to use it as a pointer.
 * Is an example of "smart pointer" used to ensure object doesn't get destroyed until after last user is done.
 * Write test cases using it as argument in callss, container elements, etc.
 */

template<typename T>
class counted_ptr
{
public:

    counted_ptr(T t);                   // Constructor
    counted_ptr(counted_ptr<T> const &cp);     // Constructor
    ~counted_ptr();                     // Destructor
    
    T& operator*() { return *ptr; }    // * operator
    T* operator->() { return ptr; }    // * operator
    
    void print_count() { std::cout << "Use count: " << *use_count << std::endl; }

private:

    T* ptr;
    int* use_count;

};

template<typename T>
counted_ptr<T>::counted_ptr(T t)
{
    ptr = new T{t};          // Allocate T object & use count
    use_count = new int{1};
}

template<typename T>
counted_ptr<T>::counted_ptr(counted_ptr<T> const &cp) : ptr{cp.ptr}, use_count{cp.use_count}
{
    ++*use_count;
}

template<typename T>
counted_ptr<T>::~counted_ptr() {
    if (use_count != nullptr) {
        // decrement use_count
        --*use_count;

        // when last counted_ptr destroyed, delete T
        if (*use_count == 0) {
            delete ptr;
            delete use_count;
        }
    }
}

// Create a local copy of the counted pointer, check deletion after leaving scope
// NB: pass by reference, otherwise additional local copy created
template<typename T>
void f(counted_ptr<T> &cp) 
{
    counted_ptr<T> copy {cp};
    std::cout<<"In function...\n";
    copy.print_count();
    cp.print_count();
    std::cout<<"Exiting function...\n";
}

int main() 
{
    // Construct new counted_ptr for int type
    std::cout<<"Constructing cp1...\n";
    counted_ptr<int> cp1 {10};
    cp1.print_count();
    std::cout<<"Constructing cp2...\n";
    counted_ptr<int> cp2 {cp1};
    cp2.print_count();
    cp1.print_count();
    f(cp1);
    cp1.print_count();
}

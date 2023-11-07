#include "std_lib_facilities.h"

// Implement an allocator using the basic allocations functions malloc() and free()
// Hint: Look up "placement new" and "explicit call of destructor"

// Allocator notes:
// Provides a way of getting uninitialized memory

template<typename T> 
class allocator {
public:
    // ...

    // allocate space for n objects of type T
    T* allocate (int n) { return malloc(n * sizeof(T)); }

    // deallocate n objects of type T starting at p
    void deallocate(T* p, int n) { free_sized(p, n*sizeof(T)); }

    // construct a T with value v in p
    void construct(T* p, const T& v) { new(p) T{v}; }   

    // destroy the T in p
    void destroy(T* p) { p->~T()}; 
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T, typename A = allocator<T>>
class vector {
    A alloc;        // use allocator to handle memory for elements
    int sz;
    T* elem;
    int space;
public:
    vector() : sz{0}, elem{nullptr}, space{0} { }
    explicit vector(int s) : sz{s}, elem{new T[s]}, space{s}
    {
        for (int i = 0; i < sz; ++i) elem[i] = 0;
    }

    vector(const vector& a)                 // copy constructor
        : sz{a.sz}, elem{new T[a.sz]}, space{a.sz}
    {
        for (int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i];
    }
    // Exercise 9
    vector& operator=(const vector& a)          // copy assignment
    {
        T* p = alloc.allocate(a.sz);            // allocate new space
        for (int i = 0; i < a.sz; ++i)
            alloc.construct(&p[i], a.elem[i]);  // copy elements
        alloc.deallocate(elem);                 // deallocate old space
        space = sz = a.sz;
        elem = p;
        return *this;
    }

    vector(vector&& a)                      // move constructor
        : sz{a.sz}, elem{a.elem}, space{a.space}
    {
        a.sz = 0;
        a.elem = nullptr;
    }
    vector& operator=(vector&& a)           // move assignment
    {
        delete[] elem;                      // deallocate old space
        elem = a.elem;                      // copy a's members
        sz = a.sz;
        space = a.sz;
        a.elem = nullptr;                   // make a the empty vector
        a.sz = 0;
        a.space = 0;
        return *this;
    }

    ~vector() { delete[] elem; }            // destructor

    T& at(int n);                           // checked access
    const T& at(int n) const;               // checked access

    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

    int size() const { return sz; }
    int capacity() const { return space; }

    void reserve(int newalloc);
    void push_back(const T& d);
    void resize(int newsize, T val = T());
};

template<typename T, typename A> T& vector<T,A>::at(int n)
{
    if (n < 0 || sz <= n)
        throw std::range_error("out of range vector access");
    return elem[n];
}

template<typename T, typename A> const T& vector<T,A>::at(int n) const
{
    if (n < 0 || sz <= n)
        throw std::range_error("out of range vector access");
    return elem[n];
}

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= space) return;          // never decrease allocation
    T* p = alloc.allocate(newalloc);        // allocate new space
    for (int i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]);   // copy
    for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);           // destroy
    alloc.deallocate(elem);                 // deallocate old space
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& val)
{
    if (space == 0) reserve(8);             // start with space for 8 elements
    else if (sz == space) reserve(2 * space);   // get more space
    alloc.construct(&elem[sz], val);
    ++sz;
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val);
    for (int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
    sz = newsize;
}

int main()
{
    //
}


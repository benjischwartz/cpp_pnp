#include "Link.h"

// insert n before this object
Link* Link::insert(Link *n)
{
    if (n==nullptr) return this;
    if(this==nullptr) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

// insert n after this object
Link* Link::add(Link* n)
{
    if (n==nullptr) return this;
    if(this==nullptr) return n;
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

// insert n in correct lexicographical position
// return head of list
Link* Link::add_ordered(Link* n)
{
    if (n==nullptr) return this;
    if(this==nullptr) return n;
    Link* p = this;                 // Keep track of current Link in list
    while (p!=nullptr) {
        if (n->value < p->value) {      // n comes before p
            if (!p->prev) {             // n is now at head of list
                p->prev = n;
                n->succ = p;
                return n;
            } else if (n->value > p->prev->value) {     // insert n before p
                p->insert(n);
                break;
            }
            p = p->prev;        
        }
        if (n->value > p->value) {      // n comes after p
            if (!p->succ) {             // n is now tail of list
                p->succ = n;
                n->prev = p;
                break;
            } else if (n->value < p->succ->value) {     // insert n after p
                p->add(n);
                break;
            }
            p = p->succ;
        }
        else {              // n has same value as p (default to insert)
            p->insert(n);
            break;
        }
    }
    Link* h = this;
    while (h->prev!=nullptr) {
        h = h->prev;
    }
    return h;
}

// return this' successor
Link* Link::erase() {
    if (this==nullptr) return nullptr;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

Link* Link::find(const string& s)
{
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

Link* Link::advance(int n) const
{
    if (this==nullptr) return nullptr;
    // necessary to copy pointer to const Link* to non-const Link*
    Link* p = const_cast<Link*>(this);
    if (0<n) {
        while(n--) {
            if (p->succ == nullptr) return nullptr;
            p = p->succ;
        }
    }
    else if (n<0) {
        while (n++) {
            if (p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
}


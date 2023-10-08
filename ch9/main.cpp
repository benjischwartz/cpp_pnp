#include "std_lib_facilities.h"
#include "exo2.h"

using namespace NamePairs;

int main()
{
    Name_pairs np;
    np.read_names();
    np.read_ages();
    try {
        cout<<"Original:\n";
        np.print();
        cout<<"\nSorted:\n";
        np.sort();
        np.print();
    } catch(Name_pairs::Invalid) {
        error("invalid name pairs");
    }
    return 0;
}

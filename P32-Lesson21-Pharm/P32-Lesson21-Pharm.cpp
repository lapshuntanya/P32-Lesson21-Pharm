#include "Medicine.h"

int main()
{
    Medicine a; //"undefined"
    Medicine b("Aspirin", TYPES::pills, 20.55, "India");
    const Medicine c("Nurofen", TYPES::capsules, 35, "Italy");
    
    a.showInfo();
    b.showInfo();
    c.showInfo();

}



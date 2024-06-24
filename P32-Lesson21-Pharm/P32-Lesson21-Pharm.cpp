#include "Medicine.h"

int main()
{
    Medicine a; //"undefined"
    Medicine b("Aspirin", TYPES::pills, 20.55, "India");
    const Medicine c("Nurofen", TYPES::capsules, 35, "Italy");
    
    a.showInfo();
    b.showInfo();
    c.showInfo();
    cout << "+++++++++++++++++++++++++++++\n";

    Medicine e = b; //"Aspirin"
    //e-this   =  b-obj
    e.setTitle("Aspirin Forte");

    b.showInfo();
    e.showInfo();


}



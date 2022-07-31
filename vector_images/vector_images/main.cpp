#include "FigureManager.h"
#include "InputManager.h"
#include <fstream>

/*!\
 *
 * The sole purpose of this programme is to operate with svg files. <br>
 * Currently the system can do basic file operations. <br>
 *
 * <br> Viktoriya Petkova, Informatics, FN: 45726, 4th group.
 */


int main()
{
    string file = "test.txt";
    InputManager test;
    test.open(file);
    test.print();
    test.create();
    test.print();
    test.save(file);
}


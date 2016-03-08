/* s01e04 */

#include <iostream>
#include "Triangle3D.hpp"
using namespace std;

int main()
{
	Triangle3D t;

	t.user_init();
	cout << "perimeter: " << t.perimeter() << endl;
	cout << "triangle " << (t.isocele()?"is":"is not") << " isocele" << endl;

	return 0;
}

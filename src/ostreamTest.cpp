#include "ostreamTest.h"
#include <ostream>
#include <iostream>
using namespace std;

Test::Test() {
        cout <<"Test constructor"<<endl;
        testID=1;

}

std::ostream& operator<<(ostream &os, const Test& t){

        os<<t.testID;
        return os;
}

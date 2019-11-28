#ifndef OSTREAMTEST_H
#define OSTREAMTEST_H
#include <ostream>

class Test{
private:
    int testID;
public:
    Test();
    friend std::ostream& operator<<(std::ostream &os, const Test& t);
};

std::ostream& operator<<(std::ostream &os, const Test& t);

#endif // OSTREAMTEST_H

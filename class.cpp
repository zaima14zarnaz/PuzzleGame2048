#include "header.h"


class block
{
public:
    int num;
    block()
    {
        num = 0;
    }
    block(int num)
    {
        this->num = num;
    }
    friend ostream& operator<<(ostream &out, block a)
    {
        out << a.num ;
    }
};

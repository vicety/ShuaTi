#ifndef LINKEDLISTERROR_H
#define LINKEDLISTERROR_H

#include<string>
using namespace std;

class IndexOutOfRange
{
public:
    IndexOutOfRange(int validLen, int index);
    string what();
private:
    int validlen, index;
};

#endif // LINKEDLISTERROR_H

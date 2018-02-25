#ifndef AVLERROR_H
#define AVLERROR_H


#include<string>
using namespace std;

class DeleteInexistentValue
{
public:
    DeleteInexistentValue(int val);
    string what() const;
private:
    int val;
};

#endif // AVLERROR_H

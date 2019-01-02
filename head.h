#ifndef HEAD_H
#define HEAD_H

#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include <numeric>

using namespace std;

inline ostream &operator << (ostream& os, vector<bool> &vec)
{
    for(vector<bool>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
       os << *iter;

    return os;
}

#endif // HEAD_H

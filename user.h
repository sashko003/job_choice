#ifndef USER_H
#define USER_H
#include "header.h"

class User
{
public:
    User();
    User(string _name, map<string, float> _skills);

    set(string _name, map<string, float> _skills);
    set(string _name, vector<float> _values);
private:
    string StrName;
    map<string, float> MapSkills;
};

#endif // USER_H

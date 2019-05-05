#include "user.h"

User::User()
{

}

User::User(std::string _name, map<std::string, float> _skills)
{
    set(_name, _skills);
}

User::set(std::string _name, map<std::string, float> _skills)
{
    StrName = _name;
    MapSkills = _skills;
}

User::set(std::string _name, vector<float> _values)
{
    this->StrName = _name;
    vector<float>::iterator val = _values.begin();
    for(map<string, float>::iterator skill = MapSkills.begin();
        skill != MapSkills.end();
        ++skill){
        MapSkills[skill->first] = *val;
        ++val;
    }
}

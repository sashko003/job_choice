#include "user.h"

User::User()
{
    vector<string> features = {"швидкість та гнучкість мислення",
                               "вміння швидко приймати рішення",
                               "стійкість та концентрація уваги",
                               "зорова память",
                               "швидкість реакції",
                               "рухлива память",
                               "фізична виносливість",
                               "координація рухів",
                               "емоційно-вольова стійкість",
                               "відповідальність"
    };
    std::pair<string, float> temp;
    for(vector<string>::const_iterator it = features.begin();
        it != features.end();
        ++it){
        temp.first = *it;
        temp.second = 0.0;
        MapSkills.insert(temp);
    }
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

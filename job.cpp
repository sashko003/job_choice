#include "job.h"

Job::Job()
{

}

Job::Job(std::string _name, map<std::string, float> _features)
{
    set(_name, _features);
}

Job::Job(std::string _name, vector<std::string> _features, vector<float> _values)
{
    set(_name, _features, _values);
}

void Job::set(std::string _name, map<std::string, float> _features)
{
    this->StrName = _name;
    this->MapFeatures = _features;
}

void Job::set(std::string _name, vector<std::string> _features, vector<float> _values)
{
    this->StrName = _name;
    vector<float>::iterator val = _values.begin();
    std::pair<string, float> temp;
    for(vector<string>::iterator feature = _features.begin();
        feature != _features.end();
        ++feature){
        temp.first = *feature;
        temp.second = *val;
        MapFeatures.insert(temp);
        ++val;
    }
}

std::string Job::getName() const
{
    return StrName;
}

map<std::string, float> Job::getFeatures() const
{
    return MapFeatures;
}

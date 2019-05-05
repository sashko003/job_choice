#ifndef JOB_H
#define JOB_H
#include "header.h"

class Job
{
public:
    Job();
    Job(string _name, map<string, float> _features);
    Job(string _name, vector<string> _features, vector<float> _values);

    void set(string _name, map<string, float> _features);
    void set(string _name, vector<string> _features, vector<float> _values);
    string getName() const;
    map<string, float> getFeatures() const;

protected:
    string StrName;
    map<string, float> MapFeatures;
};

#endif // JOB_H

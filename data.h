#ifndef DATA_H
#define DATA_H

#include "list.h"

class Data
{
public:
    Data();
    Data(const LIST<double> features);
    void addFeature(const double &data);
    void setFeatures(const LIST<double> &features);
    void feature(const int &index, const double &data);
    LIST<double> *getFeatures();
    void setCluster(const int &cluster);
    int *getCluster();

    // private attr
private:
    LIST<double> features;
    int cluster;
};

#endif // DATA_H

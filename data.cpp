#include "data.h"

Data::Data() :
    cluster(0)
{

}

Data::Data(const LIST<double> _features) :
    cluster(0)
{
    features = _features;
}

void Data::addFeature(const double &_data)
{
    features.append(_data);
}

void Data::setFeatures(const LIST<double> &_features)
{
    features = _features;
}

void Data::feature(const int &index, const double &data)
{
    features[index] = data;
}

LIST<double> *Data::getFeatures()
{
    return &features;
}

void Data::setCluster(const int &_cluster)
{
    cluster = _cluster;
}

int *Data::getCluster()
{
    return &cluster;
}

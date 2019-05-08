#ifndef KMEANS_H
#define KMEANS_H

#include "tableview.h"
#include "modelindex.h"
#include "clustering_global.h"
#include "data.h"
#include "abstractitemmodel.h"
#include "list.h"

class CLUSTERINGSHARED_EXPORT Kmeans
{
public:
    Kmeans(TABLEVIEW *tableView, ABSTRACT_TABLE_MODEL *itemModel, const int &numOfCluster);
    ~Kmeans();
    LIST<Data *> *execKMeans();

    //private func
private:
    void init();
    double getDist(Data *data, Data *centroid);

    // private attr
private:
    TABLEVIEW *tableView;
    ABSTRACT_TABLE_MODEL *itemModel;
    LIST<Data *> dataSet;
    LIST<Data *> centroids;
    int totalData;
    int totalFeatures;
    int numOfCluster;
};

#endif // KMEANS_H

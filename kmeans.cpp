#include <cmath>
#include <QDebug>

#include "kmeans.h"
#include "float.h"

Kmeans::Kmeans(TABLEVIEW *tableView, ABSTRACT_TABLE_MODEL *itemModel, const int &numOfCluster):
    tableView(tableView),
    itemModel(itemModel),
    numOfCluster(numOfCluster)
{

}

/**
 * @brief Kmeans::~Kmeans
 * hapus dataset dan centroids
 */
Kmeans::~Kmeans()
{
    for (int i = 0; i < dataSet.length(); ++i) {
        delete dataSet.at(i);
    }

    for (int i = 0; i < centroids.length(); ++i) {
        delete centroids.at(i);
    }
}


/**
 * Hitung KMeans
 *
 */
LIST<Data *> *Kmeans::execKMeans()
{
    if(!tableView->selectionModel()->hasSelection()){
        return nullptr;
    }
    init();

    double minimum = DBL_MAX;
    double distance = 0.0;
    int cluster = 0;

    bool move = true;

    while(move) {
        move = false;
        // tentukan setiap data masuk ke cluster mana
        for (int i = 0; i < dataSet.length(); ++i) {
            Data *ptrData = dataSet.at(i);
            minimum = DBL_MAX;
            for (int j = 0; j < numOfCluster; ++j) {
                distance = getDist(ptrData, centroids.at(j));
                if (distance < minimum) {
                    minimum = distance;
                    cluster = j;
                }
            }
            if (*ptrData->getCluster() != cluster) {
                ptrData->setCluster(cluster);
                move = true;
            }
        }

        if (!move) {
            break;
        }

        // hitung centroid baru
        for (int i = 0; i < numOfCluster; ++i) {

            double features[totalFeatures];
            memset(features, 0, sizeof (features));

            size_t totalInCluster = 0;
            for (int j = 0; j < dataSet.length(); ++j) {
                if (*dataSet.at(j)->getCluster() == i) {
                    for (int k = 0; k < totalFeatures; ++k) {
                        features[k] += dataSet.at(j)->getFeatures()->at(k);
                    }
                    totalInCluster++;
                }
            }

            qDebug() << QString("Centroids %1, cluster meber : %2").arg(i).arg(totalInCluster);

            if (totalInCluster > 0) {
                for (int j = 0; j < totalFeatures; ++j) {
                    centroids.at(i)->feature(j, (features[j]/totalInCluster));
                }
            }
        }
    }

    //
    for (int i = 0; i < numOfCluster; ++i) {

        qDebug() << QString("Centroid : %1").arg(i);
        for (int j = 0; j < totalFeatures; ++j) {
            qDebug() << centroids.at(i)->getFeatures()->at(j);
        }
        for (int j = 0; j < dataSet.length(); ++j) {
            if (*dataSet.at(j)->getCluster() == i) {
                qDebug() << QString("Member : %1, %2").arg(dataSet.at(j)->getFeatures()->at(0))
                            .arg(dataSet.at(j)->getFeatures()->at(1));
            }
        }
    }

    return &dataSet;
}

/**
 * @brief Kmeans::init
 * init : memasukkan data ke dataset dan membangun centroid
 */
void Kmeans::init()
{
    MODELINDEX_LIST modelIndexList = tableView->selectionModel()->selectedIndexes();
    totalData = modelIndexList.last().row() - modelIndexList.first().row() + 1;
    totalFeatures = modelIndexList.last().column() - modelIndexList.first().column() + 1;

    int firstCol = modelIndexList.first().column();
    int lastCol = modelIndexList.last().column();

    int dataIndex = 0;

    while(dataSet.length() < totalData){
        QList<double> features;
        Data *data;
        for (int i = firstCol; i <= lastCol; ++i) {
            double currentFeature = itemModel->index(dataIndex, i).data().toDouble();
            features.append(currentFeature);
        }
        data = new Data(features);
        dataSet.append(data);
//        if (centroids.length() < numOfCluster) {
//            centroids.append(new Data(features));
//        }
        dataIndex++;
    }

    // init centroids
    for (int i = 0; i < numOfCluster; ++i) {
        QList<double> *features = dataSet.at(i)->getFeatures();
        centroids.append(new Data(*features));
    }

}

/**
 * @brief Kmeans::getDist
 * @param data
 * @param centroid
 * @return jarak centroid dengan data
 *
 * hitung jarak euclidean distance
 */
double Kmeans::getDist(Data *data, Data *centroid)
{
    double a = 0;
    for (int i = 0; i < totalFeatures; ++i) {
        a += std::pow(centroid->getFeatures()->at(i) - data->getFeatures()->at(i), 2);
    }

    return std::sqrt(a);
}

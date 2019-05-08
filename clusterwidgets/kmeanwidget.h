#ifndef KMEANWIDGET_H
#define KMEANWIDGET_H

#include <QWidget>

#include "list.h"
#include "variant.h"

namespace Ui {
class KMeanWidget;
}

class KMeanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KMeanWidget(const LIST<STRING> &clusterList, QWidget *parent = nullptr);
    ~KMeanWidget();
    void init();
    void setClusterNumber(const int &clusterNumber);

    // private attr
private:
    Ui::KMeanWidget *ui;
    LIST<STRING> clusterList;
    int clusterNumber;
};

#endif // KMEANWIDGET_H

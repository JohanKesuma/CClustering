#include "clusterwidgets/kmeanwidget.h"
#include "ui_kmeanwidget.h"

KMeanWidget::KMeanWidget(const LIST<STRING> &clusterList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KMeanWidget),
    clusterList(clusterList)
{
    ui->setupUi(this);

    init();
}

KMeanWidget::~KMeanWidget()
{
    delete ui;
}

void KMeanWidget::init()
{
    for (int i = 0; i < clusterList.size(); ++i) {
        ui->clusterList->addItem(clusterList.at(i));
    }
}

void KMeanWidget::setClusterNumber(const int &clusterNumber)
{
    this->clusterNumber = clusterNumber;
    ui->clusterLabel->setText(STRING("Cluster %1").arg(clusterNumber));
}

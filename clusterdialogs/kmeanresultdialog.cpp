#include "clusterdialogs/kmeanresultdialog.h"
#include "ui_kmeanresultdialog.h"
#include "clusterwidgets/kmeanwidget.h"

KMeanResultDialog::KMeanResultDialog(LIST<Data *> *dataSet, const size_t &numOfCluster, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KMeanResultDialog),
    numOfCluster(numOfCluster),
    dataSet(dataSet)
{
    ui->setupUi(this);

    init();
}

KMeanResultDialog::~KMeanResultDialog()
{
    delete ui;
}

void KMeanResultDialog::init()
{
    for (size_t i = 0; i < numOfCluster; ++i) {
        LIST<STRING> dataSetStr;
        for (int j = 0; j < dataSet->size(); ++j) {
            if(*dataSet->at(j)->getCluster() == i){
                dataSetStr.append(STRING("%1").arg(j));
            }
        }
        ui->clusterTabWidget->addTab(new KMeanWidget(dataSetStr, this), STRING("Cluster %1").arg(i));
    }
}

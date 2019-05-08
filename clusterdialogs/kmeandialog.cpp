#include "clusterdialogs/kmeandialog.h"
#include "ui_kmeandialog.h"
#include "kmeanresultdialog.h"
#include "data.h"
#include "list.h"

KMeanDialog::KMeanDialog(TABLEVIEW *tableView, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KMeanDialog),
    tableView(tableView)
{
    ui->setupUi(this);
    setFixedSize(this->size());
}
KMeanDialog::~KMeanDialog()
{
    delete ui;
}

/**
 * @brief KMeanDialog::on_cancelButton_clicked
 *
 *  Cancel button click
 */
void KMeanDialog::on_cancelButton_clicked()
{
    this->close();
}

/**
 * @brief KMeanDialog::on_okButton_clicked
 *
 * Ok Button click
 */
void KMeanDialog::on_okButton_clicked()
{
    int numOfCluster = ui->numOfClusterLineEdit->text().toInt();
    Kmeans kMeans(tableView, (ABSTRACT_TABLE_MODEL*)tableView->model(), numOfCluster);
    LIST<Data *> *dataSet = kMeans.execKMeans();
    KMeanResultDialog resultDialog(dataSet, numOfCluster, this);
    resultDialog.exec();
    this->close();
}

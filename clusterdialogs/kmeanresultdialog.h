#ifndef KMEANRESULTDIALOG_H
#define KMEANRESULTDIALOG_H

#include <QDialog>

#include "data.h"
#include "list.h"

namespace Ui {
class KMeanResultDialog;
}

class KMeanResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KMeanResultDialog(LIST<Data *> *dataSet, const size_t &numOfCluster, QWidget *parent = nullptr);
    ~KMeanResultDialog();
    void init();

private:
    Ui::KMeanResultDialog *ui;
    size_t numOfCluster;
    LIST<Data *> *dataSet;
};

#endif // KMEANRESULTDIALOG_H

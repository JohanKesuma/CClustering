#ifndef KMEANDIALOG_H
#define KMEANDIALOG_H

#include <QDialog>

#include "tableview.h"

#include "kmeans.h"

namespace Ui {
class KMeanDialog;
}

class KMeanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KMeanDialog(TABLEVIEW *tableView, QWidget *parent = nullptr);
    ~KMeanDialog();

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::KMeanDialog *ui;
    TABLEVIEW *tableView;

};

#endif // KMEANDIALOG_H

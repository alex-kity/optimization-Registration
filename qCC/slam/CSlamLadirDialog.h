#ifndef CSLAMLADIRDIALOG_H
#define CSLAMLADIRDIALOG_H

#include <QDialog>
#include "ccOverlayDialog.h"
namespace Ui {
class CSlamLadirDialog;
}

class CSlamLadirDialog :public ccOverlayDialog
{
    Q_OBJECT

public:
    explicit CSlamLadirDialog(QWidget *parent = nullptr);
    ~CSlamLadirDialog();

private:
    Ui::CSlamLadirDialog *ui;
};

#endif // CSLAMLADIRDIALOG_H

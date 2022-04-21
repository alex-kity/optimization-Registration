#include "CSlamLadirDialog.h"
#include "ui_CSlamLadirDialog.h"


CSlamLadirDialog::CSlamLadirDialog(QWidget *parent) :
    ccOverlayDialog(parent),
    ui(new Ui::CSlamLadirDialog)
{
    ui->setupUi(this);
}

CSlamLadirDialog::~CSlamLadirDialog()
{
    delete ui;
}

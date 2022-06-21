#include "frmplot.h"
#include "ui_frmplot.h"

frmplot::frmplot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmplot)
{
    ui->setupUi(this);
    //    m_pgridLayout_viewimage
    qApp->installEventFilter(this);

//    QWidget* pTitleWidget = ui->dockWidget ->titleBarWidget();
//    QWidget* pWidget = new QWidget;
//    ui->dockWidget ->setTitleBarWidget(pWidget );
//    delete pTitleWidget ;

}

frmplot::~frmplot()
{
    delete ui;
}

bool frmplot::eventFilter(QObject *watched, QEvent *event)
{
    //    if (watched->inherits("QAbstractButton")) {
    if(watched == ui->dockWidget){
        if (event->type() == QEvent::Resize) {

            if((ui->dockWidgetContents->height() *100) /1.5 <= (ui->dockWidgetContents->width()*100))
            {
                ui->m_pgridLayout_viewimage->addWidget(ui->label_front,0,1);
                ui->m_pgridLayout_viewimage->addWidget(ui->label_back,0,2);
                ui->m_pgridLayout_viewimage->addWidget(ui->label_left,1,1);
                ui->m_pgridLayout_viewimage->addWidget(ui->label_right,1,2);
            }
            else
            {
                ui->m_pgridLayout_viewimage->addWidget(ui->label_front,0,1);
                ui->m_pgridLayout_viewimage->addWidget(ui->label_back,1,1);
                ui->m_pgridLayout_viewimage->addWidget(ui->label_left,2,1);
                ui->m_pgridLayout_viewimage->addWidget(ui->label_right,3,1);
            }

        }
    }

    return QObject::eventFilter(watched, event);
}

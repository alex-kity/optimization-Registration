#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QDialog>

class frmStyleWidget;
class QToolButton;

namespace Ui {
class frmMain;
}

class frmMain : public QDialog
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::frmMain *ui;
    frmStyleWidget *style;

    QList<int> icons;           //按钮图形字体队列
    QList<QToolButton *> btns;  //按钮队列
    QList<QPixmap> pixNormal;   //正常图片队列
    QList<QPixmap> pixDark;     //加深图片队列

private slots:
    void initForm();
    void initBtn();
    void buttonClicked();
    void changeTime();
    void changeStyle(const QString &color);
    void setStyle(const QString &mainBgColor = "#FFFFFF",
                  const QString &mainTextNormalColor = "#5C5C5C",
                  const QString &mainTextDarkColor = "#474849",
                  const QString &titleBgColor = "#159C77",
                  const QString &titleTextNormalColor = "#F0F0F0",
                  const QString &titleTextDarkColor = "#FFFFFF",
                  const QString &navBgColor = "#F6F6F8",
                  const QString &navBtnBgColor = "#EAEAEA",
                  const QString &navBtnBorderColor = "#159C77",
                  const QString &borderColor = "#E1E1E2");

private slots:
    void on_btnMenu_Style_clicked();
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

};

#endif // FRMMAIN_H

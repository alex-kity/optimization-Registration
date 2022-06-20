#ifndef FRMSTYLEWIDGET_H
#define FRMSTYLEWIDGET_H

#include <QWidget>

class StyleWidget;

namespace Ui {
class frmStyleWidget;
}

class frmStyleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit frmStyleWidget(QWidget *parent = 0);
    ~frmStyleWidget();

private:
    Ui::frmStyleWidget *ui;
    QList<StyleWidget *> widgets;

private slots:
    void initForm();
    void selected(const QColor &color);
    void sliderReleased();

public slots:
    void setCurrentStyle(int index);

signals:
    void changeStyle(const QString &color);
};

#endif // FRMSTYLEWIDGET_H




#include "ColorChangeTool.h"
#include "ccGLWindow.h"
#include <ccGLWidget.h>
#include <QMdiSubWindow>
#include "ccPointCloud.h"
#include "mainwindow.h"
#include "ccDBRoot.h"
#include "ccConsole.h"
#include "ui_ColorChangeTool.h"

ColorChangeTool::ColorChangeTool(QWidget* parent, ccPointCloud* pc)
    :ccOverlayDialog( parent )
    ,m_ui( new Ui::ColorChangeTool )
    ,m_cloud( pc )
{
    m_ui->setupUi(this);

    //获取主窗体单例
    m_app = MainWindow::TheInstance();

    initUi();

    //信号槽连接
    connect(m_ui->cloneBtn, &QAbstractButton::clicked, this, &ColorChangeTool::onClone);
    connect(m_ui->redSlider, &QAbstractSlider::valueChanged, this, &ColorChangeTool::redSliderValueChanged);
    connect(m_ui->greenSlider, &QAbstractSlider::valueChanged, this, &ColorChangeTool::greenSliderValueChanged);
    connect(m_ui->blueSlider, &QAbstractSlider::valueChanged, this, &ColorChangeTool::blueSliderValueChanged);
    connect(m_ui->redSpinBox, SIGNAL(valueChanged(int)), this, SLOT(redSpinboxValueChanged(int)));
    connect(m_ui->greenSpinBox, SIGNAL(valueChanged(int)), this, SLOT(greenSpinboxValueChanged(int)));
    connect(m_ui->blueSpinBox, SIGNAL(valueChanged(int)), this, SLOT(blueSpinboxValueChanged(int)));
}


ColorChangeTool::~ColorChangeTool()
{
    if (m_ui){
        delete m_ui;
        m_ui = nullptr;
    }

    if (m_cloud){
        delete m_cloud;
        m_cloud = nullptr;
    }
}


void ColorChangeTool::initUi()
{
    m_ui->redSlider->setMinimum(0);
    m_ui->redSlider->setMaximum(255);
    m_ui->redSlider->setValue(125);

    m_ui->greenSlider->setMinimum(0);
    m_ui->greenSlider->setMaximum(255);
    m_ui->greenSlider->setValue(125);

    m_ui->blueSlider->setMinimum(0);
    m_ui->blueSlider->setMaximum(255);
    m_ui->blueSlider->setValue(125);

    m_ui->redSpinBox->setValue(m_ui->redSlider->value());
    m_ui->greenSpinBox->setValue(m_ui->greenSlider->value());
    m_ui->blueSpinBox->setValue(m_ui->blueSlider->value());
}


bool ColorChangeTool::start()
{
    ccOverlayDialog::start();
    m_processing = false;
    return true;
}


void ColorChangeTool::updateColor(const int& r, const int& g, const int& b)
{
    //设置点云颜色RGB
    m_cloud->setColor((unsigned char)r, (unsigned char)g, (unsigned char)b);

    //点云对象添加到DB-Tree中
    m_app->addToDB(m_cloud);
    m_app->RefreshAllGLWindow();
}


void ColorChangeTool::redSliderValueChanged(int r)
{
    m_ui->redSpinBox->blockSignals(true);
    m_ui->redSpinBox->setValue(r);
    m_ui->redSpinBox->blockSignals(false);
    updateColor(m_ui->redSpinBox->value(), m_ui->greenSpinBox->value(), m_ui->blueSpinBox->value());
}


void ColorChangeTool::greenSliderValueChanged(int g)
{
    m_ui->greenSpinBox->blockSignals(true);
    m_ui->greenSpinBox->setValue(g);
    m_ui->greenSpinBox->blockSignals(false);
    updateColor(m_ui->redSpinBox->value(), m_ui->greenSpinBox->value(), m_ui->blueSpinBox->value());
}


void ColorChangeTool::blueSliderValueChanged(int b)
{
    m_ui->blueSpinBox->blockSignals(true);
    m_ui->blueSpinBox->setValue(b);
    m_ui->blueSpinBox->blockSignals(false);
    updateColor(m_ui->redSpinBox->value(), m_ui->greenSpinBox->value(), m_ui->blueSpinBox->value());
}


void ColorChangeTool::redSpinboxValueChanged(int r)
{
    m_ui->redSlider->blockSignals(true);
    m_ui->redSlider->setValue(r);
    m_ui->redSlider->blockSignals(false);
    updateColor(m_ui->redSpinBox->value(), m_ui->greenSpinBox->value(), m_ui->blueSpinBox->value());
}

void ColorChangeTool::greenSpinboxValueChanged(int g)
{
    m_ui->greenSlider->blockSignals(true);
    m_ui->greenSlider->setValue(g);
    m_ui->greenSlider->blockSignals(false);
    updateColor(m_ui->redSpinBox->value(), m_ui->greenSpinBox->value(), m_ui->blueSpinBox->value());
}

void ColorChangeTool::blueSpinboxValueChanged(int b)
{
    m_ui->blueSlider->blockSignals(true);
    m_ui->blueSlider->setValue(b);
    m_ui->blueSlider->blockSignals(false);
    updateColor(m_ui->redSpinBox->value(), m_ui->greenSpinBox->value(), m_ui->blueSpinBox->value());
}


void ColorChangeTool::GetSelectedCloud()
{
    if (m_cloud)
    {
        //设置取消选中上一块点云，同时包围盒消失
        m_cloud->setSelected(false);
    }

    //DB-Tree中所有被选中的实体存入container
    ccHObject::Container container;
    m_app->db()->getSelectedEntities(container);

    if (container.size())
    {
        //拿到第一个被选中的实体
        ccHObject* ent = container[0];
        if (!ent->isKindOf(CC_TYPES::POINT_CLOUD))
        {
            ccConsole::Error(QStringLiteral("选择的对象不是点云类型！"));
            return;
        }
        ccGenericPointCloud* cloud = ccHObjectCaster::ToGenericPointCloud(ent);
        m_cloud = static_cast<ccPointCloud*>(cloud);

        //设置选中当前点云，同时显示包围盒
        m_cloud->setSelected(true);
    }
    //刷新
    m_app->RefreshAllGLWindow();
}


void ColorChangeTool::onClear()
{
    m_cloud->clear();
    m_cloud = nullptr;
}


void ColorChangeTool::onClone()
{
    if (!m_cloud)
    {
        return;
    }

    //法一（点到点的克隆）
    ccPointCloud* pc = new ccPointCloud(m_cloud->getName() + QString("-Clone"));
    //为克隆对象分配内存（坐标与颜色）
    pc->reserve(m_cloud->size());
    pc->reserveTheRGBTable();
    size_t pointSize = m_cloud->size();
    for (size_t i = 0; i < pointSize; ++i)
    {
        pc->addPoint(*m_cloud->getPoint(i));
        pc->addColor(m_cloud->getPointColor(i));
    }
    pc->showColors(true);

    //法二（调用ccPointCloud的接口克隆）
    //ccPointCloud* pc = new ccPointCloud(m_cloud->getName() + QString("-Clone"));
    //m_cloud->clone(pc);

    //将克隆点云pc添加到与m_cloud相同的目录下，并选中。
    m_cloud->getParent()->addChild(pc);
    m_app->db()->selectEntity(pc);
    m_app->addToDB(pc);
    m_app->UpdateUI();
}

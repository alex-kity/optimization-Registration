

#include "ccOverlayDialog.h"

class QMdiSubWindow;
class ccGenericPointCloud;
class ccPointCloud;
class MainWindow;

namespace Ui
{
    class ColorChangeTool;
}


class ColorChangeTool :public ccOverlayDialog
{
    Q_OBJECT

public:
    explicit ColorChangeTool(QWidget* parent, ccPointCloud* pc);

    virtual ~ColorChangeTool() override;

    bool start() override;

public slots:
    void onClone();   //点云克隆

    void redSliderValueChanged(int r);
    void greenSliderValueChanged(int g);
    void blueSliderValueChanged(int b);

    void redSpinboxValueChanged(int r);
    void greenSpinboxValueChanged(int g);
    void blueSpinboxValueChanged(int b);

    void GetSelectedCloud();
    void onClear();
private:
    void initUi();    //初始化界面控件属性
    void updateColor(const int& r, const int& g, const int& b);  //更新点云颜色

    Ui::ColorChangeTool* m_ui = nullptr;    //功能界面
    ccPointCloud* m_cloud = nullptr;         //DB-Tree中被选中的点云
    MainWindow* m_app = nullptr;             //主窗体单例
};

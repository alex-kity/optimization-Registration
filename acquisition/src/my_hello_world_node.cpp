// //包含头文件ros/ros.h,ROS提供的C++客户端库，在后面的编译配置中要添加相应的依赖库roscpp
// #include "ros/ros.h"



// #include <QApplication>

// #include <QWidget>


// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);

//   ros::init(argc,argv,"hello_node"); //初始化ros节点;并指明节点的名称为 hello_node
//   ros::NodeHandle n;                //声明一个ros节点的句柄;
//   //调用了roscpp库提供的方法ROS_INFO_STREAM来打印信息。这里打印字符串"hello world!"。
//   ROS_INFO_STREAM("hello world!");

//     QWidget w;
//     w.show();



//     return a.exec();
// }

#include "ros/ros.h"
#include "frmmain.h"
#include "appinit.h"
#include "quihelper.h"
#include "frminputnum.h"


int main(int argc, char *argv[])
{
    //设置不应用操作系统设置比如字体
    QApplication::setDesktopSettingsAware(false);
#if (QT_VERSION >= QT_VERSION_CHECK(5,14,0))
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Floor);
#endif
    QApplication a(argc, argv);

    QUIHelper::setFont();
    QUIHelper::setCode();
    QUIHelper::initRand();

    frmInputNum::Instance()->init("black", 10);
    AppInit::Instance()->start();

   ros::init(argc,argv,"hello_node"); //初始化ros节点;并指明节点的名称为 hello_node
   ros::NodeHandle n;                //声明一个ros节点的句柄;
   //调用了roscpp库提供的方法ROS_INFO_STREAM来打印信息。这里打印字符串"hello world!"。
   ROS_INFO_STREAM("===================================!");

    frmMain w;
    w.setWindowTitle("雷达相机控制系统");
    QUIHelper::setFormInCenter(&w);
    w.show();

    return a.exec();
}

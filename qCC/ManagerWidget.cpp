#include "ManagerWidget.h"
#include "ui_ManagerWidget.h"

#include <ui_mainWindow.h>
#include <ui_ManagerWidget.h>

ManagerWidget::ManagerWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerWidget)
{
    ui->setupUi(this);

//    m_SgsTagging = new SgsTagging(this);
//   m_SgsTagging->show();

//    PointCoordinateType width = static_cast<PointCoordinateType>(wDoubleSpinBox->value());
//    PointCoordinateType height = static_cast<PointCoordinateType>(hDoubleSpinBox->value());

//    ccPlane* plane = new ccPlane(width, height);
//    updatePlane(plane);
//    if (m_pickingWin)
//    {
//        plane->setDisplay(m_pickingWin);
//    }
//    if (MainWindow::TheInstance())
//    {
//        MainWindow::TheInstance()->addToDB(plane);
//    }
//    else
//    {
//        delete plane;
//        plane = nullptr;
//    }
}

ManagerWidget::~ManagerWidget()
{
    delete ui;
}


//void ManagerWidget::updatePlane(ccPlane* plane)
//{
//	if (!plane)
//	{
//		assert(false);
//		return;
//	}

//	double dip = dipDoubleSpinBox->value();
//	double dipDir = dipDirDoubleSpinBox->value();
//	bool upward = upwardCheckBox->isChecked();
//	PointCoordinateType width  = static_cast<PointCoordinateType>(wDoubleSpinBox->value());
//	PointCoordinateType height = static_cast<PointCoordinateType>(hDoubleSpinBox->value());
//	CCVector3 Nd = ccNormalVectors::ConvertDipAndDipDirToNormal(dip, dipDir, upward);
//	CCVector3 Cd = {	static_cast<PointCoordinateType>(cxAxisDoubleSpinBox->value()),
//						static_cast<PointCoordinateType>(cyAxisDoubleSpinBox->value()),
//						static_cast<PointCoordinateType>(czAxisDoubleSpinBox->value()) };

//	CCVector3 N = plane->getNormal();
//	CCVector3 C = plane->getCenter();

//	//shall we transform (translate and / or rotate) the plane?
//	ccGLMatrix trans;
//	bool needToApplyRot = (std::abs(N.dot(Nd) - CCCoreLib::PC_ONE) > std::numeric_limits<PointCoordinateType>::epsilon());
//	bool needToApplyTrans = (needToApplyRot || ((C - Cd).norm2d() != 0));

//	if (needToApplyTrans)
//	{
//		trans.setTranslation(-C);
//	}
//	if (needToApplyRot)
//	{
//		ccGLMatrix rotation;
//		//special case: plane parallel to XY
//		if (std::abs(N.z) > CCCoreLib::PC_ONE - std::numeric_limits<PointCoordinateType>::epsilon())
//		{
//			ccGLMatrix rotX; rotX.initFromParameters( CCCoreLib::DegreesToRadians( -dip ), CCVector3(1, 0, 0), CCVector3(0, 0, 0) ); //plunge
//			ccGLMatrix rotZ; rotZ.initFromParameters( CCCoreLib::DegreesToRadians( dipDir ), CCVector3(0, 0, -1), CCVector3(0, 0, 0) );
//			rotation = rotZ * rotX;
//		}
//		else //general case
//		{
//			rotation = ccGLMatrix::FromToRotation(N, Nd);
//		}
//		trans = rotation * trans;
//	}
//	if (needToApplyTrans)
//	{
//		trans.setTranslation(trans.getTranslationAsVec3D() + Cd);
//	}
//	if (needToApplyRot || needToApplyTrans)
//	{
//		plane->applyGLTransformation_recursive(&trans);

//		ccLog::Print("[Plane edit] Applied transformation matrix:");
//		ccLog::Print(trans.toString(12, ' ')); //full precision
//	}

//	if (	plane->getXWidth() != width
//		||	plane->getYWidth() != height)
//	{
//		plane->setXWidth(width, false);
//		plane->setYWidth(height, true);
//	}
//}



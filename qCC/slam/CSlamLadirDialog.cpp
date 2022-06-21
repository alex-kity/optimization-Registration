#include "CSlamLadirDialog.h"
#include "ui_CSlamLadirDialog.h"
#include "ClidarCompute.h"


static CAppConfig g_CAppConfig;


///
/// \brief CSlamLadirDialog::CSlamLadirDialog
/// \param parent
/// \param _pMainWindow
///
CSlamLadirDialog::CSlamLadirDialog(QWidget *parent, MainWindow* _pMainWindow ) :
    ccOverlayDialog(parent),
    ui(new Ui::CSlamLadirDialog)
{
    ui->setupUi(this);
    m_pMainWindow = _pMainWindow;

    ui->widget_option->hide();
    this->resize(150,30);

    initForm();

    my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    my_logger->info("ladir data, {}",1);

}



///
/// \brief CSlamLadirDialog::~CSlamLadirDialog
///
CSlamLadirDialog::~CSlamLadirDialog()
{

    delete ui;
}



///
/// \brief CSlamLadirDialog::initForm
///
void CSlamLadirDialog::initForm()
{
    connect(ui->pushButton_resample,&QPushButton::clicked,this,[=](){emit SignalsResample();});
    connect(ui->pushButtonpointresi,&QPushButton::clicked,this,[=](){emit SignalsRegisterPoint();});
    connect(ui->btnclose,&QPushButton::clicked,this,[=](){this->close();});
    connect(ui->m_btnTransFrom,&QPushButton::clicked,this,[=](){emit SignalsTransFrom();});
    connect(ui->SavePath,&QPushButton::clicked,this,[=](){emit SignalsSavePath();});
    connect(ui->btn_TestPath,&QPushButton::clicked,this,[=](){
        //get trajectory data
        lygs::CGYLCommon _CGYLCommon;
        QFileDialog _FileDialog;
        _FileDialog.setStyleSheet("color: rgb(241, 241, 241);");
        QString fileName = _FileDialog.getOpenFileName(nullptr,QStringLiteral("trajectory！"),"F:",QStringLiteral("file(*txt)"));

        if(!fileName.isEmpty())
        {
            m_filenametnt = fileName.toStdString();
            std::map<std::string,lygs::trajectoryData> trajectorys;
            std::vector<lygs::trajectoryData>  m_vecs = _CGYLCommon.readTrajectoryToxian1(fileName.toStdString(),trajectorys);

            //    m_pMainWindow->ADDRecently(fileName);
            //show trajectorydata
            QList<QVector3D> _vec3d;
            QVector3D vec;
            for (int i = 0;i<m_vecs.size();i++) {
                vec.setX(m_vecs[i].x);
                vec.setY(m_vecs[i].y);
                vec.setZ(m_vecs[i].z);

                _vec3d.push_back(vec);
            }
            emit SignalsTestLoadPath(_vec3d);

        }
    });
    connect(ui->setpointfile,&QPushButton::clicked,this,[=](){
        //    ui->load_path->setEnabled(true);
        m_pointDir = QFileDialog::getExistingDirectory(
                    nullptr, "choose src Directory",
                    "/");
        if (m_pointDir.isEmpty())
        {
            m_pointDir = nullptr;
            return;
        }
        else
        {
            qDebug() << "srcDirPath=" << m_pointDir;
            m_pointDir += "/";
        }
        if (m_selectedFiles.isEmpty())
            return;
    });


}

void CSlamLadirDialog::DataClear()
{
    m_vecs.clear();
    g_trajectoryMap.clear();
    m_selectedFiles.clear();
    m_IndextrajectoryMap.clear();
}



///
/// \brief CSlamLadirDialog::on_load_path_clicked
///
void CSlamLadirDialog::on_load_path_clicked()
{
    //get trajectory data
    int m_currentType = 0;
    lygs::CGYLCommon _CGYLCommon;
    QFileDialog _FileDialog;
    _FileDialog.setStyleSheet("color: rgb(241, 241, 241);");
    QString fileName = _FileDialog.getOpenFileName(nullptr,QStringLiteral("trajectory！"),"F:",QStringLiteral("file(*txt)"));


    if(!fileName.isEmpty())
    {
        m_filename = fileName.toStdString();
        spdlog::info("trajectory : {}",m_filename);
        //        m_recentFiles->addFilePath( fileName );
        DataClear();
        m_vecs = _CGYLCommon.readTrajectoryToxian1(m_filename,g_trajectoryMap);

        std::function<void()> fun_type = [=]()
        {
            for (int i = 0; i < m_vecs.size(); i++)
            {
                lygs::trajectoryData lidarSe3 = m_vecs[i];
                Eigen::Matrix4f Roi2w = ClidarCompute::getSE3Mat(lidarSe3.yaw * (180.0 / M_PI), lidarSe3.pitch * (180.0 / M_PI), lidarSe3.roll * (180.0 / M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");
                ccGLMatrix transTemp = ClidarCompute::FromEigenMat(Roi2w);
                m_IndextrajectoryMap[i] = transTemp;
            }

            //    m_pMainWindow->ADDRecently(fileName);
            // show trajectorydata
            QList<QVector3D> _vec3d;
            QVector3D vec;
            for (int i = 0; i < m_vecs.size(); i++)
            {
                vec.setX(m_vecs[i].x);
                vec.setY(m_vecs[i].y);
                vec.setZ(m_vecs[i].z);
                _vec3d.push_back(vec);
            }
            emit SignalsLoadPath(_vec3d);

            /// 1
                std::vector<std::pair<unsigned, unsigned>> match;
            ClidarCompute::GetPointDataSelf(m_vecs, match);
            //        ClidarCompute::GetPointDataSelf1(m_vecs,match, ClidarCompute::Index_Iter);

            if (!match.empty())
            {
                /// 2
                std::function<_MapMatch(int, int)> func =
                    std::bind(&CSlamLadirDialog::DataSpit, this,std::placeholders::_1,std::placeholders::_2);
                SetShowCloudPoint(match, func);
            }
        };

        //if ONCE point cloud , we registrae twice
        if(m_currentType == 0)
        {
            
            fun_type();
           
        }
        else if(m_currentType == 1) 
        {
            //if the same point cloud , we registrae twice
            // fun_type();
        }

        ui->widget_option->show();

    }

}





///
/// \brief MeragePoint
/// \param newGroups
/// \return
///
ccPointCloud* MeragePoint(ccHObject* newGroups)
{
    qDebug()<<newGroups->getName();
    ccHObject* newGroup = nullptr;
    ccPointCloud* firstCloud = new ccPointCloud(newGroups->getName());


    for (unsigned i = 0; i < newGroups->getChildrenNumber(); ++i)
    {
        newGroup = newGroups->getChild(i);
        //        ccConsole::Error(newGroups->getName().toLatin1().data());
        //qstr.toLatin1().data();

        ccPointCloud* pc = static_cast<ccPointCloud*>(newGroup);
        //        pc->point()
        //        ccPointCloud* pc = ccHObjectCaster::ToPointCloud(newGroup);
        ccConsole::Error((QString::number(pc->size())+"---"+pc->getName()).toLatin1().data());
        //        assert(pc);
        //        *firstCloud += pc;

        for (int i = 0; i < pc->size(); i++)
        {

            CCVector3 P11(pc->getPoint(i)->x, pc->getPoint(i)->y, pc->getPoint(i)->z);
            firstCloud->addPoint(P11);

        }

        ccConsole::Error((QString::number(firstCloud->size())+"---"+pc->getName()).toLatin1().data());

        //        ccConsole::Error(firstCloud->getName().toLatin1().data());
    }


    if(firstCloud != nullptr)
        firstCloud->setName(newGroups->getName());



    return firstCloud;

    //    ccPointCloud* firstCloud = new ccPointCloud(objname);
    //    for (unsigned i = 0; i < _vecpointcloud.size(); ++i)
    //    {
    //        if(_vecpointcloud[i])
    //        {
    //            qDebug()<<"_vecpointcloud is null";

    //            *firstCloud += _vecpointcloud[i];
    //        }
    //    }
    //    if(firstCloud!=nullptr)
    //        newGroups->addChild(firstCloud);


    //    ccHObject* newGroup = nullptr;
    //    ccPointCloud* firstCloud = nullptr;
    //    for (unsigned i = 0; i < newGroups->getChildrenNumber(); ++i)
    //    {
    //        newGroup = newGroups->getChild(i);
    //        ccPointCloud* pc = ccHObjectCaster::ToPointCloud(newGroup);
    //        assert(pc);
    //        *firstCloud += pc;
    //    }

    //qDebug()<<"newGroups";

    //    zoomOn(newDataCloud);
    //    addToDB(newDataCloud);
}





// this pointcloud transform form origin to world

///
/// \brief CSlamLadirDialog::changeMat
/// \param obj
/// \param strfilename
/// \return
///
ccPointCloud*  CSlamLadirDialog::changeMat(ccPointCloud* obj,std::string strfilename)
{
    std::string  str = strfilename.substr(0,strfilename.length()-4);

    if(g_trajectoryMap.count(str) == 1)
    {

        lygs::trajectoryData lidarSe3 = g_trajectoryMap[strfilename.substr(0, strfilename.size() - 4)];
        Eigen::Matrix4f Roi2w = ClidarCompute::getSE3Mat(lidarSe3.yaw*(180.0/M_PI), lidarSe3.pitch*(180.0/M_PI), lidarSe3.roll*(180.0/M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");

        ccGLMatrix transTemp = ClidarCompute::FromEigenMat(Roi2w);

        obj->applyRigidTransformation(transTemp);

        //        pcl::PointCloud<pcl::PointXYZI>::Ptr cloudRGBAllreult = transform<pcl::PointXYZI>(cloudA, Roi2w);

    }

    return obj;
}






///
/// \brief CSlamLadirDialog::loadpoint
/// \param newGroups
/// \param objname
/// \param filenames
/// \param dir
/// \param fileFilter
/// \param destWin
///
void CSlamLadirDialog::loadpoint(ccHObject *newGroups, const QString objname,	const QStringList& filenames, QString dir,
                                 QString fileFilter/*=QString()*/,
                                 ccGLWindow* destWin/*=0*/ )
{

    std::vector<ccPointCloud*> _vecpointcloud;

    //to use the same 'global shift' for multiple files
    CCVector3d loadCoordinatesShift(0, 0, 0);
    bool loadCoordinatesTransEnabled = false;

    FileIOFilter::LoadParameters parameters;
    {
        parameters.alwaysDisplayLoadDialog = true;
        parameters.shiftHandlingMode = ccGlobalShiftManager::DIALOG_IF_NECESSARY;
        parameters.coordinatesShift = &loadCoordinatesShift;
        parameters.coordinatesShiftEnabled = &loadCoordinatesTransEnabled;
        parameters.parentWidget = this;
    }

    bool normalsDisplayedByDefault = ccOptions::Instance().normalsDisplayedByDefault;
    FileIOFilter::ResetSesionCounter();

    for ( const QString &filename : filenames )
    {
        CC_FILE_ERROR result = CC_FERR_NO_ERROR;
        ccHObject* newGroup = FileIOFilter::LoadFromFile(dir +filename, parameters, result, fileFilter);

        if (newGroup)
        {
            if (!normalsDisplayedByDefault)
            {
                //disable the normals on all loaded clouds!
                ccHObject::Container clouds;
                newGroup->filterChildren(clouds, true, CC_TYPES::POINT_CLOUD);
                for (ccHObject* cloud : clouds)
                {
                    if (cloud)
                    {
                        static_cast<ccGenericPointCloud*>(cloud)->showNormals(false);
                    }
                }
            }

            if (destWin)
            {
                newGroup->setDisplay_recursive(destWin);
            }


            for (unsigned i = 0; i < newGroup->getChildrenNumber(); ++i)
            {

                ccHObject* cloud = newGroup->getChild(i);

                //获取选中的点云对象

                if (!cloud || !cloud->isA(CC_TYPES::POINT_CLOUD)) {

                    ccConsole::Error((QString::number(cloud->getClassID())+"---"+cloud->getName()).toLatin1().data());
                    //                    continue;
                }
                else
                {


                    //                    ccPointCloud *pc = ccHObjectCaster::ToPointCloud(cloud);

                    ccPointCloud *pc =changeMat(ccHObjectCaster::ToPointCloud(cloud),filename.toStdString());

                    //                    ccScalarField *sf = pc->getCurrentDisplayedScalarField();
                    _vecpointcloud.push_back(pc);
                    //                    ccConsole::Error((QString::number(pc->size())+"---"+pc->getName()).toLatin1().data());
                }



            }
            //分类，继承关系，类型转换
        }

        if (result == CC_FERR_CANCELED_BY_USER)
        {
            //stop importing the file if the user has cancelled the current process!
            break;
        }
    }
    //    baseMesh->addChild(baseVertices);

    if(!_vecpointcloud.empty())
    {

        ccPointCloud* firstCloud = new ccPointCloud(objname);

        for(int i = 0;i<_vecpointcloud.size();i++)
        {
            *firstCloud += _vecpointcloud[i];
        }
        newGroups->addChild(firstCloud);

    }


}


_MapMatch CSlamLadirDialog::DataSpit(int first,int second)
{
    _MapMatch _MapMatch_t;
    std::string flagname ;

    QStringList selectedFilesMatching;
    QStringList selectedFilesMatched;
    QString strtype = ".pcd";

    int index = first + g_CAppConfig.firstsatrt;
    for (int i = index;i<index+g_CAppConfig.firststep;i++) {

        int icurrent = i;
        if(icurrent>=0 && icurrent<m_vecs.size())
        {
            //                    selectedFilesMatched.push_back(m_pointDir+m_vecs[icurrent].name.data() + strtype);
            selectedFilesMatched.push_back(m_vecs[icurrent].name.data() + strtype);

            m_selectedFiles.push_back(m_vecs[icurrent].name.data() + strtype);
        }

    }


    //2
    index = second+ g_CAppConfig.secondsatrt;
    for (int i = index;i<index+g_CAppConfig.secondstep;i++) {


        int icurrent = i;
        if(icurrent>=0 && icurrent<m_vecs.size())
        {
            //                    selectedFilesMatching.push_back(m_pointDir+m_vecs[icurrent].name.data() + strtype);
            selectedFilesMatching.push_back(m_vecs[icurrent].name.data() + strtype);
            m_selectedFiles.push_back(m_vecs[i].name.data() + strtype);
        }

    }


    flagname = "N-" +std::to_string(second)+"-"+std::to_string(first);

    _MapMatch_t.name = QString(QString::fromLocal8Bit(flagname.c_str()));

    _MapMatch_t.matched = QString(QString::fromLocal8Bit(g_CAppConfig.Matched.c_str())) +
            QString::number(second)  + _MapMatch_t.name;
    _MapMatch_t.matchedlist = selectedFilesMatched;

    _MapMatch_t.matching = QString(QString::fromLocal8Bit(g_CAppConfig.Matching.c_str())) +
            QString::number(first)  + _MapMatch_t.name;
    _MapMatch_t.matchinglist = selectedFilesMatching;

    return _MapMatch_t;
}

///
/// \brief CSlamLadirDialog::SetShowCloudPoint
/// \param match
///
void CSlamLadirDialog::SetShowCloudPoint(std::vector<std::pair<unsigned,unsigned>> match,
                                         std::function<_MapMatch(int,int)> func)
{
    if (m_pointDir == nullptr || m_pointDir.isEmpty())
    {
        m_pointDir = nullptr;
        QMessageBox message_box( QMessageBox::Question,
                                 tr("warn"),
                                 tr("please setting the point cloud path"),
                                 QMessageBox::Yes | QMessageBox::No,
                                 nullptr );

        if (message_box.exec() == QMessageBox::Yes)
        {
            ui->setpointfile->clicked();
        }
    }


    if (m_pointDir.isEmpty())
    {
        m_pointDir = nullptr;
        return;
    }
    spdlog::info("m_pointDir: {}",m_pointDir.toStdString());



    //创建一个进度对话框
    QProgressDialog m_pProgressDialog;
    QFont font("compute Registration.....",12);
    m_pProgressDialog.setFont(font);
    //设置进度对话框采用模态方式进行，即显示进度的同时，其他窗口将不响应输入信号
    m_pProgressDialog.setWindowModality(Qt::WindowModal);
    //设置进度对话框出现需等待的时间，默认为4s
    m_pProgressDialog.setMinimumDuration(1);
    //设置进度对话框的窗体标题
    m_pProgressDialog.setWindowTitle(tr("Please Wait"));
    //设置进度对话框的显示文字信息
    m_pProgressDialog.setLabelText(tr("Compute..."));
    //设置进度对话框的“取消”按钮的显示文字
    m_pProgressDialog.setCancelButtonText(tr("Cancel"));
    m_pProgressDialog.show();
    QThread::msleep(50);
    // perform

    std::vector<_MapMatch> _showVecpointlist;
    std::vector<std::pair<unsigned,unsigned>>::iterator iter;
    for(iter = match.begin(); iter!= match.end(); iter++)
    {
        if(!m_vecs.empty())
        {

            _showVecpointlist.push_back(func(iter->first,iter->second));
            // _showVecpointlist.push_back(DataSpit(iter->first,iter->second));
        }
    }


    if (m_selectedFiles.isEmpty())
        return;
    else
    {
        int num = _showVecpointlist.size()+1;
        m_pProgressDialog.setRange(0,num); //设置进度对话框的步进范围

        for (int i = 0;i<_showVecpointlist.size();i++) {
            m_pProgressDialog.setValue(i);
            _MapMatch _MapMatch_t = _showVecpointlist[i];
            ccHObject* newGroups = new ccHObject(g_CAppConfig.MATCHName+QString::number(i));
            loadpoint(newGroups, _MapMatch_t.matched,_MapMatch_t.matchedlist , m_pointDir,g_CAppConfig.currentOpenDlgFilter);
            loadpoint(newGroups, _MapMatch_t.matching,_MapMatch_t.matchinglist, m_pointDir,g_CAppConfig.currentOpenDlgFilter);
            m_pMainWindow->addToDB(newGroups, true, true, false);

            if(m_pProgressDialog.wasCanceled())
                return;
            QCoreApplication::processEvents();
        }

    }

    m_pProgressDialog.close();
    //    delete m_pProgressDialog;

}





//// this pointcloud transform form origin to world
//ccPointCloud*  CSlamLadirDialog::GetOrignMat(int index,ccGLMatrix &transTemp)
//{

//    if(g_trajectoryMap.count(str) == 1)
//    {

//        lygs::trajectoryData lidarSe3 = g_trajectoryMap[strfilename.substr(0, strfilename.size() - 4)];
//        Eigen::Matrix4f Roi2w = getSE3Mat(lidarSe3.yaw*(180.0/M_PI), lidarSe3.pitch*(180.0/M_PI), lidarSe3.roll*(180.0/M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");

//        ccGLMatrix transTemp = ClidarCompute::FromEigenMat(Roi2w);

//        obj->applyRigidTransformation(transTemp);

//        //        pcl::PointCloud<pcl::PointXYZI>::Ptr cloudRGBAllreult = transform<pcl::PointXYZI>(cloudA, Roi2w);

//    }
//}




















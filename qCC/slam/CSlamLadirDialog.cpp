#include "CSlamLadirDialog.h"
#include "ui_CSlamLadirDialog.h"
#include "ClidarCompute.h"
#include "CDataChange.h"
#include "ccSubsamplingDlg.h" //Aurelien BEY"


#include "CObjCCAlgorithm.h"


CObjCCAlgorithm* CObjCCAlgorithm::single = nullptr;
CObjCCAlgorithm::CRelease CObjCCAlgorithm::release;
pthread_mutex_t CObjCCAlgorithm::mutex = PTHREAD_MUTEX_INITIALIZER;
CObjCCAlgorithm * m_pCObjCCAlgorithm = CObjCCAlgorithm::getInstance();
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


    g_CDataChange.reset(new CBackOptimization());

}



///
/// \brief CSlamLadirDialog::~CSlamLadirDialog
///
CSlamLadirDialog::~CSlamLadirDialog()
{

    delete ui;
}




std::vector<ccPointCloud *>  CSlamLadirDialog::SetResampleGui(ccPointCloud* cloud)
{

    std::vector<ccPointCloud *> resultingClouds;
    //find candidates
    std::vector<ccPointCloud*> clouds;
    unsigned maxPointCount = 0;
    double maxCloudRadius = 0;
    ScalarType sfMin = CCCoreLib::NAN_VALUE;
    ScalarType sfMax = CCCoreLib::NAN_VALUE;
    {
        clouds.push_back(cloud);

        maxPointCount = std::max<unsigned>(maxPointCount, cloud->size());
        maxCloudRadius = std::max<double>(maxCloudRadius, cloud->getOwnBB().getDiagNorm());

        //we also look for the min and max sf values
        ccScalarField* sf = cloud->getCurrentDisplayedScalarField();
        if (sf)
        {
            if (!ccScalarField::ValidValue(sfMin) || sfMin > sf->getMin())
                sfMin = sf->getMin();
            if (!ccScalarField::ValidValue(sfMax) || sfMax < sf->getMax())
                sfMax = sf->getMax();
        }



    }

    if (clouds.empty())
    {
        ccConsole::Error(tr("Select at least one point cloud!"));
        return resultingClouds;
    }

    //Display dialog
    ccSubsamplingDlg sDlg(maxPointCount, maxCloudRadius, this);
    bool hasValidSF = ccScalarField::ValidValue(sfMin) && ccScalarField::ValidValue(sfMax);
    if (hasValidSF)
        sDlg.enableSFModulation(sfMin,sfMax);
    if (!sDlg.exec())
        return resultingClouds;

    //process clouds

    // ccHObject::Container resultingClouds;
    {
        ccProgressDialog pDlg(false, this);
        pDlg.setAutoClose(false);

        pDlg.setMethodTitle(tr("Subsampling"));

        bool errors = false;

        QElapsedTimer eTimer;
        eTimer.start();

        for (size_t i = 0; i < clouds.size(); ++i)
        {
            ccPointCloud* cloud = clouds[i];
            CCCoreLib::ReferenceCloud *sampledCloud = sDlg.getSampledCloud(cloud,&pDlg);
            // CCCoreLib::ReferenceCloud *sampledCloud = getSampledCloud(cloud,sfMin,sfMax);
            
            if (!sampledCloud)
            {
                ccConsole::Warning(tr("[Subsampling] Failed to subsample cloud '%1'!").arg(cloud->getName()));
                errors = true;
                continue;
            }

            int warnings = 0;
            ccPointCloud *newPointCloud = cloud->partialClone(sampledCloud,&warnings);

            delete sampledCloud;
            sampledCloud = nullptr;

            if (newPointCloud)
            {
                newPointCloud->setName(cloud->getName() + QString(".subsampled"));
                newPointCloud->copyGlobalShiftAndScale(*cloud);
                newPointCloud->setDisplay(cloud->getDisplay());
                newPointCloud->prepareDisplayForRefresh();
                if (cloud->getParent())
                    cloud->getParent()->addChild(newPointCloud);
                cloud->setEnabled(false);


                newPointCloud->prepareDisplayForRefresh();
                resultingClouds.push_back(newPointCloud);



                if (warnings)
                {
                    ccLog::Warning(tr("[Subsampling] Not enough memory: colors, normals or scalar fields may be missing!"));
                    errors = true;
                }
            }
            else
            {
                ccLog::Error(tr("Not enough memory!"));
                break;
            }
        }

        ccLog::Print("[Subsampling] Timing: %3.3f s.",eTimer.elapsed()/1000.0);

        if (errors)
        {
            ccLog::Error(tr("Errors occurred (see console)"));
        }
    }


    return resultingClouds;



}








void CSlamLadirDialog::on_pushButton_test_clicked()
{
    QString dir = "/home/alexlyg/file/2022-01-14-16-15-03/key_frames/";


    QStringList filename1{
        "1642148136.989636.pcd"
    };

    QStringList filename2{
        "1642148137.089613.pcd"
    };

    //src is change
    ccPointCloud* transcloud = loadPointCloud("1",filename1,dir,g_CAppConfig.currentOpenDlgFilter);

    ccPointCloud* dstcloud = loadPointCloud("2",filename2,dir,g_CAppConfig.currentOpenDlgFilter);

    ccGLMatrix transMat;

    ICPPERDATA _icpperdata_t;

    _icpperdata_t.minRMSDecrease = 1e-05;
    _icpperdata_t.maxIterationCount= 20;
    _icpperdata_t.randomSamplingLimit= 50000;
    _icpperdata_t.removeFarthestPoints= true;
    _icpperdata_t.useDataSFAsWeights= false;
    _icpperdata_t.useModelSFAsWeights= false;
    _icpperdata_t.adjustScale= false;
    _icpperdata_t.transformationFilters= false;
    _icpperdata_t.finalOverlap= 100;
    _icpperdata_t.method= 0 ;
    _icpperdata_t.maxThreadCount= 8;
    _icpperdata_t.bisREname = false;

    m_pCObjCCAlgorithm->AutoICPRegister(_icpperdata_t,transcloud,dstcloud,transMat);


    m_pMainWindow->addToDB(transcloud, true, true, false);
    m_pMainWindow->addToDB(dstcloud, true, true, false);
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
    connect(ui->SavePath,&QPushButton::clicked,this,[=](){
        QString _pointDir = QFileDialog::getExistingDirectory(
                    nullptr, "choose src Directory",
                    "/");

        if (_pointDir.isEmpty())
        {
            _pointDir = nullptr;
            return;
        }

        try
        {
            if(g_CDataChange!=nullptr)
                g_CDataChange->graphOptimizerAndSavePoses(_pointDir.toStdString());
        }
        catch (const std::bad_alloc&)
        {
            ccLog::Error(tr("Based on Optimization"));
        }

    });

    connect(ui->btn_TestPath,&QPushButton::clicked,this,[=](){
        //get trajectory data
        lygs::CGYLCommon _CGYLCommon;
        QFileDialog _FileDialog;
        _FileDialog.setStyleSheet("color: rgb(241, 241, 241);");
        QString fileName = _FileDialog.getOpenFileName(nullptr,QStringLiteral("trajectory！"),"F:",QStringLiteral("file(*txt)"));

        if(!fileName.isEmpty())
        {
            std::map<std::string,SensorTrajectoryData> trajectorys;
            std::vector<SensorTrajectoryData>  m_vecs = _CGYLCommon.readTrajectoryToxian1(fileName.toStdString(),trajectorys);

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

            ccPointCloud* pclCloud = new ccPointCloud(fileName);
            ccHObject* ladirnewGroup = nullptr;
            //Sphere
            if(ladirnewGroup==nullptr)
            {
                ladirnewGroup = new ccHObject(QString::fromLocal8Bit("ladir-path-dnt"));
            }


            //pointcloud
            int num = _vec3d.size();
            pclCloud->reserve(static_cast<unsigned>(num));

            for (int i = 0; i < num; i++)
            {
                pclCloud->addPoint(CCVector3f(_vec3d[i].x(), _vec3d[i].y(), _vec3d[i].z()));
            }
            pclCloud->setPointSize(3);
            ladirnewGroup->addChild(pclCloud);
            //        //obj
            //        for (int i = 0;i<_vec.size();i++) {
            //            ccGenericPrimitive* primitive = nullptr;
            //            ccGLMatrix transMat;
            //            transMat.setTranslation(CCVector3f(_vec[i].x(), _vec[i].y(), _vec[i].z()));

            //            CCVector3 dims(	static_cast<PointCoordinateType>(0.3),
            //                            static_cast<PointCoordinateType>(0.3),
            //                            static_cast<PointCoordinateType>(0.3));
            //            primitive = new ccBox(dims,&transMat);
            //            //            primitive = new ccSphere(static_cast<PointCoordinateType>(10.0f), &transMat);
            //            newGroup->addChild(primitive);
            //        }
            m_pMainWindow->addToDB(m_ladirnewGroup, true, true, false);

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

        SensorTrajectoryData lidarSe3 = g_trajectoryMap[strfilename.substr(0, strfilename.size() - 4)];
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
    ccPointCloud* firstCloud = loadPointCloud(objname,filenames,dir,fileFilter,destWin);

    if(firstCloud!=nullptr)
    {
        std::vector<ccPointCloud *> resultingClouds =m_pCObjCCAlgorithm->SetResample(firstCloud);
        for(int i = 0;i<resultingClouds.size();i++)
        {
            newGroups->addChild(resultingClouds[i]);

        }
    }

}




///
/// \brief CSlamLadirDialog::loadPointCloud
/// \param newGroups
/// \param objname
/// \param filenames
/// \param dir
/// \param fileFilter
/// \param destWin
///
ccPointCloud * CSlamLadirDialog::loadPointCloud(const QString objname,	const QStringList& filenames, QString dir,
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

    ccPointCloud *pointclouds = nullptr;
    if(!_vecpointcloud.empty())
    {

        pointclouds = new ccPointCloud(objname);

        for(int i = 0;i<_vecpointcloud.size();i++)
        {
            *pointclouds += _vecpointcloud[i];

        };

        return pointclouds;
    }
    else
    {
        pointclouds = nullptr;
    }
}


///
/// \brief DataSpit
/// \param first
/// \param second
/// \return
///
_MapMatch CSlamLadirDialog::ReserveDirDataSpit(int first,int second,bool isSameDir)
{
    //big small
    _MapMatch _MapMatch_t;
    QString strtype = ".pcd";
    QStringList selectedFilesMatched ,selectedFilesMatching;

    std::function<QStringList(int ,int)> funcConvert = [=](int index_t,int step) mutable->QStringList
    {

        QStringList selectedFilesMatched;
        for (int i = index_t;i<index_t+step;i++) {

            int icurrent = i;
            if(icurrent>=0 && icurrent<m_vecs.size())
            {
                selectedFilesMatched.push_back(m_vecs[icurrent].name.data() + strtype);

                m_selectedFiles.push_back(m_vecs[icurrent].name.data() + strtype);
            }

        }

        return selectedFilesMatched;
    };


    if(isSameDir)
    {
        //1
        int index = first ;
        selectedFilesMatched = funcConvert(index,1);
        //2
        index = second;
        selectedFilesMatching = funcConvert(index,10);
        _MapMatch_t.isSame = true;
    }
    else
    {

        //1 da
        int index = first + g_CAppConfig.firstsatrt;
        selectedFilesMatched = funcConvert(index,g_CAppConfig.firststep);
        //2
        index = second+ g_CAppConfig.secondsatrt;
        selectedFilesMatching = funcConvert(index,g_CAppConfig.secondstep);
        _MapMatch_t.isSame = false;
    }



    _MapMatch_t.matchedid = first;

    _MapMatch_t.matchedingid = second;

    _MapMatch_t.name = "Reserve-" +QString::number(second)+"-"+QString::number(first);

    _MapMatch_t.matched = QString(QString::fromLocal8Bit(g_CAppConfig.Matched.c_str())) +
            QString::number(first)  + _MapMatch_t.name;
    _MapMatch_t.matchedlist = selectedFilesMatched;

    _MapMatch_t.matching = QString(QString::fromLocal8Bit(g_CAppConfig.Matching.c_str())) +
            QString::number(second)  + _MapMatch_t.name;
    _MapMatch_t.matchinglist = selectedFilesMatching;


    return _MapMatch_t;
}








///
/// \brief CSlamLadirDialog::on_load_path_clicked
///
void CSlamLadirDialog::on_load_path_clicked()
{    
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
        bool isOpt = false;

        if(isOpt)
        {
            m_vecs = _CGYLCommon.readTrajectoryToxian1(m_filename,g_trajectoryMap);
        }
        else
        {
            g_CDataChange->loadTrajectory(m_filename);
            g_CDataChange->GetTrajectOptData(m_vecs,g_trajectoryMap);
        }
        spdlog::info("vecs size : {}",m_vecs.size());
        ShowTrajectorydata();

        std::function<void()> fun_type = [=]()
        {
            for (int i = 0; i < m_vecs.size(); i++)
            {
                SensorTrajectoryData lidarSe3 = m_vecs[i];
                Eigen::Matrix4f Roi2w = ClidarCompute::getSE3Mat(lidarSe3.yaw * (180.0 / M_PI), lidarSe3.pitch * (180.0 / M_PI), lidarSe3.roll * (180.0 / M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");
                ccGLMatrix transTemp = ClidarCompute::FromEigenMat(Roi2w);
                m_IndextrajectoryMap[i] = transTemp;
            }

            try
            {
                spdlog::info("Optimization : loadTrajectory");
                //2022/0624
                // if(g_CDataChange!=nullptr)
                //     g_CDataChange->loadTrajectory(m_pSlamLadirDialog->GetFileName());
            }
            catch (const std::bad_alloc&)
            {
                ccLog::Error(tr("Based on Optimization"));
            }


            /// 1
            std::vector<std::pair<unsigned, unsigned>> samematch;
            std::vector<std::pair<unsigned, unsigned>> reservematch;
            std::function<_MapMatch(int, int,bool)> func;
            ClidarCompute::GetPointDataSelf(m_vecs,samematch ,reservematch);
            //        ClidarCompute::GetPointDataSelf1(m_vecs,match, ClidarCompute::Index_Iter);

            spdlog::info("reservematch: {}",reservematch.size());
            spdlog::info("samematch: {}",samematch.size());

            if(!samematch.empty())
            {
                /// 2
                func = std::bind(&CSlamLadirDialog::ReserveDirDataSpit, this,std::placeholders::_1,
                                 std::placeholders::_2,true);
                SetShowCloudPoint(samematch, func,true);
            }

            if (!reservematch.empty())
            {
                /// 2
                func = std::bind(&CSlamLadirDialog::ReserveDirDataSpit, this,std::placeholders::_1,
                                 std::placeholders::_2,false);
                SetShowCloudPoint(reservematch, func,false);
            }

        };

        //if ONCE point cloud , we registrae twice
        if(m_currentOptimizationType == 0)
        {
            fun_type();
        }
        // if many data about tranject
        else if(m_currentOptimizationType == 1)
        {
            //if the same point cloud , we registrae twice
            // fun_type();
        }

        ui->widget_option->show();

    }
    else
    {
        return;
    }

}


void CSlamLadirDialog::ShowTrajectorydata()
{
    //    m_pMainWindow->ADDRecently(fileName);
    {
        // show trajectorydata


        ccPointCloud* pclCloud = new ccPointCloud(QString::fromLocal8Bit(m_filename.c_str()));

        //Sphere
        if(m_ladirnewGroup==nullptr)
        {
            m_ladirnewGroup = new ccHObject(QString::fromLocal8Bit("ladir path"));
        }

        //pointcloud
        int num = m_vecs.size();
        pclCloud->reserve(static_cast<unsigned>(num));

        for (int i = 0; i < num; i++)
        {
            pclCloud->addPoint(CCVector3f(m_vecs[i].x, m_vecs[i].y, m_vecs[i].z));
        }
        pclCloud->setPointSize(3);
        m_ladirnewGroup->addChild(pclCloud);


        //        //obj
        //        for (int i = 0;i<_vec.size();i++) {
        //            ccGenericPrimitive* primitive = nullptr;
        //            ccGLMatrix transMat;
        //            transMat.setTranslation(CCVector3f(_vec[i].x(), _vec[i].y(), _vec[i].z()));

        //            CCVector3 dims(	static_cast<PointCoordinateType>(0.3),
        //                            static_cast<PointCoordinateType>(0.3),
        //                            static_cast<PointCoordinateType>(0.3));
        //            primitive = new ccBox(dims,&transMat);
        //            //            primitive = new ccSphere(static_cast<PointCoordinateType>(10.0f), &transMat);
        //            newGroup->addChild(primitive);
        //        }

        m_pMainWindow->addToDB(m_ladirnewGroup, true, true, false);
    }

}






///
/// \brief CSlamLadirDialog::SetShowCloudPoint
/// \param match
///
void CSlamLadirDialog::SetShowCloudPoint(std::vector<std::pair<unsigned,unsigned>> match,
                                         std::function<_MapMatch(int,int,bool)> func,bool isSame)
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
    spdlog::info("match : {}",match.size());
    for(iter = match.begin(); iter!= match.end(); iter++)
    {
        if(!m_vecs.empty())
        {

            _showVecpointlist.push_back(func(iter->first,iter->second,isSame));
            // _showVecpointlist.push_back(DataSpit(iter->first,iter->second));
        }
    }
    spdlog::info("issame : {}",_showVecpointlist.size());



    if (m_selectedFiles.isEmpty())
        return;
    else
    {
        ccGLMatrix transMat;
        ICPPERDATA _icpperdata_t;
        int num = _showVecpointlist.size()+1;
        m_pProgressDialog.setRange(0,num); //设置进度对话框的步进范围
        double dManualRegistration = 0.0f;
        double dminRMSRegistration = 0.35;
        long double g_dprice = 0.001;

        _icpperdata_t.minRMSDecrease = 1e-05;
        _icpperdata_t.maxIterationCount= 20;
        _icpperdata_t.randomSamplingLimit= 50000;
        _icpperdata_t.removeFarthestPoints= true;
        _icpperdata_t.useDataSFAsWeights= false;
        _icpperdata_t.useModelSFAsWeights= false;
        _icpperdata_t.adjustScale= false;
        _icpperdata_t.transformationFilters= false;
        _icpperdata_t.finalOverlap= 100;
        _icpperdata_t.method= 0 ;
        _icpperdata_t.maxThreadCount= 8;
        _icpperdata_t.bisREname = false;


        for (int i = 0;i<_showVecpointlist.size();i++) {
            m_pProgressDialog.setValue(i);
            _MapMatch _MapMatch_t = _showVecpointlist[i];
            ccHObject* newGroups = new ccHObject(g_CAppConfig.MATCHName+QString::number(i));
            ccPointCloud* transcloud = loadPointCloud(_MapMatch_t.matched,_MapMatch_t.matchedlist,m_pointDir,g_CAppConfig.currentOpenDlgFilter);
            ccPointCloud* dstcloud = loadPointCloud(_MapMatch_t.matching,_MapMatch_t.matchinglist,m_pointDir,g_CAppConfig.currentOpenDlgFilter);
            dManualRegistration = m_pCObjCCAlgorithm->AutoICPRegister(_icpperdata_t,transcloud,dstcloud,transMat);

            std::function<void(ccPointCloud *)> funcpoint = [=](ccPointCloud *firstCloud)
            {
                std::vector<ccPointCloud *> resultingClouds = m_pCObjCCAlgorithm->SetResample(firstCloud);
                for(int i = 0;i<resultingClouds.size();i++)
                {
                    newGroups->addChild(resultingClouds[i]);
                }
            };

            std::map<int,std::function<int()>> m_funmap;
            m_funmap.insert(make_pair(0,[=]() mutable->int
            {
                if(newGroups != nullptr && transcloud !=nullptr && dstcloud !=nullptr)
                {
                    funcpoint(transcloud);
                    funcpoint(dstcloud);
                    m_pMainWindow->addToDB(newGroups, true, true, false);
                    newGroups->setVisible(false);
                    newGroups->setEnabled(false);
                }
                return 1;
            }));
            m_funmap.insert(make_pair(1,[=]() mutable->int
            {
                newGroups->setName(newGroups->getName()+"_same_autoregister");
                GetResultRegister(transMat,_MapMatch_t.matchedingid,_MapMatch_t.matchedid);
                delete transcloud;
                delete dstcloud;
                delete newGroups;
                return 0;
            }));
            m_funmap.insert(make_pair(2,[=]() mutable ->int
            {
                newGroups->setName(newGroups->getName()+"_same");
                return 1;
            }));
            m_funmap.insert(make_pair(3,[=]() mutable->int
            {
                newGroups->setName(newGroups->getName()+"_reserve_autoregister");
                GetResultRegister(transMat,_MapMatch_t.matchedingid,_MapMatch_t.matchedid);
                return 1;
            }));
            m_funmap.insert(make_pair(4,[=]() mutable ->int
            {
                newGroups->setName(newGroups->getName()+"_reserve");
                return 1;
            }));


            int key = 1;
            /* get key and perform */
            if(_MapMatch_t.isSame && dManualRegistration-dminRMSRegistration < g_dprice)
                key = 1;
            else if(_MapMatch_t.isSame && dManualRegistration-dminRMSRegistration > g_dprice)
                key = 2;
            else if(!_MapMatch_t.isSame && dManualRegistration-dminRMSRegistration < g_dprice)
                key = 3;
            else if(!_MapMatch_t.isSame && dManualRegistration-dminRMSRegistration > g_dprice)
                key = 4;

            spdlog::info("matchedingid : {}",_MapMatch_t.matchedingid);
            spdlog::info("matchedid : {}",_MapMatch_t.matchedid);
            spdlog::info("key : {}",key);
            if(m_funmap[key]() == 1)
                m_funmap[0]();

            if(m_pProgressDialog.wasCanceled())
                return;
            QCoreApplication::processEvents();
        }

    }

    m_pProgressDialog.close();
    //    delete m_pProgressDialog;
}




void CSlamLadirDialog::GetResultRegister(ccGLMatrix finalTrans,int m_strfirstID,int m_strsecondID)
{
    try {

        float phi_rad = 0.0;
        float theta_rad = 0.0;
        float psi_rad = 0.0;
        CCVector3 t3D;
        ccGLMatrix finalTransCorrected = finalTrans;

        //将相对量变化为绝对直
        if(m_strsecondID!=0)
        {

            ccGLMatrix tempTrans = m_IndextrajectoryMap[m_strsecondID];

            tempTrans.getParameters(phi_rad,theta_rad,psi_rad,t3D);
            finalTransCorrected.initFromParameters(phi_rad,theta_rad,psi_rad,t3D);

            finalTrans = finalTrans * tempTrans ;

            tempTrans.getParameters(phi_rad,theta_rad,psi_rad,t3D);

            finalTrans.getParameters(phi_rad,theta_rad,psi_rad,t3D);
            finalTransCorrected.initFromParameters(phi_rad,theta_rad,psi_rad,t3D);


            PointTypePose key_frame_pose;

            key_frame_pose.id = m_strsecondID;
            key_frame_pose.yaw = phi_rad;
            key_frame_pose.pitch = theta_rad;
            key_frame_pose.roll = psi_rad;

            key_frame_pose.x = t3D.x;
            key_frame_pose.y = t3D.y;
            key_frame_pose.z = t3D.z;

            spdlog::info("{: } {: } {: } {: } {: } {: } {: }",key_frame_pose.id ,key_frame_pose.yaw,
            key_frame_pose.pitch,key_frame_pose.roll,key_frame_pose.x,key_frame_pose.y,key_frame_pose.z);
            try
            {
                if(g_CDataChange!=nullptr)
                    g_CDataChange->addLoopClosureFactor(key_frame_pose, m_strfirstID);
            }
            catch (const std::bad_alloc&)
            {
                ccLog::Error(tr("Based on Optimization"));
            }


        }

    }
    catch (const std::bad_alloc&)
    {
        ccLog::Error(tr("Not enough memory"));
    }



}












//// this pointcloud transform form origin to world
//ccPointCloud*  CSlamLadirDialog::GetOrignMat(int index,ccGLMatrix &transTemp)
//{

//    if(g_trajectoryMap.count(str) == 1)
//    {

//        SensorTrajectoryData lidarSe3 = g_trajectoryMap[strfilename.substr(0, strfilename.size() - 4)];
//        Eigen::Matrix4f Roi2w = getSE3Mat(lidarSe3.yaw*(180.0/M_PI), lidarSe3.pitch*(180.0/M_PI), lidarSe3.roll*(180.0/M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");

//        ccGLMatrix transTemp = ClidarCompute::FromEigenMat(Roi2w);

//        obj->applyRigidTransformation(transTemp);

//        //        pcl::PointCloud<pcl::PointXYZI>::Ptr cloudRGBAllreult = transform<pcl::PointXYZI>(cloudA, Roi2w);

//    }
//}



// if(_MapMatch_t.isSame)
// {
//     if(dManualRegistration-dminRMSRegistration<g_dprice)
//     {
//         newGroups->setName(newGroups->getName()+"_same_autoregister");
//         // GetResultRegister(transMat,_MapMatch_t.matchedid,_MapMatch_t.matchedingid);
//         GetResultRegister(transMat,_MapMatch_t.matchedingid,_MapMatch_t.matchedid);
//         delete transcloud;
//         delete dstcloud;
//         delete newGroups;

//     }
//     else
//     {
//         newGroups->setName(newGroups->getName()+"_same");
//         funcpoint(transcloud);
//         funcpoint(dstcloud);
//         m_pMainWindow->addToDB(newGroups, true, true, false);
//         newGroups->setVisible(false); //hide the cloud
//         newGroups->setEnabled(false);
//     }

// }else
// {
//     if(dManualRegistration-dminRMSRegistration<g_dprice)
//     {
//         newGroups->setName(newGroups->getName()+"_reserve_autoregister");
//         GetResultRegister(transMat,_MapMatch_t.matchedingid,_MapMatch_t.matchedid);

//     }
//     else
//     {
//         newGroups->setName(newGroups->getName()+"_reserve");
//     }

//     funcpoint(transcloud);
//     funcpoint(dstcloud);
//     m_pMainWindow->addToDB(newGroups, true, true, false);
//     newGroups->setVisible(false); //hide the cloud
//     newGroups->setEnabled(false);
// }


// else
// {
//     ccHObject* newGroups = new ccHObject(g_CAppConfig.MATCHName+QString::number(i));
//     loadpoint(newGroups, _MapMatch_t.matched,_MapMatch_t.matchedlist , m_pointDir,g_CAppConfig.currentOpenDlgFilter);
//     loadpoint(newGroups, _MapMatch_t.matching,_MapMatch_t.matchinglist, m_pointDir,g_CAppConfig.currentOpenDlgFilter);
//     m_pMainWindow->addToDB(newGroups, true, true, false);
//     newGroups->setVisible(false); //hide the cloud
//     newGroups->setEnabled(false);
// }









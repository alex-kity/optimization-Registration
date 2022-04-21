


//获取cc的点云对象
    ccHObject::Container selectedEntities = m_selectedEntities; // 当前所选择的点云对象
    //为了访问点云里的文件---自己加的的一段测试代码
    size_t selNum = selectedEntities.size();
    if (selNum != 1)
    {
        /*    m_app->dispToConsole("Please select two cloud!", ccMainAppInterface::ERR_CONSOLE_MESSAGE);*/
        return;
    }
    ccHObject* ent = selectedEntities[0];
    assert(ent);
    ccPointCloud* m_cloud = static_cast<ccPointCloud*>(ent);
    pcl::PointCloud<pcl::PointXYZ>::Ptr clouds(new pcl::PointCloud<pcl::PointXYZ>);
    CCcloudToPCLcloud(m_cloud,clouds);


    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ground(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ground_remove(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointIndicesPtr ground(new pcl::PointIndices);

    // 创建形态学滤波器对象
    pcl::ProgressiveMorphologicalFilter<pcl::PointXYZ> pmf;
    pmf.setInputCloud(clouds);

    // 设置过滤点最大的窗口尺寸
    pmf.setMaxWindowSize(10);

    // 设置计算高度阈值的斜率值--就是坡度
    pmf.setSlope(1.0f);

    // 设置初始高度参数被认为是地面点
    pmf.setInitialDistance(0.5f);

    // 设置被认为是地面点的最大高度
    pmf.setMaxDistance(3.0f);
    pmf.extract(ground->indices);

    // Create the filtering object
    pcl::ExtractIndices<pcl::PointXYZ> extract;
    extract.setInputCloud(clouds);
    extract.setIndices(ground);
    extract.filter(*cloud_ground);

    // 提取非地面点
    extract.setNegative(true);
    extract.filter(*cloud_ground_remove);


    //-------接下来给他们更新到dbtree里面

    //1。需要对pcl的cloud转换成cc的
    ccPointCloud *cloudGround = new ccPointCloud();
    ccPointCloud *cloudNoGround = new ccPointCloud();

    PCLcloudToCCcloud(cloud_ground, cloudGround);
    PCLcloudToCCcloud(cloud_ground_remove, cloudNoGround);

    //设置颜色区分一下
    cloudGround->setRGBColor(255,0,0);
    cloudGround->showColors(true);//显示颜色
    cloudGround->setPointSize(2);

    cloudNoGround->setRGBColor(0, 255, 0);
    cloudNoGround->showColors(true);
    cloudNoGround->setPointSize(3);



    m_cloud->setEnabled(false);
    
    //添加新的一组DB实体
    ccHObject* cloudContainer = new ccHObject(m_cloud->getName() + QString::fromLocal8Bit("分割场景-地面点"));//父目录
    //设置新点云并添加到实体
    cloudGround->setVisible(true);
    cloudGround->setName(QString::fromLocal8Bit("zx的地面点！"));//子目录
    cloudContainer->addChild(cloudGround);
    //添加实体到DB树
    addToDB(cloudContainer);

    //添加新的一组DB实体
    ccHObject* cloudContainer1 = new ccHObject(m_cloud->getName() + QString::fromLocal8Bit("分割场景-非地面点"));//父目录
    //设置新点云并添加到实体
    cloudNoGround->setVisible(true);
    cloudNoGround->setName(QString::fromLocal8Bit("zx的非地面点！"));//子目录
    cloudContainer1->addChild(cloudNoGround);
    //添加实体到DB树
    addToDB(cloudContainer1);

    //刷新
    refreshAll();

    QMessageBox::about(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("这是莫某的开发"));
    return;

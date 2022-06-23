

//#ifndef POINT_PAIR_REGISTRATION_DIALOG_HEADER
//#define POINT_PAIR_REGISTRATION_DIALOG_HEADER

////Local
//#include "ccMainAppInterface.h"
//#include "ccOverlayDialog.h"
//#include "ccPickingListener.h"

////CCCoreLib
//#include <PointProjectionTools.h>

////qCC_db
//#include <ccPointCloud.h>

////Qt generated dialog
//#include <ui_pointPairRegistrationDlg.h>


//class ccGenericPointCloud;
//class ccGenericGLDisplay;
//class ccGLWindow;
//class cc2DLabel;
//class ccPickingHub;
//class ccGLMatrix;
////Dialog for the point-pair registration algorithm (Horn)
//class CSlamPointPairRegistrationDlg : public ccOverlayDialog, public ccPickingListener, Ui::pointPairRegistrationDlg
//{
//	Q_OBJECT

//public:

//    ///	//! Default constructor
//    /// \brief CSlamPointPairRegistrationDlg
//    /// \param pickingHub
//    /// \param app
//    /// \param parent
//    ///
//    explicit
//    CSlamPointPairRegistrationDlg(ccPickingHub* pickingHub, ccMainAppInterface* app, QWidget* parent = nullptr);

//	//inherited from ccOverlayDialog
//	bool linkWith(ccGLWindow* win) override;
//	bool start() override;
//	void stop(bool state) override;

//    /////! Inits dialog
//    /// \brief init
//    /// \param win
//    /// \param alignedEntities
//    /// \param referenceEntities
//    /// \return
//    ///
//    bool
//    init(	ccGLWindow* win,
//				const ccHObject::Container& alignedEntities,
//				const ccHObject::Container* referenceEntities = nullptr);

//    /////! Clears dialog
//    /// \brief clear
//    ///
//    void
//    clear();

//    /////! Pauses the dialog
//    /// \brief pause
//    /// \param state
//    ///
//    void
//    pause(bool state);


//    /////! Adds a point to the 'align' set
//    /// \brief addAlignedPoint
//    /// \param P
//    /// \param entity
//    /// \param shifted
//    /// \return
//    ///
//    bool
//    addAlignedPoint(CCVector3d& P, ccHObject* entity = nullptr, bool shifted = true);


//    /////! Adds a point to the 'reference' set
//    /// \brief addReferencePoint
//    /// \param P
//    /// \param entity
//    /// \param shifted
//    /// \return
//    ///
//    bool
//    addReferencePoint(CCVector3d& P, ccHObject* entity = nullptr, bool shifted = true);


//    /////! Removes a point from the 'align' set
//    /// \brief removeAlignedPoint
//    /// \param index
//    /// \param autoRemoveDualPoint
//    ///
//    void
//    removeAlignedPoint(int index, bool autoRemoveDualPoint = true);


//    /////! Removes a point from the 'reference' set
//    /// \brief removeRefPoint
//    /// \param index
//    /// \param autoRemoveDualPoint
//    ///
//    void
//    removeRefPoint(int index, bool autoRemoveDualPoint = true);


//    /////! Inherited from ccPickingListener
//    /// \brief onItemPicked
//    /// \param pi
//    ///
//    void
//    onItemPicked(const PickedItem& pi) override;


//    ccGLMatrix m_transMatRT ;


//signals:
//    void
//    SignalRegistrationFinish();

//protected:

//    /////! Slot called to change aligned entities visibility
//    /// \brief showAlignedEntities
//    ///
//    void
//    showAlignedEntities(bool);


//    /////! Slot called to change reference entities visibility
//    /// \brief showReferenceEntities
//    ///
//    void
//    showReferenceEntities(bool);

//    /////! Slot called to add a manual point to the 'align' set
//    /// \brief addManualAlignedPoint
//    ///
//    void
//    addManualAlignedPoint();

//    /////! Slot called to add a manual point to the 'reference' set
//    /// \brief addManualRefPoint
//    ///
//    void
//    addManualRefPoint();


//    /////! Slot called to remove the last point on the 'align' stack
//    /// \brief unstackAligned
//    ///
//    void
//    unstackAligned();



//    //////! Slot called to remove the last point on the 'reference' stack
//    /// \brief unstackRef
//    ///
//    void
//    unstackRef();



//    /////! Slot called when a "delete" button is pushed
//    /// \brief onDelButtonPushed
//    ///
//    void
//    onDelButtonPushed();


//    /////! Updates the registration info and buttons states
//    /// \brief updateAlignInfo
//    ///
//    void
//    updateAlignInfo();

//    ///
//    /// \brief apply
//    ///
//    void
//    apply();

//    ///
//    /// \brief align
//    ///
//    void
//    align();

//    ///
//    /// \brief reset
//    ///
//    void
//    reset();

//    ///
//    /// \brief cancel
//    ///
//	void cancel();

//protected:

//    /////! Enables (or not) buttons depending on the number of points in both lists
//    /// \brief onPointCountChanged
//    ///
//    void
//    onPointCountChanged();


//    /////! Calls Horn registration (CCCoreLib::HornRegistrationTools)
//    /// \brief callHornRegistration
//    /// \param trans
//    /// \param rms
//    /// \param autoUpdateTab
//    /// \return
//    ///
//    bool
//    callHornRegistration(CCCoreLib::PointProjectionTools::Transformation& trans, double& rms, bool autoUpdateTab);



//    /////! Clears the RMS rows
//    /// \brief clearRMSColumns
//    ///
//    void
//    clearRMSColumns();



//    /////! Adds a point to one of the table (ref./aligned)
//    /// \brief addPointToTable
//    /// \param tableWidget
//    /// \param rowIndex
//    /// \param P
//    /// \param pointLabel
//    ///
//    void
//    addPointToTable(	QTableWidget* tableWidget,
//							int rowIndex,
//							const CCVector3d& P,
//							QString pointLabel );

//	//! Converts a picked point to a sphere center (if necessary)
//	/** \param P input point (may be converted to a sphere center)
//		\param entity associated entity
//		\param sphereRadius the detected spherer radius (or -1 if no sphere)
//		\return whether the point can be used or not
//	**/
//    bool
//    convertToSphereCenter(CCVector3d& P, ccHObject* entity, PointCoordinateType& sphereRadius);


//    //////! Resets the displayed title (3D view)
//    /// \brief resetTitle
//    ///
//    void
//    resetTitle();


//    /////! Entity original context
//    /// \brief The EntityContext struct
//    ///
//	struct EntityContext
//	{
//		//! Default constructor
//		explicit EntityContext(ccHObject* ent);

//		//! Restores cloud original state
//		void restore();

//		ccHObject* entity;
//		ccGenericGLDisplay* originalDisplay;
//		bool wasVisible;
//		bool wasEnabled;
//		bool wasSelected;
//	};



//    /////! Set of contexts
//    /// \brief The EntityContexts struct
//    ///
//	struct EntityContexts : public QMap< ccHObject*, EntityContext >
//	{
//		void fill(const ccHObject::Container& entities);

//		void restoreAll()
//		{
//			for (EntityContext& ctx : *this)
//				ctx.restore();
//		}

//		bool isShifted;
//		CCVector3d shift;
//		double scale = 1.0;
//	};


//    /////! Removes a label (and restore its associated label if any)
//    /// \brief removeLabel
//    /// \param points
//    /// \param childIndex
//    /// \param entities
//    ///
//    void
//    removeLabel(	ccPointCloud& points,
//						unsigned childIndex,
//						const EntityContexts& entities);

//protected: //members

//	//! Aligned entity
//	EntityContexts m_alignedEntities;

//	//! Aligned points set
//	ccPointCloud m_alignedPoints;
	
//	//! Reference entity (if any)
//	EntityContexts m_referenceEntities;

//	//! Reference points set
//	ccPointCloud m_refPoints;

//	//! Dedicated window
//	ccGLWindow* m_win;sunsun

//	//! Whether the dialog is paused or not
//	bool m_paused;

//	//! Picking hub
//	ccPickingHub* m_pickingHub;

//	//! Main application interface
//	ccMainAppInterface* m_app;


//};

//#endif //POINT_PAIR_REGISTRATION_DIALOG_HEADER

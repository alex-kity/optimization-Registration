////##########################################################################
////#                                                                        #
////#                              CLOUDCOMPARE                              #
////#                                                                        #
////#  This program is free software; you can redistribute it and/or modify  #
////#  it under the terms of the GNU General Public License as published by  #
////#  the Free Software Foundation; version 2 or later of the License.      #
////#                                                                        #
////#  This program is distributed in the hope that it will be useful,       #
////#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
////#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          #
////#  GNU General Public License for more details.                          #
////#                                                                        #
////#                       COPYRIGHT: SAGE INGENIERIE                       #
////#                                                                        #
////##########################################################################

//#ifndef CC_PLANE_EDIT_DLG_HEADER
//#define CC_PLANE_EDIT_DLG_HEADER

////Local
//#include <ui_SgsTagging.h>
//#include "ccPickingListener.h"

////CCCoreLib
//#include <CCGeom.h>

////Qt
//#include <QDialog>

//class ccGLWindow;
//class ccPlane;
//class ccHObject;
//class ccPickingHub;

//////! Dialog to create (or edit the parameters) of a plane
////class SgsTagging : public QDialog, public ccPickingListener, public Ui::SgsTagging
////{
////    Q_OBJECT

////public:
////    //semi-persistent parameters
////     double s_dip = 0;
////     double s_dipDir = 0;
////     double s_width = 10.0;
////     double s_height = 10.0;
////     bool s_upward = true;
////     CCVector3d s_center;


////    //! Default constructor
////    explicit SgsTagging(ccPickingHub* pickingHub, QWidget* parent);

////    //! Destructor
////    virtual ~SgsTagging();

////    //! Links this dialog with an existing plane
////    void initWithPlane(ccPlane* plane);

////    //! Updates a plane with the current parameters
////    void updatePlane(ccPlane* plane);

////    //! Inherited from ccPickingListener
////    virtual void onItemPicked(const PickedItem& pi);

////public:

////    void pickPointAsCenter(bool);
////    void onDipDirChanged(double);
////    void onDipDirModified(bool);
////    void onNormalChanged(double);

////protected:

////    void saveParamsAndAccept();

////protected: //members

////    //! Picking window (if any)
////    ccGLWindow* m_pickingWin;

////    //! Associated plane (if any)
////    ccPlane* m_associatedPlane;

////    //! Picking hub
////    ccPickingHub* m_pickingHub;

////};

//#endif

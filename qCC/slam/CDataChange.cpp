
#include "CDataChange.h"
#include "CGYLCommon.h"
void CDataChange::InitData(std::string filename)
{
    lygs::CGYLCommon _CGYLCommon;
    std::map<std::string,lygs::trajectoryData> trajectorys;
    std::vector<lygs::trajectoryData> m_vecs  = _CGYLCommon.readTrajectoryToxian(filename,trajectorys);



}

void CDataChange::SetData(DATARegistration)
{

}

void CDataChange::SetFinished(const bool finish)
{

}

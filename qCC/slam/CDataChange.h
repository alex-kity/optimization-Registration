

#include <eigen3/Eigen/Eigen>
#include <CCVector3>
#include <string>

struct DATARegistration
{
    float phi_rad,
    float theta_rad,
    float psi_rad,
    float x,
    float y,
    float z,

    int ied = 0;
    int iing = 0;

};


class CDataChange
{
public:
    CDataChange(){}


    //interface
    void InitData(std::string filename)
    {

    }

    //! data once
    void SetData(DATARegistration)
    {

    }


    //! SetFinished
    void SetFinished(const bool finish)
    {

    }


private:



};

#include "cov_calculate.h"

int main (int argc, char *argv[])
{    
    CovCalculate covcalculate(3,3);
    std::vector<float> data;
    data.push_back(1.0f);  // x
    data.push_back(22.0f); // y
    data.push_back(3.0f);  // z
    covcalculate.InseretData(data);
    data.clear();
    data.push_back(4.0f);
    data.push_back(55.0f);
    data.push_back(6.0f);
    covcalculate.InseretData(data);
    data.clear();
    data.push_back(7.0f);
    data.push_back(23.0f);
    data.push_back(9.0f);
    covcalculate.InseretData(data);
    std::cout << covcalculate.returnCovMatirx();
    return 0;
}
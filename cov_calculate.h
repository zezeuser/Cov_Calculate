#include <iostream>
#include <sstream>
#include <Eigen/Dense>
#include <vector>
#ifndef COVCALCULATE_H
#define COVCALCULATE_H
class CovCalculate{
    /*
        CovCalculate 类用于计算矩阵的协方差 
        cols 为数据维度
        rows 为可容数据量
    */
    public:
        CovCalculate(int rows ,int cols ):
        variable_matrix_(rows , cols)
        {
            rows_ = rows;
            cols_ = cols;
            replace_rows_ = 0;
            variable_matrix_.setZero();
        }
        /*
           InseretData 插入数据至矩阵中 
           param : vector<float> data , data.size = cols
        */
        void InseretData(std::vector<float> variables){
            int temp_replace_rows = replace_rows_++ % rows_; 
            int temp_replace_cols = 0;
            for(auto variable = variables.begin(); variable != variables.end(); variable++){
                variable_matrix_(temp_replace_rows,temp_replace_cols++) = *variable;
            }
        }
        /*
           InseretData 返回协方差矩阵
           param : None
        */
        Eigen::MatrixXf returnCovMatirx(){
            Eigen::MatrixXf meanVec = variable_matrix_.colwise().mean();
            Eigen::RowVectorXf meanVecRow(Eigen::RowVectorXf::Map(meanVec.data(),variable_matrix_.cols()));
            Eigen::MatrixXf zeroMeanMat = variable_matrix_;
            zeroMeanMat.rowwise()-=meanVecRow;

            Eigen::MatrixXf cov_matirx;
            if(variable_matrix_.rows()==1){
                cov_matirx = (zeroMeanMat.adjoint()*zeroMeanMat)/double(variable_matrix_.rows());
            }
            else{
                cov_matirx = (zeroMeanMat.adjoint()*zeroMeanMat)/double(variable_matrix_.rows()-1);
            }
            return cov_matirx;
        }

    private:
        int rows_;
        int cols_;
        int replace_rows_;;
        Eigen::MatrixXf variable_matrix_;
};

#endif //COVCALCULATE_H



## Cov_Calculate
使用说明：
计算数据的协方差
\
初始化：

```cpp
// 将接收两个 int 类型 ， 用于保存数据，称为变量矩阵
// 行数为数据容量
// 列数为数据维度 
// example :  (x,y,z) 三个变量为一次数据结果 ,存取 4 次
// 					cols = 3;  rows = 4 ;	 
CovCalculate(int rows ,int cols )
```

API :

```cpp
// 将数据保存至变量矩阵中，
// 若插入次数超过变量矩阵的行数，
// 将替换最旧的数据
InseretData(std::vector<float> variables) 
```

```cpp
// 返回数据的协方差矩阵
Eigen::MatrixXf returnCovMatirx()
```

demo:

```cpp
git clone git@github.com:zezeuser/Cov_Calculate.git
cd Cov_Calculate
mkdir build
cd build
cmake ..
make 
./demo
```


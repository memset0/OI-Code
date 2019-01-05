#include <iostream>
using namespace std; //头文件和命名空间
inline bool IsAddable(int iNum, int iLBound, int iUBound){ //判断是否满足要求的函数，iNum-判断的数字；iLBound-各位和下界；iUBound-各位和的上界
    int iSum = 0; //各位和
    while (iNum){ //求各位和
        iSum += iNum % 10; //加上最后一位
        iNum /= 10; //消去最后一位
    }
    return (iLBound <= iSum && iSum <= iUBound); //判断
}
int main(){
    ios::sync_with_stdio(false); //输入输出加速
    int iEnd, iLB, iUB; //区间结尾以及各位数字之和的上下界
    cin >> iEnd >> iLB >> iUB; //读入限制条件
    register int i; //循环变量
    register long long iSum = 0; //累加器
    for (i = 1; i <= iEnd; ++i){ //枚举
        if (IsAddable(i, iLB, iUB)) //判断是否相加
            iSum += i; //若满足则累加
    }
    cout << iSum << endl; //输出和，勿忘换行
    return 0; //结束
}
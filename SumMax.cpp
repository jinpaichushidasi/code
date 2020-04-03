#include <iostream>
using namespace std;

int main()
{
    int n,i,a[10],sum1=0,sum2=0,mod=0;
    cout << "请输入数组数量"<<endl;
    cin >> n;
    cout << "请输入数组" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        sum1 = sum1 + a[i];
        if (sum1 < 0)
        {
            sum1 = 0;
        }
        if (sum1 > sum2)
        {
            sum2 = sum1;
        }
    }
    cout << "最大子段和为" << endl;
    cout << sum2;
    return 0;
}

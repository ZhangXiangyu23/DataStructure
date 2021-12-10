#include<iostream>
#include<set>
#include<vector>
#include<cmath>

using namespace std;

int Place(vector<int> &X, multiset<int> DSet, int N, int left, int right)
{
    int MaxDist, Found = false;
    if (DSet.empty())       // 如果距离集合为空，表示所有距离都被用上
        return true;
    MaxDist = *DSet.rbegin();   // 当前距离的最大值
    multiset<int> DSetcopy = DSet;      // 创建DSet副本
    // 检查当前被放置的X[Right]==MaxDist是否可行
    int flag = 1;   
    X[right] = MaxDist;     // 尝试在right位置放置当前最大距离值行不行，不行就回溯
    for (int i = 1;i < left;i++)
    {// 如果DSet中没有已放置好的X[i](0<i<left)减去当前最大距离MaxDist的绝对值（Dset中距离值）时
        if (DSetcopy.find(abs(X[i] - MaxDist)) == DSetcopy.end())
        {
            flag = 0;break; // flag置为0
        }
        DSetcopy.erase(DSetcopy.find(abs(X[i] - X[right])));    // 删除距离集合中相关距离值
    }
    for (int i = right + 1;i <= N;i++)
    {// 如果DSet中没有已放置好的X[i](right<i<=N)减去当前最大距离MaxDist的绝对值时
        if (DSetcopy.find(abs(X[i] - MaxDist)) == DSetcopy.end())
        {
            flag = 0;   // flag置为0
            break;
        }
        DSetcopy.erase(DSetcopy.find(abs(X[i] - X[right])));
    }
    if (flag)
    {
        DSet = DSetcopy;
        Found = Place(X, DSet, N, left, right - 1);     // 继续在下一个位置right-1处插入下一个最大的距离值
        if (!Found) // 如果Found==false表示距离集合不为空，则进行回溯
        {
            for (int i = 1;i < left;i++)
                DSet.insert(abs(X[i] - X[right]));  // 回插距离集合中相关距离值，将删除的距离值返回
            for (int i = right + 1;i <= N;i++)
                DSet.insert(abs(X[i] - X[right]));
        }
    }

    flag = 1;
    DSetcopy = DSet;        // 创建DSet副本
    if ((!Found))           // 如果尝试在右边放置失败，则尝试在左边放置
    {
        X[left] = X[N] - MaxDist;
        for (int i = 1;i < left;i++)
        {   // 如果DSet中没有已放置好的X[i](0<i<left)使得X[N]减去当前最大距离MaxDist再减去X[i]的结果绝对值时
            if (DSetcopy.find(abs(X[left] - X[i])) == DSetcopy.end())
            {
                flag = 0;   // flag置为0
                break;
            }
            DSetcopy.erase(DSetcopy.find(abs(X[left] - X[i]))); // 删除距离集合中相关距离值
        }
        for (int i = right + 1;i <= N;i++)
        {
            // 如果DSet中没有已放置好的X[i](right<i<=N)减去当前最大距离MaxDist再减去X[i]的结果绝对值时
            if (DSetcopy.find(abs(X[left] - X[i])) == DSetcopy.end())
            {
                flag = 0;   // flag置为0
                break;
            }
            DSetcopy.erase(DSetcopy.find(abs(X[left] - X[i])));
        }
        if (flag)       // 表示距离集合DSet中元素分布满足插入X[left]的条件
        {
            DSet = DSetcopy;
            Found = Place(X, DSet, N, left + 1, right);
            if (!Found) // 如果Found==false表示距离集合不为空，则进行回溯
            {
                for (int i = 1;i < left;i++)
                    DSet.insert(abs(X[N] - MaxDist - X[i]));    // 回插距离集合中相关距离值，将删除的距离值返回
                for (int i = right + 1;i <= N;i++)
                    DSet.insert(abs(X[N] - MaxDist - X[i]));
            }
        }
    }
    return Found;
}

int main()
{
    const int N = 6;
    int DistSet[] = { 1,2,2,2,3,3,3,4,5,5,5,6,7,8,10 };     // 距离集合
    multiset<int> DSet;     // 将距离集合存放至multiset中，方便后续操作
    vector<int> X(N + 1);           // 向量X用于存放点集合结果
    for (int i = 0;i < sizeof(DistSet) / sizeof(int);i++)
    {
        DSet.insert(DistSet[i]);
    }
    X[1] = 0;           // X[1]置为1
    X[N] = *DSet.rbegin();  // X[N]置为距离集合中的最大值
    DSet.erase(*DSet.rbegin()); // 删除最大距离值
    Place(X, DSet, N, 2, N - 1);    // 回溯算法来确定每个点的位置
    for (vector<int>::iterator iter = X.begin()+1;iter != X.end();iter++)
    {// 打印点集合中的点
        cout << *iter << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

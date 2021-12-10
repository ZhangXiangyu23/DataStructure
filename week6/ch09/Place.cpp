#include<iostream>
#include<set>
#include<vector>
#include<cmath>

using namespace std;

int Place(vector<int> &X, multiset<int> DSet, int N, int left, int right)
{
    int MaxDist, Found = false;
    if (DSet.empty())       // ������뼯��Ϊ�գ���ʾ���о��붼������
        return true;
    MaxDist = *DSet.rbegin();   // ��ǰ��������ֵ
    multiset<int> DSetcopy = DSet;      // ����DSet����
    // ��鵱ǰ�����õ�X[Right]==MaxDist�Ƿ����
    int flag = 1;   
    X[right] = MaxDist;     // ������rightλ�÷��õ�ǰ������ֵ�в��У����оͻ���
    for (int i = 1;i < left;i++)
    {// ���DSet��û���ѷ��úõ�X[i](0<i<left)��ȥ��ǰ������MaxDist�ľ���ֵ��Dset�о���ֵ��ʱ
        if (DSetcopy.find(abs(X[i] - MaxDist)) == DSetcopy.end())
        {
            flag = 0;break; // flag��Ϊ0
        }
        DSetcopy.erase(DSetcopy.find(abs(X[i] - X[right])));    // ɾ�����뼯������ؾ���ֵ
    }
    for (int i = right + 1;i <= N;i++)
    {// ���DSet��û���ѷ��úõ�X[i](right<i<=N)��ȥ��ǰ������MaxDist�ľ���ֵʱ
        if (DSetcopy.find(abs(X[i] - MaxDist)) == DSetcopy.end())
        {
            flag = 0;   // flag��Ϊ0
            break;
        }
        DSetcopy.erase(DSetcopy.find(abs(X[i] - X[right])));
    }
    if (flag)
    {
        DSet = DSetcopy;
        Found = Place(X, DSet, N, left, right - 1);     // ��������һ��λ��right-1��������һ�����ľ���ֵ
        if (!Found) // ���Found==false��ʾ���뼯�ϲ�Ϊ�գ�����л���
        {
            for (int i = 1;i < left;i++)
                DSet.insert(abs(X[i] - X[right]));  // �ز���뼯������ؾ���ֵ����ɾ���ľ���ֵ����
            for (int i = right + 1;i <= N;i++)
                DSet.insert(abs(X[i] - X[right]));
        }
    }

    flag = 1;
    DSetcopy = DSet;        // ����DSet����
    if ((!Found))           // ����������ұ߷���ʧ�ܣ���������߷���
    {
        X[left] = X[N] - MaxDist;
        for (int i = 1;i < left;i++)
        {   // ���DSet��û���ѷ��úõ�X[i](0<i<left)ʹ��X[N]��ȥ��ǰ������MaxDist�ټ�ȥX[i]�Ľ������ֵʱ
            if (DSetcopy.find(abs(X[left] - X[i])) == DSetcopy.end())
            {
                flag = 0;   // flag��Ϊ0
                break;
            }
            DSetcopy.erase(DSetcopy.find(abs(X[left] - X[i]))); // ɾ�����뼯������ؾ���ֵ
        }
        for (int i = right + 1;i <= N;i++)
        {
            // ���DSet��û���ѷ��úõ�X[i](right<i<=N)��ȥ��ǰ������MaxDist�ټ�ȥX[i]�Ľ������ֵʱ
            if (DSetcopy.find(abs(X[left] - X[i])) == DSetcopy.end())
            {
                flag = 0;   // flag��Ϊ0
                break;
            }
            DSetcopy.erase(DSetcopy.find(abs(X[left] - X[i])));
        }
        if (flag)       // ��ʾ���뼯��DSet��Ԫ�طֲ��������X[left]������
        {
            DSet = DSetcopy;
            Found = Place(X, DSet, N, left + 1, right);
            if (!Found) // ���Found==false��ʾ���뼯�ϲ�Ϊ�գ�����л���
            {
                for (int i = 1;i < left;i++)
                    DSet.insert(abs(X[N] - MaxDist - X[i]));    // �ز���뼯������ؾ���ֵ����ɾ���ľ���ֵ����
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
    int DistSet[] = { 1,2,2,2,3,3,3,4,5,5,5,6,7,8,10 };     // ���뼯��
    multiset<int> DSet;     // �����뼯�ϴ����multiset�У������������
    vector<int> X(N + 1);           // ����X���ڴ�ŵ㼯�Ͻ��
    for (int i = 0;i < sizeof(DistSet) / sizeof(int);i++)
    {
        DSet.insert(DistSet[i]);
    }
    X[1] = 0;           // X[1]��Ϊ1
    X[N] = *DSet.rbegin();  // X[N]��Ϊ���뼯���е����ֵ
    DSet.erase(*DSet.rbegin()); // ɾ��������ֵ
    Place(X, DSet, N, 2, N - 1);    // �����㷨��ȷ��ÿ�����λ��
    for (vector<int>::iterator iter = X.begin()+1;iter != X.end();iter++)
    {// ��ӡ�㼯���еĵ�
        cout << *iter << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

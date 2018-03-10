#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
struct Stu
{
    string id;
    int c;
    int m;
    int e;
    int average;
    int c_rank;
    int m_rank;
    int e_rank;
    int a_rank;
    int top_rank;
    char top_subject;
};
 
bool cmp_c(const Stu & a, const Stu & b) { return a.c > b.c; }
bool cmp_m(const Stu & a, const Stu & b) { return a.m > b.m; }
bool cmp_e(const Stu & a, const Stu & b) { return a.e > b.e; }
bool cmp_a(const Stu & a, const Stu & b) { return a.average > b.average; }
 
void rank_c(vector<Stu> & stulist, const int len)
{
    stulist[0].c_rank = 1;
    for (int i = 1;i < len;++i)
    {
        if (stulist[i].c == stulist[i - 1].c)
        {
            stulist[i].c_rank = stulist[i - 1].c_rank;
        }
        else
        {
            stulist[i].c_rank = i + 1;
        }
    }
}
 
void rank_m(vector<Stu> & stulist, const int len)
{
    stulist[0].m_rank = 1;
    for (int i = 1;i < len;++i)
    {
        if (stulist[i].m == stulist[i - 1].m)
        {
            stulist[i].m_rank = stulist[i - 1].m_rank;
        }
        else
        {
            stulist[i].m_rank = i + 1;
        }
    }
}
 
void rank_e(vector<Stu> & stulist, const int len)
{
    stulist[0].e_rank = 1;
    for (int i = 1;i < len;++i)
    {
        if (stulist[i].e == stulist[i - 1].e)
        {
            stulist[i].e_rank = stulist[i - 1].e_rank;
        }
        else
        {
            stulist[i].e_rank = i + 1;
        }
    }
}
 
void rank_a(vector<Stu> & stulist, const int len)
{
    stulist[0].a_rank = 1;
    for (int i = 1;i < len;++i)
    {
        if (stulist[i].average == stulist[i - 1].average)
        {
            stulist[i].a_rank = stulist[i - 1].a_rank;
        }
        else
        {
            stulist[i].a_rank = i + 1;
        }
    }
}
 
void rank_top(vector<Stu> & stulist, const int len)
{
    for (int i = 0;i < len;++i)
    {
        if (stulist[i].a_rank <= stulist[i].c_rank &&
            stulist[i].a_rank <= stulist[i].m_rank &&
            stulist[i].a_rank <= stulist[i].e_rank)
        {
            stulist[i].top_rank = stulist[i].a_rank;
            stulist[i].top_subject = 'A';
        }
        else if (stulist[i].c_rank < stulist[i].a_rank &&
            stulist[i].c_rank <= stulist[i].m_rank &&
            stulist[i].c_rank <= stulist[i].e_rank)
        {
            stulist[i].top_rank = stulist[i].c_rank;
            stulist[i].top_subject = 'C';
        }
        else if (stulist[i].m_rank < stulist[i].a_rank &&
            stulist[i].m_rank < stulist[i].c_rank &&
            stulist[i].m_rank <= stulist[i].e_rank)
        {
            stulist[i].top_rank = stulist[i].m_rank;
            stulist[i].top_subject = 'M';
        }
        else if (stulist[i].e_rank < stulist[i].a_rank &&
            stulist[i].e_rank < stulist[i].c_rank &&
            stulist[i].e_rank < stulist[i].m_rank)
        {
            stulist[i].top_rank = stulist[i].e_rank;
            stulist[i].top_subject = 'E';
        }
        else
        {
            //
        }
    }
}
 
bool check(const vector<Stu>stulist, const int len, const string id, int & index)
{
    for (int i = 0;i < len;++i)
    {
        if (id == stulist[i].id)
        {
            index = i;
            return true;
        }
    }
    return false;
}
 
int main()
{

    int N, M;
    cin >> N >> M;
    vector<Stu>stulist;
    Stu stu;
    for (int i = 0;i < N;++i)
    {
        cin >> stu.id >> stu.c >> stu.m >> stu.e;
        stu.average = (stu.c + stu.m + stu.e) / 3;
        stu.top_rank = stu.c_rank = stu.m_rank = stu.e_rank = stu.a_rank = 0;
        stu.top_subject = 'A';
        stulist.push_back(stu);
    }
 
    // sort
    int len = 0;
    len = stulist.size();
    // sort c
    sort(stulist.begin(), stulist.end(), cmp_c);
    rank_c(stulist, len);
    // sort m
    sort(stulist.begin(), stulist.end(), cmp_m);
    rank_m(stulist, len);
    // sort e
    sort(stulist.begin(), stulist.end(), cmp_e);
    rank_e(stulist, len);
    // sort a
    sort(stulist.begin(), stulist.end(), cmp_a);
    rank_a(stulist, len);
    // filiter top
    rank_top(stulist, len);
 
    // find
    for (int i = 0;i < M;++i)
    {
        int index = 0;
        string id = "";
        cin >> id;
        if (check(stulist, len, id, index))
        {
            cout << stulist[index].top_rank << " " << stulist[index].top_subject << endl;
        }
        else
        {
            cout << "N/A" << endl;
        }
    }
    getchar();
    return 0;
}


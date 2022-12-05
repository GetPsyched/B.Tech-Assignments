#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;

int pop[10][10], npop[10][10], tpop[10][10], x[10], fx[10], m_max = 1,
                                                            ico = 0, ico1, it = 0;
void iter(int[10][10], int, int);
int u_rand(int);
void tour_sel(int, int);
void cross_ov(int, int);
void mutat(int, int);
int main()
{
    int k, m, j, i, p[10], n = 0, a[10], nit;
    cout << "Enter the number of Population in each iteration is : ";
    cin >> n;
    cout << "Enter the number of iteration is : ";
    cin >> nit;
    m = 5;
    for (i = 0; i < n; i++)
    {
        for (j = m - 1; j >= 0; j--)
        {
            pop[i][j] = u_rand(2);
        }
    }
    cout << "\nIteration " << it << " is :\n";
    iter(pop, n, m);
    it++;
    do
    {
        it++;
        cout << "\nIteration " << it << " is :\n";
        tour_sel(n, m);
        iter(pop, n, m);
    } while (it < nit);
    cout << "\n\nAfter the " << ico1 << " Iteration, the Maximum Valueis : " << (int)sqrt(m_max);
}

void iter(int pp[10][10], int o, int p)
{
    int i, j, sum, avg, max = 1;
    for (i = 0; i < o; i++)
    {
        x[i] = 0;
        for (j = 0; j < p; j++)
        {
            x[i] = x[i] + (pp[i][j] * pow(2, p - 1 - j));
        }
        fx[i] = x[i] * x[i];
        sum = sum + fx[i];
        if (max <= fx[i])
            max = fx[i];
    }
    avg = sum / o;
    cout << "\n\nS.No.\tPopulation\tX\tf(X)\n\n";
    for (i = 0; i < o; i++)
    {
        cout << ico << "\t";
        ico++;
        for (j = 0; j < p; j++)
            cout << pp[i][j];
        cout << "\t\t" << x[i] << "\t" << fx[i] << "\n";
    }
    cout << "\n\t Sum : " << sum << "\tAverage : " << avg << "\tMaximum :" << max << "\n";
    if (m_max < max)
    {
        m_max = max;
        ico1 = it;
    }
}
int u_rand(int x)
{
    int y;
    y = rand() % x;
    return (y);
}
void tour_sel(int np, int mb)
{
    int i, j, k, l, co = 0, cc;
    do
    {
        k = u_rand(np);
        do
        {
            cc = 0;
            l = u_rand(np);
            if (k == l)
                cc++;
        } while (cc != 0);
        if (fx[k] > fx[l])
        {
            for (j = 0; j < mb; j++)
                npop[co][j] = pop[k][j];
        }
        else if (fx[k] < fx[l])
        {
            for (j = 0; j < mb; j++)
                npop[co][j] = pop[l][j];
        }
        co++;
    } while (co < np);
    cross_ov(np, mb);
}
void cross_ov(int np1, int mb1)
{
    int i, j, k, l, co, temp;
    i = 0;
    do
    {
        k = rand() % 2;
        do
        {
            co = 0;
            l = u_rand(mb1);
            if (((k == 0) && (l == 0)) || ((k == 1) && (l == mb1)))
                co++;
        } while (co != 0);
        if ((k == 0) && (l != 0))
        {
            for (j = 0; j < l; j++)
            {
                temp = npop[i][j];
                npop[i][j] = npop[i + 1][j];
                npop[i + 1][j] = temp;
            }
        }
        else if ((k == 1) && (l != mb1))
        {
            for (j = l; j < mb1; j++)
            {
                temp = npop[i][j];
                npop[i][j] = npop[i + 1][j];
                npop[i + 1][j] = temp;
            }
        }
        i = i + 2;
    } while (i < np1);
    for (i = 0; i < np1; i++)
    {
        for (j = 0; j < mb1; j++)
        {
            tpop[i][j] = npop[i][j];
        }
    }
    mutat(np1, mb1);
}
void mutat(int np2, int mb2)
{
    int i, j, r, temp, k, z;
    i = 0;
    do
    {
        for (k = 0; k < np2; k++)
        {
            r = 0;
            if (i != k)
            {
                for (j = 0; j < mb2; j++)
                {
                    if (tpop[i][j] == tpop[k][j])
                        r++;
                }
                if (r != mb2 - 1)
                {
                    z = u_rand(mb2);
                    if (tpop[i][z] == 0)
                        tpop[i][z] = 1;
                    else
                        tpop[i][z] = 0;
                    if (npop[k][u_rand(mb2)] == 0)
                        npop[k][u_rand(mb2)] = 1;
                    else
                        npop[k][u_rand(mb2)] = 0;
                    mutat(k, mb2);
                }
            }
        }
        i++;
    } while (i < np2);
    for (i = 0; i < np2; i++)
    {
        for (j = 0; j < mb2; j++)
        {
            pop[i][j] = tpop[i][j];
        }
    }
}
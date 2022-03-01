#include <iostream>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include<fstream>
using namespace std;
using namespace std::chrono;

struct Records
{
    int Key;
    Records* L;

    Records(): Key(0), L(nullptr) {}
    Records(int k): Key(k), L(nullptr) {} 
};
struct Coordinates
{
    int x;
    int y;
  };
Records* radix_list(int N, Records* R, int m, int p, Records** T, Records** B);
int main()
{
  fstream file("radix.txt",ios::out);
  Coordinates m_coordinates;
    const int m = 4;    //2^m will be the base so here 16 is base 
    const int p = 3;    //3 digits of 16 base, no of digits in that base
	
	for (int N = 10000; N <= 1000000; N=N+10000)	//10 hajar dekhi 500 hajar samma hai lmao
	{
		Records* T[1<<m];  //array of top pointers for the queue;
		Records* B[1<<m];
		Records* Recs;
		Recs = new Records[1+N];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
		random_shuffle(Recs+1, Recs+N+1);
		
	    auto start = steady_clock::now();	
		radix_list(N, Recs, m, p, T, B);
		auto end = steady_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
    m_coordinates.y=duration.count();
    m_coordinates.x=N;
    file.write(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
		cout << "(" << setw(10) << N << "," << setw(10) << duration.count() << ")" << endl;
		delete[] Recs;
	}
  file.close();
}


Records* radix_list(int N, Records* R, int m, int p, Records** T, Records** B)
{
    Records* P;     //P will be after returning pointing to the element of smallest key
    int M = 1 << m; //now we will be needing the
                    //bottom pointers for the queue;
    P = R+N;  //initially P starts by pointing to the last element of the record

    for (int k = 1; k <= p; ++k)    //k be be the ?th digit of the key so at first we work with 1st digit
    {
        for (int j = 0; j <= M-1; ++j)
        {
            T[j] = nullptr;     //setting them emtpy
            B[j] = nullptr;
        }

        while(1)
        {
            //i is the kth digit of base M in pointer P record key;
            int i = ((P->Key)>>(m*(k-1)))&(M-1);
            
            //after getting the value of i we weave that record to ith queue
            if (T[i] == 0)
            {
                B[i] = P;
                T[i] = P;
            }
            else
            {
                T[i]->L = P;
                T[i] = P;
            }

            //lets go to next record, depending on the value of k, if and else combination does that
            
            //if were working on the first k means that we donot have the link between the nodes so we have to work like sequentailly
            if (k == 1)
            {
                int j = P - R;  //R points to the base(not first) element of the records array
                                //P points to the last element of that array
                
                //j being equal means there was only one key
                if (j != 1)
                {
                    //if there are more than one key let P point to the second last and we go gain
                    P = &R[j-1];
                }
                else
                {
                    //if there was only one then break
                    break;
                }
            }
            else
            {
                //in case of not first iteration, we already have linked formed so lets move on to the next link of P
                P = P->L;
                //finally if P reaches null we break
                if (P == 0)
                {
                    break;
                }
            }
        }
        
        //cout <<endl << "current tops of queues: " << endl;
        //for (int i = 0; i <= M-1; ++i)
        //{
        //    if (T[i] == nullptr)
        //    {
        //        cout << "empty" << " ";
        //    }
        //    else
        //    {
        //        cout << T[i]->Key << " ";
        //    }
        //}

        //After sorting on the kth key now lets weaave the list togethers

        int i = 0;

        while(1)
        {
            P = T[i];

            Next:
            ++i;

            if (i == M)
            {
                P->L = nullptr;
                P = B[0];
                break;
            }

            //if the pile is empty we skip it and find another non empty pile
            if (B[i] == 0)
            {
                goto Next;
            }

            //now non empty pile is found so lets hook it up.
            P->L = B[i];
        }
        //nothing here, break will take us here. so we can print the hooked queue here.
        //cout << "the weaved list after sorting on digit "<< k << "looks like" << endl;
    }
    return P;
}

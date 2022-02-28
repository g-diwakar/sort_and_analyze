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
};
struct Coordinates
{
    int x;
    int y;
};
void heap(int, Records *);
int main()
{
  Coordinates m_coordinates;
  fstream file("heap.txt",ios::out);
	for (int N = 100000; N <= 1000000; N=N+100000)	//10 hajar dekhi 500 hajar samma hai lmao
	{
		Records* Recs;
		Recs = new Records[1+N];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
		random_shuffle(Recs+1, Recs+N+1);
		
	    auto start = steady_clock::now();	
		heap(N, Recs);
		auto end = steady_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
    m_coordinates.x=N;
    m_coordinates.y=duration.count();
    file.write(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
		cout << "(" << setw(10) << N << "," << setw(10) << duration.count() << ")" << endl;
		delete[] Recs;
	}
  file.close();
}

void heap(int N, Records *Recs)
{
    //l is the index of the element that is first from left into the heap feature.
    int l = (N >> 1) + 1;

    //r is the index of last element in heap
    int r = N;
    Records Rm;
    int Km;

    while(1)
    {
        //this condition means theat we are in the process of transforming the file into the heap, 
        //ie if 1 is the left element in heap that means heap is already done
        if (l > 1)
        {
            --l;    //now l points to the element to transfer into the heap so lets save those values
            Rm = Recs[l];
            Km = Recs[l].Key;
        }
        else
        {
            Rm = Recs[r];
            Km = Recs[r].Key;
            Recs[r] = Recs[1];

            --r;

            if (r == 1)
            {
                Recs[1] = Rm;
                break;
            }
        }
        
        //now begins the sift up algorithm
        int j = l;
        int i;

        //this loop runs from the element to insert to the last element,
        //will run until i points to the place to enter the reocrd.
        while(1)
        {
            //j will point to the first child while i follows it, starting from i pointint to the element to insert.
            i = j; j = j << 1;

            //the selected is not the terminal node so it has a sibling lets decide which sibling to choose
            if (j < r)
            {
                //out of the siblings we choose the largest.
                if (Recs[j].Key < Recs[j+1].Key) {++j;}
            }

            //the child is either the last element or the ith element itself is the child.
            else
            {
                //the element is itseff its child
                if (j > r) {break;}
            }

            if (Km >= Recs[j].Key) 
                {break;}   //position found, as selected node is larger or equal to the childs.
            else 
                {Recs[i] = Recs[j];} // else we move the elements up.
        }
        Recs[i] = Rm;
    }
}

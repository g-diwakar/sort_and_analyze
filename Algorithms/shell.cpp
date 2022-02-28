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
void shell(int, Records *);
int main()
{
 
  Coordinates m_coordinates;
  fstream file("shell.txt",ios::out);
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
		shell(N, Recs );
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

void shell(int N, Records *Recs )
{
  int H[500] = {0, 1};
    for (int i = 1; i <= 400; ++i)
    {
        H[i+1] = pow(4,i)+3*pow(2,(i-1))+1;
    }

    int t = 0;
    do 
    {
        ++t;
    }
    while(H[t] <= N >> 1);
    //cout << N;

    for (int k = t; k >= 1; --k)
    {
        int h = H[k];
        //leaving h elements aheads as they will be considered first element of their respective lists that are h apart
        for (int i = h+1; i <= N; ++i)
        {
            int Km = Recs[i].Key;
            Records Rm = Recs[i];
            int j;
            for (j = i-h; j >= 1; j-=h)
            {   
                //the given key is still grater than being checked key
                //this if condition implies that we have not found the position yet,
                if (Recs[j].Key <= Km)
                {
                    break;
                }
                else
                {
                    Recs[j+h] = Recs[j];
                }
            }
            Recs[j+h] = Rm;
        }
    }
}

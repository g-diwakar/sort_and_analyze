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
void straight_selection(int, Records *);
int main()
{
  Coordinates m_coordinates;
  fstream file("selection.txt",ios::out);
	for (int N = 300; N <= 32000; N=N+300)	//10 hajar dekhi 500 hajar samma
	{
		Records* Recs;
		Recs = new Records[1+N];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
		random_shuffle(Recs+1, Recs+N+1);
		
	    auto start = steady_clock::now();	
		straight_selection(N, Recs);
		auto end = steady_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
    m_coordinates.x=N;
    m_coordinates.y=duration.count();
    file.write(reinterpret_cast<char*>(&m_coordinates), sizeof(m_coordinates));
		cout << "(" << setw(10) << N << "," << setw(10) << duration.count() << ")" << endl;
		delete[] Recs;
	}
  file.close();
}

void straight_selection(int N, Records *Recs)
{
    //for every element from last, we find maximum in the array left to them;
    for (int i = N; i >= 2; --i)
    {
        //considering the selected element as maximum s and we check with others, if maximum is found we replace it.
        int k = i;
        int M = Recs[k].Key;

        //checking maximum left to the selected array
        for (int j = i-1; j>= 1; --j)
        {
            if (Recs[j].Key > M)
            {
                k = j;
                M = Recs[j].Key;
            }
        }
        Records temp;
        temp = Recs[i];
        Recs[i] = Recs[k];
        Recs[k] = temp;
    }
}

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
void bubble(int, Records *);
int main()
{
  fstream file("bubble.txt",ios::out);
  Coordinates m_coordinates;
	for (int N = 200; N <= 21000; N=N+200)	//10 hajar dekhi 500 hajar samma hai lmao
	{
		Records* Recs;
		Recs = new Records[1+N];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
		random_shuffle(Recs+1, Recs+N+1);
		
	    auto start = steady_clock::now();	
		bubble(N, Recs);
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

void bubble(int N, Records *Recs)
{
    int B = N;
    do
    {
    int t = 0;
        for (int i = 1; i <= B-1; ++i)
        {
            if  (Recs[i].Key > Recs[i+1].Key)
            {
                Records temp;
                temp = Recs[i];
                Recs[i] = Recs[i+1];
                Recs[i+1] = temp;
                t = i;
            }
        }
    B = t;
    } while (B > 0);
    
}

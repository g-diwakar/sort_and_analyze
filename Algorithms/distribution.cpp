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

void distribution_counting(Records *Recs, int N, int M);
int main()
{
  Coordinates m_coordinates;
  fstream file("distribution.txt",ios::out);
	for (int N = 10000; N <= 1000000; N=N+10000)	//10 hajar dekhi 500 hajar samma hai lmao
	{
		Records* Recs;
		Recs = new Records[1+N+N];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
		random_shuffle(Recs+1, Recs+N+1);
		
	    auto start = steady_clock::now();	
		distribution_counting(Recs, N, N);
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

void distribution_counting(Records *Recs, int N, int M)
{
    int *C = new int[1+M];
    //as before the count are to be incremented so lets initialize them to zero.
    for (int i = M; i >= 1; --i)
    {
        C[i] = 0;
    }
    //this loop runs over each element, as it encounters a key it increases the respective index of the count array.
    //here C[i] array has the number of keys that equal i
    for (int i = N; i >= 1; --i)
    {
        ++C[Recs[i].Key];
    }

    //this is a cumilative loop that adds the keys before of the given key
    //now the array will have the count of keys that are less than the given key but wrt to the keys not position.
    for (int i = 2; i <= M; ++i)
    {
        C[i] += C[i-1];
    }

    for (int i = N; i >= 1; --i)
    {
        int k = C[Recs[i].Key];
        Recs[N+k] = Recs[i];
        C[Recs[i].Key] = k-1;
    }
}

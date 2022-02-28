#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include<fstream>
using namespace std;
using namespace std::chrono;

struct Records
{
    int Key;
    int Link;   //the records must contain a link
};
struct Coordinates
{
    int x;
    int y;
  };
void list_insertion(int, Records *);

int main()
{
  Coordinates m_coordinates;
  fstream file("listinsertion.txt",ios::out);
    //const int N = 16;
    //Records Recs[1+N] = {0, 503, 87, 512, 061, 908, 170, 897, 275, 653, 426, 154, 509, 612, 677, 765, 703};
	for (int N = 10000; N <= 100000; N=N+10000)
	{
		Records* Recs;
		Recs = new Records[1+N];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
			Recs[i].Link = 0;
		}
		random_shuffle(Recs+1, Recs+N+1);
		auto start = chrono::high_resolution_clock::now();		
		list_insertion(N, Recs);
		auto end = chrono::high_resolution_clock::now();
    
		auto duration = duration_cast<milliseconds>(end - start);
    m_coordinates.x=N;
    m_coordinates.y=duration.count();
    file.write(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
		cout << "(" << setw(10) << N << "," << setw(10) << duration.count() << ")" << endl;
		delete[] Recs;
	}
file.close();
    //for (int i = 1; i <= N; ++i)
        //cout << Recs[i].Key << " ";
}

void list_insertion(int N, Records *Recs)
{  
    //the first element is inserted into the list.
    Recs[0].Link = N;
    Recs[N].Link = 0;

    //we insert each record from the last.
    for (int i = N-1; i >= 1; --i)
    {
        int Km = Recs[i].Key;

        int q = 0;
        int p = Recs[q].Link;

        while (p > 0)
        {
            if (Recs[p].Key >= Km)
            {
                break;
            }
            else
            {
                q = p;
                p = Recs[q].Link;
            }
        }
        Recs[q].Link = i;
        Recs[i].Link = p;
    }



}

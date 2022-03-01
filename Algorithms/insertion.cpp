#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include<fstream>
using namespace std;
using namespace std::chrono;

bool stop;
struct Records
{
    int Key;
};
struct Coordinates
{
    int x;
    int y;
};
void straight_insertion(int, Records *);

int main()
{
    //const int N = 16;
    //Records Recs[1+N] = {0, 503, 87, 512, 061, 908, 170, 897, 275, 653, 426, 154, 509, 612, 677, 765, 703};
  Coordinates m_coordinates;
  fstream file("insertion.txt",ios::out);
	for (int N = 500; N <= 50000; N=N+500)
	{
		Records* Recs;
		Recs = new Records[1+N];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
		random_shuffle(Recs+1, Recs+N+1);
		auto start = chrono::high_resolution_clock::now();		
		straight_insertion(N, Recs);
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

void straight_insertion(int N, Records *Recs)
{

    //The first record is already supposed to be sorted then for second to last record we put them in position
    for (int i = 2; i <= N; ++i)
    {
        //since involves shifting the records lets save them
        int Km = Recs[i].Key;
        Records Rm = Recs[i];

        //now for every before elements, we check one by one, if its greater we shift that record one bit and 
        //finally as the sitatuion is violted we insert to its right.
        int j;
        for (j = i-1; j >= 1; --j)
        {
            //the given key is still grater than being checked key
            //this if condition implies that we have not found the position yet,
                if (Recs[j].Key <= Km)
                {
                    break;
                }
                else
                {
                    Recs[j+1] = Recs[j];
                }
        }
        Recs[j+1] = Rm;
    }
 
}

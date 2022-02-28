#include <iostream>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include<fstream>

using namespace std;
using namespace std::chrono;
struct Coordinates
{
    int l;
    int r;
};
struct Records
{
    int Key;
};
struct Coord
{
    int x;
    int y;
  };
void Quick(int, Records *, int);
int main()
{
    const int M = 12;
    Coord m_coordinates;
   fstream file("improvedquick.txt",ios::out); 
    for (int N = 1000000; N <= 10000000; N=N+1000000)	//10 hajar dekhi 500 hajar samma hai lmao
	{
        Records* Recs;
        Recs = new Records[1+N+1];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
            Recs[0].Key = -90000000;
        Recs[N+1].Key = +90000000;
		random_shuffle(Recs+1, Recs+N+1);
		
		
		auto start = steady_clock::now();  
		Quick(N, Recs, M);
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
void Quick(int N, Records *Recs, int M)
{   
    int l = 1;
    int r = N;
	
	Coordinates* S;
	S = new Coordinates[N];
	int T = 0;
    if (N <= M)
    {
        goto StraightInsertion;
    }
    while(1)
    {
		top:
        int i = l;
        int j = r+1;
		
		int q = rand()%(r-l) + l;
        int Km = Recs[q].Key;
		Records Ramp = Recs[q];
		Recs[q] = Recs[l];
		Recs[l] = Ramp;
		
        
        while(1)
        {			
            do {++i;} while(Recs[i].Key < Km);
            do {--j;} while(Recs[j].Key > Km);
            if (i < j)
            {
                Records temp;
                temp = Recs[i];
                Recs[i] = Recs[j];
                Recs[j] = temp;
            }
            else
            {
                Records temp;
                temp = Recs[l];
                Recs[l] = Recs[j];
                Recs[j] = temp;
                break;
            }			
        }
        //if (r-j >= j-l && j-l > M) 
		//{Coordinates voila = {j+1,r}; S[++T] = voila; r=j-1;}
	
        //else if (j-l > r-j && r-j > M)
		//{Coordinates voila = {l,j-1}; S[++T] = voila; l=j+1;}
		
        //else if (r-j > M && M >= j-l) {l=j+1;}
        //else if (j-l > M && M >= r-j) {r=j-1;}
        //else 
        //{
        //    if (T == 0) 
        //        {
        //        goto StraightInsertion;
        //        } 
        //    Coordinates temp; 
        //    temp = S[T--]; 
        //    l = temp.l; 
        //    r = temp.r;
        //}
		
		int rf = r-j;
		int lf = j-l;
		
		
		if (rf >= lf)
		{
			//means we will definitely work on the left file
			
			//lets decide what to do with the right file ie to push it or just leave it
			
			//is right subfile too small?
			if (rf < M)
			{
				goto popper;
				//pop from the stack and work on that array
			}
			
			//is left subfile too small?
			else if (lf < M)
			{
				l = j+1;
				//work on the right file and no need to push anything
			}
			else
			{    
				Coordinates check = {j+1,r};
				S[++T] = check;
				r = j-1;
				//push the right file and work on the left file	
			}
			
		}
		else
		{
			//means we will definitley work on the right file 
			
			//lets decide what to do with the left file ie to push it or just leave it
			
			//is right subfile too small?
			if (lf < M)
			{
				goto popper;
				//pop from the stack and work on that array
				
			}
			else if (rf < M)
			{
				r = j-1;
				//work on the left subfile and no need to psuh anything
			}
			else
			{
				//push the left file and work on the right file  
				Coordinates check = {l,j-1};
				S[++T] = check;
				l = j+1;				
			}
		}
		goto top; 
		
		popper: 
		if (T == 0)
		{
			break;
		}
		else
		{
			Coordinates check = S[T--];
			l = check.l;
			r = check.r;
		}
    }
    StraightInsertion:
    for (int j = 2; j <= N; ++j)
    {
        if (Recs[j].Key < Recs[j-1].Key)
        {
            int Km = Recs[j].Key;
            Records Rm = Recs[j];
            int i = j-1;
            do
            {
                Recs[i+1] = Recs[i];
                --i; 
            } while (Recs[i].Key > Km);
            Recs[i+1] = Rm;
        }
    }	
}

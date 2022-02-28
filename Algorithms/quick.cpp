#include <iostream>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;
struct Coordinates
{
    int l;
    int r;
};
struct Coordi 
{
    int x;
    int y;
  };
class Stack
{
    private:
        Coordinates* coor;
        int T;
    public:
        Stack(int N): T(0) 
        {
            //this is how you caculate floor of lgN
            int t = -1;
            while (N > 0)
            {
                N >>= 1;
                ++t;
            }
            coor = new Coordinates[1+t];
        }
        void push(int ll, int rr)
        {
            ++T;
            coor[T] = {ll, rr};
        }
        Coordinates pop()
        {
            --T;
            return coor[T+1];
        }
        int top()
        {
            return T;
        }
        ~Stack()
        {
            delete[] coor;
        }
};
struct Records
{
    int Key;
};

bool stop;
//we will have three subroutines, first checks the size of the list then sends to whichever routine is suitable.
void Quick(int, Records *, int, fstream&);
void StraightInsertion(int, Records *);

int main()
{

  fstream file("quick.txt",ios::out);
    const int M = 32;
    stop = false;
    for (int N = 10000; N <= 1000000; N=N+10000)	//10 hajar dekhi 500 hajar samma hai lmao
	{
        if (stop == true)
        {
            return 0;
        }
        Records* Recs;
        Recs = new Records[1+N+1];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
            Recs[0].Key = -90000000;
        Recs[N+1].Key = +90000000;
		random_shuffle(Recs+1, Recs+N+1);
		Quick(N, Recs, M,file);
        delete[] Recs;
	}
  file.close();
}

void Quick(int N, Records *Recs, int M, fstream& file)
{
  Coordi m_coordinates;
	// auto start = chrono::high_resolution_clock::now();
    auto start = steady_clock::now();    
    if (N <= M)
    {
        StraightInsertion(N, Recs);
    }
    //get the stack ready
    Stack S(N);
    // l points to first element of the list, r to the last, comes handy in calculating the size of the sublists
    int l = 1;
    int r = N;

    //an infinite loop that only breaks when all arrays are less than M,

    //the game plan is to move the first element to its approriate position while exchanging on ways elements to their appropriate place    
    //here lth element if to be placed so i and j will point
    //to just before and after it
    while(1)
    {
        int i = l;
        int j = r+1;
        int Km = Recs[l].Key;
        
        //Km is the key of the pivot to place

        //the inner while loop breaks only when the pivot is placed
        //and array is now ready to be divided into two parts
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
        if (r-j >= j-l && j-l > M) {S.push(j+1,r); r=j-1;}
        else if (j-l > r-j && r-j > M) {S.push(l,j-1); l=j+1;}
        else if (r-j > M && M >= j-l) {l=j+1;}
        else if (j-l > M && M >= r-j) {r=j-1;}
        else 
        {
            if (S.top() == 0) 
                {
                StraightInsertion(N, Recs);
                break;
                } 
            Coordinates temp; 
            temp = S.pop(); 
            l = temp.l; 
            r = temp.r;
        }
    }
    auto end = steady_clock::now();
    //auto end = chrono::high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start);
    m_coordinates.x=N;
    m_coordinates.y=duration.count();
    file.write(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));

    cout << "(" << setw(10) << N << "," << setw(10) << duration.count() << ")"<< endl;
	
}
void StraightInsertion(int N, Records *Recs)
{
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

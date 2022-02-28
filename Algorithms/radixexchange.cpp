#include <iostream>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include<fstream>
using namespace std;
using namespace std::chrono;

struct Records {int Key;};
struct Coordinates {int r; int b;};
struct Coordi{
  int x;
  int y;
};
class Stack
{
    private:
        Coordinates* coor;
        int T;
    public:
        Stack(int m): T(0)
        {
            coor = new Coordinates[1+m-1];  //stack for m-1 enteries
        }
        void push(int rr, int bb)
        {
            ++T;
            coor[T] = {rr, bb};
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
};
void radix_exchange(int, Records *, int);
int main()
{
  Coordi m_coordinates;
  fstream file("radix_exchange.txt", ios::out);
	for (int N = 100000; N <= 1000000; N=N+100000)	//10 hajar dekhi 500 hajar samma hai lmao
	{
		    const int m = 10;	//2^m is the base of exchange
		Records* Recs;
		Recs = new Records[1+N];
		for (int i = 1; i <= N; ++i)
		{
			Recs[i].Key = i;
		}
		random_shuffle(Recs+1, Recs+N+1);
		
	    auto start = steady_clock::now();	
		radix_exchange(N, Recs, m);
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

void radix_exchange(int N, Records *Recs, int m)
{
    Stack S(m);
    int l = 1;
    int r = N;
    int b = 1 << (m-1); //b has 1 bit in required position

    //this loops ends when the stack is empty;
    while(1)
    {
        //this sorts a given array from l to r, one iteration means sorting one array
        while(l < r)
        {
            int i = l;  //now they point to the exact first node
            int j = r;  //i to the first and j to the last
            //cout << "current working array: " << l << " " << r << " the division number is " << b << endl;

            //this sorts on the bit b; and breaks only after completely sorting it on bit b
            while(1)
            {
                if ((Recs[i].Key&b) != 0)
                {
                    Here:
                    --j;
                    if (i > j)
                    {
                        break;
                    }
                    if ((Recs[j+1].Key&b) == 0)
                    {
                        Records temp;
                        temp = Recs[i];
                        Recs[i] = Recs[j+1];
                        Recs[j+1] = temp;
                    }
                    else
                    {
                        goto Here;
                    }
                }
                ++i;
                if (i > j)
                {
                    break;
                }
            }
            //for (int i = 1; i <= N; ++i)
            //cout << Recs[i].Key << " ";
            //cout << endl;

            //lowering the bit b to sort on that
            b >>= 1;
            if (b == 0) {break;}


            //checking the special cases
            if (j < l || j == r)    //the array was all 1 or 0 respectively
            {
                continue;
            }
            if (j == l) //only one 0 bit
            { 
                ++l;
                continue;
            }
            //else of course just push up the stack
            S.push(r,b);
            r = j;
        }

            if (S.top() == 0) {break;}
            else
            {
                l = r + 1;
                Coordinates temp;
                temp = S.pop();
                r = temp.r;
                b = temp.b;
            }
    }

}

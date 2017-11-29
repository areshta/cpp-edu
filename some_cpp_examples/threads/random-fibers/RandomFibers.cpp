#include <iostream>
#include <thread>
#include <chrono>
#include <array>
#include <random>
#include <future>
#include <mutex>
#include <memory>
#include <vector>

using namespace std;

const int gnChar = 181;
const int gMinPos = 1;
const int gMaxPos = gnChar - 2;
const int gMaxAttempts = 10000;
int gLastFiber = 0;

mutex gMutex; 


array<char, gnChar> line;
random_device rd; 
mt19937 gen(rd());

inline char toChar(int n)
{
	return '0' + n;
}

void initLine(int nFibers)
{
	for(int i=0; i < line.size() - 1; ++i)
	{
		line[i] = ' ';
	}
	line[ line.size()-1] = '\0';
	line[gMinPos - 1] = '#';
	line[gMaxPos + 1] = '#';

    uniform_int_distribution<> rnd_init(gnChar/10, 9*gnChar/10);
 
    for (int i = 0; i < nFibers; ++i)
	{
		for (int j = 0; j < gMaxAttempts; ++j) 
		{		
			int newPos = rnd_init(gen);
			if( line[newPos] == ' ')
			{
				line[newPos] = toChar(i);
				break;
			}
		}
	}
}

int getLastIndex(int nFiber)
{
	for(int i=gMinPos; i <= gMaxPos; ++i)
	{
		if( line[i] == toChar(nFiber) )
		{
			return i;
		}			
	}	
}

uniform_int_distribution<> rnd_delta(1, 5);

void tryMoveFiber(int nFiber)
{
	while(true)
	{
		if( gLastFiber == nFiber)
		{
			continue;
		}

		lock_guard<mutex> lock(gMutex);
	
			int nLastIndex = getLastIndex(nFiber);

			int nMaxJamp = 20;
			int nDelta = rnd_delta(gen) - 3; // -2..2
			int nNext = nLastIndex;
			for(int i = 0 ;i < nMaxJamp; i++)
			{
				nNext += nDelta;
				line[nLastIndex] = ' ';
			
				if(nNext < gMinPos || nNext > gMaxPos )
				{
					goto endFiber;
				}

				if( line[nNext] == ' ' )
				{
					line[nNext] = toChar(nFiber);	
					break;
				}
			}
			gLastFiber = nFiber;
	}
	endFiber:;	
}

int main()
{
	const int nFibers = 60;

	initLine(nFibers);
	cout << &(line[0]) << endl;

	vector<thread> vpThread;

   	for(int i=0; i<nFibers; i++)
	{
		vpThread.push_back( move(thread(tryMoveFiber,i)) );
	}

	while(true)
	{
		cout << &(line[0]) << endl;
		this_thread::sleep_for( chrono::milliseconds(10) );
	}

	return 0;
}

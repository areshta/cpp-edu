#include <iostream>
#include <unordered_map>

using namespace std;

namespace am
{
typedef enum {
		VAL_SEAT_ROW1_LEFT = 0,
		VAL_SEAT_ROW1_RIGHT,
		VAL_SEAT_ROW2_LEFT,
		VAL_SEAT_ROW2_RIGHT,
		VAL_SEAT_ROW3_LEFT,
		VAL_SEAT_ROW3_RIGHT,
		VAL_SEAT_UNKNOWN = 0xFF
	} am_SeatID_e;
}

int main()
{
   unordered_map<int8_t, int16_t> mSeats4DIntensity;
   mSeats4DIntensity[am::VAL_SEAT_ROW1_LEFT]    = 0;
   mSeats4DIntensity[am::VAL_SEAT_ROW1_RIGHT]   = 0;
   mSeats4DIntensity[am::VAL_SEAT_ROW2_LEFT]    = 0;
   mSeats4DIntensity[am::VAL_SEAT_ROW2_RIGHT]   = 0;
   mSeats4DIntensity[am::VAL_SEAT_ROW3_LEFT]    = 0;
   mSeats4DIntensity[am::VAL_SEAT_ROW3_RIGHT]   = 0;
   mSeats4DIntensity[am::VAL_SEAT_UNKNOWN]      = 0xFF;

	size_t count = 0; 
    for (unsigned i = 0; i < mSeats4DIntensity.bucket_count(); ++i) { 
		size_t bucket_size = mSeats4DIntensity.bucket_size(i); 
		if (bucket_size == 0) { 
		 count++; 
		} 
		else { 
		 count += bucket_size; 
		} 
    } 

	count += count*sizeof(int) + 7*(2+1); 

	cout << "sizeof unordered_map<int8_t, int16_t>: " << count << "    bites on element:" << (float)count/7 << endl;


  return 0;
}

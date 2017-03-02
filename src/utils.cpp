/*
 * utils.cpp
 *
 *  Created on: 1 Mar 2017
 *      Author: conor
 */
#include "utils.h"
#include <iostream>
using namespace std;

#define START 0

#define START2 1
#define END2 2

#define START3 3
#define MID3 4
#define END3 5

static int black_keys[36] = {22, 25, 27, 30, 32, 34, 37, 39, 42, 44, 46, 49,
							  51, 54, 56, 58, 61, 63, 66, 68, 70, 73, 75, 78,
							  80, 82, 85, 87, 90, 92, 94, 97, 99, 102, 104, 106};

namespace utils{
	// Determines if the key is black
	int isBlack(int key) {
		return binary_search(&black_keys[0], &black_keys[36], key);
	}

	// Maps the white keys midi values to their offset on the keyboard (a range 0-52).
	void mapWhiteOffset(map<int, float>& white_offset){
		int count = 0;
		for(int key = 21; key < 109; key++) {
			if(!isBlack(key)){
				//cout << key << "\t" << count << "\t" << endl;
				white_offset[key] = count++;
			}
		}
	}

	// Maps the black keys midi values to their offset on the keyboard. Because black keys
	// sit on half notes, the range here is 0-104. I then divided by 2 to make it relative to
	// the white keys.
	void mapBlackOffset(map<int, float>& black_offset){
		int count = 1;
		int state = START;
		for(int key = 22; key < 109; key++) {
			if(isBlack(key)) {
				black_offset[key] = float(count)/2.0f;
				//cout << key << "\t" << count << "\t" << float(count)/2.0f << endl;
				switch(state) {
				case START:
					count += 4;
					state = START2;
					break;
				case START2:
					count += 2;
					state = END2;
					break;
				case END2:
					count += 4;
					state = START3;
					break;
				case START3:
					count += 2;
					state = MID3;
					break;
				case MID3:
					count += 2;
					state = END3;
					break;
				case END3:
					count += 4;
					state = START2;
					break;
				}

			}
		}
	}
}



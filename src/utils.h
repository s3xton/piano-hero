/*
 * utils.h
 *
 *  Created on: 1 Mar 2017
 *      Author: conor
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <algorithm>    // std::binary_search, std::sort
#include <map>

namespace utils {
	int isBlack(int key);
	void mapWhiteOffset(std::map<int, float>& white_offset);
	void mapBlackOffset(std::map<int, float>& black_offset);
}



#endif /* UTILS_H_ */

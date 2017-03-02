/*
 * Song.h
 *
 *  Created on: 1 Mar 2017
 *      Author: conor
 */

#ifndef SONG_H_
#define SONG_H_

#include <vector>

#include "Note.h"

using namespace std;

class Song {
public:
	Song(char* filename);
	double get_QPS();
	vector<Note> get_notes();
	virtual ~Song();

private:
	double m_qps;
	vector<Note> m_notes;
};

#endif /* SONG_H_ */

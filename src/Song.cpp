/*
 * Song.cpp
 *
 *  Created on: 1 Mar 2017
 *      Author: conor
 */

#include "Song.h"
#include "MidiFile.h"
#include "utils.h"
#include <iostream>
#include <algorithm>    // std::binary_search, std::sort

using namespace std;

Song::Song(char* filename) {
	MidiFile midifile;
	midifile.read(filename);
	if (!midifile.status()) {
		cerr << "[!] Error reading MIDI file: " << filename << endl;
		exit(1);
	}

	midifile.linkNotePairs();

	midifile.joinTracks();
	m_qps = midifile.getTotalTimeInQuarters()/midifile.getTotalTimeInSeconds();
	float tpq = float(midifile.getTicksPerQuarterNote());

	// Used for debugging scaling
	/*
	for (int count=21; count < 109; count++) {
		float start = 0;
		float duration = 1;
		if(count == 21){
			start = 1;
			duration = 2;
		}

		const int key_number = count;

		int is_black = utils::isBlack(key_number);
		cout << is_black << "\t" << key_number << endl;

		m_notes.push_back(Note(start, duration, key_number, is_black));
	}
	*/

	int track = 0;
	for (int i=0; i<midifile[track].size(); i++) {
		if (!midifile[track][i].isNoteOn()) {
		   continue;
		}

		float start = float(midifile[track][i].tick) / tpq;
		float duration = float(midifile[track][i].getTickDuration()) /tpq;
		const int key_number = int(midifile[track][i][1]);

		int is_black = utils::isBlack(key_number);

		m_notes.push_back(Note(start, duration, key_number, is_black));
	}

}

double Song::get_QPS(){
	return m_qps;
}

vector<Note> Song::get_notes(){
	return m_notes;
}


Song::~Song() {
	// TODO Auto-generated destructor stub
}


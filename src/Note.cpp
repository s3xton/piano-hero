/*
 * NoteModel.cpp
 *
 *  Created on: 28 Feb 2017
 *      Author: conor
 */

#include <iostream>
#include "Note.h"


Note::Note(float start, float duration, int key_number, int is_black) {
	m_start = start;
	m_duration = duration;
	m_key_number = key_number;
	m_is_black = is_black;
}

Note::~Note() {
	// TODO Auto-generated destructor stub
}

int Note::get_key_number() {
	return m_key_number;
}

float Note::get_duration() {
	return m_duration;
}

float Note::get_start() {
	return m_start;
}

int Note::is_black() {
	return m_is_black;
}

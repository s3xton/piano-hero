/*
 * NoteModel.h
 *
 *  Created on: 28 Feb 2017
 *      Author: conor
 */

#ifndef NOTE_H_
#define NOTE_H_
#include <GL/glut.h>

class Note {
public:
	Note(float start, float duration, int key_number, int is_black);
	virtual ~Note();
	int get_key_number();
	float get_duration();
	float get_start();
	int is_black();

private:
	float m_start;
	float m_duration;
	int m_key_number;
	int m_is_black;

};

#endif /* NOTE_H_ */

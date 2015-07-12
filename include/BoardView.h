/* 
 * File:   BoardView.h
 * Author: lmachiso
 *
 * Created on July 12, 2015, 1:10 PM
 */

#ifndef BOARDVIEW_H
#define	BOARDVIEW_H

#include "include/Board.h"

class BoardView
{
public:
	BoardView(const Board& board);
	~BoardView();
	int draw();
private:
	const Board& m_board;
    void format_string_value(int value, char* string_value);
};

#endif	/* BOARDVIEW_H */
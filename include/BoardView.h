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
	//! Constructor
    /*!
    \param board - the board which will be displayed
    */
    BoardView(const Board& board);

    //! Destructor
    /*!
    */
	~BoardView();

    //! Draws the board on the screen in text mode
    /*!
    */
	int draw();
private:
	//! Formats a number into a 7-chars string, the slots not filled with digits are filled with spaces
    /*!
    \param value - the integer value to be formatted
    \param string_value - the formatted 7-chars string
    */
    void format_string_value(int value, char* string_value);

    //! The board to be displayed
    /*!
    The board is not owned by the board view
    */
    const Board& m_board;
};

#endif	/* BOARDVIEW_H */
/* 
 * File:   BoardPosition.h
 * Author: lmachiso
 *
 * Created on July 11, 2015, 11:06 AM
 */

#ifndef BOARDPOSITION_H
#define	BOARDPOSITION_H

class BoardPosition
{
public:
    //! Constructor
    /*!
    \param size - the size of the board
    */
    BoardPosition();
    
    //! Copy constructor
    /*!
    \param board_position - the object to copy from
    */
    BoardPosition(const BoardPosition& board_position);

    //! Assignment operator
    /*!
    \param board_position - right hand side value
    */
    BoardPosition& operator=(const BoardPosition& board_position);
    
    //! Destructor
    /*!
    */
    ~BoardPosition();

    //! Get the value of the board position
    /*!
    \return the value of the board position
    */
    const int get_value() const;

    //! Determines whether the player won
    /*!
    \return a boolean variable specifying whether the position was already merged with another
    */
    const bool was_merged() const;

    //! Sets the value of the board position
    /*!
    \param value - the value to be set
    */
    void set_value(int value);

    //! Sets the merged status of the board position
    /*!
    \param was_merged - the value of the merged status
    */
    void set_was_merged(bool was_merged);
    
private:
    //! The value of the board position
    int m_value;
    
    //! The value of the merged status of the board position
    bool m_was_merged;
};

#endif	/* BOARDPOSITION_H */

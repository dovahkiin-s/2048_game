/* 
 * File:   Board.h
 * Author: lmachiso
 *
 * Created on July 11, 2015, 1:10 PM
 */

#ifndef BOARD_H
#define	BOARD_H

#include "include/BoardPosition.h"

class Board
{
public:
    //! Constructor
    /*!
    \param size - the size of the board
    */
    Board(int size);

    //! Copy constructor
    /*!
    \param board - the object to copy from
    */
    Board(const Board& board);
    
    //! Destructor
    /*!
    */
    ~Board();

    //! Assignment operator
    /*!
    \param board - right hand side value
    */
    Board& operator=(const Board& board);

    //! Get the size of the board
    /*!
    \return the size of the board
    */
    int get_size() const;

    //! Get the current score of the board
    /*!
    \return the current score of the board
    */
    int get_score() const;

    //! Get the BoardPosition element on position [i,j]
    /*!
    \param i - x-axis index
    \param j - y-axis index
    \return a pointer to the BoardPosition element
    */
    BoardPosition* get_elem(const int pos_x, const int pos_y) const;

    //! Creates a random tile on the board with a random value of 2 or 4
    /*!
    */
	int create_random_tile();

    //! Determines whether the board is full
    /*!
    \return a boolean variable specifying if the board is full or not
    */
    bool is_full() const;

    //! Determines whether the player won
    /*!
    \return a boolean variable if the player won (an element with value 2048 was found)
    */
    bool is_win() const;

    //! Creates a random tile on the board with a random value of 2 or 4
    /*!
    \param direction - a char specifying the direction of the tilt ("w" - forward, "s" - backward, "a" - left, "d" - right)
    \param state_chaged - a boolean value specifying whether a change was performed by the tilt
    \return an error code, 0 for success
    */
    int tilt(char direction, bool& state_changed);

    //! Swaps 2 positions from the board
    /*!
    \param pos1 - the first position to be swapped
    \param pos1 - the second position to be swapped
    */
    static void swap_positions(BoardPosition* pos1, BoardPosition* pos2);

    //! Merges 2 positions from the board - the first position to the second position
    /*!
    \param pos1 - the position to be merged
    \param pos2 - the position to merge to
    */
    static void merge_positions(BoardPosition* pos1, BoardPosition* pos2);
    
private:
    
    //! Finds a specific value on the board
    /*!
    \param value - the value to be searched
    \return a boolean value specifying whether the value was found
    */
    bool find_value(int value) const;

    //! Tilts an array to the right
    /*!
    \param array - the array to be tilted
    \param size - the size of the array to be tilted
    \param state_changed - a boolean value specifying whether a change was performed by the tilt
    \return a boolean value specifying whether the value was found
    */
    void tilt_array(BoardPosition** pos_array, int size, bool& state_changed);

    //! Creates an array from the matrix, either a line or a column, in a normal or reversed order
    /*!
    \param component - the line or column to be extracted to the array ('l' - line, 'c' - column)
    \param index - the index of the line or column in the matrix
    \param direction - specifies whether the array will be extracted in normal mode or reversed ('n' - normal, 'r' - reversed)
    \param pos_array - the extracted array
    \param size - the size of the array
    \return an error code, 0 for success
    */
    int create_array(char component, int index, char direction, BoardPosition** pos_array, int size);

   //! Sets all the pointers in an array to 0
    /*!
    \param pos_array - the array to be reset
    \param size - the size of the array
    */
    static void reset_array(BoardPosition** pos_array, int size);

    //! Creates an array with all the free positions in a matrix (where the value of the position is 0)
    /*!
    \param pos_array - the extracted array
    \param size - the size of the extracted array
    */
    void create_free_position_array(char** free_pos_array, int& size) const;
    
    //! Gets a random value of 2 with the 90% probabilty and of 4 with 10% probability
    /*!
    \return the random value chosen
    */
    static int get_random_value();
    
    //! The size of the board
    const int m_size;

    //! The matrix used to memorize the board positions
    BoardPosition** m_board;

    //! The array which holds all the free positions in the matrix
    /*!
    Pre-allocated in the constructor since allocation is expensive
    */
    char** m_free_pos_array;

    //! The current score of the board
    int m_score;
};

#endif	/* BOARD_H */


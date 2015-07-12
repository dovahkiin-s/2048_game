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
    BoardPosition();
    // automatically generated - provided here only for clarity
    BoardPosition(const BoardPosition& board);
    BoardPosition& operator=(const BoardPosition& board);
    ~BoardPosition();
    const int get_value() const;
    const bool was_merged() const;
    void set_value(int value);
    void set_was_merged(bool was_merged);
    
private:
    int m_value;
    bool m_was_merged;
};

#endif	/* BOARDPOSITION_H */

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
    ~BoardPosition();
    const int get_value() const;
    const bool was_merged() const;
    void set_value(int new_value);
    void set_was_merged(bool was_merged);
    
private:
    int m_value;
    bool m_was_merged;
};

#endif	/* BOARDPOSITION_H */

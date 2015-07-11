/* 
 * File:   BoardPosition.cpp
 * Author: lmachiso
 *
 * Created on July 11, 2015, 11:13 AM
 */

#include "include/BoardPosition.h"


BoardPosition::BoardPosition()
{
    m_value = 0;
    m_was_merged = 0;
}


BoardPosition::~BoardPosition()
{
}


const int BoardPosition::get_value() const
{
    return m_value;
}


const bool BoardPosition::was_merged() const
{
    return m_was_merged;
}


void BoardPosition::set_value(int new_value)
{
    m_value = new_value;
}


void BoardPosition::set_was_merged(bool was_merged)
{
    m_was_merged = was_merged;
}

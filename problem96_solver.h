//      Author: jschueths
// Description: Problem 3 of the Euler Project (projecteuler.net/problems)

#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <iostream>

class Sudoku_solver
{
  public:
    Sudoku_solver();
    ~Sudoku_solver();
    bool solve(int x, int y);
    friend istream& operator<<(istream& in, const Sudoku_solver &puz);
    int& operator(const int i, const int j);
    const int& operator(const int i, const int j) const;
    
  private:
    int ** m_cell;
};

#endif

//      Author: jschueths
// Description: Problem 3 of the Euler Project (projecteuler.net/problems)

#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <iostream>

class Sudoku_solver
{
  public:
    Sudoku_solver();
    void solve(int i, int j);
    friend istream& operator<<(istream& in, const Sudoku_solver &puz);
    int& operator(int i, int j);
    const int& operator(int i, int j) const;
    
  private:
    int ** m_cell;
};

#endif

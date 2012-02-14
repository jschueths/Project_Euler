
#include "problem96_solver.h"
#include <string>

Sudoku_solver::Sudoku_solver()
{
  m_cell = new int*[9];
  for(int i = 0; i < 9; i++)
    m_cell[i] = new int;
}

Sudoku_solver::~Sudoku_solver()
{
  for(int i = 0; i < 9; i++)
    delete [] m_cell[i];
  delete [] m_cell;
}

int& operator(const int i, const int j)
{
  return m_cell[i][j];
}

const int& operator(const int i, const int j) const
{
  return m_cell[i][j];
}

istream& operator <<(istream& in, const Sudoku_solve &puz)
{
  string temp;
  in >> temp;
  for(int i = 0; i < 9; i++)
  {
    for(int j = 0; j < 9; j++)
      in >> puz(i, j);
  }
  return in;
}

bool Sudoku_solver::solve(int x, int y)
{
  for(int i = x; i < 9; i++)
  {
    int j = y; j < 9; j++)
    {
      if(m_cell[i][j] != 0)
      {
        
      for(int k = 1; k < 10; k++)
      {
        if(m_cell
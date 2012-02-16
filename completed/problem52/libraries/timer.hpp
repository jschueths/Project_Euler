
Timer::Timer()
{
  m_expired = false;
  m_up = true;
  m_stopped = true;
}

Timer::Timer(long double x)
{
  m_expired = false;
  m_up = false;
  m_stopped = true;
  if(x < 0)
    cerr << "Input time less than zero!" << endl;
  m_duration = x;
}

void Timer::start()
{
  m_start = clock();
  m_stopped = false;
  return;
}

void Timer::end()
{
  m_end = clock();
  m_stopped = true;
  return;
}

bool Timer::expired()
{
  if((m_duration - (((double) clock() - m_start) / CLOCKS_PER_SEC)) <= 0)
    m_expired = true;
  else
    m_expired = false;
  return m_expired;
}

void Timer::lap() // Right now doesn't do anything.
{
  m_laps.push_back(clock());
  return;
}

ostream& operator<<(ostream &out, const Timer &data)
{
  if(data.m_up)
  {
    if(data.m_stopped)
      out << ((double) data.m_end - data.m_start) / CLOCKS_PER_SEC;
    else
      out << ((double) clock() - data.m_start) / CLOCKS_PER_SEC;
  }
  else
  {
    out << data.m_duration - (((double) clock() - data.m_start) / CLOCKS_PER_SEC);
  }
  return out;
}

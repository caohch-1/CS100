#ifndef LAPTIMER_HPP_
#define LAPTIMER_HPP_

#include <stdlib.h>

#include <chrono>
#include <vector>
#include <string>

class LapHandle {
 public:
  LapHandle();
  LapHandle(int number);
  virtual ~LapHandle();

  int value();
  bool valid();

 private:
  int m_number;
};

class LapTimer {
 public:
  LapTimer( bool start = false, size_t precision = 5 );
  virtual ~LapTimer();
  
  void start();
  void start( LapHandle & lap );
  void stop( bool restart = false );
  void stop( size_t iterations, bool restart = false );
  void stop( int iterations, bool restart = false );
  void stop( LapHandle & nextLap, bool restart = false );
  void stop( LapHandle & nextLap, size_t iterations, bool restart = false );
  void stop( LapHandle & nextLap, int iterations, bool restart = false );
  void reset();
  
  void clear();

  LapHandle addLap( const std::string & lapName );
  LapHandle findLap( const std::string & lapName ) const;

  void printSummary() const;
  
 private:
  std::chrono::high_resolution_clock::time_point m_startingTime;
  bool m_running;
  LapHandle m_activeLap;

  std::vector<std::string> m_lapNames;
  std::vector<double> m_cummulativeLapTimes;
  std::vector<size_t> m_lapIterations;

  size_t m_precision;
};

#endif
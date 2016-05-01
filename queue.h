/*******************************************************
		     G/G/1 QUEUE SIMULATOR
*******************************************************/
#ifndef _QUEUE_H
#define _QUEUE_H

#include "simulator.h"
#include "calendar.h"
#include "event.h"
#include "buffer.h"
#include "packet.h"
#include "stat.h"

class queue : public simulator {

  virtual void input(void);

  virtual void inputStatic(void);

  buffer *buf;            // queue buffer

  /**
   * 1 = poisson
   */
  int traffic_model;

  /**
   * in Erlang
   * avg 0.4, min 0.01, max 0.999
   */
  double load;

  /**
   * 1 = poisson
   */
  int service_model;

  // counters
  double packets;
  double tot_delay;
  // statistics
  Sstat *delay;
public:
  queue(int argc, char *argv[]);

  virtual ~queue(void);

  virtual void init(void);

  virtual void run(void);

private:
  virtual void clear_counters(void);

  virtual void clear_stats(void);

  virtual void update_stats(void);

  virtual void print_trace(int Run);

  virtual void results(void);

  virtual int isConfSatisf(double perc);
};

#endif


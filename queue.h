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

typedef struct initParameters {
  void init(){

  }
  int traffic_model;
  double load;
  int service_model;
  double duration;
  double Trslen;
  double Runlen;
  int NRUNmin;
} initParameters;

class queue : public simulator {

  virtual void input(void);

  virtual void inputStatic(void);
  virtual void input(initParameters parameters);

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
  virtual void init(initParameters parameters);

  virtual void run(void);
  virtual void results(void);

private:
  virtual void clear_counters(void);

  virtual void clear_stats(void);

  virtual void update_stats(void);

  virtual void print_trace(int Run);


  virtual int is_confidence_satisfied(double perc);
};

#endif


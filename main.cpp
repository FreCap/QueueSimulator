/* -*- C++ -*- */
#include <stdio.h>
#include "global.h"
#include "queue.h"
#include "simulator.h"


int main(int argc, char *argv[]) {

  queue *eval;

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("**********************************************************\n\n");
  printf("               G/G/1 QUEUE SIMULATION PROGRAM\n\n");
  printf("**********************************************************\n\n");

  eval = new queue(argc, argv);

  initParameters parameters = {
      .traffic_model = 1,
      .load = 0.4,
      .service_model = 1,
      .duration = 0.4,
      .Trslen = 100,
      .Runlen = 100,
      .NRUNmin = 5
  };

  eval->init(parameters);
  eval->run();
  eval->results();
  delete (eval);
  return 0;
}

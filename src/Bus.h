#ifndef BUS_H
#define BUS_H
#include <systemc.h>
#include "scTypes.h"
typedef struct ABusTag{
  uint32_t data;
}  ABus;
extern void sc_trace(sc_trace_file *tf, const ABus& v, const sc_string& NAME);

typedef struct BBusTag{
  uint32_t data;
}  BBus;
extern void sc_trace(sc_trace_file *tf, const BBus& v, const sc_string& NAME);


#endif
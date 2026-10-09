#include "systemc.h"

SC_MODULE(Countdown) {	// declare SystemC module "Countdown"

	/* constructor */
	SC_CTOR(Countdown) {	// note: constructor argument should be the same with the module name

		SC_THREAD(count);	// register a simulation process to the simulation kernel
	}

	void count(void);	// declaration of simulation process
};

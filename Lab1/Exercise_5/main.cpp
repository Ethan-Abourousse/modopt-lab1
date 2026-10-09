#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Network) {
	sc_event evt_wakeup_tic, evt_wakeup_toc;
	int tic_count, toc_count;

	SC_CTOR(Network) : tic_count(0), toc_count(0) {
		SC_THREAD(tic_thread);
		SC_THREAD(toc_thread);
	}

	void tic_thread() {
		while (true) {
			tic_count++;
			cout << sc_time_stamp() << " : tic awake (" << tic_count << ")" << endl;
			wait(10, SC_NS);
			evt_wakeup_toc.notify();
			wait(evt_wakeup_tic);
		}
	}

	void toc_thread() {
		// toc sleeps until tic wakes it
		while (true) {
			wait(evt_wakeup_toc);
			toc_count++;
			cout << sc_time_stamp() << " : toc awake (" << toc_count << ")" << endl;
			wait(10, SC_NS);
			evt_wakeup_tic.notify();
		}
	}
};

int sc_main(int argc, char * argv[]) {
	Network net("net");
	sc_start(100, SC_NS);
	cout << "tic was awake " << net.tic_count << " times" << endl;
	cout << "toc was awake " << net.toc_count << " times" << endl;
	return 0;
}

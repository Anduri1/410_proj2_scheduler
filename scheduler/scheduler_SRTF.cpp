/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */


#include "../includes/scheduler_SRTF.h"
#include <algorithm>

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort(); //??
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_SRTF::sort() {
	std::vector<PCB> vec;
	while (!ready_q->empty()) {
		vec.push_back(ready_q->front());
		ready_q->pop();
	}
	std::sort(vec.begin(), vec.end(), [](PCB & one, PCB & two){return one.remaining_cpu_time < two.remaining_cpu_time;});
	for(int i = 0; i < vec.size(); i++) {
		ready_q->push(vec[i]);
	}
}

/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */


#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector): vec(&finished_vector) {
	calcStats();
	av_wait_time = get_av_wait_time();
	av_turnaround_time = get_av_turnaround_time();
	av_response_time = get_av_response_time();
}

void Stats::showAllProcessInfo() {
	for (int i = 0; i < vec->size(); i++) {
		std::cout << "Process " << vec->at(i).process_number << " Required CPU time:" << vec->at(i).required_cpu_time << "  arrived:" << vec->at(i).arrival_time << " started:" << vec->at(i).start_time << " finished:" << vec->at(i).finish_time;
	}
}

float Stats::get_av_response_time() {
	return av_response_time;
}

float Stats::get_av_turnaround_time() {
	return av_turnaround_time;
}

float Stats::get_av_wait_time() {
	return av_wait_time;
}

void Stats::calcStats() {
	float r_avg = 0.0;
	float t_avg = 0.0;
	float w_avg = 0.0;

	for (int i = 0; i < vec->size(); i++) {
		r_avg += ((vec->at(i).start_time) - (vec->at(i).arrival_time));
		t_avg += ((vec->at(i).finish_time) - (vec->at(i).arrival_time));
		w_avg += ((vec->at(i).finish_time) - (vec->at(i).arrival_time) - (vec->at(i).required_cpu_time));
	}

	av_response_time = (r_avg/(vec->size()));
	av_turnaround_time = (t_avg/(vec->size()));
	av_wait_time = (w_avg/(vec->size()));
}

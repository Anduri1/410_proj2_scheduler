/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/stats.h";
//#include <iostream>

void Stats::showAllProcessInfo() {
	for (int i = 0; i < vec->size(); i++) {
		std::cout << "Process " << i << "CPU time:2" << "arrived:0" << "started:0" << "finished:2";
	}
}

float Stats::get_av_response_time() {

}

float Stats::get_av_turnaround_time() {

}

float Stats::get_av_wait_time() {

}

void Stats::calcStats() {

}

#include "graph.hpp"
#include "api.h"
#include "robodash/apix.h"

// ============================== Constructor ============================== //

rd::Graph::Graph(std::string name, int update_rate) {
	this->rate = update_rate;
	this->name = name;
	pros::Task task(&rd::Graph::update_task, "Graph updater");
}

// ================================ Methods ================================ //

void rd::Graph::set_series_color(std::string series, int color) {
	series_colors.emplace(series, color);
}

void rd::Graph::plot(double value) { plot("", value); }

void rd::Graph::plot(std::string series, double value) { data[series].push_back(value); }

// ============================== Updater Task ============================== //

void rd::Graph::update_task() {}

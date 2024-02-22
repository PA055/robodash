#include "graph.hpp"
#include "api.h"
#include "robodash/apix.h"

// ============================== Constructor ============================== //

rd::Graph::Graph(std::string name, int update_rate) {
	// Set properties
	this->rate = update_rate;
	this->name = name;

	// Create GUI
	// TODO: Make gui
	rd_view_t *view = rd_view_create(name.c_str());
	lv_obj_t *cont = rd_view_obj(view);

	chart = lv_chart_create(cont);
	lv_obj_align(chart, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_size(chart, 416, 208);

	// Run background task
	// FIXME: Correct way to do this?
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

/**
 * @file graph.hpp
 * @brief Robodash grapher
 * @ingroup graph
 */

#pragma once
#include "robodash/api.h"
#include <map>

namespace rd {

/**
 * @brief Graph class
 * @ingroup graph
 */
class Graph {
	/**
	 * @defgroup graph Grapher
	 * @brief A grapher for debugging
	 * TODO: Add image
	 *
	 * TODO: Add description
	 */

	/// @addtogroup graph
	/// @{

  public:
	/// @name Graph functions

	/**
	 * @brief Construct a new Graph
	 *
	 * @param name Name of the graph
	 * @param update_rate Rate to update the graph (milliseconds)
	 */
	Graph(std::string name, int update_rate = 100);

	/**
	 * @brief Set a series' color
	 *
	 * @param series
	 * @param color
	 */
	void set_series_color(std::string series, int color);

	/**
	 * @brief Plot a value on the graph
	 *
	 * @param value Value to plot
	 */
	void plot(double value);

	/**
	 * @brief Plot a value on the graph on another series
	 *
	 * @param series Series name
	 * @param value Value to plot
	 */
	void plot(std::string series, double value);

  private:
	int rate;
	std::string name;

	std::map<std::string, std::vector<double>> data;
	std::map<std::string, int> series_colors;

	lv_obj_t *chart;
	lv_obj_t *name_label;

	void sd_save();
	void update_task();
};

} // namespace rd
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
	Graph(int min_x, int max_x, int min_y, int max_y, std::string name = "Graph");

	/**
	 * @brief Add a Y value to the graph
	 *
	 * @param y Y value
	 */
	void insert(int y);

	/**
	 * @brief Add an X and Y value to the graph
	 *
	 * @param x X value
	 * @param y Y value
	 */
	void insert(int x, int y);

	/**
	 * @brief Add a Y value to the graph on another series
	 *
	 * @param series Series name
	 * @param y Y value
	 */
	void insert(std::string series, int y);

	/**
	 * @brief Add a value to the graph on another series
	 *
	 * @param series Series name
	 * @param x X value
	 * @param y Y value
	 */
	void insert(std::string series, int x, int y);

  private:
	std::map<std::string, std::pair<double, double>> data;

	void sd_save();
};

} // namespace rd
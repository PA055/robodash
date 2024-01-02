/**
 * @file graph.hpp
 * @brief Robodash grapher
 * @ingroup graph
 */

#pragma once
#include "robodash/api.h"

namespace rd {

/**
 * @brief Graph class
 * @ingroup graph
 */
class Graph {
	/**
	 * @defgroup graph Grapher
	 * @brief A graph plotter for debugging
	 * TODO: Add image
	 *
	 * TODO: Add description
	 */

	/// @addtogroup graph
	/// @{

  public:
	/// @name Graph functions
	Graph(std::string name = "Graph");
};

} // namespace rd
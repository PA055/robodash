#pragma once
#include "apix.h"

namespace rd {

/**
 * @brief View class
 */
class View {
  private:
	rd_view_t *c_view;

  public:
	/**
	 * @brief Create a View
	 *
	 * @param name Name of the View
	 */
	View(std::string name);

	/**
	 * @brief Set this View to the currently active View
	 */
	void focus();

	/**
	 * @brief Add a flag to the View
	 *
	 * @param flag Flag to add
	 */
	void add_flag(rd_flag_t flag);

	/**
	 * @brief Remove a flag from the View
	 *
	 * @param flag Flag to clear
	 */
	void remove_flag(rd_flag_t flag);

	/**
	 * @brief Get the C view object
	 *
	 * @return rd_view_t*
	 */
	rd_view_t *get_c_view();

	/**
	 * @brief Cast to an rd_view_t
	 *
	 * @return rd_view_t *
	 */
	operator rd_view_t *() const;

	/**
	 * @brief Get the View's lvgl object
	 */
	lv_obj_t *get_lv_obj();

	/**
	 * @brief Cast to an LVGL object
	 *
	 * @return lv_obj_t *
	 */
	operator lv_obj_t *() const;
};

} // namespace rd
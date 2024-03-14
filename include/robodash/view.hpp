#pragma once
#include "apix.h"

namespace rd {

/**
 * @brief Flags that can alter the behavior of a View
 */
enum class ViewFlag {
	NoAnimation,
	Hidden,
};

/**
 * @brief View class
 */
class View {
  private:
	std::vector<ViewFlag> flags;
	std::string name;

	lv_obj_t *list_btn;
	lv_obj_t *obj;

  public:
	/**
	 * @brief Create a View
	 *
	 * @param name Name of the View
	 */
	View(std::string name);

	/**
	 * @brief Create a View
	 *
	 * @param name Name of the View
	 * @param flags Flags passed to the View
	 */
	View(std::string name, std::vector<ViewFlag> flags);

	/**
	 * @brief Set this View to the currently active View
	 */
	void focus();

	/**
	 * @brief Add a flag to the View
	 *
	 * @param flag Flag to add
	 */
	void add_flag(ViewFlag flag);

	/**
	 * @brief Remove a flag from the View
	 *
	 * @param flag Flag to clear
	 */
	void clear_flag(ViewFlag flag);

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
/**
 * @file core.h
 * @brief Robodash core header
 * @ingroup core
 */

#pragma once

#include "liblvgl/lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup core Core
 * @brief The view management system.
 *
 * The LVGL view management system to enable compatibility between templates that provide LVGL GUIs.
 * Knowledge of LVGL is required to use this API.
 */

/// @addtogroup core
/// @{

/**
 * @brief View flags
 */
enum rd_flag {
	RD_NO_ANIMATION = (1L << 0),
	RD_HIDDEN = (1L << 1),
};

/**
 * @brief Robodash view structure
 */
typedef struct rd_view {
	const char *name;
	lv_obj_t *obj;
	lv_obj_t *_list_btn;
	uint32_t flags;
} rd_view_t;

/**
 * @brief Create a view
 *
 * @param name Name of the view
 * @return A pointer to a view object
 */
rd_view_t *rd_view_create(const char *name);

/**
 * @brief Set a view to the currently active view
 *
 * @param view View to focus
 */
void rd_view_focus(rd_view_t *view);

/**
 * @brief Delete a view
 * @warning Deleting a view will free the memory the view occupied, but will not set any variables
 * pointing to said view `NULL`.
 *
 * @param view View to delete
 */
void rd_view_del(rd_view_t *view);

/**
 * @brief Get the view's lvgl object
 *
 * @param view View to query
 */
lv_obj_t *rd_view_obj(rd_view_t *view);

/**
 * @brief Push an alert
 *
 * Pushes an alert to the screen, regardless of which view is active.
 *
 * @param view View to link back to
 * @param msg Message to display
 */
void rd_view_alert(rd_view_t *view, const char *msg);

/**
 * @brief Add a flag to a view
 * @param view View to modify
 * @param flags Flags to add
 */
void rd_view_add_flag(rd_view_t *view, uint32_t flags);

/**
 * @brief Remove a flag from a view
 * @param view View to modify
 * @param flags Flags to remove
 */
void rd_view_remove_flag(rd_view_t *view, uint32_t flags);

/// @}

#ifdef __cplusplus
}
#endif
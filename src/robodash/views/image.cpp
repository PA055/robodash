#include "api.h"
#include "robodash/apix.h"

// ============================= Core Functions ============================= //

rd::Image::Image(lv_img_dsc_t image_dsc, std::string name) {
	if (!pros::usd::is_installed()) return;

	this->view = new View(name);
	this->view->add_flag(RD_FLAG_NO_ANIMATION);

	lv_obj_t *image = lv_img_create(*this->view);
	lv_img_set_src(image, &image_dsc);
	lv_obj_align(image, LV_ALIGN_CENTER, 0, 0);
}

rd::Image::Image(std::string path, std::string name) {
	if (!pros::usd::is_installed()) return;

	this->view = new View(name);
	this->view->add_flag(RD_FLAG_NO_ANIMATION);

	lv_obj_t *image = lv_img_create(*this->view);
	lv_img_set_src(image, ("S:" + path).c_str());
	lv_obj_align(image, LV_ALIGN_CENTER, 0, 0);
}

void rd::Image::focus() { this->view->focus(); }
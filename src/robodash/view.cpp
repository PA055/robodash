#include "view.hpp"

rd::View::View(std::string name) { this->c_view = rd_view_create(name.c_str()); }

void rd::View::focus() { rd_view_focus(this->c_view); }
void rd::View::alert(std::string msg) { rd_view_alert(this->c_view, msg.c_str()); }

void rd::View::add_flag(rd_flag_t flag) { rd_view_add_flag(this->c_view, flag); }
bool rd::View::has_flag(rd_flag_t flag) { return rd_view_has_flag(this->c_view, flag); }
void rd::View::remove_flag(rd_flag_t flag) { rd_view_remove_flag(this->c_view, flag); }

rd_view_t *rd::View::get_c_view() { return this->c_view; }
rd::View::operator rd_view_t *() const { return this->c_view; }

lv_obj_t *rd::View::get_lv_obj() { return rd_view_obj(this->c_view); }
rd::View::operator lv_obj_t *() const { return rd_view_obj(this->c_view); }

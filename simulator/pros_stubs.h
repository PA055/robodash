#pragma once

#ifdef SIMULATOR
#ifdef __cplusplus
#include <chrono>
#include <thread>

namespace pros {
namespace usd {
inline bool is_installed() { return false; }
} // namespace usd
inline void delay(int msec) { std::this_thread::sleep_for(std::chrono::milliseconds(msec)); }
} // namespace pros
#endif
#endif
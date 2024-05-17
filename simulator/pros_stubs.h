#pragma once

#ifdef SIMULATOR
#ifdef __cplusplus
namespace pros {
namespace usd {
inline bool is_installed() { return false; }
inline void delay() { return; }
} // namespace usd
} // namespace pros
#endif
#endif
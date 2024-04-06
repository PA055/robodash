# Changelog

Changes to this project will be logged in this file. This project uses
[Semantic Versioning](https://semver.org/spec/v2.0.0.html). Format is loosely
based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

## 3.0.0

### Added

- A C++ wrapper class for the view API
- An LVGL-style flag system for views

## 2.1.0

Robodash 2.1.0 resolves issues with the autonomous selector.

### Added

- The ability to associate images with autonomous routines
- Support for multiple active selectors
- Automatic SD saving, no need to press a button

Minor breaking changes with selector: `rd::Selector::routine_t` is now a
`struct` instead of an `std::pair`. This shouldn't break any existing code.

### Fixed

- A data abort error when a routine name was too long

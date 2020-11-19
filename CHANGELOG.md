# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres to [BNN Tools](https://github.com/FlySkyPie/bnn-tools).

## [1.1.1] 2020-11-19

### Fixed

- Fix mutator chrash bug.
- Change error message pipe to stderr, instead stdout.

## [1.1.0] 2020-11-01

### Added

- Add stdin mode to input chromosome binary to BNN tools.

## [1.0.0] 2020-03-23

### Added

- Add BNN tools to process chromosome: generator, mutator and decoder.
- The Generator can create random chromosome.
- The mutator can create mutated chromosome from given source.
- The decoder can convert binary of chromosome to JSON.
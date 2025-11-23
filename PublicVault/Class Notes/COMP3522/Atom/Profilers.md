# Profilers
## Statistical Profilers
- Randomly samples the instruction pointer and deduces where time is being spent
- requires less overhead
- **not used in python**
## Deterministic Profiling
- Monitors **everything**
- Times between events are recorded
- Requires more overhead
- In python we can use cprofile and profile
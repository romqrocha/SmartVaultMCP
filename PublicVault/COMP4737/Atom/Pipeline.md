---
aliases:
  - Pipelining
  - Instruction-Level Parallelism
---
- Instead of fetching, decoding, and executing a single instruction at a time, we can fetch and decode multiple instructions, pace them in a buffer, and execute whenever an Execute Unit is available.
- Alternatively, we can have each step of a pipeline actively working on the results of the previous step; like an Assembly line
![[CPU-Pipelining.png]]
- This reduces the [[Cycle Time]] and [[Latency]]
- Even more advanced versions can have multiple pipelines existing in parallel, with Execute units for specific instructions, such as integer, Boolean, or floating point arithmetic.
- ![[Superscalar_Pipeline.png]]
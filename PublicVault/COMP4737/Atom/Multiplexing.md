---
aliases:
  - muxing
---

- When multiple signals are combined into one signal over some shared medium
- Sharing resources in two ways [[#Time]] and [[#Space]]
# Time
- Different programs or users take turns using a resource
- The the [[Operating System|OS]] determines what gets to use the resource, for how long, and who goes next.
# Space
- Different programs or users get to use a part of the resource
- The OS splits [[Main Memory]] into sections and allows each program to work within that section
- If enough Jobs can be held in memory at once, the CPU can be kept busy all the time.
- Requires special hardware to protect each job from trying to read or manipulate other jobs memory locations
# Intel x86 Architecture
![[Intel_PrivilegeRings.png]]
## Ring 0
- AKA [[Kernel Mode]]
- Unrestricted access to all hardware and system resources
- Can execute privileged instructions
- can manage memory, devices, and processes
- Device Drives and Core [[Operating System]] components run in Ring 0.
## Ring 1 and 2
- Used for Operating System Services, such as Device Drivers
## Ring 3
- AKA [[User Mode]]
- Least privileged level
- Where user applications run
- Limited access to System Resources and Hardware
- Must make system calls to request services from the OS rather than being able to manage memory or execute processes.
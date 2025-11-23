---
Created: 2024-03-18T10:30
Class: Comp1712 - Biz Analysis & System Design
Reviewed: false
---
- Architecture is about **what** components exist and **where** those components are.
- The general components of any system are **software** and **hardware**
- The goal of architecture design is to decide how the hardware and software interact.

  

# Basic components of a system

Any software system has 4 basic software functions

1. Data Storage
    - The software the drives the database
2. Data Access Logic
    - The software that allows you to get data from your storage
3. Application Logic/Business Logic
    - Is the meat of the application, and drives the goals of the application
        - Checking out of a store, for example
4. Presentation Logic
    - UI

Three primary hardware components

- Client computers
    - Laptops, desktops, smartphones, etc.
- Servers
    - Hardware that listens to requests and ‘serves’ information
- Network
    - Allows the client and server to communicate.

  

# Types of Architectures

## Client-Server Architecture

- The client runs the presentation logic
    - The client is responsible for displaying the information properly, like CSS for websites.
- Server handles data storage and access
- Application logic can be stored on client **or** server
- There can be multiple clients or multiple servers
- Two sub-types of clients:
    - Thin Client: contains small amounts of application logic
    - Thick Client: contains most or all of the application logic
- Benefits:
    - Scalable
    - Can design each of the software logics (presentation, application, storage, access) independently.
    - Allows you to simply replace failed servers.
- Downsides:
    - More complex, since they have two parts; software on client side, and software on server side.

### Client-server tiers

- Two-Tiered Architecture
    - Application logic lives on client side, so it is inherently a **thick** client
- Three-Tiered Architecture
    - Uses three sets of computers
        - Client
        - Application Server
            - May be split into N-tier as each application server specializes in some part of the application, such as analytics.
                - This lets you use specialized hardware as well.
        - Database Server
- N-Tier Architecture
    - Distributes the work amongst multiple specialized servers
    - Client
    - Web Server
    - Application Server
    - Database Server
    - Needs a higher capacity network, since there’s more data transfer happening
    - Also much harder to test and program.

## Server-Based Architecture

- First computing architectures
- Older style still used where
    - security is important
    - high transaction volume
- A huge computer (usually called a mainframe) performed all 4 application functions
- the clients used **dumb** **terminals** to send and receive messages
    - dumb terminals do no actual processing, they just send and receive data; think the old punch cards.
- Can only be upgrades by upgrading the whole mainframe, since all the systems are integrated.

## Zero/Ultrathin Client

- Used in Virtual Desktop
- A small box passes User I/O to a remote server through ethernet
- The server hosts **everything**
- Benefits:
    - Lower power use compared to fat clients
    - No software at client means no/low vulnerability to malware
    - Multiple virtual machines can run on a single server hardware, so we need less hardware overall.

## Mobile Application Architecture

- Rich-client
    - Application usually requires local processing using the devices resources (GPS/camera/etc.)
    - Connected to server infrequently
    - Application, data access, and presentation logic are all on the client.
- Thin web-based clients
    - Application can rely on server processing
    - device is required to always be connected
    - Application and data access logic are on the server
- Rich Internet Application (RIA)
    - Application requires a ‘rich’ UI
        - Browser games are a good example, since they have a lot of graphics going on, and require system resources.
    - Has limited access to local device resources
    - Must work on multiple platforms
- If I need the abilities of the device, then we need Rich Client
- If we need constant connection to a server, and don’t need device resources, we will mainly use thin web-based clients

# Development Options

# Virtualization

- Server virtualization
    - Partition a physical server into smaller, independent, virtual servers. Each run their own OS and can be rebooted independently.
    - Less hardware → Reduced cost.
- Storage virtualization
    - Combine multiple storage devices into, what appears to me, a single storage device.
    - Storage devices are connected in a _storage area network_
    - Makes up backup, archival, and recovery easier and faster
- Other types: **Application Virtualization** and **Virtual Desktop Infrastructure**

# Cloud

- A set of hardware, networks, storage, services, and interfaces to deliver specific aspects of computing as a service
- Highly scalable and cost efficient. Allows for device independence and increased performance.

  

# Creating an Architecture Design

- Operational Requirements
    - Technical Environment Requirements
    - System Integration Requirements
    - Portability Requirements
    - Maintainability Requirements
- Performance Requirements
    - Speed
    - Capacity
    - Availability and reliability requirements (Uptime)
- Security
    - System Value Estimates
    - Access Control Requirements
    - Encryption and Authentication requirements
    - Virus Control Requirements
- Cultural and Political
    - Multi-lingual requirements
    - Customization
    - Making unstated norms
    - Legal requirements

  

- The most important asset is any organization is not the equipment; it is its **data**.
- a _mission critical system_ is one that the life of the organization depends on.
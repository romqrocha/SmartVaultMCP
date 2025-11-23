DNS Proxy Diagram
```mermaid
sequenceDiagram

    External Request->>+Cloudflare: Where is CoreyBuchan.com?

    Cloudflare->>+CloudflareDNS: Do we know where CoreyBuchan.com is?

    CloudflareDNS-->>Cloudflare: Yup! Give me a moment

    CloudflareDNS->>+Cloudflare Proxy: Can you create a route for CoreyBuchan.com?

    Cloudflare Proxy->>-CloudflareDNS: x.x.x.x is free!

    CloudflareDNS->>-Cloudflare: CoreyBuchan.com is at x.x.x.x

    Cloudflare->>-External Request: CoreyBuchan.com is at x.x.x.x
```

Home Server Architecture
```mermaidJS
%Cant use this because its in beta!%
architecture-beta

    group homenet(cloud)[Home Network]

  

    service router(database)[Router] in homenet

    service homeother(database)[Other home devices] in homenet

  

    junction hnjunction in homenet

  

    router:B -- T:homeother

  

    group homelab(cloud)[Home Lab]

  

    service pc(server)[Naberius] in homelab

    service nginx(internet)[NGINX] in homelab

    service ddns(internet)[Cloudflare DDNS] in homelab

    service portainer(server)[Portainer] in homelab

    service 3tdb(disk)[Database] in homelab

    service 3tweb(internet)[Website] in homelab

  

    junction hlJunctionCenter in homelab

  

    router:R -- L:pc

    pc:R -- L:nginx

    nginx:T <-- B:ddns

    nginx:R -- L:hlJunctionCenter

  

    hlJunctionCenter:R -- L:portainer

    hlJunctionCenter:T -- B:3tdb

    hlJunctionCenter:B -- T:3tweb

  

    group cloudflare(cloud)[Cloudflare]

  

    service dns(database)[Cloudflare DNS] in cloudflare

    service proxy(internet)[Cloudflare Proxy] in cloudflare

  

    junction dnsJunction in cloudflare

  

    dns:R -- L:proxy

    proxy:R -- L:router

    dns:T <-- B:dnsJunction

    dnsJunction:L -- R:ddns

  

    service external(cloud)[External request]

    external:R -- L:dns
```

NGINX Sequence Diagram
```mermaid
sequenceDiagram

    actor External Request

    participant NGINX

    participant 3TWeb

    participant 3TDB

    External Request->>+NGINX: Hey, can I get the website at 3TWeb.CoreyBuchan.com/index.html?

    NGINX->>+3TWeb: Hey, can I get the page at 192.168.1.200/index.html?

    3TWeb->>-NGINX: Sure, here's the file

    NGINX->>-External Request: Sure, here's the file

    External Request->>+NGINX: Can I now get this file from the database at 3TDB.CoreyBuchan.com?

    NGINX->>+ 3TDB: Hey, I need this file

    3TDB->>-NGINX:Sure, here it is!

    NGINX->>-External Request: Sure, here it is!
```

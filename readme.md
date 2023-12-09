## Eclipse IDE with Docker Compose V2 fix
This repository contains solution to fix compatibility issue for Docker Compose V2 and Docker Tooling plugin for Eclipse IDE.

### Issue description
[Eclipse Docker Tooling](https://marketplace.eclipse.org/content/eclipse-docker-tooling) plugin is designed to work with 
Docker Compose V1 and requires `docker-compose` binary to be provided. The final Compose V1 release, version 1.29.2, was May 10, 2021
and from July 2023 Compose V1 stopped receiving updates.

Unlike Compose V1, Compose V2 integrates into the Docker CLI platform and the recommended command-line syntax is `docker compose`.
So in Compose V2 there is no `docker-compose` binary which is required by Eclipse Docker Tooling for container orchestration.

### Software versions
Issue was detected while using next software versions:
+ **OS**: Ubuntu MATE 22.04.3 LTS
+ **Docker Compose**: 2.21.0
+ **Eclipse IDE**: 2023-06 (4.28.0)
+ **Eclipse Docker Tooling**: 5.11.0.202306052033

### Proposed solution
Create binary called `docker-compose` which will receive command-line arguments and transfer them to `docker compose` under the hood.

### Usage
Clone repository and compile `src/docker-compose.cpp` (g++ can be used on Linux). `docker-compose` binary will be in `bin/` directory.
Then open Eclipse IDE, go to `Window -> Preferences -> Docker -> Docker Compose` and browse to compiled `docker-compose` binary.

```
git clone https://github.com/arvisit/eclipse-docker-compose-v2-fix.git
cd eclipse-docker-compose-v2-fix/src/
mkdir ../bin
g++ docker-compose.cpp -o ../bin/docker-compose
```


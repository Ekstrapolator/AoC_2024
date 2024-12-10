#!/bin/bash

ulimit -c unlimited
path="/home/wolek/work/cppPrograms/gitHubRepos/AoC_2024/coreDump"

sysctl -w kernel.core_pattern="${path}/core.%e.%p.%h.%t"
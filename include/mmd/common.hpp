#ifndef __MMD_COMMON
#define __MMD_COMMON

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#include <glm/glm.hpp>

#define MMDExport __attribute__((visibility("default")))
#define MMDImport __attribute__((visibility("default")))

#ifdef Shared
#define MMDAPI MMDExport
#else
#define MMDAPI MMDImport
#endif

#define MMDPacked __attribute__((packed))

#endif

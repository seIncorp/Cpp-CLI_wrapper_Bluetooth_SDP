// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here

#include <stdio.h>
#include <vector>
#include <iostream>
#include <winsock2.h>
#include <bthdef.h>
#include <bthioctl.h>
#include <functional>


#include "ioctl_data.h"

#pragma comment(lib, "SDP_data.lib")


//constexpr auto ON = 1;
//constexpr auto OFF = 0;

#endif //PCH_H

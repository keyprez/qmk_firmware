// Copyright 2022 Christian Sandven (@keyprez)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,           R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,           R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29, L30, R31, R32, R33, R34, R35, R36, R37, \
                   L40, L41, L42, L43, R44, R45, R46, R47 \
) \
{ \
    { L00,   L01,   L02,   L03,   L04,   L05   }, \
    { L12,   L13,   L14,   L15,   L16,   L17   }, \
    { L24,   L25,   L26,   L27,   L28,   L29   }, \
    { KC_NO, L40,   L41,   L42,   L43,   L30   }, \
    { R11,   R10,   R09,   R08,   R07,   R06   }, \
    { R23,   R22,   R21,   R20,   R19,   R18   }, \
    { R37,   R36,   R35,   R34,   R33,   R32   }, \
    { KC_NO, R47,   R46,   R45,   R44,   R31 }, \
}

/* Copyright 2021 csandven
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    ka0, ka1, ka2, ka3, ka4, ka5, ka6, ka7, ka8, ka9, ka10, ka11, ka12, ka13, ka14, \
    kb0, kb1, kb2, kb3, kb4, kb5, kb6, kb7, kb8, kb9, kb10, kb11, kb12, kb13, kb14, \
    kc0, kc1, kc2, kc3, kc4, kc5, kc6, kc7, kc8, kc9, kc10, kc11,     kc12,   kc13, \
      kd0, kd1, kd2, kd3, kd4, kd5, kd6, kd7, kd8, kd9, kd10,   kd11,   kd12, kd13, \
    ke0, ke1, ke2,             ke3,                       ke4, ke5, ke6, ke7, ke8 \
) { \
    { ka0, ka1, ka2, ka3, ka4, ka5, ka6 }, \
    { kb0, kb1, kb2, kb3, kb4, kb5, kb6 }, \
    { kc0, kc1, kc2, kc3, kc4, kc5, kc6 }, \
    { kd0, kd1, kd2, kd3, kd4, kd5, kd6 }, \
    { ke0, ke1, ke2, ke3, ke4, ke5, ke6 }, \
    { ka7, ka8, ka9, ka10, ka11, ka12, ka13 }, \
    { kb7, kb8, kb9, kb10, kb11, kb12, kb13 }, \
    { kc7, kc8, kc9, kc10, kc11, kc12, kd7 }, \
    { kd8, kd9, kd10, kd11, kd12, ka14, kb14 }, \
    { kc13, kd13, ke7, ke8, KC_NO, KC_NO, KC_NO }, \
}

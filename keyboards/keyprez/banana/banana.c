/* Copyright 2021 Christian Sandven
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

#include "banana.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }

    switch(index) {
        case 0:
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;

        case 1:
            tap_code(clockwise ? KC_PGDN : KC_PGUP);
            break;

        case 2:
            tap_code(clockwise ? KC_RIGHT : KC_LEFT);
            break;
    }

    return true;
}

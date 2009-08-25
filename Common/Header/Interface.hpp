/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000 - 2009

	M Roberts (original release)
	Robin Birch <robinb@ruffnready.co.uk>
	Samuel Gisiger <samuel.gisiger@triadis.ch>
	Jeff Goodenough <jeff@enborne.f2s.com>
	Alastair Harrison <aharrison@magic.force9.co.uk>
	Scott Penrose <scottp@dd.com.au>
	John Wharington <jwharington@gmail.com>
	Lars H <lars_hn@hotmail.com>
	Rob Dunning <rob@raspberryridgesheepfarm.com>
	Russell King <rmk@arm.linux.org.uk>
	Paolo Ventafridda <coolwind@email.it>
	Tobias Lohner <tobias@lohner-net.de>
	Mirek Jezek <mjezek@ipplc.cz>
	Max Kellermann <max@duempel.org>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#if !defined(XCSOAR_INTERFACE_HPP)
#define XCSOAR_INTERFACE_HPP
#include "XCSoar.h"

void FocusOnWindow(int i, bool selected);

bool Debounce();
extern int debounceTimeout;
void SwitchToMapWindow(void);
void FullScreen();

// instance of main program
extern HINSTANCE hInst;

// windows
extern HWND hWndMainWindow;           // HWND Main Window
//extern MapWindow hWndMapWindow;

extern bool GlobalRunning;

extern bool InfoWindowActive;

extern bool csFlightDataInitialized;

typedef enum {
  psInitInProgress=0,
  psInitDone=1,
  psFirstDrawDone=2,
  psNormalOp=3
} StartupState_t;

// 0: not started at all
// 1: everything is alive
// 2: done first draw
// 3: normal operation

extern StartupState_t ProgramStarted;

#endif

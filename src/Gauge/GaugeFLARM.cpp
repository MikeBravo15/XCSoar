/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2011 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

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

#include "Gauge/GaugeFLARM.hpp"
#include "NMEA/Info.hpp"
#include "Dialogs/Traffic.hpp"

/**
 * Constructor of the GaugeFLARM class
 * @param parent Parent window
 * @param left Left edge of window pixel location
 * @param top Top edge of window pixel location
 * @param width Width of window (pixels)
 * @param height Height of window (pixels)
 */
GaugeFLARM::GaugeFLARM(ContainerWindow &parent,
                       PixelScalar left, PixelScalar top,
                       UPixelScalar width, UPixelScalar height,
                       const FlarmTrafficLook &look,
                       const WindowStyle style)
  :FlarmTrafficWindow(look, 1, true),
   ForceVisible(false), Suppress(false)
{
  set(parent, left, top, width, height, style);
}

void
GaugeFLARM::Update(bool enable, const NMEAInfo &gps_info,
                   const TeamCodeSettings &settings)
{
  const FlarmState &flarm = gps_info.flarm;

  // If FLARM alarm level higher then 0
  if (flarm.available && flarm.alarm_level > 0)
    // Show FLARM gauge and do not care about suppression
    Suppress = false;

  bool visible = ForceVisible ||
    (flarm.available && !flarm.traffic.empty() && enable && !Suppress);
  if (visible) {
    FlarmTrafficWindow::Update(gps_info.track, flarm,
                               settings);
    show();
  } else
    hide();
}

/**
 * This function is called when the mouse is pressed on the FLARM gauge and
 * opens the FLARM Traffic dialog
 * @param x x-Coordinate of the click
 * @param y y-Coordinate of the click
 */
bool
GaugeFLARM::on_mouse_down(PixelScalar x, PixelScalar y)
{
  dlgFlarmTrafficShowModal();
  return true;
}

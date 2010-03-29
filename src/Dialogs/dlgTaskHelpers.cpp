/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009

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
	Tobias Bieniek <tobias.bieniek@gmx.de>

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

#include "dlgTaskHelpers.hpp"
#include "Task/Tasks/OrderedTask.hpp"
#include "Units.hpp"

const TCHAR* OrderedTaskFactoryName(OrderedTask::Factory_t type)
{
  const TCHAR* text;
  switch(type) {
  case OrderedTask::FACTORY_FAI:
    text = _T("FAI triangle");
    break;
  case OrderedTask::FACTORY_AAT:
    text = _T("AAT");
    break;
  case OrderedTask::FACTORY_MIXED:
    text = _T("Mixed AAT");
    break;
  };
  return text;
}

const TCHAR* OrderedTaskFactoryDescription(OrderedTask::Factory_t type)
{
  const TCHAR* text;
  switch(type) {
  case OrderedTask::FACTORY_FAI:
    text = _T("FAI triangle task");
    break;
  case OrderedTask::FACTORY_AAT:
    text = _T("AAT racing task, all turnpoints are are assigned areas");
    break;
  case OrderedTask::FACTORY_MIXED:
    text = _T("AAT racing task, mixed assigned area and non-assigned area turnpoints");
    break;
  };
  return text;
}

void OrderedTaskSummary(OrderedTask* task, TCHAR* text)
{
  const TaskStats &stats = task->get_stats();

  if (!task->task_size()) {
    _stprintf(text, _T("%s\nTask is empty"),
              OrderedTaskFactoryName(task->get_factory_type()));
  } else {
    _stprintf(text, _T("%s\nNominal dist: %.0f %s\nMax dist: %.0f %s\nMin dist: %.0f %s"), 
              OrderedTaskFactoryName(task->get_factory_type()),
              Units::ToUserDistance(stats.distance_nominal),
              Units::GetDistanceName(),
              Units::ToUserDistance(stats.distance_max),
              Units::GetDistanceName(),
              Units::ToUserDistance(stats.distance_min),
              Units::GetDistanceName()
      );
  }
}

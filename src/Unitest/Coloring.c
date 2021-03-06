/*
Unitest - Unit Testing Framework for C
Copyright (C) 2016  @maldevel

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Coloring.h"

void Start_Coloring(CONSOLE_SCREEN_BUFFER_INFO *pcsbi)
{
	GetConsoleScreenBufferInfo(STD_OUT, pcsbi);
}

void Stop_Coloring(CONSOLE_SCREEN_BUFFER_INFO csbi)
{
	SetConsoleTextAttribute(STD_OUT, csbi.wAttributes);
}

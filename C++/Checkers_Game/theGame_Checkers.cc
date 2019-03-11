/*
 * theGame_Checkers.cc
 * 
 * Copyright 2019 Mark Brown <mark_VM@mark_VM-VirtualBox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <iostream>
#include <cstring>
#include <stdlib.h>

#include <sstream>
#include <string>

#include "game.h"
#include "colors.h"
#include "checkers.h"
#include "spaces.h"


using namespace main_savitch_14;



int main(){
	checkers games;
	game::who winner;
	winner = games.play();
	if(winner == game::HUMAN)
		cout << "Congratulations >:[ You've won this time, Human. Don't get use to it.\n";
	else
		cout << "HAHAHA! You lose... I win! Who is the superior one now?.\n";
}

/*
 * spaces.h
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

#ifndef SPACES_H
#define SPACES_H

class spaces{
	public:
		int is_space()const{return item;};
		void set_space(int a){item = a;};
		bool is_red()const{return item == 0;};
		bool is_black()const{return item == 1;};
		bool is_eking()const{return item ==4;};
		bool is_gking()const{return item == 5;};
		bool is_good()const{return item == 3;};
		bool is_evil()const{return item == 2;};
		
	private:
		/*
		Table of contends for personal reference:
		
		
		0 = RED
		1 = BLACK
		2 = EVIL
		3 = GOOD
		4 = KING->EVIL
		5 = KING->GOOD
		*/
		int item;
};



#endif
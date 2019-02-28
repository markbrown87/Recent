/*
 * checkers.h
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
 *
 * NOTE: Savitch developed code in this file and I added my own to it and
 *        or modified it to work with my Checkers game
 *
 */

#include <string>
#include <queue>
#include "game.h"
#include "spaces.h"

namespace main_savitch_14{
	
	class checkers:public game{	
		public: 
			checkers();
			int convert_to_number(char a)const;
			int get_count(int a)const;
			bool is_human_move()const;
			bool is_computer_move()const;
			bool is_regular_move(int current_alpha, int current_num, int next_alpha, int next_num)const;
			bool is_jump_move(int current_alpha, int current_num, int next_alpha, int next_num, int item)const;
			void make_jump_move(int current_alpha, int current_num, int next_alpha, int next_num);
			void turn_king(int next_alpha, int next_num);
			char convert_back(int a) const;
		protected:
			virtual void restart();
			virtual void display_status() const;
			virtual bool is_legal(const std::string& move)const;
			virtual void make_move(const std::string& move);
			virtual bool is_game_over()const;
			virtual game* clone()const
				{ return new checkers(*this); }
			virtual void compute_moves(std::queue<std::string>& moves) const;
			virtual int evaluate()const;
		private:
			spaces board[8][8];
			int evil_count, good_count;
	};
	
}
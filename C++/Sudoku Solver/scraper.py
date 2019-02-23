#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  scraper.py
#  
#  Copyright 2019 Mark Brown <mark_VM@mark_VM-VirtualBox>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  

import requests
import sys
from bs4 import BeautifulSoup
urlx2 = 'https://www.menneske.no/sudoku/2/eng/'
urlx3 = 'https://www.menneske.no/sudoku/eng/'
urlx4 = 'https://www.menneske.no/sudoku/4/eng/'
urlx5 = 'https://www.menneske.no/sudoku/5/eng/'

def switch(value):
	switcher = {
		2: "Two",
		3: "Three",
		4: "Four",
		5: "Five"
	}
	
	return switcher.get(value, "Invalid Selection")


def main(args):
	
	if len(args) == 2:
		try:
			pSize = int(args[1])
			
			if pSize > 1 and pSize < 6:
				print('Perfect amount: ', switch(pSize))
			
			else:
				print('Please input between 2 and 5 (inclusive)')
			
		except IndexError:
			print('Arguments not Found')
	else:
		print('Incorret amount of arguments')
	
	return 0

if __name__ == '__main__':
    
    sys.exit(main(sys.argv))

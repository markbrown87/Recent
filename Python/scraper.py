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

# import declarations
import requests, sys, os, re
from bs4 import BeautifulSoup

# global variables
urlx2 = 'https://www.menneske.no/sudoku/2/eng/'
urlx3 = 'https://www.menneske.no/sudoku/eng/'
urlx4 = 'https://www.menneske.no/sudoku/4/eng/'

# Check if file already exists (change name of new file to include incremented value)
def FileChecker(pSize):
	
	pSize = str(pSize)
	newFile = ""
	incNum = 0
	
	myBinFolder = os.getcwd() + "/bin"
	myBinFile = "/" + pSize + "x" + pSize + ".bin"
	newFile = myBinFolder + "/" + pSize + "x" + pSize + ".bin"
	
	if not os.path.isdir(myBinFolder):
		os.makedirs(myBinFolder)	
		print('Creating Bin folder in: ', myBinFolder)
	
	return newFile

# Print list data to .bin file
def PrintList(pSize, com):
	newFile = FileChecker(pSize)
	
	with open(newFile, "a+") as handle:
		# ~ handle.write(com)
		print(com,file=handle, sep='\n')
		# ~ print(com, file=handle)
		print('Printed to file: ' + newFile)


# Compose List; parses the list and returns the nice pretty list of values in the sudoku puzzle
def comList(myTable):
	
	com = []
	
	for row in myTable.find_all('tr'):
		col = row.find_all('td')
		col = [ele.text.strip() for ele in col]
		com.append([ele for ele in col])
	
	return com
	

# switch statment that returns the proper URL for the corresponding sudoku size
def switch(value):
	
	switcher = {
		2: requests.get(urlx2).text,
		3: requests.get(urlx3).text,
		4: requests.get(urlx4).text
	}
	
	return switcher.get(value, "Invalid Selection")

# takes in the argv as inputs to make a 2x2,3x3,4x4 sudoku puzzle and spits it into a bin file
def main(args):
	
	if len(args) == 2:
		try:
			pSize = int(args[1])
			
			if pSize > 1 and pSize < 5:
				html = switch(pSize)
				
				soup = BeautifulSoup(html, 'lxml')
				
				myTable = soup.find('div',{'class':'grid'})
				myTable = myTable.find('table')
				
				com = comList(myTable)
				
				PrintList(pSize, com)
				
			else:
				print('Please input between 2 and 5 (inclusive)')
			
		except IndexError:
			print('Arguments not Found')
	else:
		print('Incorret amount of arguments')
	
	return 0
	
	

if __name__ == '__main__':
    
    sys.exit(main(sys.argv))

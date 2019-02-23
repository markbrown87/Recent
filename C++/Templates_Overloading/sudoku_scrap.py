import requests
import lxml.html as lh
import pandas as pd

url='http://wwww.websudoku.com'

#Create a handle to work the contents of the webpage
page = requests.get(url)

#store the contents of the webpage
doc = lh.fromstring(page.content)

#parse the data
tr_elements = doc.xpath('//table[@id="puzzle_grid"]')

for T in tr_elements
	print("Here is ", T)

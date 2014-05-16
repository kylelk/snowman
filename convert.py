#!/usr/bin/python

from PIL import Image
import sys
file_in = sys.argv[1]
img = Image.open(file_in)
file_out = sys.argv[2]
img.save(file_out)

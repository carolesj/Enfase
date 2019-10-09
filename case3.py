"""
Caroline Jesuíno Nunes da Silva

I had some trouble doing this one. I thought in a absolutely incorrect
approach, so I decided to search for it. I found a solution online, that looks
kinda like the problem, but only works for positive integers. This is it:
https://www.geeksforgeeks.org/find-length-of-longest-fibonacci-like-subsequence/
Since it is not my code, I decided not to implement it, but I decide to show
that I could find something similar.
"""

import numpy as np

def make_fibonnaci_like_sequence(sequence):
	

def main():
	sequence_size = int(input())
	sequence = np.zeros(sequence_size)
	for i in sequence:
		sequence[i] = int(input())
	
	np.sort(sequence)

if __name__ == '__main__':
	main()

import string
from random import choice

def hang():
	print "You have seven chances to fill up the random word"
	man = ["\\","0","/"," \n|","\n/","\\"]
	word = [choice(string.ascii_lowercase) for l in range(5)]
	mystery = list(map(lambda x: "_ ", word))
	count = 0 
	for i in range(1,7):
		letter = raw_input("Enter letter:")
		if letter in word:
			ind = [x for x,l in enumerate(word) if l == letter][0]
			mystery[ind] = letter
			print "Yes! just "+ str(len(word)-i)+ " to go"
			print ''.join(mystery)
		else:
			count = count + 1
			print ''.join(man[:count])
	print "\nThe word is " + ''.join(word)
		

if __name__ == "__main__":
	hang()

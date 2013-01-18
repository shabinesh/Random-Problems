import string
from random import choice

def hang():
	found = 0
	print "You have seven chances to fill up the random word"
	man = ["\\","0","/"," \n |","\n/","\\"]

	try:
	        print "trying the dict words"
		words = [line.strip() for line in open('/usr/share/dict/words')]
		word = choice(words)
	except Exception:
		word = [choice(string.ascii_lowercase) for l in range(5)]

	mystery = list(map(lambda x: "_ ", word))
	guessed = []
	count = 0
	while count < len(man) and not found:
		letter = raw_input("?: ")
                if letter in guessed:
                        print "You already have guessed it"
                        continue

		guessed.append(letter)

                print ''.join(mystery)
		if letter in word:
			for ind in range(0, len(word)):
				if letter == word[ind]:
					mystery[ind] = letter
			if '_' in ''.join(mystery):
				print ''.join(mystery)
			else:
				print "Congrats!! You have done it!!"
				found = 1
		else:
			count = count + 1
			print ''.join(man[:count])
	if not found:
		print "\nThe word is " + ''.join(word)

if __name__ == "__main__":
	hang()

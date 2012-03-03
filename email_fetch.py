#!/usr/bin/python

import imaplib,re,getopt,sys,getpass
from sets import Set

e_regex = re.compile(r'[\w\-][\w\-\.]+@[\w\-][\w\-\.]+[a-zA-Z]{1,4}')
emails = []
passwd = ''
try:
	arg,r = getopt.getopt(sys.argv[1:],'-u:-p:')
	print sys.argv[1:]
	for c,o in arg:
		if c == '-u':
			username = o
		elif c == '-p':
			if o == '':
				passwd = getpass.getpass()
			else:
				passwd = o
	if passwd == '':
		passwd = getpass.getpass()
except getopt.GetoptError:	
	print "Usage: $command -u <username> [-p [<password>]]"
	sys.exit(-1)

#connect to the email server

conn = imaplib.IMAP4_SSL('imap.gmail.com')
conn.login(username,passwd)
conn.select("[Gmail]/Spam")
t, d = conn.search(None, "ALL") #search for all mails
for i in d[0].split():
	 emails.extend(e_regex.findall(str(conn.fetch(i,'(RFC822)'))))
d_emails = list(Set(emails))
conn.logout()
f = open('emails.txt','w')
for i in d_emails:
	f.write(i+"\n")
f.close()

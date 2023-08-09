from email.message import EmailMessage
import ssl
import smtplib

email_sender = ''
email_reciever = ''
email_pass=''
subject = 'trying out email sender . PY'
body = ''' 
Just trying out new stuff nvm!!
'''
em = EmailMessage()
em['From']=email_sender
em['To']=email_reciever
em['Subject']=subject
em.set_content(body)

context = ssl.create_default_context()

with smtplib.SMTP_SSL('smtp.gmail.com',465,context=context) as smtp:
    smtp.login(email_sender,email_pass)
    smtp.sendmail(email_sender,email_reciever,em.as_string())


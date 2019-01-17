import datetime

i = datetime.datetime.now()

subject = '%s月%s日 通源小学无网络安全问题' % (i.month, i.day-1 )

print(subject)

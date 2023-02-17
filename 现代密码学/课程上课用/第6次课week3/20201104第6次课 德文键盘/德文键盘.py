import hashlib
import itertools

# (Q=win*5
# k = '(Q=Win5qw80IN*%'

k = 'QqWw%58(=0Ii*+nN'
keys = itertools.permutations(k, 8)
for key in keys:
    c = ''.join(key)
    if (hashlib.sha1(c.encode()).hexdigest() == '67ae1a64661ac8b4494666f58c4822408dd0a3e4'):
        print(c)
        break

# ''.join(('1', '2'))


# k = '1234'
# for i in itertools.permutations(k, 2):
#     print(i)

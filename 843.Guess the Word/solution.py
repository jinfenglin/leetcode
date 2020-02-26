import random
from typing import List

class Solution:
    def findSecretWord(self, wordlist: List[str], master: 'Master') -> None:
        check = lambda s1,s2: sum([1 for x,y in zip(s1,s2) if x==y ])
        random.seed(1)
        while wordlist:
            choice = random.choice(wordlist)
            num = master.guess(choice)
            wordlist.remove(choice)
            wordlist  = [word for word in wordlist if check(choice,word)==num]
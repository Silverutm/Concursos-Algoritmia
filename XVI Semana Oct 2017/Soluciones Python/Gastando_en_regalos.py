TEST_CASES = int(raw_input())
for case in xrange(TEST_CASES):
    number_of_people = int(raw_input())
    dictionary = {}
    flag = True
    for x in xrange(number_of_people):
        gift_giver, receipter = map(int, raw_input().split())
        if gift_giver == receipter:
            flag = False
        if gift_giver in dictionary:
            if dictionary[gift_giver][0]:
                flag = False
            else:
                dictionary[gift_giver][0] = True
        else:
            dictionary[gift_giver] = [True, False]
        if receipter in dictionary:
            if dictionary[receipter][1]:
                flag = False
            else:
                dictionary[receipter][1] = True
        else:
            dictionary[receipter] = [False, True]
    if flag:
        print "Intercambio exitoso."
    else:
        print "Papelitos otra vez."
                

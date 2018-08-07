'''
the copy of an object in python, like "a = A(), b = a", b is a reference.
two list sum, from the rightest num to the leftest, each time multiply a multiplier
then convert num to LinkedList 
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        res = 0
        mul = 1
        while l1 or l2:
            first = l1.val if l1 else 0
            second = l2.val if l2 else 0
            res += (first + second) * mul
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            mul *= 10
        
        # print(res)
        res_list = ListNode(res % 10)
        res //= 10
        cur = res_list
        while res:

            tmp = ListNode(res % 10)
            res //= 10
            cur.next = tmp
            cur = cur.next
        
        return res_list 
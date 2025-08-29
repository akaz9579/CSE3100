nums = [9,1,4,7,3,-1,0,5,8,-1,6]

def longestConsecutive(nums):
        orderedSet = set()
        for n in nums:
            orderedSet.add(n)
        sortedSet = sorted(orderedSet)

        print("Ordered set:", orderedSet)
        print("Sorted set:", sortedSet)

        if sortedSet ==[]:
            count = 0
        else:
            count = 1

        maxcount = 0
        for i in range(len(sortedSet)-1):
            if sortedSet[i+1]-sortedSet[i] == 1:
                count+=1 
                if maxcount < count:
                    maxcount = count
            else:
                if maxcount < count:
                    maxcount = count
                count = 1
                
        return maxcount


print(longestConsecutive(nums))
def jump(self, nums):
  opt = []
  for i in range(0, len(nums)):
     opt.append(sys.maxint)

  opt[0] = 0
  for i in range(1, len(nums)):
    for j in range(0, i):
        if nums[j] + j >= i:
          opt[i] = min(opt[j] + 1, opt[i])
  return opt[len(nums) - 1]

def tribonacci(n):
  num_1, num_2, num_3 = 1, 0, 0
  for _ in xrange(n): 
      num_1, num_2, num_3 = num_2, num_3, num_1 + num_2 + num_3
  return num_3

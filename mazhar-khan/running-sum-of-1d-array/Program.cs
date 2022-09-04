var sums = RunningSum(new int[] { 1, 1, 1, 1, 1 });

for (var i = 0; i < sums.Length; i++)
{
  Console.WriteLine(sums[i]);
}

int[] RunningSum(int[] nums)
{
  var runningSums = new int[nums.Length];
  runningSums[0] = nums[0];

  for (var i = 1; i < nums.Length; i++)
  {
    runningSums[i] = runningSums[i - 1] + nums[i];
  }

  return runningSums;
}
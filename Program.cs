int[] nums = {3, 9, 4, 6, 0 };
int target = 6;

int[]? result = TwoSum(nums, target);

if (result != null)
{
    Console.WriteLine("[" + result[0] + "," + result[1]  + "]\n");
}
else
{
    Console.WriteLine("No answer. \n");
}

int[]? TwoSum(int[] nums, int target)
{
    Dictionary<int, int> map = new Dictionary<int, int>();
    for (int i = 0; i < nums.Length; i++)
    {
        int complement = target - nums[i];
        if (map.ContainsKey(complement))
        {
            return new int[] { map[complement], i };
        }
        map[nums[i]] = i;
    }

    // Return an empty array if no solution is found
    return null;
}


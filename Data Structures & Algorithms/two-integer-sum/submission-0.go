func twoSum(nums []int, target int) []int {

    length := len(nums)

    solution := make([]int, 2)

    for i:= 0; i < length; i++ {
        for j:= i + 1; j < length; j ++ {
            if nums[i]+nums[j] == target {
                solution[0] = i
                solution[1] = j
                return solution
            }
        }
    }





    return nil
}


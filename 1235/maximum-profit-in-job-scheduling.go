import "sort"

type job struct {
	st int
	en int
	pr int
}

func jobScheduling(startTime []int, endTime []int, profit []int) int {
	jobs := make([]job, len(startTime))
	for i := 0; i < len(startTime); i++ {
		jobs[i] = job{startTime[i], endTime[i], profit[i]}
	}
	sort.Slice(jobs, func(i, j int) bool { return jobs[i].en <= jobs[j].en })

	dp := make([][]int, 1)
	dp[0] = []int{0, 0}

	for _, job := range jobs {
		j := 1
		for ; j < len(dp) && dp[j][0] <= job.st; j++ {
		}
		j--

		if dp[j][1]+job.pr > dp[len(dp)-1][1] {
			dp = append(dp, []int{job.en, dp[j][1] + job.pr})
		}
	}

	return dp[len(dp)-1][1]
}

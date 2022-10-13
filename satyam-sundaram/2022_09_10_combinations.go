type Stack struct {
    data []int
    cur int
    size int
}

func (st *Stack) Push(x int) {
    if st.cur == st.size {
        st.data = append(st.data, x)
        st.cur++
        st.size++
    } else {
        st.data[st.cur] = x
        st.cur++
    }
}

func (st *Stack) Pop() {
    if st.cur == 0 {
        return
    }
    st.cur--
}

func (st *Stack) Size() int {
    return st.cur
}

func (st *Stack) Get() []int {
    data := make([]int, st.cur)
    copy(data, st.data[:st.cur])
    return data
}

func newStack() *Stack {
    return &Stack{data: make([]int, 0), size:0, cur: 0}
}

type Answer struct {
    data     [][]int
    st       *Stack
    limit    int // k
    maxIndex int // n
    nums     []int // 1...n
}
func (ans *Answer) checkSize() bool {
    return ans.st.cur <= ans.limit
}

func (ans *Answer) Add(index int) {
    ans.st.Push(ans.nums[index])
}

func (ans *Answer) Remove() {
    ans.st.Pop()
}

func (ans *Answer) solve(index, remaining int) {
    if remaining == 0 {
        ans.data = append(ans.data, ans.st.Get())
        return
    }
    if index >= ans.maxIndex {
        return
    }
    if ans.checkSize() {
        ans.Add(index)
        ans.solve(index+1, remaining-1)
    }
    ans.Remove()
    ans.solve(index+1, remaining)
}

func newAnswer(k, n int) *Answer {
    var data []int
    for i := 1;i <= n; i++ {
        data = append(data, i)
    }
    return &Answer{
        data: make([][]int, 0),
        st: newStack(),
        limit: k,
        maxIndex: n,
        nums: data,
    }
}

func combine(n int, k int) [][]int {
    ans := newAnswer(k, n)
    ans.solve(0, k)
    return ans.data
}

func addStrings(num1 string, num2 string) string {
    n1 := len(num1)
    n2 := len(num2)
    
    var data bytes.Buffer
    i := n1-1
    j := n2-1
    
    c := 0
    s := 0
    for i >= 0 && j >= 0 {
        x1, _ := strconv.Atoi(string(num1[i]))
        x2, _ := strconv.Atoi(string(num2[j]))
        s = c + x1 + x2
        r := s % 10
        data.WriteString(strconv.Itoa(r))
        c = s/10
        i--
        j--
    }
    for i >= 0 {
        x, _ := strconv.Atoi(string(num1[i]))
        s = c + x
        r := s%10
        data.WriteString(strconv.Itoa(r))
        c = s/10
        i--
    }
    
    for j >= 0 {
        x, _ := strconv.Atoi(string(num2[j]))
        s = c + x
        r := s%10
        data.WriteString(strconv.Itoa(r))
        c = s/10
        j--
    }
    if c != 0 {
        data.WriteString(strconv.Itoa(c))
    }
    s1 := []byte(data.String())
    for i, j := 0, len(s1)-1; i < j; i, j = i+1, j-1 {
        s1[i], s1[j] = s1[j], s1[i]
    }
    return string(s1)
}

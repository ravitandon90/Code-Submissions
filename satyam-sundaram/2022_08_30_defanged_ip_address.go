// package main

func defangIPaddr(address string) string {
    parts := strings.Split(address, ".")
    return strings.Join(parts, "[.]")
}

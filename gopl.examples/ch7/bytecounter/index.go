package bytecounter

// Bytecounter 类型
type Bytecounter int

func (c *Bytecounter) Write(p []byte) (int, error) {
	*c += Bytecounter(len(p))
	return len(p), nil
}

package tempconv

import (
	"flag"
	"fmt"
)

// Celsius 摄氏度
type Celsius float64

// Fahrenheit 法师
type Fahrenheit float64

const (
	// AbsoluteZeroC 绝对零度
	AbsoluteZeroC Celsius = -273.15
	// FreezingC 零度
	FreezingC Celsius = 0
	// BoilingC 沸腾温度
	BoilingC Celsius = 100
)

func (c Celsius) String() string {
	return fmt.Sprintf("%gC", c)
}

func (f Fahrenheit) String() string {
	return fmt.Sprintf("%gF", f)
}

// CToF 摄氏度转法师摄氏度
func CToF(c Celsius) Fahrenheit {
	return Fahrenheit(c*9/5 + 32)
}

// FToC 和上面相反
func FToC(f Fahrenheit) Celsius {
	return Celsius((f - 32) * 5 / 9)
}

type celsiusFlag struct{ Celsius }

func (f *celsiusFlag) Set(s string) error {
	var unit string
	var value float64
	fmt.Sscanf(s, "%f%s", &value, &unit)

	switch unit {
	case "C":
		f.Celsius = Celsius(value)
		return nil
	case "F":
		f.Celsius = FToC(Fahrenheit(value))
		return nil
	}

	return fmt.Errorf("invalid temperature %q", s)
}

// CelsiusFlag xxx
func CelsiusFlag(name string, value Celsius, usage string) *Celsius {
	f := celsiusFlag{Celsius: value}

	flag.CommandLine.Var(&f, name, usage)
	return &f.Celsius
}

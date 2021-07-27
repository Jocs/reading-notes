package main

import (
	"fmt"
	"image/color"

	"gopl.io/ch6/geometry"
	"gopl.io/ch6/intset"
)

func main() {
	p := geometry.Point{X: 1, Y: 2}
	q := geometry.Point{X: 4, Y: 6}
	fmt.Println(geometry.Distance(p, q))
	fmt.Println(p.Distance(q))

	perim := geometry.Path{
		{X: 1, Y: 1},
		{X: 5, Y: 1},
		{X: 5, Y: 4},
		{X: 1, Y: 1},
	}
	fmt.Println(perim.Distance())
	r := &geometry.Point{X: 1, Y: 2}
	r.ScaleBy(2)
	fmt.Println(*r)
	a := geometry.Point{X: 2, Y: 6}
	a.ScaleBy(3) // 隐式转换
	fmt.Println(a)
	var cp geometry.ColoredPoint
	cp.X = 1
	fmt.Println(cp.Point.X)
	cp.Point.X = 2
	fmt.Println(cp.X)
	red := color.RGBA{255, 0, 0, 255}
	blue := color.RGBA{0, 0, 255, 255}
	var pp = geometry.ColoredPoint{Point: geometry.Point{X: 1, Y: 1}, Color: red}
	var qq = geometry.ColoredPoint{Point: geometry.Point{X: 5, Y: 4}, Color: blue}
	fmt.Println(pp.Distance(qq.Point))
	pp.ScaleBy(2)
	qq.ScaleBy(2)
	fmt.Println(pp.Distance(qq.Point))

	var x, y intset.IntSet
	x.Add(1)
	x.Add(144)
	x.Add(9)
	fmt.Println(x.String())
	y.Add(144)
	y.Add(3)
	fmt.Println(y.String())
	x.UnionWith(&y)
	fmt.Println(x.String())
	fmt.Println(x.Has(3))
	var m intset.IntSet = x.UnionSet(&y)
	fmt.Println(m.String())
}

package geometry

import (
	"image/color"
	"math"
)

// Point 一个点
type Point struct {
	X, Y float64
}

// Path 路径
type Path []Point

// ColoredPoint colored point
type ColoredPoint struct {
	Point
	Color color.RGBA
}

// Distance 普通方法
func Distance(p, q Point) float64 {
	return math.Hypot(p.X-q.X, q.Y-p.Y)
}

// Distance Point 类型方法
func (p Point) Distance(q Point) float64 {
	return math.Hypot(p.X-q.X, q.Y-p.Y)
}

// Distance path 的路径
func (p Path) Distance() float64 {
	sum := 0.0
	for i := range p {
		if i > 0 {
			sum += p[i-1].Distance(p[i])
		}
	}

	return sum
}

// ScaleBy 放大倍数
func (p *Point) ScaleBy(factor float64) {
	p.X *= factor
	p.Y *= factor
}

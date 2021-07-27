#include <stdio.h>

#define RECTANGLE 1
#define CIRCLE 2
#define PI 3.1415926

struct point {
  int x;
  int y;
};

struct shape {
  int shape_kind;
  struct point center;
  union {
    struct {
      double width;
      double height;
    } rectangle;
    struct {
      double radio;
    } circle;
  } u;
};

double area(struct shape);
struct shape transform(struct shape, int, int);
struct shape scale(struct shape, double);

int main(void)
{
  // ...
}

double area(struct shape s)
{
  if (s.shape_kind == RECTANGLE) {
    return s.u.rectangle.width * s.u.rectangle.height;
  } else {
    return PI * s.u.circle.radio * s.u.circle.radio;
  }
}

struct shape transform(struct shape s, int x, int y)
{
  struct shape result = s;
  result.center.x += x;
  result.center.y += y;
  return result;
}

struct shape scale(struct shape s, double c)
{
  struct shape result = s;
  if (result.shape_kind == RECTANGLE) {
    result.u.rectangle.width *= c;
    result.u.rectangle.height *= c;
  } else {
    result.u.circle.radio *= c;
  }

  return result;
}

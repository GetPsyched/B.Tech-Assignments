#include <stdio.h>

int main()
{
  int main_ch, ch;
  float num1, num2, radius, base, height, side, principal, rate, time, final;
  // Circle
  printf("\nEnter radius of circle --> ");
  scanf("%f", &radius);
  final = (22 * radius * radius)/7;
  printf("\nThe area of the circle is --> %f\n", final);
  final = (44 * radius)/7;
  printf("The perimeter of the circle is --> %f\n", final);
  // Triangle
  printf("\nEnter base --> ");
  scanf("%f", &base);
  printf("Enter height --> ");
  scanf("%f", &height);
  final = (base * height)/2;
  printf("\nThe area of the triangle is --> %f\n", final);
  printf("\nEnter side 1 --> ");
  scanf("%f", &side);
  final = side;
  printf("Enter side 2 --> ");
  scanf("%f", &side);
  final = final + side;
  printf("Enter side 3 --> ");
  scanf("%f", &side);
  final = final + side;
  printf("\nThe perimeter of the triangle is --> %f\n", final);
  // Rectangle
  printf("\nEnter length --> ");
  scanf("%f", &base);
  printf("Enter breadth --> ");
  scanf("%f", &height);
  final = base * height;
  printf("\nThe area of the rectangle is --> %f\n", final);
  final = (base + height) * 2;
  printf("The perimeter of the rectangle is --> %f\n", final);
  // Square
  printf("\nEnter side --> ");
  scanf("%f", &side);
  final = side * side;
  printf("\nThe area of the square is --> %f\n", final);
  final = 4 * side;
  printf("The perimeter of the square is --> %f\n", final);
}

using System;
delegate int Operation(int x, int y);
class Helloworld
{
    static void Main()
    {
        Operation del = Add;
        del += Multiply;
        Int result = del(4, 8);
        Console.WriteLine(result);
｝
private static int Add(int x, int y) { return x + y; }
    private static int Multiply(int x, int y) { return x * y; }
}

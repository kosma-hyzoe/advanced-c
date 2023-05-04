int sum(int num)
{
        static int s = 0;
        s += num;
        return s;
}
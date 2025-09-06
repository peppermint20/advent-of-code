// See https://aka.ms/new-console-template for more information

Part1();
Part2();

void Part1()
{
    String line;
    try
    {
        StreamReader sr = new StreamReader("./input.txt");
        line = sr.ReadLine();
        List<int> l = new List<int>();
        List<int> r = new List<int>();
        while (line != null)
        {
            String[] items = line.Split("   ");
            line = sr.ReadLine();
            l.Add(Int32.Parse(items[0]));
            r.Add(Int32.Parse(items[1]));
            // Console.WriteLine($"l: {l}\nr:{r}");
        }
        l.Sort();
        r.Sort();
        int ans = 0;
        for (int i = 0; i < l.Count; ++i)
        {
            int distance = Math.Abs(l[i] - r[i]);
            ans += distance;
        }
        Console.WriteLine($"Ans: {ans}");
    }
    catch (Exception e)
    {
        Console.WriteLine("Exception:" + e.Message);
    }
}

void Part2()
{
    String line;
    try
    {
        StreamReader sr = new StreamReader("./input.txt");
        line = sr.ReadLine();
        List<int> l = new List<int>();
        List<int> r = new List<int>();
        while (line != null)
        {
            String[] items = line.Split("   ");
            line = sr.ReadLine();
            l.Add(Int32.Parse(items[0]));
            r.Add(Int32.Parse(items[1]));
            // Console.WriteLine($"l: {l}\nr:{r}");
        }
        var result = l.Select(num => new
        {
            Number = num,
            Product = num * r.Count(x => x == num)
        });

        var ans = result.Sum(x => x.Product);

        Console.WriteLine($"Answer Part 2: {ans}");
    }
    catch (Exception e)
    {
        Console.WriteLine("Exception:" + e.Message);
    }
}

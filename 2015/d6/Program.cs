using System.IO;
using System.Text.RegularExpressions;
namespace d6;
class Program
{

    static string[] parseString(string str)
    {
        return Regex.Matches(str, @"\d+")
                        .OfType<Match>()
                        .Select(m => m.Value)
                        .ToArray();
    }

    static void p1()
    {
        StreamReader sr = new("input.txt");
        string line = sr.ReadLine();

        Int32[,] grid = new Int32[1000, 1000];
        bool containsTurnOn = line.Contains("turn on");
        bool containsTurnOff = line.Contains("turn off");
        bool containsToggle = line.Contains("toggle");

        while (line != null)
        {
            containsTurnOn = line.Contains("turn on");
            containsTurnOff = line.Contains("turn off");
            containsToggle = line.Contains("toggle");

            var nums = parseString(line);
            Int32[] dimensions = new Int32[4];

            for (int i = 0; i < nums.Length; ++i)
            {
                Int32.TryParse(nums[i], out dimensions[i]);
            }
            if (containsTurnOn)
            {
                for (int x = dimensions[0]; x <= dimensions[2]; ++x)
                {
                    for (int y = dimensions[1]; y <= dimensions[3]; ++y)
                    {
                        grid[x, y] = 1;
                    }
                }
            }
            else if (containsTurnOff)
            {
                for (int x = dimensions[0]; x <= dimensions[2]; ++x)
                {
                    for (int y = dimensions[1]; y <= dimensions[3]; ++y)
                    {
                        grid[x, y] = 0;
                    }
                }

            }
            else if (containsToggle)
            {
                for (int x = dimensions[0]; x <= dimensions[2]; ++x)
                {
                    for (int y = dimensions[1]; y <= dimensions[3]; ++y)
                    {
                        grid[x, y] = grid[x, y] ^ 1;
                    }
                }

            }

            line = sr.ReadLine();
        }
        Int32 answer = 0;
        for (int i = 0; i < 1000; ++i)
        {
            for (int j = 0; j < 1000; ++j)
            {
                if (grid[i, j] > 0)
                {
                    answer++;
                }
            }
        }
        Console.WriteLine($"Answer Part 1: {answer}");
    }

    static void p2()

    {
        StreamReader sr = new("input.txt");
        string line = sr.ReadLine();

        Int32[,] grid = new Int32[1000, 1000];
        bool containsTurnOn = line.Contains("turn on");
        bool containsTurnOff = line.Contains("turn off");
        bool containsToggle = line.Contains("toggle");

        while (line != null)
        {
            containsTurnOn = line.Contains("turn on");
            containsTurnOff = line.Contains("turn off");
            containsToggle = line.Contains("toggle");

            var nums = parseString(line);
            Int32[] dimensions = new Int32[4];

            for (int i = 0; i < nums.Length; ++i)
            {
                Int32.TryParse(nums[i], out dimensions[i]);
            }
            if (containsTurnOn)
            {
                for (int x = dimensions[0]; x <= dimensions[2]; ++x)
                {
                    for (int y = dimensions[1]; y <= dimensions[3]; ++y)
                    {
                        grid[x, y] = grid[x, y] + 1;
                    }
                }
            }
            else if (containsTurnOff)
            {
                for (int x = dimensions[0]; x <= dimensions[2]; ++x)
                {
                    for (int y = dimensions[1]; y <= dimensions[3]; ++y)
                    {
                        if (grid[x, y] > 0)
                            grid[x, y] = grid[x, y] - 1;
                    }
                }

            }
            else if (containsToggle)
            {
                for (int x = dimensions[0]; x <= dimensions[2]; ++x)
                {
                    for (int y = dimensions[1]; y <= dimensions[3]; ++y)
                    {
                        grid[x, y] = grid[x, y] + 2;
                    }
                }

            }

            line = sr.ReadLine();
        }
        Int32 answer = 0;
        for (int i = 0; i < 1000; ++i)
        {
            for (int j = 0; j < 1000; ++j)
            {
                answer += grid[i, j];
            }
        }
        Console.WriteLine($"Answer Part 2: {answer}");
    }


    static void Main(string[] args)
    {
        p1();
        p2();
    }
}

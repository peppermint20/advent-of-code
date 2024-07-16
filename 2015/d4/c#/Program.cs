using System;
using System.IO;
using System.Text;
using System.Security.Cryptography;


namespace d4;

class Program
{

    static void part1()
    {
        string input = "bgvyzdsv";
        byte[] bytes = Encoding.UTF8.GetBytes(input);
        int decimalPart = 1;
        string hexString = Convert.ToHexString(MD5.HashData(bytes));
        string ans;
        while (!hexString.StartsWith("00000") && hexString[6] != 0)
        {
            decimalPart++;
            ans = input + decimalPart.ToString();
            bytes = Encoding.UTF8.GetBytes(ans);
            hexString = Convert.ToHexString(MD5.HashData(bytes));
        }
        Console.WriteLine("Day 4 Part 1 answer {0}", decimalPart);
    }

    static void part2()
    {

        string input = "bgvyzdsv";
        byte[] bytes = Encoding.UTF8.GetBytes(input);
        int decimalPart = 1;
        string hexString = Convert.ToHexString(MD5.HashData(bytes));
        string ans;
        while (!hexString.StartsWith("000000") && hexString[7] != 0)
        {
            decimalPart++;
            ans = input + decimalPart.ToString();
            bytes = Encoding.UTF8.GetBytes(ans);
            hexString = Convert.ToHexString(MD5.HashData(bytes));
        }
        Console.WriteLine("Day 4 Part 2 answer {0}", decimalPart);

    }

    static void Main(string[] args)
    {
        part1();
        part2();
    }
}

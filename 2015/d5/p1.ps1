cat .\input.txt | grep -E "(.*[aeiou]){3,}" | grep "\(.\)\1" | grep -Ev "(ab|cd|pq|xy)" | Measure-Object

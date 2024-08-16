cat .\input.txt | grep  "\(..\).*\1" | grep "\(.\).\1"| Measure-Object

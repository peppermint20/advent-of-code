package main

import (
	"fmt"
	"os"
	"strings"
)

type Position struct {
	x int
	y int
}

// We want to find the smallest path

func main() {
	inputDirectoryPath := "../inputs/1.txt"
	dat, err := os.ReadFile(inputDirectoryPath)

	if err != nil {
		panic(err)
	}
	fmt.Println(dat)
	fileContent := string(dat)
	parts := strings.Split(fileContent, ",")

	//fmt.Println(parts)
	currentPosition := 2
	currentCoordinate := Position{0, 0}
	for i := range len(parts) {
		lhs := parts[i][0]
		rhs := parts[i][1]

		if lhs == 'L' {
			if currentPosition == '2' || currentPosition == '4' {

			}
		} else if rhs == 'R' {
		}

	}
	// currentPosition := 2
	// Read instruction -> R2
	// 2 --> rotate to 1 (2,0)
	// currentPosition = 1
	// L3 -> position 2 (2,3)
	// currentPosition = 2
	// L3 -> position 3 (-1,3)
	// currentPosition = 3
	// L3 -> position 4 (-1,0)

}

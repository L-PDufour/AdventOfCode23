package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"unicode"
)

func findFirstDigit(text string) int {
	for _, c := range text {
		if unicode.IsDigit(c) {
			return int(c - '0')
		}
	}
	return -1
}

func findLastDigit(text string) int {
	for i := len(text) - 1; i >= 0; i-- {
		if unicode.IsDigit(rune(text[i])) {
			return int(text[i] - '0')
		}
	}
	return -1
}

func main() {
	var filename string

	fmt.Print("Enter the filename: ")
	fmt.Scan(&filename)

	file, err := os.Open(filename)
	if err != nil {
		log.Fatal("Error opening file:", err)
	}
	defer file.Close()

	var sumALL int

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		firstDigit := findFirstDigit(line) * 10
		lastDigit := findLastDigit(line)
		if firstDigit != -1 && lastDigit != -1 {
			sum := firstDigit + lastDigit
			sumALL += sum
		}
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	fmt.Printf("\nSum is: %d\n", sumALL)
}

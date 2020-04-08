package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"io/ioutil"
	
	"github.com/gosimple/slug"
	"github.com/fatih/color"
)

type problemInfo struct {
	Nb string
	Nm string
	Statement string
}

func main() {
	var pi problemInfo
	pi = readInfo()
	
	path, err := createProblemDir(pi.Nm, pi.Nb)
	if err != nil {
		color.Red("Couldn't create directory: %v", err)
	}
	color.Green("Created problem directory ...\n")

	if err := fillProblemReadme(path, pi.Nm, pi.Statement); err != nil {
		color.Red("Couldn't write to problems' README.md: %v", err)
	}
	color.Blue("Wrote minimal README.md for the problem ...")

	/*
	if err := addProblemToReadme(); err != nil {
		color.Red("Couldn't add problem to README.md: %v", err)	
	}
	color.Yellow("Added problem to README.md ...\n")
	*/
}

func createProblemDir(name, number string) (string, error) {
	
	name = slug.Make(name)
	path := "../" + number + "/"

	file := name + ".go"

	if err := os.Mkdir(path, 0777); err != nil {
		return "", err
	}

	f1, err := os.Create(path + file)
	if err != nil {
		return "", err
	}
	defer f1.Close()

	f2, err := os.Create(path + "README.md")
	if err != nil {
		return "", err
	}
	defer f2.Close()

	return path, nil 
}

func fillProblemReadme(path, name , statement string) error {
	template := []byte("## " + name + "\n\n" + statement + "\n\n- - -\n\n")
	
	if err := ioutil.WriteFile(path + "README.md", template, 0777); err != nil {
		return err
	}
	
	return nil
}

func addProblemToReadme() {
	
}

func readInfo() problemInfo {
	reader := bufio.NewReader(os.Stdin)

	fmt.Printf("Adding a new problem...\n\n")
	fmt.Printf("- - - - - - - - - - - -\n\n")

	fmt.Printf("Enter problem's sequence number: ")
	number := readNewInfo(reader)

	fmt.Printf("Enter problem's name: ")
	name := readNewInfo(reader)

	fmt.Printf("Enter problem's statement: ")
	statement := readNewInfo(reader)

	return problemInfo{number, name, statement}
}

func readNewInfo(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.Replace(str, "\n", "", -1)
}

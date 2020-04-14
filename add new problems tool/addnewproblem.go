package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"

	"github.com/fatih/color"
	"github.com/gosimple/slug"
)

var LANGS = map[string]string{
	"golang": "Golang",
	"go":     "Golang",
	"python": "Python",
	"cpp":    "CPP",
	"java":   "Java",
}

var EXTENSIONS = map[string]string{
	"Golang": ".go",
	"Python": ".py",
	"CPP":    ".cpp",
	"Java":   ".java",
}

type problemInfo struct {
	Number          string
	Name            string
	Statement       string
	Url             string
	TimeComplexity  string
	SpaceComplexity string
	Lang            string
	Difficulty      string
	Tag             string
}

func main() {
	var pi problemInfo
	pi = readInfo()

	path, err := createProblemDir(pi.Name, pi.Number, pi.Lang)
	if err != nil {
		color.Red("Couldn't create directory: %v", err)
	}
	color.Green("Created problem directory ...\n")

	if err := fillProblemReadme(path, pi.Name, pi.Statement); err != nil {
		color.Red("Couldn't write to problems' README.md: %v", err)
		return
	}
	color.Blue("Wrote minimal README.md for the problem ...")

	if err := addProblemToCSV(path, pi.Name, pi.Number, pi.Url, pi.Difficulty, pi.TimeComplexity, pi.SpaceComplexity, pi.Lang, pi.Tag); err != nil {
		color.Red("Couldn't add problem to the CSV: %v", err)
		return
	}
	color.Yellow("Added problem to CSV ...\n")

	if err := generateReadme("readmetemplate.md", "problems.csv"); err != nil {
		color.Red("Couldn't add problem to global README.md: %v", err)
		return
	}
	color.Yellow("Added problem to global README.md ...\n")
}

func createProblemDir(name, number, lang string) (string, error) {

	name = slug.Make(name)
	path := fmt.Sprintf("../%s/", number)

	file := name + EXTENSIONS[lang]

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

func fillProblemReadme(path, name, statement string) error {
	template := []byte(fmt.Sprintf("## %s\n\n%s\n\n- - -\n\n", name, statement))

	if err := ioutil.WriteFile(path+"README.md", template, 0777); err != nil {
		return err
	}

	return nil
}

func addProblemToCSV(path, name, number, url, difficulty, timecomplexity, spacecomplexity, lang, tag string) error {
	line := fmt.Sprintf("%s,%s,%s,%s,%s,%s,%s,%s\n", number, name, lang, timecomplexity, spacecomplexity, difficulty, tag, url)

	f, err := os.OpenFile("problems.csv", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return err
	}
	if _, err := f.Write([]byte(line)); err != nil {
		return err
	}
	defer f.Close()

	return nil
}

func generateReadme(template, csvfile string) error {
	header, err := ioutil.ReadFile(template)
	if err != nil {
		return err
	}

	body, err := createMarkdownFromCSV(csvfile)
	if err != nil {
		return err
	}

	content := append(header, body...)

	f, err := os.OpenFile("../README.md", os.O_RDWR|os.O_CREATE|os.O_TRUNC, 0640)
	if err != nil {
		return err
	}
	defer f.Close()

	if _, err := f.Write(content); err != nil {
		return err
	}

	return nil
}

func createMarkdownFromCSV(filepath string) ([]byte, error) {
	res := []byte{}

	f, err := os.Open(filepath)
	if err != nil {
		return nil, err
	}

	defer f.Close()

	lines, err := csv.NewReader(f).ReadAll()
	if err != nil {
		return nil, err
	}

	mp := map[string][]string{}

	for _, line := range lines {
		number, _ := strconv.Atoi(line[0])
		formattedLine := fmt.Sprintf("%04d| [%s](%s)| [%s](./%s) | _O(%s)_ | _O(%s)_ | %s\n", number, line[1], line[7], line[2], line[0], line[3], line[4], line[5])

		if val, ok := mp[line[6]]; ok {
			mp[line[6]] = append(val, formattedLine)
		} else {
			mp[line[6]] = []string{formattedLine}
		}
	}

	for key, sl := range mp {
		res = append(res, []byte(fmt.Sprintf("## %s\n|  #  | Title           |  Solution       |  Time           | Space           | Difficulty    |\n|-----|---------------- | --------------- | --------------- | --------------- | ------------- |\n", key))...)
		for _, str := range sl {
			res = append(res, []byte(str)...)
		}
	}
	return res, nil
}

func readInfo() problemInfo {
	reader := bufio.NewReader(os.Stdin)

	fmt.Printf("Adding a new problem...\n\n")
	fmt.Printf("- - - - - - - - - - - -\n\n")

	fmt.Printf("Enter problem's URL: ")
	url := readNewInfo(reader)

	fmt.Printf("Enter problem's sequence number: ")
	number := readNewInfo(reader)

	fmt.Printf("Enter problem's name: ")
	name := readNewInfo(reader)

	fmt.Printf("Difficulty of the problem: ")
	difficulty := readNewInfo(reader)

	fmt.Printf("Enter problem's statement: ")
	statement := readNewInfo(reader)

	fmt.Printf("Time complexity of the solution: ")
	timecomplexity := readNewInfo(reader)

	fmt.Printf("Space complexity of the solution: ")
	spacecomplexity := readNewInfo(reader)

	fmt.Printf("Programming Language: ")
	lang := readNewInfo(reader)

	fmt.Printf("Tag: ")
	tag := readNewInfo(reader)

	return problemInfo{number, name, statement, url, timecomplexity, spacecomplexity, LANGS[strings.ToLower(lang)], difficulty, tag}
}

func readNewInfo(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.Replace(str, "\n", "", -1)
}

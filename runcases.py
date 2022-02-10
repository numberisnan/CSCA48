import time
import os
import sys
import subprocess

EXENAME = "temp"

args = sys.argv
filepath = args[1]
filetype = filepath.split(".")[1]
filename = os.path.basename(filepath).split(".")[0]
testfilepath = os.path.join(os.path.dirname(filepath), filename + ".tc")

# compile
if filetype == "cpp":
    print("Type: C++")
    print("Compiling " + filepath)
    os.system("g++ -std=c++11 ./" + filepath + " -o " + EXENAME + ".exe")
    print("Done compiling!")
elif filetype == "c":
    print("Type: C")
    print("Compiling " + filepath)
    os.system("gcc -Wall ./" + filepath + " -o " + EXENAME + ".exe")
    print("Done compiling!")
elif filetype == "py":
    print("Type: Python")
print()


class Case:
    def __init__(self, data, result):
        self.data = data
        self.result = ""
        for line in result:
            self.result += line

    def tostring(self):
        print("data: " + str(self.data))
        print("result: " + str(self.result))

    def createfile(self):
        if os.path.exists("temp.txt"):
            os.remove("temp.txt")
        with open("temp.txt", "w") as file:
            for line in self.data:
                file.write(line)


# get test cases
try:
    with open(testfilepath) as file:
        testStrings = file.readlines()
except FileNotFoundError:
    # create the file and end the program
    print("Test file " + testfilepath + " not found. Creating...")
    file = open(testfilepath, 'w')
    file.write("0\n1\n")
    print("Test file created! Please add test cases")
    os.system("write ./" + testfilepath)
    sys.exit(0)


testcases = []
ln = 2
timeLimit = float(testStrings[1])
for i in range(int(testStrings[0])):
    testdata = []
    results = []
    while "begin results" not in testStrings[ln]:
        testdata.append(testStrings[ln])
        ln += 1
    ln += 1
    while "end case" not in testStrings[ln]:
        results.append(testStrings[ln])
        ln += 1
    ln += 1
    testcases.append(Case(testdata, results))

tc = 1
status = []
for case in testcases:
    # print(case.tostring())
    case.createfile()
    # time.sleep(0.1)
    start = time.time()
    res = ""
    try:
        if filetype == "cpp" or filetype == "c":
            res = subprocess.check_output("temp.exe < temp.txt", shell=True, text=True)
        elif filetype == "py":
            res = subprocess.check_output("python -W ignore " + args[1] + " < temp.txt", shell=True, text=True)
    except subprocess.CalledProcessError as e:
        print(e)
        status.append("RTE")
        continue
    end = time.time()
    if res == "":
        print("No output received")
    else:
        print(res)
    print("Case " + str(tc) + ": ", end="")
    if res.strip() == case.result.strip():
        print("correct")
        if end-start > timeLimit:
            status.append("TLE (" + str(round(end-start, 2)) + "s)")
        else:
            status.append("AC")
    else:
        print("incorrect")
        status.append("WA")
    print("Time: " + str(end-start) + "s\n")

    tc += 1

print("Statuses--------------")
i = 1
for code in status:
    print("Test Case " + str(i) + ":       " + code)
    i += 1


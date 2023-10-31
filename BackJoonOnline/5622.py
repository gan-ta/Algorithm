if __name__ == "__main__":
    temp = input()

    dict = {}
    dict["A"] = 3
    dict["B"] = 3
    dict["C"] = 3

    dict["D"] = 4
    dict["E"] = 4
    dict["F"] = 4

    dict["G"] = 5
    dict["H"] = 5
    dict["I"] = 5

    dict["J"] = 6
    dict["K"] = 6
    dict["L"] = 6

    dict["M"] = 7
    dict["N"] = 7
    dict["O"] = 7

    dict["P"] = 8
    dict["Q"] = 8
    dict["R"] = 8
    dict["S"] = 8

    dict["T"] = 9
    dict["U"] = 9
    dict["V"] = 9

    dict["W"] = 10
    dict["X"] = 10
    dict["Y"] = 10
    dict["Z"] = 10

    res = 0
    for c in temp:
        res += dict[c]

    print(res)
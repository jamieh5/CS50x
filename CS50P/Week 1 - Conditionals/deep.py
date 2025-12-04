def deep_thought(text):
    if text == "forty two" or text == "forty-two" or text == "42":
        return("Yes")
    else:
        return("No")

def main():
    output = deep_thought(input("What is the Answer to the Great Question of Life, the Universe, and Everything? ").lower().strip())
    print(output)


if __name__ == "__main__":
    main()

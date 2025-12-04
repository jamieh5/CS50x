def greeting(text):
    if text == "hello":
        return 0
    elif text[0] == "h":
        return 20
    else:
        return 100

def main():
    output = greeting(input("Greeting: ").strip())
    print(f"${output}")

if __name__ == "__main__":
    main()

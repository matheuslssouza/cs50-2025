def coleman(L, S):
    index = (0.0588 * L) - (0.296 * S) - 15.8
    return round(index)


def main():
    text = input("Text: ")

    letras = sum(1 for c in text if c.isalpha())

    palavras = text.split()
    L = (letras / len(palavras))*100

    sentences = text.count(".") + text.count("!") + text.count("?")

    S = (sentences / len(palavras))*100

    index = coleman(L, S)
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


main()
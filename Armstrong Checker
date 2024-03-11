while True:
    Number = input("Enter your number to check if it's an Armstrong number (type 'exit' to quit): ")

    if Number.lower() == 'exit': #The Choice of exiting the program
        print("Exiting the program.")
        break

    Power = len(Number)  #The power is equal to the num of digits in the input number
    Armstrong_sum = sum(int(digit) ** Power for digit in Number) #armstrong number checking

    if int(Number) == Armstrong_sum:
        print(Number, "is an Armstrong number")
    else:
        print(Number, "is not an Armstrong number")


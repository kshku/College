qa = [(["Hi"], "Hello"),
      (["How are you?", "How do you do?"], "I am fine!"),
      (["Are you studying?", "Are you doing any job?"], "Yes, I am!"),
      (["What is your name?"], "My name is StupidBot"),
      (["What did you do yesterday?"], "I saw bahubail 5 times!"),
]

print("Simple Question and Answering Program")
print("-------------------------------------")
print("You may ask one of these questions:")

for q, a in qa:
    print(f"{q[0]}")

print("Quit")

while True:
    print()
    question = input("Enter the prompt: ").lower()
    if question == 'quit':
        break
    else:
        for q, a in qa:
            if question in [varient.lower() for varient in q]:
                print(a)
                if a == "My name is StupidBot":
                    print("Nice to meet you,", input("Enter your name: "))
                break
        else:
            print("I don't understand what you said")

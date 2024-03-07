def chatbot(user_input):
    if "hello" in user_input.lower():
        return "Hi there! How can I assist you today?"
    elif "hii" in user_input.lower():
        return "Hi there! How can I assist you today?"
    elif "how are you" in user_input.lower():
        return "I'm just a chatbot, but thanks for asking!"
    elif "who is the prime minister of india" in user_input.lower():
        return "Narendar modi"
    elif "bubye" in user_input.lower():
        return "Goodbye! Have a great day!"
    elif "what are the colours of rainbow" in user_input.lower():
        return " red, orange, yellow, green, cyan, blue, violet"
    elif "interships or jobs which is better " in user_input.lower():
        return "both are good for experience"
    else:
        return "I'm sorry, I didn't understand that. Can you please rephrase?"

def main():
    print("Welcome to the AI based Chatbot!, Type bubye to exit")
    print("You can start chatting with the bot.")

    while True:
        user_input = input("You: ")
        response = chatbot(user_input)
        print("Chatbot:", response)

        if user_input.lower() == "bubye":
            break

if __name__ == "__main__":
    main()

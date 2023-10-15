import random


def generate_halloween_message():
    """
    Generate a random Halloween message.

    :return: Random Halloween message.
    :rtype: str
    """
    adjectives = ["spooky", "creepy", "ghastly", "frightening", "haunting"]
    nouns = ["ghost", "witch", "zombie", "vampire", "monster"]
    actions = ["haunts", "scares", "chases", "bewitches", "bites"]

    adjective = random.choice(adjectives)
    noun = random.choice(nouns)
    action = random.choice(actions)

    message = f"A {adjective} {noun} {action} you!"
    return message


if __name__ == "__main__":
    halloween_message = generate_halloween_message()
    print(halloween_message)

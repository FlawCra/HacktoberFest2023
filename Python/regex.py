import re

def extract_phone_numbers_and_emails(text):
    phone_pattern = r'\b\d{3}[-.\s]?\d{3}[-.\s]?\d{4}\b'
    email_pattern = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,7}\b'

    phones = re.findall(phone_pattern, text)
    emails = re.findall(email_pattern, text)

    return phones, emails

if __name__ == "__main__":
    text = """
    Please contact John at 123-456-7890 or email him at john@example.com.
    For support, call our support team at 555.555.5555 or email support@company.com.
    """

    phone_numbers, email_addresses = extract_phone_numbers_and_emails(text)

    print("Phone Numbers:")
    for phone in phone_numbers:
        print(phone)

    print("\nEmail Addresses:")
    for email in email_addresses:
        print(email)

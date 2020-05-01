"""
    Scrieti o functie care converteste un sir de caractere din UpperCamelCase in lowercase_with_underscores
"""

import sys

def camel_case_to_lower_case_underscore(string):
    """
    Split string by upper case letters.

    F.e. useful to convert camel case strings to underscore separated ones.

    @return words (list)
    """
    words = []
    from_char_position = 0
    for current_char_position, char in enumerate(string):
        """
            current_char_position reprezinta indexul
            char reprezinta caraterul de pe pozitia indexului
            acest lucru este posibil doar cu enumerate()
        """
        if char.isupper() and from_char_position < current_char_position:
            words.append(string[from_char_position:current_char_position].lower())
            from_char_position = current_char_position
    words.append(string[from_char_position:].lower())
    return '_'.join(words)


print(camel_case_to_lower_case_underscore('LowercaseWithUnderscores'))
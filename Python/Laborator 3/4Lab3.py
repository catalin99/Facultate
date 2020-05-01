"""
    Fie functia build_xml_element care primeste urmatorii parametri: tag, content si
    elemente cheie-valoare date ca parametri cu nume. Sa se construiasca si sa se
    returneze un string care reprezinta elementul XML aferent. Exemplu:
    build_xml_element("a", "Hello there", href="http://python.org", _class="my-link",
    id="someid") => "<a href=\"http://python.org\" _class=\"my-link\" id=\"someid\">Hello
    there</a>"
"""

def build_xml_element(tag, content, **kwargs):
    s = "<" + tag + " "
    for k in kwargs.keys():
        s = s + k + "=" + kwargs[k] + " "
    s = s[:-1] + ">" + content + "</" + tag + ">"
    return s

print(build_xml_element("a", "Hello there", href="http://python.org", _class="my-link",
    id="someid"))
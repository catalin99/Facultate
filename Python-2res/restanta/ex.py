
import zeep

fd = open("ex1.txt", "rb").read()
url = "http://nlptools.info.uaic.ro/WebPosRo/PosTaggerRoWS?wsdl"
client = zeep.Client(wsdl=url)
print(client.service.parseSentence_XML(fd))

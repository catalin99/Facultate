from pandas import DataFrame
import json
import matplotlib.pyplot as plt

def get_number_of_viewers_by_activity_id(color,activity_id, *jsons):
    dict = {}
    filess = []
    viewer_count = []
    game_id = []
    for file in jsons:
        with open(file) as fd:
            data = json.load(fd)
            d = {"viewer_count": [], "game_id": []}
            for f in data["data"]:
                if f["game_id"] == activity_id:
                    d["viewer_count"].append(f["viewer_count"])
                    d["game_id"].append(f["game_id"])
                    viewer_count.append(f["viewer_count"])
                    game_id.append(f["game_id"])
                    file_name = file.split('-')[1][9:11] + ":" + file.split('-')[1][11:13]
                    filess.append(file_name)
            dict[file] = d

    abc = json.dumps(dict)

    Data = {'Viewers': viewer_count,
            'Games': game_id,
            'Files': filess
            }

    df = DataFrame(Data)
    ax = plt.gca()

    df.plot(kind='line', x='Files', y='Viewers', color=color, ax=ax)
    plt.show()

    return abc


if __name__ == '__main__':
    # 512710 CODMW
    # 29595 DOTA2
    abc = get_number_of_viewers_by_activity_id("blue","512710", "top20_streams-20200523_1421.json",
                                               "top20_streams-20200524_2355.json",
                                               "top20_streams-20200525_1622.json",
                                               "top20_streams-20200526_2259.json",
                                               "top20_streams-20200527_1043.json")

    ads = get_number_of_viewers_by_activity_id("red","29595", "top20_streams-20200523_1421.json",
                                               "top20_streams-20200524_2355.json",
                                               "top20_streams-20200525_1622.json",
                                               "top20_streams-20200526_2259.json",
                                               "top20_streams-20200527_1043.json")
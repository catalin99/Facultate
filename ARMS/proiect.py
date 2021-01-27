import json
import requests
from datetime import date, datetime
import json as JSON
import pandas as pd

# Pentru luat OAUTH token
# https://id.twitch.tv/oauth2/authorize
#     ?client_id=n23ybd5bk9rr48r0cr669laek7b4pj
#     &redirect_uri=http://localhost
#     &response_type=token
#     &scope=analytics:read:games


CLIENT_ID = 'n23ybd5bk9rr48r0cr669laek7b4pj'
OAUTH_TOKEN = '0f0c2fz1ighm085hc97dqagbb53h64'
HEADERS = {
    'Client-ID': CLIENT_ID,
    'Authorization': 'Bearer ' + OAUTH_TOKEN
}
BASE_URL = 'https://api.twitch.tv/helix/'
TOP_GAMES_URL = 'https://api.twitch.tv/helix/games/top'
TOP_STREAMS_URL = 'https://api.twitch.tv/helix/streams'
GAMES_URL = 'https://api.twitch.tv/helix/games'
USERS_FOLLOWERS_URL = "https://api.twitch.tv/helix/users/follows"
USERS_FOLLOWED_URL = "https://api.twitch.tv/helix/users/follows"
USERS_URL = "https://api.twitch.tv/helix/users"


def get_response(input_url, query):
    url = input_url + query
    response = requests.get(url, headers=HEADERS)
    return response


def print_response(response):
    response_json = response.json()
    printed_response = json.dumps(response_json, indent=4)
    print(printed_response)


def export_response(response, title):
    response = response.json()
    today = date.today().strftime("%Y%m%d")
    time = datetime.now().strftime("%H%M")
    # filename = title + "-" + today + "_" + time + ".json"
    filename = title + ".json"
    with open(filename, "w", encoding='utf-8') as fd:
        json.dump(response, fd, indent=4)


def get_top_20_streams():
    response = get_response(TOP_STREAMS_URL, '')
    export_response(response, "top20_streams")
    return response


def get_top_20_activities():
    response = get_response(TOP_GAMES_URL, '')
    export_response(response, "top20_activities")
    return response


# TODO:Top 20 pe un anumit joc/activitate
def get_top_20_streams_by_activity(id_activity, name_activity):
    response = get_response(TOP_STREAMS_URL, '?game_id=' + id_activity)
    export_response(response, "top20_streams_" + name_activity)
    # print_response(response)


def get_users_ids_from_json(json):
    topIDs = []
    with open(json) as data_file:
        data = JSON.load(data_file)
        for v in data["data"]:
            topIDs.append((v["user_id"],v["user_name"]))
    return topIDs


def get_user_followers(user):
    response = get_response(USERS_FOLLOWERS_URL, '?to_id='+user[0])
    export_response(response, "Top_20_followers/top20_followers_" + user[1])


def get_user_followed_by(user):
    response = get_response(USERS_FOLLOWED_URL, '?from_id='+user[0])
    export_response(response, "Top_20_followed/top20_followed_by_" + user[1])


def get_users_nodes_from_all_jsons(users):
    userIDs = []
    for user in users:
        if not user.__contains__(user[0]):
            userIDs.append(user[0])
        with open("Top_20_followers/top20_followers_" + user[1]+".json") as data_file:
            data = JSON.load(data_file)
            for v in data["data"]:
                if not userIDs.__contains__(v["from_id"]):
                    userIDs.append(v["from_id"])
        with open("Top_20_followed/top20_followed_by_" + user[1]+".json") as data_file:
            data = JSON.load(data_file)
            for v in data["data"]:
                if not userIDs.__contains__(v["to_id"]):
                    userIDs.append(v["to_id"])
    print(len(userIDs))
    f = open("user_data.csv", "a")
    f.write("id,username,type,broadcaster_type,views\n")
    print("id,username,type,broadcaster_type,views")

    for userid in userIDs:
        response = get_response(USERS_URL, '?id=' + userid)
        details = response.json()["data"][0]
        f.write(details["id"]+","+details["display_name"]+","+details["type"]+','+details["broadcaster_type"]+","+str(details["view_count"])+'\n')
        print(details["id"]+","+details["display_name"]+","+details["type"]+','+details["broadcaster_type"]+","+str(details["view_count"]))
    f.close()


def get_user_edges_from_all_jsons(users):
    validIDs = []
    with open('user_data.csv') as fp:
        line = fp.readline()
        cnt = 1
        while line:
            fields = line.split(',')
            validIDs.append(fields[0])
            line = fp.readline()
            cnt += 1
    f = open("user_edges.csv", "a")
    f.write("Source,Target,Type,Weight\n")
    for user in users:
        with open("Top_20_followers/top20_followers_" + user[1] + ".json") as data_file:
            data = JSON.load(data_file)
            for v in data["data"]:
                if validIDs.__contains__(v["from_id"]) and validIDs.__contains__(v["to_id"]):
                    f.write(v["from_id"]+","+v["to_id"]+",Directed,0.2\n")
        with open("Top_20_followed/top20_followed_by_" + user[1] + ".json") as data_file:
            data = JSON.load(data_file)
            for v in data["data"]:
                if validIDs.__contains__(v["from_id"]) and validIDs.__contains__(v["to_id"]):
                    f.write(v["from_id"]+","+v["to_id"]+",Directed,0.2\n")
    f.close()

# TODO:ceva despre utilizatori, dar nu stiu ce


if __name__ == '__main__':
    # helix = twitch.Helix(client_id=CLIENT_ID, bearer_token=OAUTH_TOKEN)

    # top_20_streams = get_top_20_streams()
    # top_20_activities = get_top_20_activities()
    #
    # get_top_20_streams_by_activity('516575', "VALORANT")

    # df = pd.read_json(r'W:\Faculty\ARMS\top20_activities-20200523_1421.json')
    # export_csv = df.to_csv(r'W:\Faculty\ARMS\top20_activities-20200523_1421.csv', index=None, header=True)
    # df = pd.read_json(r'W:\Faculty\ARMS\top20_streams-20200523_1421.json')
    # export_csv = df.to_csv(r'W:\Faculty\ARMS\top20_streams-20200523_1421.csv', index=None, header=True)
    # VALORANT - 516575
    # Grand Theft Auto V - 32982
    # Dota 2 - 29595

    users = get_users_ids_from_json('top20_streams-20200527_1043.json')
    # for user in users:
    #     get_user_followers(user)
    #     get_user_followed_by(user)
    # get_users_nodes_from_all_jsons(users)
    get_user_edges_from_all_jsons(users)

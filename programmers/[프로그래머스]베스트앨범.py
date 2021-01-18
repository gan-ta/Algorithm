def solution(genres, plays):
    answer = []
    genre_dict = dict()
    pick_set = set()
    acc_dict = dict()

    for i in range(len(genres)):
        genre = genres[i]
        play = plays[i]

        if genre not in genre_dict.keys():
            genre_dict[genre] = [[i, play]]
            acc_dict[genre] = play
        else:
            genre_dict[genre].append([i, play])
            acc_dict[genre] += play

    acc_list = sorted(acc_dict.items(), key=lambda x: -x[1])

    for search in acc_list:
        genre_dict[search[0]].sort(key=lambda x: (-x[1], x[0]))
        for i, v in enumerate(genre_dict[search[0]]):
            if i == 2:
                break
            answer.append(v[0])

    return answer
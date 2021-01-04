def tuning(music_):
    music_ = music_.replace('C#', 'c')
    music_ = music_.replace('D#', 'd')
    music_ = music_.replace('F#', 'f')
    music_ = music_.replace('G#', 'g')
    music_ = music_.replace('A#', 'a')
    return music_


def calctime(musicinfo_):
    start = musicinfo_[0].split(':')
    end = musicinfo_[1].split(':')
    hour = 1 * (int(end[0]) - int(start[0]))
    if hour == 0:
        total = int(end[1]) - int(start[1])
    else:
        total = (60 * (hour - 1)) + int(end[1]) + (60 - int(start[1]))

    return total


def solution(m, musicinfos):
    answer = []
    m = tuning(m)

    for i, musicinfo in enumerate(musicinfos):
        musicinfo = tuning(musicinfo)
        musicinfo = musicinfo.split(',')
        time = calctime(musicinfo)

        # 길이가 시간보가 긴 경우
        # 나는 while문을 돌렸기 떄문에 상대적으로 시간이 길게 먹혔을 수 있음
        if len(musicinfo[3]) >= time:
            melody = musicinfo[3][0:time]
        else:
            a = time // len(musicinfo[3])
            b = time % len(musicinfo[3])

            melody = musicinfo[3] * a + musicinfo[3][0:b]

        # 순서, 길이, 제목 순으로 저장
        if m in melody:
            answer.append([i, time, musicinfo[2]])

    if len(answer) == 0:
        return '(None)'
    else:
        answer.sort(key=lambda x: (-x[1], x[0]))
        return answer[0][2]

    return answer
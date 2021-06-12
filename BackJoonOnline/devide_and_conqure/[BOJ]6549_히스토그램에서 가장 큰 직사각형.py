global hist_list
import sys
sys.setrecursionlimit(10**7)

# l 부터 r까지 보고 있음
def check_histogram(l, r):
    size = r - l + 1
    global hist_list

    if size == 1: # l 과 r이 같을 때
        return hist_list[l]

    # 해당 히스토그램의 조사 시작
    mid = (l + r) // 2

    lptr = mid
    rptr = mid + 1

    # 중간 길이 조사
    height = min(hist_list[mid], hist_list[mid + 1])
    ans = height * 2

    # 중간을 기준으로 탐욕적인 방법으로 작은 길이를 찾아 나감
    while l < lptr or rptr < r:
        left_height = -1
        right_height = -1

        if lptr - 1 >= l:  # 작은 것이 안나오면 계속 옆으로
            left_height = hist_list[lptr - 1]
        if rptr + 1 <= r:
            right_height = hist_list[rptr + 1]

        if left_height < right_height:
            rptr += 1
            height = min(height, hist_list[rptr])
        else:
            lptr -= 1
            height = min(height, hist_list[lptr])

        area = (rptr - lptr + 1) * height

        ans = max(ans, area)

    ans = max(ans, check_histogram(l, mid))
    ans = max(ans, check_histogram(mid + 1, r))

    return ans


if __name__ == '__main__':

    global hist_list

    while True:
        hist_list = input()

        if hist_list == '0':
            break

        hist_list = list(map(int, hist_list.split()))
        hist_count = hist_list[0]
        hist_list = hist_list[1:]

        res = check_histogram(0, hist_count - 1)
        print(res)

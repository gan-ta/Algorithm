N = int(input())
cards = list(map(int, input().split(" ")))
M = int(input())
targets = list(map(int, input().split(" ")))

sorted_cards = sorted(cards)

card_count = {}

for card in cards:
    if card not in card_count.keys():
        card_count[card] = 1
    else:
        card_count[card] += 1


def search(aim, start, end):
    if start > end:
        return 0

    mid = (start + end) // 2

    if aim == sorted_cards[mid]:
        return card_count[sorted_cards[mid]]
    elif aim > sorted_cards[mid]:
        return search(aim, mid + 1, end)
    else:
        return search(aim, start, mid - 1)


res = []
for target in targets:
    res.append(str(search(target, 0, len(cards) - 1)))

print(" ".join(res).strip())

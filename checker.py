state = []
target = []


insts = [e.lower() for e in input().split()]

input()

state += ([int(e) for e in input().split()])

width = len(state)

for _ in range(width - 1):
    state += ([int(e) for e in input().split()])

input()

for _ in range(width):
    target += ([int(e) for e in input().split()])

zero_indx = state.index(0)


def print_state(board):
    for i in range(width):
        for j in range(width):
            print(f"{board[i * width + j]:2}", end=" ")
        print()

for i in range(len(insts)):
    if insts[i] == "u":
        if zero_indx - width < 0:
            print("\033[91merror :\033[0m  illegal move 'U' while state is :")
            print_state(state)
            break
        else:
            state[zero_indx - width], state[zero_indx] = state[zero_indx], state[zero_indx - width]
            zero_indx = zero_indx - width
    elif insts[i] == "d":
        if zero_indx + width >= width * width:
            print("\033[91merror :\033[0m  illegal move 'D' while state is :")
            print_state(state)
            break
        else:
            state[zero_indx + width], state[zero_indx] = state[zero_indx], state[zero_indx + width]
            zero_indx = zero_indx + width
    elif insts[i] == "l":
        if zero_indx % width - 1 < 0:
            print("\033[91merror :\033[0m  illegal move 'L' while state is :")
            print_state(state)
            break
        else:
            state[zero_indx  - 1], state[zero_indx] = state[zero_indx], state[zero_indx - 1]
            zero_indx = zero_indx - 1
    elif insts[i] == "r":
        if zero_indx % width + 1 >= width:
            print("\033[91merror :\033[0m  illegal move 'R' while state is :")
            print_state(state)
            break
        else:
            state[zero_indx  + 1], state[zero_indx] = state[zero_indx], state[zero_indx + 1]
            zero_indx = zero_indx + 1



print("\033[92mSUCCESS\033[0m" if state == target else "\033[91mFAIL\033[0m")
print("state : ")
print_state(state)
print("*****\ntarget :")
print_state(target)


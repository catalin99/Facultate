

def generate_rare_array(filename):
    dimens = 0
    rare_array = []
    with open(filename) as file:
        dimens = int(file.readline())
        data = file.readline()
        while data:
            values = data.split(", ")
            values[2] = values[2][:-1]
            rare_array.append(set())
            # if rare_array.__len__() > int(values[1]):
            modified = False
            for elem in rare_array[int(values[1])]:
                if elem[1] == int(values[2]):
                    elem_to_list = list(elem)
                    elem_to_list[0] += float(values[0])
                    rare_array[int(values[1])].remove(elem)
                    rare_array[int(values[1])].add((elem_to_list[0], elem_to_list[1]))
                    modified = True
                    break
            if not modified:
                # if rare_array[int(values[1])].__len__() <= 10:
                rare_array[int(values[1])].add((float(values[0]), int(values[2])))
                # else:
                #     print("err at line: ", int(values[1]))
            # else:
            #     rare_array.append({(float(values[0]), int(values[2]))})
            data = file.readline()
    return rare_array, dimens


arrayA = generate_rare_array("a.txt")
print("a.txt: ", arrayA[1])
# for i in arrayA[0]:
#     print(i)

arrayB = generate_rare_array("b.txt")
print("b.txt: ", arrayB[1])
# for i in arrayB[0]:
#     print(i)

# print("dimens A: ", len(arrayA[0]))
# print("dimens B: ", len(arrayB[0]))


def calculate_a_plus_b(A, B):
    sum_array = []
    for index in range(0, A.__len__()):
        set_line = set()
        for elemA in A[index]:
            found = False
            for elemB in B[index]:
                if elemA[1] == elemB[1]:
                    found = True
                    set_line.add((elemA[0]+elemB[0], elemA[1]))  # sum where A[i][j] and B[i][j] != 0
                    break
            if not found:
                set_line.add((elemA[0], elemA[1]))  # sum where A[i][j] !=0 and B[i][j] == 0
        for elemB in B[index]:
            found = False
            for elemA in A[index]:
                if elemA[1] == elemB[1]:
                    found = True
                    break
            if not found:
                set_line.add((elemB[0], elemB[1]))  # sum where A[i][j] ==0 and B[i][j] != 0
        sum_array.append(set_line)
    return sum_array


AplusB = calculate_a_plus_b(arrayA[0], arrayB[0])
# print("a + b: ")
# for i in AplusB:
#     print(i)


def calculate_a_mul_b(A, B):
    mul_array = []
    for index in range(0, A.__len__()):
        mul_array.append(set())
        for elemA in A[index]:
            elem_prod = 0
            for elemB in B[elemA[1]]:  # in matricea B mergem pe linia echivalenta cu coloana pe care suntem in A
                found = False
                for elem in mul_array[index]:
                    tuple_to_list = list(elem)
                    if tuple_to_list[1] == elemB[1]:
                        tuple_to_list[0] += elemA[0]*elemB[0]
                        mul_array[index].remove(elem)
                        mul_array[index].add((tuple_to_list[0],tuple_to_list[1]))
                        found = True
                        break
                if not found:
                    mul_array[index].add((elemA[0]*elemB[0], elemB[1]))
    return mul_array


AmulB = calculate_a_mul_b(arrayA[0], arrayB[0])
# print("a + b: ")
# # # for i in AmulB:
# # #     print(i)

checkMul = generate_rare_array("mul.txt")
checkPlus = generate_rare_array("plus.txt")
EPSILON = 10 ** -5


def check(my_result, expected_result):
    wrong = 0
    for index in range(0, my_result.__len__()):
        line = my_result[index]
        line_correct = True
        for col in line:
            found = False
            for elem in expected_result[0][index]:
                if elem[1] == col[1] and abs(elem[0] - col[0]) < EPSILON:
                    found = True
                    break
            line_correct = found
        if line_correct:
            # print(index, ": correct")
            None
        else:
            print(index, ": wrong")
            print("myRes: ", line)
            print("expectedRes: ", expected_result[0][index])
            wrong += 1
    return wrong


print("\nMul Errors: ", check(AmulB, checkMul))
print("\nPlus Errors: ", check(AplusB, checkPlus))
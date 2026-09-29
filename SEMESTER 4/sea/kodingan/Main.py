    import os
    from Game import *
    from tabulate import tabulate

    while True:
        os.system("cls")
        selected = menu()
        if selected == 1:
            score = Game().start()
            os.system("cls")
            print("===== Game Over =====")
            print("> Final score:", score)
            name = input("> Enter your name: ")
            Score().insert(name, score)
        elif selected == 2:
            os.system("cls")
            data = Score().getAllData()
            print("================================")
            print("|          High Score          |")
            if len(data) == 0:
                print("================================")
                print("|            No Data           |")
                print("================================")
            else:
                print(tabulate(data, headers=["Pos", "Name", "Score"], tablefmt="psql", showindex=range(1, len(data)+1)))
            os.system("pause")
        elif selected == 3:
            print("=====================================================")
            print(" Good Bye ~")
            os.system("pause")
            os.system("cls")
            break

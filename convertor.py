import re
string = """
    cout << "┌────────────────────────────────────────────────────────────────────────┐" << endl;
    cout << "│ __________      .__  .__                                               │" << endl;
    cout << "│  \\______   \\____ |  | |__| ____   ____   _____   ____________ _______  │" << endl;
    cout << "│   |     ___/  _ \\|  | |  |/    \\ /  _ \\ /     \\  \\_  __ \\__  \\\\_  __ \\ │" << endl;
    cout << "│   |    |  (  <_> |  |_|  |   |  (  <_> |  Y Y  \\  |  | \\// __ \\|  | \\/ │" << endl;
    cout << "│   |____|   \\____/|____|__|___|  /\\____/|__|_|  /  |__|  (____  |__|    │" << endl;
    cout << "│                               \\/             \\/              \\/        │" << endl;
    cout << "└────────────────────────────────────────────────────────────────────────┘" << endl << endl << endl;

    do {
        cout << "                    ┌─────────┰───────────────────────────┐" << endl;
        cout << "                    │ Optiune │        Operatie           │" << endl;
        cout << "                    ├─────────╀───────────────────────────┤" << endl;
        cout << "                    │    1    │ Citirea polinomului       │" << endl;
        cout << "                    │    2    │ Scrierea polinoumului     │" << endl;
        cout << "                    │    3    │ Valoarea in punctul x     │" << endl;
        cout << "                    │    4    │    Inmultirea cu scalar   │" << endl;
        cout << "                    │    5    │ Aduanarea a doua polinoame│" << endl;
        cout << "                    │    e    │        Iesire             │" << endl;
        cout << "                    └─────────┴───────────────────────────┘" << endl << endl;
        cout << "                                    OPTIUNE: ";
        cin >> input;
        cout << endl;
"""

original = ['─', '│', '┌', '┐', '└', '┘', '╀', '┴', '├', '┰', '┤']
replaceWith = ['\x1b(0\x71\x1b(B', '\x1b(0\x78\x1b(B', '\x1b(0\x6c\x1b(B', '\x1b(0\x6b\x1b(B', '\x1b(0\x6d\x1b(B',
 '\x1b(0\x6a\x1b(B', '\x1b(0\x6e\x1b(B', '\x1b(0\x76\x1b(B', '\x1b(0\x74\x1b(B', '\x1b(0\x77\x1b(B', '\x1b(0\x75\x1b(B']

for i in range (0, len(original) - 1):
    string = string.replace(original[i], re.escape(replaceWith[i]))

print (repr(string))
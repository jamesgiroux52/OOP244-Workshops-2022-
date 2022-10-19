Dictionary word[10];
		Dictionary d;
		string convertToString(filename);
		fstream f(filename, ios::in);

		if (f.is_open()) {
			string temp;
			int wordPos = 0;
			int defPos = 0;
			bool flag = true;

			getline(f, temp);
			trim(temp);

			while (f) {
				if (flag = false) {
					d[wordPos].word.word = temp;
					cout << "Word: " << d[wordPos].word.word << endl;
					flag = true;
				}


				while (flag && f) {
					getline(f, d[defPos].type, ':');
					trim(d[defPos].type);
					cout << "Type: " << d[defPos].type << endl;

					getline(f, d[defPos].definition, '\n');  
					trim(d[defPos].definition);
					cout << "Def: " << d[defPos].definition << endl;
					defPos++;
					getline(f, temp);
					if (temp.empty()) {
						getline(f, temp);
						flag = false;
					}

				}

			}
			f.close();
			return 0;
		} else {
			return 1;
		}
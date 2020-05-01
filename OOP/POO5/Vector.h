#pragma once
#define MAX_SIZE 100

template <class Template>
class Vector {
private:
	Template zet[MAX_SIZE];
	unsigned int len = 0;

private:
	void Swap(Template &x, Template &y) {
		Template aux = x;
		x = y;
		y = aux;
	}

public:
	void Print() {
		for (unsigned int i = 0; i < len; i++) {
			cout << zet[i] << " ";
		}
		cout << endl;
	}
	void PushBack(Template x) {
		zet[len++] = x;
	}

	void InsertAtPos(Template x, unsigned int pos) {
		if (pos > len)
		{
			cout << "Ai incercat sa inserezi pe o pozitie invalida";
			return;
		}
		len++;
		for (unsigned int i = len; i > pos; i--) {
			zet[i] = zet[i - 1];
		}
		zet[pos] = x;
	}

	void EraseAtPos(unsigned int pos) {
		if (pos > len)
		{
			cout << "Ai incercat sa stergi de pe o pozitie invalida";
			return;
		}
		for (unsigned int i = pos; i < len; i++)
			zet[i] = zet[i + 1];
		len--;
	}

	Template AtPos(unsigned int pos) {
		return zet[pos];
	}

	void Sort() {
		bool sorted;
		do {
			sorted = true;
			for (unsigned int i = 0; i < len - 1; i++) {
				if (zet[i] > zet[i + 1]) {
					Swap(zet[i], zet[i + 1]);
					sorted = false;
				}
			}
		} while (!sorted);
	}

};

template <>
class Vector<const char*> {
private:
	const char* zet[MAX_SIZE];
	unsigned int len = 0;

private:
	void Swap(const char* &x, const char* &y) {
		const char* aux = x;
		x = y;
		y = aux;
	}

public:
	void Print() {
		for (unsigned int i = 0; i < len; i++) {
			cout << zet[i] << " ";
		}
		cout << endl;
	}
	void PushBack(const char* x) {
		zet[len++] = x;
	}

	void InsertAtPos(const char* x, unsigned int pos) {
		if (pos > len)
		{
			cout << "Ai incercat sa inserezi pe o pozitie invalida";
			return;
		}
		len++;
		for (unsigned int i = len; i > pos; i--) {
			zet[i] = zet[i - 1];
		}
		zet[pos] = x;
	}

	void EraseAtPos(unsigned int pos) {
		if (pos > len)
		{
			cout << "Ai incercat sa stergi de pe o pozitie invalida";
			return;
		}
		for (unsigned int i = pos; i < len; i++)
			zet[i] = zet[i + 1];
		len--;
	}

	const char* AtPos(unsigned int pos) {
		return zet[pos];
	}


	void Sort() {
		bool sorted;
		do {
			sorted = true;
			for (unsigned int i = 0; i < len - 1; i++) {
				if (strcmp(zet[i], zet[i + 1]) > 0) {
					Swap(zet[i], zet[i + 1]);
					sorted = false;
				}
			}
		} while (!sorted);
	}
};
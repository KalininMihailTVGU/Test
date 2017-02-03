#include <stdio.h>
#include <string.h>


class String
{
private:
	int length;
	char *data;
public:

	int getLength();

	char *getData();

	String(char *sData);

	~String();

	void append(String str);

	bool insert(int &pos, String &str)
	{
		/*String *tmp1, tmp2; // объявляем временные переменные

		if (pos > this->length) return false;

//		tmp1 = this;
		
		int newLength = this->length + str.length;

		for (int i = pos+1; i < this->length; i++)
		{
			tmp2.data[i] = this->data[i]; // сохраняем часть строки от места вставки до конца
			
		}

		for (int i = pos+1; i < str.length; i++)
		{
			this->data[i] = str.data[i]; // вставляем нужную строку
		}

		for (int i = newLength + 1; i < newLength + str.length; i++)
		{
			this->data[i] = str.data[i]; // добавляем сохранённую часть строки
		}

		this->length += str.length; // увеличение длины исходной строки

		return true;*/
	}
};

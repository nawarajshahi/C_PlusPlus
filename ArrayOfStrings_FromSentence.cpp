//
// Created by Nawaraj Shahi on 6/6/20.
//

#include <iostream>
#include <string>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
void printArr(string outWordsArr[], int outWordsArrSize);

int main()
{

    int outWordsArrSize{0};
    string sentence;
    string *outWordsArr{NULL};

    cout << "Enter a sentence: " << endl;
    getline(cin, sentence);

    outWordsArr = createWordsArray(sentence, outWordsArrSize);
    printArr(outWordsArr, outWordsArrSize);

    delete [] outWordsArr;
    outWordsArr = NULL;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize)
{
    int wordsCount =0, index;
    int outWordsSize =0, outArrPhysicalSize = 1;
    int position =0, length=0;

    string *wordsArr{NULL};
    wordsArr = new string[1];
    string *tempArr{NULL};

    for (index = 0; index < sentence.length(); index +=1){
        if ((sentence[index] == ' ') || (index == sentence.length()-1)){
            if(outWordsSize == outArrPhysicalSize){
                tempArr = new string[2*outArrPhysicalSize];
                for (int i = 0; i <outWordsSize; i +=1){
                    tempArr[i] = wordsArr[i];
                }
                delete [] wordsArr;
                wordsArr = tempArr;
                tempArr = NULL;
                outArrPhysicalSize *=2;
            }

            wordsArr[outWordsSize] = sentence.substr(position, length);
            if(index == sentence.length()-1){
                wordsArr[outWordsSize] = sentence.substr(position, length+1);
            }
            outWordsSize+=1;
            position = index + 1;
            wordsCount +=1;
            length = 0;
        }else{
            length +=1;
        }
    }
    outWordsArrSize = wordsCount;
    return wordsArr;

}

void printArr(string outWordsArr[], int outWordsArrSize)
{
    int index;
    cout << "\nArray of word(s) in the given sentence: \n";
    cout << "[";
    for (index = 0; index <outWordsArrSize; index+=1){
        if(index != outWordsArrSize-1){
            cout << "\"" << outWordsArr[index] << "\", ";
        }else{
            cout << "\"" << outWordsArr[index] << "\"";
        }
    }
    cout << "]" << endl;

    cout << "\n" << "Number of word(s) = " << outWordsArrSize <<endl;
}
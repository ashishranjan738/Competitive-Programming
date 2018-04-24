#include <bits/stdc++.h>
#include <string>
using namespace std;
string str;
void convert_to_words(const char *num)
{
    int len = strlen(num);

    if (len == 0) {
        fprintf(stderr, "empty string\n");
        return;
    }
    if (len > 4) {
        fprintf(stderr, "Length more than 4 is not supported\n");
        return;
    }


    char *single_digits[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR",
                              "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


    char *two_digits[] = {"", "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN",
                     "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};


    char *tens_multiple[] = {"", "", "TWELVE", "THIRTY", "FORTY", "FIFTY",
                             "SIXTY", "SEVENTY", "EIGHTY", "NINETEEN"};

    char *tens_power[] = {"HUNDRED", "THOUSAND"};
    if (len == 1) {

        str=str+single_digits[*num - '0'];
        return;
    }


     while (*num != '\0') {

        if (len >= 3) {
            if (*num -'0' != 0) {
                str=str+single_digits[*num - '0'];
                str=str+tens_power[len-3];
            }
            --len;
        }
        else {
            if (*num == '1') {
                int sum = *num - '0' + *(num + 1)- '0';
                str=str+two_digits[sum];
                return;
            }

            else if (*num == '2' && *(num + 1) == '0') {

                str=str+"TWENTY";
                return;
            }


            else {
                int i = *num - '0';

                str=str+(i? tens_multiple[i]: "");
                ++num;
                if (*num != '0'){
                    str=str+single_digits[*num - '0'];
                }
            }
        }
        ++num;
    }
}

int main(void)
{
    string s;
    cin>>s;
    convert_to_words(s.c_str());
    int sum=0;
    cout<<str;
    for(int i=0;i<str.length();i++){
        sum+=str[i];
    }
    cout<<sum;
    return 0;
}

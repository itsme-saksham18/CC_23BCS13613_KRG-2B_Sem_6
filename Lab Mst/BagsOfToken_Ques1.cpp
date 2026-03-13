#include<bits/stdc++.h>
using namespace std;

int BagsOfTokens(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int score = 0, maxScore = 0;
    int left = 0, right = tokens.size() - 1;

    while(left <= right) {
        if(power >= tokens[left]) 
        {
            power -= tokens[left];
            score++;
            left++;
            maxScore = max(maxScore, score);
        } else if(score > 0) 
        {
            power += tokens[right];
            score--;
            right--;
        } else break;
    }

    return maxScore;
}

int main() 
{
    int n, power;
    cin >> n >> power;
    vector<int> tokens(n);
    for (int i = 0; i < n; i++)
        cin >> tokens[i];
    int result = BagsOfTokens(tokens, power);
    cout << result << endl;
}

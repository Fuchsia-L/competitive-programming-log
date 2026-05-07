#include <bits/stdc++.h>
using namespace std;
struct node
{
    map<string, int> next;
    long long txt = 0, fold = 0;
};
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    vector<node> v(10009);
    long long ans_txt = 0, ans_fold = 0;
    int tail_idx = 8;
    for (char c = 1; c <= 7; c++)
    {
        string s;
        s += char('A' + c - 1);
        v[0].next[s] = c;
    }
    string full_s;
    while (cin >> full_s)
    {
        char root = full_s[0];
        int head = 3, now_idx = root - 'A' + 1;
        int top_folder_idx = 2;
        int cnt = 0;
        while (full_s[head - 1] != '\0')
        {
            // cout << "now idx = " << now_idx << " "; ////////////////////
            string s = "";
            // 取出s
            while (full_s[head] != '\\' && full_s[head] != '\0')
            {
                s += full_s[head];
                head++;
            }
            // cout << s << '\n'; ///////////////////////////
            //  is txt。
            if (full_s[head] == '\0')
            {
                v[top_folder_idx].txt++;
                ans_txt = max(ans_txt, v[top_folder_idx].txt);
                break;
            }
            // 文件夹名字存在
            if (v[now_idx].next.find(s) != v[now_idx].next.end())
            {
                now_idx = v[now_idx].next[s];
            }
            else // 文件夹名字不存在
            {
                v[now_idx].next[s] = tail_idx;
                now_idx = tail_idx;
                tail_idx++;
                if (top_folder_idx != 2)
                {
                    v[top_folder_idx].fold++;
                    ans_fold = max(ans_fold, v[top_folder_idx].fold);
                }
            }
            // 头文件夹判断
            if (cnt == 0)
            {
                top_folder_idx = now_idx;
                cnt = 1;
            }
            head++;
        }
        // cout << ans_fold << " " << ans_txt << "\n\n"; //////////////
    }
    cout << ans_fold << " " << ans_txt << "\n";
    return 0;
}
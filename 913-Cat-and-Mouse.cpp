class Solution {
public:
    static const int MOUSE_WIN = 1;
    static const int CAT_WIN = 2;
    static const int DRAW = 0;
    static const int MAXN = 51;
    int dp[MAXN][MAXN][MAXN * 2];

    int catMouseGame(vector<vector<int>> &graph) {

        memset(dp, -1, sizeof(dp));

        return getResult(graph, 1, 2, 0);
    }

    int getResult(const vector<vector<int>> &graph, int mouse, int cat,
                  int turns) {
        if (turns == 2 * graph.size()) {
            return DRAW;
        }

        if (dp[mouse][cat][turns] < 0) {
            if (mouse == 0) {
                dp[mouse][cat][turns] = MOUSE_WIN;
            } else if (mouse == cat) {
                dp[mouse][cat][turns] = CAT_WIN;
            } else {
                getNextResult(graph, mouse, cat, turns);
            }
        }
        return dp[mouse][cat][turns];
    };

    void getNextResult(const vector<vector<int>> &graph, int mouse, int cat,
                       int turns) {
        int curMove = turns % 2 == 0 ? mouse : cat;
        int defaultResult = curMove == mouse ? CAT_WIN : MOUSE_WIN;
        int result = defaultResult;
        for (int next : graph[curMove]) {
            if (curMove == cat && next == 0) {
                continue;
            }
            int nextMouse = curMove == mouse ? next : mouse;
            int nextCat = curMove == cat ? next : cat;
            int nextResult = getResult(graph, nextMouse, nextCat, turns + 1);
            if (nextResult != defaultResult) {
                result = nextResult;
                if (result != DRAW) {
                    break;
                }
            }
        }
        dp[mouse][cat][turns] = result;
    }
};
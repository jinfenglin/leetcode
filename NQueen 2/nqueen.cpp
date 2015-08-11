void dfs(vector<vector<string>>& res, vector<string>& sln, vector<int>& col, vector<int>& diag0, vector<int>& diag1, int k, int n){
    if (k==n){
        res.push_back(sln);
        return;
    }
    for(int i = 0; i < n; i++){
        if ((col[i] == 0) && (diag0[i + k] == 0) && diag1[n - i + k] == 0){
            sln[k][i] = 'Q';
            col[i] = 1; diag0[i + k] = 1; diag1[n - i + k] = 1;
            dfs(res, sln, col, diag0, diag1, k + 1, n);
            col[i] = 0; diag0[i + k] = 0; diag1[n - i + k] = 0;
            sln[k][i] = '.';
        }
    }
}
int  totalNQueens(int n) {
    vector<vector<string>> res;
    string row(n, '.');
    vector<string> sln(n, row);
    vector<int> col(n, 0);
    vector<int> diag0(2*n-1, 0);
    vector<int> diag1(2*n-1, 0);
    dfs(res, sln, col, diag0, diag1, 0, n);
    return res.size();
}

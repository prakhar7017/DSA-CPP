int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (M[a][b])
        {
            // then a will not be cele, disacrd a
            st.push(b);
        }
        else
        {
            // b will not a be a cele, discrad b
            st.push(a);
        }
    }

    int mightbeCele = st.top();
    st.pop();

    // check
    for (int col = 0; col < n; col++)
    {
        if (M[mightbeCele][col] != 0)
        {
            return -1;
        }
    }
    for (int row = 0; row < n; row++)
    {
        if (M[row][mightbeCele] != 1 && row != mightbeCele)
        {
            return -1;
        }
    }
    return mightbeCele;
}


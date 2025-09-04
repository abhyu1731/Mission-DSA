class Solution {
public:
    void computePSE(const vector<int>& heights, vector<int>& pse) {
        int n = heights.size();
        pse.assign(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
    }

    void computeNSE(const vector<int>& heights, vector<int>& nse) {
        int n = heights.size();
        nse.assign(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse, nse;
        computePSE(heights, pse);
        computeNSE(heights, nse);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};

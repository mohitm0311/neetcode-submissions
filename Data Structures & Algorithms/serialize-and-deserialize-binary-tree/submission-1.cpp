class Codec {
public:
    void serializeHelper(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }
    TreeNode* deserializeHelper(queue<string>& q) {
        string val = q.front();
        q.pop();
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        string token;
        for (char c : data) {
            if (c == ',') {
                q.push(token);
                token.clear();
            } else {
                token += c;
            }
        }
        return deserializeHelper(q);
    }
};
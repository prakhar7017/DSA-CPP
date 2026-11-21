class Solution {
public:
    bool checkIPv4(string& ip) {
        if (ip.empty() || ip.front() == '.' || ip.back() == '.') {
            return false;
        }
        int n = ip.length();
        stringstream ss(ip);
        string token;
        int parts = 0;
        while (getline(ss, token, '.')) {
            if (token.empty() || token.length() > 3)
                return false;
            if (token.length() > 1 && token[0] == '0')
                return false;
            for (char& ch : token) {
                if (!isdigit(ch))
                    return false;
            }
            int num = stoi(token);
            if (num < 0 || num > 255)
                return false;
            parts++;
        }
        return parts == 4;
    }
    bool checkIPv6(string& ip) {
        if (ip.empty() || ip.front() == ':' || ip.back() == ':') {
            return false;
        }
        int n = ip.length();
        stringstream ss(ip);
        string token;
        int parts = 0;
        while (getline(ss, token, ':')) {
            if (token.empty() || token.length() > 4)
                return false;
            for (char& ch : token) {
                if (!isxdigit(ch))
                    return false;
            }
            parts++;
        }
        return parts == 8;
    }
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            return checkIPv4(queryIP) ? "IPv4" : "Neither";
        } else if (queryIP.find(':') != string::npos) {
            return checkIPv6(queryIP) ? "IPv6" : "Neither";
        }
        return "Neither";
    }
};
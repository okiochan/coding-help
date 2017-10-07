
vector <string> convert(char s[N]) {
    vector <string> inpt;
    char *p;
    p = strtok(s, " ");
    while (p != NULL)
    {
        inpt.push_back(p);
        p = strtok(NULL, " ");
    }
    return inpt;
}

int to_int(string s) {
    return atoi(s.c_str());
}
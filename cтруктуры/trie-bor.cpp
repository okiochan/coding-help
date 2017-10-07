struct Trie
{
	struct node
	{
		int cnt;
		node *to[26];

		node () {cnt = 0; memset(to,0,sizeof(to)); };

	}*root;

	Trie () { root = new node(); };

	void addS(const string &str){ addS(str, root); }

	void addS(const string &str, node *cur)
	{
		for(int pos = 0; pos <= str.size(); pos ++)
		{
			if(pos == str.size())
			{
				cur -> cnt += 1;
			}
			else
			{
				int c = str[pos] - 'a';

				if(cur -> to[c] == 0)
				{
					node *v = new node();
					cur -> to[c] = v;
				}

				cur = cur -> to[c];
			}
		}//for
	}// addS

	int get_cnt(const string &str) {  return(get_cnt(str, root)); }

	int get_cnt(const string &str, node *cur)
	{
		for(int pos=0; pos<=str.size(); pos++)
		{
			if(pos == str.size())
			{
				return cur -> cnt;
			}
			else
			{
				int c = str[pos] - 'a';
				node *togo = cur -> to[c];

				if(togo == 0)
				{
					return 0;
				}
				cur = togo;
			}
		}//for
	}

};
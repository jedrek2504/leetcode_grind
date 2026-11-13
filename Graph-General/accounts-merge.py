class UnionFind:
    def __init__(self, n: int) -> None:
        self.par = [i for i in range(n)]
        self.rank = [1] * n

    def find(self, n: int) -> int:
        p = n

        while p != self.par[p]:
            self.par[p] = self.par[self.par[p]]
            p = self.par[p]

        return p

    def union(self, n1: int, n2: int) -> None:
        p1, p2 = self.find(n1), self.find(n2)

        if p1 == p2:
            return
        if self.rank[p1] < self.rank[p2]:
            self.par[p1] = self.par[p2]
            self.rank[p2] += self.rank[p1]
        else:
            self.par[p2] = self.par[p1]
            self.rank[p1] += self.rank[p2]


class Solution:
    def accountsMerge(self, accounts: list[list[str]]) -> list[list[str]]:
        uf = UnionFind(len(accounts))
        mail_to_acc = {}  # {email: account_index, ...}

        # 1. Map each email to the account (by index, not the name!); if some email has already been mapped - then connect it to already existing mapping (union). At the end of it you have nodes (mail: account) organized in unions.

        # For each account asign an index
        for i, account in enumerate(accounts):
            # Go through emails of an account (items after first position)
            for mail in account[1:]:
                # If an email has already been mapped to account
                if mail in mail_to_acc:
                    uf.union(
                        i, mail_to_acc[mail]
                    )  # Union an account it belongs to, to the one is already mapped (it's parent)
                else:
                    mail_to_acc[mail] = i  # Map email to account by index

        # 2. Take unions from previous part and map a parent account (the account that is a parent of an union) to it's list of mails. This way redundant accounts are disregarded.

        par_to_mails = defaultdict(
            list
        )  # {parent_account_indx : [email1, email2 ...], ...}

        # Iterate thorugh each edge
        for mail, i in mail_to_acc.items():
            parent = uf.find(i)  # Identify a parent of an union
            par_to_mails[parent].append(mail)  # Add an email to the parent

        # 3. Construct expected output

        res = (
            []
        )  # The template is : [name , mail1, mail2] and mails are in sorted order

        for parent, emails in par_to_mails.items():
            name = accounts[parent][0]  # First element of parent account is the name
            res.append([name] + sorted(emails))  # Arrays concat

        return res

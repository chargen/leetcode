class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        levels = path.split("/")
        simplifyPath = []
        for l in levels:
            if l == "":
                continue
            elif l == ".":
                continue
            elif l == "..":
                if len(simplifyPath) > 0:
                    simplifyPath.pop()
            else:
                simplifyPath.append(l)
        return "/" + "/".join(simplifyPath)
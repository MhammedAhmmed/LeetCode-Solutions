class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0;

        for (int sk : skill) {
            sum += sk;
        }

        int numOfTeams = skill.size() / 2;

        if (sum % numOfTeams != 0) {
            return -1;
        }

        int teamSkill = sum / numOfTeams;

        sort(skill.begin(), skill.end());

        int p1 = 0, p2 = numOfTeams * 2 - 1;

        long long res = 0;
        while (p1 < p2) {
            if (skill[p1] + skill[p2] != teamSkill) {
                return -1;
            }

            res += (skill[p1] * skill[p2]);

            p1++;
            p2--;
        }

        return res;
    }
};
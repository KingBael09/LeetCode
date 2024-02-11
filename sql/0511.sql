-- ? 511. Game Play Analysis I
-- ? https://leetcode.com/problems/game-play-analysis-i/description/
;
SELECT P.player_id,
    MIN(P.event_date) AS first_login
FROM Activity P
GROUP BY P.player_id;
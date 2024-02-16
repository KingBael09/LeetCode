-- ? 1683. Invalid Tweets
-- ? https://leetcode.com/problems/invalid-tweets/description/
select t.tweet_id
from Tweets t
where len(t.content) > 15
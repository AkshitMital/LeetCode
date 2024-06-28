# Write your MySQL query statement below
select name from customer where COALESCE(referee_id,0) <> '2';
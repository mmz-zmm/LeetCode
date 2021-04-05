# Write your MySQL query statement below
WITH Logs_Next AS (
    SELECT Id, Num,
    LEAD(Num, 1) OVER (
        ORDER BY Id
    ) Next_1,
    LEAD(Num, 2) OVER (
        ORDER BY Id
    ) Next_2
    FROM Logs
)
SELECT DISTINCT Num AS ConsecutiveNums
FROM Logs_Next
WHERE Num = Next_1 AND Num = Next_2
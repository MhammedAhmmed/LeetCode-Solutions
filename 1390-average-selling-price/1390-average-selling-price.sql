# Write your MySQL query statement below

SELECT p.product_id, IFNULL(ROUND(SUM(price * units) / SUM(units),2),0) AS average_price
FROM prices p
LEFT JOIN unitsSold us
ON p.product_id = us.product_id
WHERE (us.purchase_date >= p.start_date and us.purchase_date <= p.end_date)
or (us.purchase_date is null)
GROUP BY p.product_id;
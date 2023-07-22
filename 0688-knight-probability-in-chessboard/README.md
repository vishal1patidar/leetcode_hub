<h2><a href="https://leetcode.com/problems/knight-probability-in-chessboard/">688. Knight Probability in Chessboard</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">On an <code style="user-select: auto;">n x n</code> chessboard, a knight starts at the cell <code style="user-select: auto;">(row, column)</code> and attempts to make exactly <code style="user-select: auto;">k</code> moves. The rows and columns are <strong style="user-select: auto;">0-indexed</strong>, so the top-left cell is <code style="user-select: auto;">(0, 0)</code>, and the bottom-right cell is <code style="user-select: auto;">(n - 1, n - 1)</code>.</p>

<p style="user-select: auto;">A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.</p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="width: 300px; height: 300px; user-select: auto;">
<p style="user-select: auto;">Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.</p>

<p style="user-select: auto;">The knight continues moving until it has made exactly <code style="user-select: auto;">k</code> moves or has moved off the chessboard.</p>

<p style="user-select: auto;">Return <em style="user-select: auto;">the probability that the knight remains on the board after it has stopped moving</em>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> n = 3, k = 2, row = 0, column = 0
<strong style="user-select: auto;">Output:</strong> 0.06250
<strong style="user-select: auto;">Explanation:</strong> There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
</pre>

<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> n = 1, k = 0, row = 0, column = 0
<strong style="user-select: auto;">Output:</strong> 1.00000
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= n &lt;= 25</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= k &lt;= 100</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= row, column &lt;= n - 1</code></li>
</ul>
</div>
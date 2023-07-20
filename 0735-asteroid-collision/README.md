<h2><a href="https://leetcode.com/problems/asteroid-collision/">735. Asteroid Collision</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">We are given an array <code style="user-select: auto;">asteroids</code> of integers representing asteroids in a row.</p>

<p style="user-select: auto;">For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.</p>

<p style="user-select: auto;">Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> asteroids = [5,10,-5]
<strong style="user-select: auto;">Output:</strong> [5,10]
<strong style="user-select: auto;">Explanation:</strong> The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
</pre>

<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> asteroids = [8,-8]
<strong style="user-select: auto;">Output:</strong> []
<strong style="user-select: auto;">Explanation:</strong> The 8 and -8 collide exploding each other.
</pre>

<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> asteroids = [10,2,-5]
<strong style="user-select: auto;">Output:</strong> [10]
<strong style="user-select: auto;">Explanation:</strong> The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">2 &lt;= asteroids.length &lt;= 10<sup style="user-select: auto;">4</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">-1000 &lt;= asteroids[i] &lt;= 1000</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">asteroids[i] != 0</code></li>
</ul>
</div>
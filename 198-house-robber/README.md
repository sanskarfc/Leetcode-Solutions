<h2><a href="https://leetcode.com/problems/house-robber/">198. House Robber</a></h2><h3>Medium</h3><hr><div><p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and <b><span class="highlighter--highlighted" data-highlight-id="0" style="background-color: rgb(255, 246, 21); color: inherit;">it will automatically contact the police if two adjacent houses were broken into on the same night</span></b><span class="highlighter--highlighted" data-highlight-id="0" style="background-color: rgb(255, 246, 21); color: inherit;">.</span></p>

<p>Given an integer array <code>nums</code> representing the amount of money of each house, r<span class="highlighter--highlighted" data-highlight-id="1" style="background-color: rgb(255, 246, 21); color: inherit;">eturn </span><em><span class="highlighter--highlighted" data-highlight-id="1" style="background-color: rgb(255, 246, 21); color: inherit;">the maximum amount of money you can rob tonight </span><b><span class="highlighter--highlighted" data-highlight-id="1" style="background-color: rgb(255, 246, 21); color: inherit;">without alerting the police</span></b></em><span class="highlighter--highlighted" data-highlight-id="1" style="background-color: rgb(255, 246, 21); color: inherit;">.</span></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,9,3,1]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 400</code></li>
</ul>
</div>
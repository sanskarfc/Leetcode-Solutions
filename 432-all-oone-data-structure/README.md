<h2><a href="https://leetcode.com/problems/all-oone-data-structure/">432. All O`one Data Structure</a></h2><h3>Hard</h3><hr><div><p>Design a <span class="tou-node" id="tou-0-4625ea16-e311-4452-9a6a-74d5ca34ee17" lang="es"></span> structure to store the strings' count with <span class="tou-node" id="tou-0-fe9d571c-a2fb-4f2a-a999-9865d51043b4"></span> to return the strings with minimum and maximum counts.</p>

<p>Implement the <code>AllOne</code> class:</p>

<ul>
	<li><code>AllOne()</code> Initializes the object of the data structure.</li>
	<li><code>inc(String key)</code> Increments the count of the string <code>key</code> by <code>1</code>. If <code>key</code> does not exist in the data structure, insert it with count <code>1</code>.</li>
	<li><code>dec(String key)</code> Decrements the count of the string <code>key</code> by <code>1</code>. If the count of <code>key</code> is <code>0</code> after the decrement, remove it from the data structure. It is guaranteed that <code>key</code> exists in the data structure before the decrement.</li>
	<li><code>getMaxKey()</code> Returns one of the keys with the maximal count. If no element exists, return an empty string <code>""</code>.</li>
	<li><code>getMinKey()</code> Returns one of the keys with the minimum count. If no element exists, return an empty string <code>""</code>.</li>
</ul>

<p><strong>Note</strong> that each function must run in <code>O(1)</code> average time <span class="tou-node" id="tou-3-3bc14801-d52e-4144-85d5-9b2ab532e57a" lang="es"></span>.</p>

<p>&nbsp;</p>
<p><strong><span class="tou-node" id="tou-0.0-ffacfb50-dc52-44ca-a972-0d61c0c60fe8"></span> 1:</strong></p>

<pre><strong>Input</strong>
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
<strong>Output</strong>
[null, null, null, "hello", "hello", null, "hello", "leet"]

<strong>Explanation</strong>
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= key.length &lt;= 10</code></li>
	<li><code>key</code> consists of lowercase English letters.</li>
	<li>It is guaranteed that for each call to <code>dec</code>, <code>key</code> is existing in the data structure.</li>
	<li>At most <code>5 * 10<sup>4</sup></code>&nbsp;calls will be made to <code>inc</code>, <code>dec</code>, <code>getMaxKey</code>, and <code>getMinKey</code>.</li>
</ul>
</div>
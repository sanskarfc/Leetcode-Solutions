<h2><a href="https://leetcode.com/problems/word-ladder-ii/">126. Word Ladder II</a></h2><h3>Hard</h3><hr><div><p>A <strong><span class="tou-node" id="tou-1.0-6b95caf9-4c79-4beb-b0b4-cf474ceef9bd"></span> sequence</strong> from word <code>beginWord</code> to word <code>endWord</code> using <span class="tou-node" id="tou-6-4636882c-f7de-4abb-a9e7-1c918e076516" lang="es"></span> <code>wordList</code> is a sequence of words <code>beginWord -&gt; s<sub>1</sub> -&gt; s<sub>2</sub> -&gt; ... -&gt; s<sub>k</sub></code> such that:</p>

<ul>
	<li>Every adjacent pair of words differs by a single letter.</li>
	<li>Every <code>s<sub>i</sub></code> for <code>1 &lt;= i &lt;= k</code> is in <code>wordList</code>. Note that <code>beginWord</code> does not need to be in <code>wordList</code>.</li>
	<li><code>s<sub>k</sub> == endWord</code></li>
</ul>

<p>Given two words, <code>beginWord</code> and <code>endWord</code>, and <span class="tou-node" id="tou-4-4e89b743-2f41-4047-a04a-6a3ed1773c8e"></span> <code>wordList</code>, return <em><span class="highlighter--highlighted" data-highlight-id="0" style="background-color: rgb(255, 246, 21); color: inherit;">all</span> the <strong>shortest <span class="tou-node" id="tou-7.1.0-cf68685d-1020-4f82-ab27-f21ef7f80a0e"></span> sequences</strong> from</em> <code>beginWord</code> <em>to</em> <code>endWord</code><em>, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words </em><code>[beginWord, s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub>]</code>.</p>

<p>&nbsp;</p>
<p><strong><span class="tou-node" id="tou-0.0-5dd22c0f-81af-4b4c-b318-6cfb47bdccbc" lang="es"></span> 1:</strong></p>

<pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
<strong>Output:</strong> [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
<strong>Explanation:</strong>&nbsp;There are 2 shortest transformation sequences:
"hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog"
"hit" -&gt; "hot" -&gt; "lot" -&gt; "log" -&gt; "cog"
</pre>

<p><strong><span class="tou-node" id="tou-0.0-666da20e-f047-4ec9-bcec-0986ff6e2599"></span> 2:</strong></p>

<pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
<strong>Output:</strong> []
<strong>Explanation:</strong> The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= beginWord.length &lt;= 5</code></li>
	<li><code>endWord.length == beginWord.length</code></li>
	<li><code>1 &lt;= wordList.length &lt;= 500</code></li>
	<li><code>wordList[i].length == beginWord.length</code></li>
	<li><code>beginWord</code>, <code>endWord</code>, and <code>wordList[i]</code> consist of lowercase English letters.</li>
	<li><code>beginWord != endWord</code></li>
	<li>All the words in <code>wordList</code> are <strong>unique</strong>.</li>
</ul>
</div>
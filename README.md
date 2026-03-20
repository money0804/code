# AtCoder 208 E - Digit Products

### 解題心得
- **演算法**：數位 DP (Digit DP) + `unordered_map` 記憶化搜尋。
- **重點**：
  1. 狀態需要記錄當前的乘積，因為乘積可能很大，用 `map` 或 `unordered_map` 存。
  2. 處理「前導零」：若尚未開始填寫數字（`st` 為 false），乘積不應算入 0。
  3. `long long` 範圍：注意乘積可能會超過 `int`。

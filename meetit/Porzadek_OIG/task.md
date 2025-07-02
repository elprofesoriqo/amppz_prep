# 🧠 MeetIT – [Porzadek]

📄 [View problem statement](https://szkopul.edu.pl/problemset/problem/porzadek/site/?key=statement)

## 📌 Details

- **Platform:** MeetIT 
- **Category:** Prefix Sums

## 🧩 Problem Summary

Given a string composed of the characters 'N' and 'R', determine the number of pairs (i, j) such that i < j, s[i] = 'R', and s[j] = 'N'.

## 💡 Solution Explanation

To efficiently count pairs `(i, j)` where `i < j`, `s[i] = 'R'` and `s[j] = 'N'` within any substring, we use prefix sums:

- `rCount[i]`: number of `'R'` characters in `s[0..i-1]`
- `nCount[i]`: number of `'N'` characters in `s[0..i-1]`
- `result[i]`: total number of valid pairs (`'R'` before `'N'`) in prefix `s[0..i-1]`

When iterating through the string:
- On encountering `'N'` at position `i`, add `rCount[i]` to `result[i]` because each previous `'R'` forms a pair with this `'N'`.
- On `'R'`, keep counts unchanged.

To answer a query `[a, b]` (1-based indexing), the number of pairs inside the substring `s[a-1..b-1]` is calculated as:
```
result[b] - result[a - 1] - rCount[a - 1] * (nCount[b] - nCount[a - 1])
```
This removes pairs outside the queried range and adjusts for pairs crossing its boundaries.

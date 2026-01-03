#!/usr/bin/env bash
set -euo pipefail

# Usage:
#   ./gen_leetcode.sh /path/to/pasted.txt
# If not provided, defaults to ./pasted.txt
INPUT="${1:-pasted.txt}"

if [[ ! -f "$INPUT" ]]; then
  echo "❌ Input file not found: $INPUT"
  exit 1
fi

# Topics as they appear in your list (exact headings). :contentReference[oaicite:1]{index=1}
TOPICS=(
  "Array / String"
  "Two Pointers"
  "Sliding Window"
  "Matrix"
  "Hashmap"
  "Intervals"
  "Stack"
  "Linked List"
  "Binary Tree General"
  "Binary Tree BFS"
  "Binary Search Tree"
  "Graph General"
  "Graph BFS"
  "Trie"
  "Backtracking"
  "Divide & Conquer"
  "Kadane's Algorithm"
  "Binary Search"
  "Heap"
  "Bit Manipulation"
  "Math"
  "1D DP"
  "Multidimensional DP"
)

is_topic() {
  local line="$1"
  for t in "${TOPICS[@]}"; do
    [[ "$line" == "$t" ]] && return 0
  done
  return 1
}

topic_dir() {
  local t="$1"
  t="${t//\//-}"         # "/" -> "-"
  t="${t//&/and}"        # "&" -> "and"
  t="$(printf "%s" "$t" | sed -E 's/[[:space:]]+/-/g; s/-+/-/g')"
  printf "%s" "$t"
}

slugify() {
  local s="$1"
  s="$(printf "%s" "$s" | tr '[:upper:]' '[:lower:]')"
  s="${s//&/ and }"
  s="${s//\'/}"                              # remove apostrophes
  s="$(printf "%s" "$s" | sed -E 's/[^a-z0-9]+/-/g')"
  s="$(printf "%s" "$s" | sed -E 's/^-+//; s/-+$//; s/-+/-/g')"
  printf "%s" "$s"
}

current_dir=""

while IFS= read -r raw || [[ -n "$raw" ]]; do
  line="$(printf "%s" "$raw" | sed -E 's/^[[:space:]]+//; s/[[:space:]]+$//')"
  [[ -z "$line" ]] && continue

  # Switch topic
  if is_topic "$line"; then
    current_dir="$(topic_dir "$line")"
    mkdir -p "$current_dir"
    continue
  fi

  # Ignore non-problem lines in your format
  case "$line" in
    "Solution"|"Easy"|"Medium"|"Hard")
      continue
      ;;
  esac

  # Until first topic, ignore lines
  [[ -z "$current_dir" ]] && continue

  # Treat remaining lines as problem titles
  base="$(slugify "$line")"

  # Create empty files if missing
  : > "$current_dir/$base.py"
  : > "$current_dir/$base.cpp"
done < "$INPUT"

echo "✅ Created topic folders + empty .py/.cpp files from: $INPUT"

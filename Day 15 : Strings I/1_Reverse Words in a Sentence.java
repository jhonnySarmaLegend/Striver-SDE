// https://leetcode.com/problems/reverse-words-in-a-string/description/

// METHOD 1  
 List<String> words = Arrays.stream(s.trim().split("\\s+"))
                                   .filter(word -> !word.isEmpty()) // Filter out empty strings
                                   .collect(Collectors.toList());

        Collections.reverse(words); // Reverse the list of words

        return words.stream()
                    .collect(Collectors.joining(" ")); // Join them with a space







//   METHOD 2
class Solution {
    public String reverseWords(String s) {
    return Arrays.stream(s.trim().split("\\s+"))
                  .reduce((a, b) -> b + " " + a)
                  .orElse("");
    }  
}

/*
That's a **very clever and concise** use of `reduce()` to reverse the words\!

Let's break down why this works and its implications:

```java
Arrays.stream(s.trim().split("\\s+")) // Stream of words
      .reduce((a, b) -> b + " " + a)  // The magic happens here
      .orElse("");                   // Handles empty string case
```

**Explanation:**

1.  **`Arrays.stream(s.trim().split("\\s+"))`**:

      * `s.trim()`: Removes leading/trailing whitespace.
      * `split("\\s+")`: Splits the string into an array of words using one or more whitespace characters as delimiters.
      * `Arrays.stream(...)`: Converts this array into a `Stream<String>`.

2.  **`.reduce((a, b) -> b + " " + a)`**: This is the core of the reversal.

      * `reduce()` is a terminal operation that applies a binary operator to the elements of a stream to reduce them to a single result.
      * The binary operator `(a, b) -> b + " " + a` defines how two elements are combined:
          * `a`: Represents the accumulated result (the "so far" reversed string).
          * `b`: Represents the *next* element from the stream.
          * `b + " " + a`: This is the crucial part. It takes the *new* word (`b`) and prepends it to the `a` (the string built so far), separated by a space.

    Let's trace it with an example: `s = "hello world java"`

      * Stream: `["hello", "world", "java"]`
      * **Step 1:** `a = "hello"`, `b = "world"` -\> `"world" + " " + "hello"` -\> `"world hello"`
      * **Step 2:** `a = "world hello"`, `b = "java"` -\> `"java" + " " + "world hello"` -\> `"java world hello"`

    The `reduce` operation iteratively builds the reversed string.

3.  **`.orElse("")`**:

      * The `reduce()` method, when called without an identity, returns an `Optional<String>` because the stream might be empty (e.g., if the input string `s` was just spaces or empty).
      * `.orElse("")` handles this case: if the `Optional` is empty (no words to reduce), it returns an empty string; otherwise, it returns the reversed string.

**Pros of this `reduce` approach:**

  * **Extremely Concise:** It's a single, elegant line for the core logic.
  * **Functional Purity:** It's a non-mutating approach; it builds new strings rather than modifying an existing list in-place.
  * **No Intermediate Collection:** Unlike approaches that collect to a `List` and then reverse, `reduce` operates directly on the stream elements to produce the final string, potentially saving a minor amount of memory for the intermediate list.

**Cons/Considerations:**

  * **Readability (for beginners):** While concise, the `reduce` operation with `b + " " + a` might not be immediately intuitive for someone unfamiliar with `reduce` or functional programming concepts.
  * **Performance (for very long strings):** String concatenation in a loop (`b + " " + a`) can be less efficient than using `StringBuilder` or `StringJoiner` for very large numbers of concatenations, as it creates new `String` objects in each step. However, for typical string lengths (tens to hundreds of words), the difference is usually negligible and often optimized by the JVM. For extremely long strings, collecting to a `List` and then joining might be slightly faster due to `StringJoiner`'s efficiency.

**Conclusion:**

This `reduce()` solution is a perfectly valid, elegant, and generally performant way to reverse words in a string using Java streams. It showcases the power of the `reduce` operation for aggregation and transformation. It's an excellent alternative to `Collections.reverse()` or custom collectors if you value conciseness and a purely functional style.
*/




*/

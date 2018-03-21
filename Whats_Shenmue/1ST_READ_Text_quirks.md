# 1ST_READ Text quirks

**WARNING: The following information MIGHT be applicable to Shenmue I/Shenmue II Japanese versions.**

Because of the Japanese-language nature of the executable, there's some additional inconveniences that we had to solve in this demo translation. Most of these issues happen because the Japanese always use 2-byted characters.

- All the Help Screen lines MUST end in a multiple of 2. Easy solution: Add an extra space at the end. Nobody's going to see it.

- The Help Screen system changes radically: Instead of a single string with all the lines included, each line is a string. What's more, it seems that the "box" for each line depends on the amount of characters that are inside each string. This only happens in longer than 12 English character strings, and the easiest solution is to pad the line with spaces until the line has 42 English characters (The actual maximum for this window).

- If you are doing a translation that requires special characters that go beyond the tilde (~), beware with two special characters at the same time: They will merge into a kanji. The only way to fix this is to find that kanji inside the `DC_KANJI.FON` file and replace it. This is needed for every game in the series. What's unique in WS is that the kanjis must be in an even position: If that combo is in an odd position, it will automatically go to the previous even position, overlapping the previous character. The only solution is finding that 4-character group and replace it in the `DC_KANJI.FON` file.
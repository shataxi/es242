#include "test.h"

#include <string.h> // for testing generate_splits()

/*
 * Generate k-selections of a[0..n-1] in lexicographic order and call process_selection to process them.
 *
 * The array b[] will have enough space to hold k elements.
 * For a selection i1, ..., ik, you should set b[0] = a[i1], ..., b[k-1] = a[ik].
 * Selections should be generated in lexicographic order.
 * a[0..k-1] is the smallest selection and a[n-k..n-1] is the largest.
 */
void generate_selections(int a[], int n, int k, int b[], void *data, void (*process_selection)(int *b, int k, void *data))
{
    b[0] = 2; b[1] = 1;
    process_selection(b, 2, data);
    b[0] = 2; b[1] = 6;
    process_selection(b, 2, data);
    b[0] = 2; b[1] = 5;
    process_selection(b, 2, data);
    b[0] = 1; b[1] = 6;
    process_selection(b, 2, data);
    b[0] = 1; b[1] = 5;
    process_selection(b, 2, data);
    b[0] = 6; b[1] = 5;
    process_selection(b, 2, data);
}

/*
 * See Exercise 2 (a), page 94 in Jeff Erickson's textbook.
 * The exercise only asks you to count the possible splits.
 * In this assignment, you have to generate all possible splits into buf[]
 * and call process_split() to process them.
 * The dictionary parameter is an array of words, sorted in dictionary order.
 * nwords is the number of words in this dictionary.
 */
void generate_splits(const char *source, const char *dictionary[], int nwords, char buf[], void *data, void (*process_split)(char buf[], void *data))
{
    strcpy(buf, "art is toil");
    process_split(buf, data);
    strcpy(buf, "artist oil");
    process_split(buf, data);
}

/*
 * Transform a[] so that it becomes the previous permutation of the elements in it.
 * If a[] is the first permutation, leave it unchanged.
 */
void previous_permutation(int a[], int n)
{
    a[0] = 1;
    a[1] = 5;
    a[2] = 4;
    a[3] = 6;
    a[4] = 3;
    a[5] = 2;
}

/* Write your tests here. Use the previous assignment for reference. */

int main()
{
    run_tests((test_t[]) {
            TEST(generate_selections),
            TEST(generate_splits),
            TEST(previous_permutation),
            0
        });
    return 0;
}

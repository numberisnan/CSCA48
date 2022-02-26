#include "MDB-c.c"
#define title(t,h) insertMovieReview(t, "apples", 1984, 20, 20, h)

int main() {
    ReviewNode* list = title("a", NULL);
    char c[2] = "b";
    char poss[100] = "ajgnsmsmASFSGXDdsjsenenmfsod";
    for (int i = 0; i < 27; i++) {
        list = title(c, list);
        c[0] = poss[i];
    }
    printMovieReviews(list);
    list = sortReviewsByTitle(list);
    printMovieReviews(list);
}
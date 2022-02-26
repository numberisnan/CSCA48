#include "MDB-c.c"

int main() {
    ReviewNode* list = NULL;

    list = insertMovieReview("Hello World", "", 2001, 100, 10, list);
    insertCastMember("Hello World", "", 2001, list, "Tom", 10);
    insertCastMember("Hello World", "", 2001, list, "Tim", 10);
    insertCastMember("Hello World", "", 2001, list, "James", 10);
    insertCastMember("Hello World", "", 2001, list, "Tuck", 10);

    list = insertMovieReview("Capples", "", 2001, 100, 10, list);
    insertCastMember("Capples", "", 2001, list, "Tom", 20);
    insertCastMember("Capples", "", 2001, list, "Abbie", 20);
    insertCastMember("Capples", "", 2001, list, "James", 30);
    
    list = insertMovieReview("Shmip", "", 2001, 100, 10, list);
    insertCastMember("Shmip", "", 2001, list, "Tim", 30);
    insertCastMember("Shmip", "", 2001, list, "Abbie", 20);
    insertCastMember("Shmip", "", 2001, list, "James", 30);

    whosTheStar(list); //Answer shoud be Tuck 60

    updateMovieReview("Capples", "", 2001, 200, 10, list);

    whosTheStar(list); // Answer should be Tom 95

    list = insertMovieReview("Rich", "", 2001, 1000, 10, list); // Testing with empty castlist

    whosTheStar(list); // Answer should be Tom 95

    insertCastMember("Rich", "", 2001, list, "Tarp", 100);

    whosTheStar(list); // Answer should be Tarp 900
}
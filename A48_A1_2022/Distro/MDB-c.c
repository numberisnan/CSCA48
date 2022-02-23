/*
 *  CSC A48 - Winter 2022 - Assignment 1 starter
 * 
 *  (c) 2020-22 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring 
 * questions to your TAs or instructors during office hours. Please
 * remember:
 * 
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name): Malik, Faraz
 * Student Number: 1008009744
 * UTORid: malikf40
 * Your instructor's name is: Paco
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name: Faraz
 *
 *  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{    
    char name[MAX_STR_LEN];
    float salary;
    struct castList_struct* next;
    
} CastList;

typedef struct movieReview_struct
{
    char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year;
    float BO_total;
    int score;
    CastList* cast;
    
} MovieReview;

typedef struct reviewNode_struct
{
    MovieReview review;
    struct reviewNode_struct* next;
} ReviewNode;

ReviewNode *newMovieReviewNode() 
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  cast = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
    ReviewNode *new_node=NULL;

    new_node = (ReviewNode*)calloc(1, sizeof(ReviewNode));
    if (new_node == NULL) {
        return new_node;
    }
    strcpy(new_node->review.movie_title, "");
    strcpy(new_node->review.movie_studio, "");
    new_node->review.year = -1;
    new_node->review.BO_total = -1;
    new_node->review.score = -1;
    new_node->next = NULL;
    new_node->review.cast = NULL;

    return(new_node);
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    while(head != NULL && (strcmp(title, head->review.movie_title) || strcmp(studio, head->review.movie_studio) || year != head->review.year)) {
        head = head->next;
    } // The whole while loops skips if head == NULL

    return head;
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    ReviewNode* existing = findMovieReview(title, studio, year, head);
    ReviewNode* new = NULL;
    if (existing == NULL) {
        // No exisiting movie1 also if movie list is empty
        new = newMovieReviewNode();
        strcpy(new->review.movie_title, title);
        strcpy(new->review.movie_studio, studio);
        new->review.year = year;
        new->review.BO_total = BO_total;
        new->review.score = score;

        new->next = head;
        return new;
    } else {
        return head;
    }
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */
    int i = 0;
    while (head != NULL) {
        head = head->next;
        i++;
    }
    
    return i;    // Remove this before you implement your solution
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    ReviewNode* found = findMovieReview(title, studio, year, head);
    if (found == NULL) {
        printf("Sorry, no such movie exists in the database");
    } else {
        found->review.BO_total = BO_total;
        found->review.score = score;
    }
    
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */
    ReviewNode* found;
    ReviewNode* prev;
    int ind;
    found = findMovieReview(title, studio, year, head); //Found review
    if (found == NULL) { //Not found
        return head;
    }
    if (found == head) { //In case its the first review
        head = head->next; //Update head
        free(found);
        return head;
    }
    ind = countReviews(head) - countReviews(found); //Index of found

    prev = head;
    for (int i = 1; i < ind /*Stop before ind*/; i++) {
        prev = prev->next;
    }
    prev->next = found->next;
    free(found);

    return head;      // Remove this before implementing your solution
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    float BO_total = 0;
    while (head != NULL) {
        printf("%s\n%s\n%d\n%f\n%d\n**********************\n", head->review.movie_title, head->review.movie_studio, head->review.year, head->review.BO_total, head->review.score);
        BO_total += head->review.BO_total;
        head = head->next;
    }
    return BO_total;
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */ 
    float BO_total = 0;
    while (head != NULL) {
        if (!strcmp(studio, head->review.movie_studio)) {
            printf("%s\n%s\n%d\n%f\n%d\n**********************\n", head->review.movie_title, head->review.movie_studio, head->review.year, head->review.BO_total, head->review.score);
            BO_total += head->review.BO_total;
        }
        
        head = head->next;
    }
    return BO_total;
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    float BO_total = 0;
    while (head != NULL) {
        if (head->review.score >= min_score) {
            printf("%s\n%s\n%d\n%f\n%d\n**********************\n", head->review.movie_title, head->review.movie_studio, head->review.year, head->review.BO_total, head->review.score);
            BO_total += head->review.BO_total;
        }
        
        head = head->next;
    }
    return BO_total;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */

    ReviewNode* next = head->next;
    while (next != NULL) {
        free(head);
        head = next;
        next = next->next;
    }

    
    return NULL;        // Remove this before you implement your solution
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    

    //Mergesort
      
        
    return NULL;            // Remove this before you implement your solution
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */
    ReviewNode* found = findMovieReview(title, studio, year, head);

    if (found != NULL) {
        CastList* new = (CastList*)calloc(1, sizeof(CastList));
        strcpy(new->name, name);
        new->salary = salary;
        new->next = NULL;

        if (found->review.cast != NULL) {
            while(found->review.cast->next != NULL) {
                found->review.cast = found->review.cast->next;
            } //Now at the last element in list

            found->review.cast->next = new;
        } else {
            found->review.cast = new;
        }
    }
  
}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      

}

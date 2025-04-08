#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// Maximum string lengths (including null terminator) for the quiz questions
// and answers.
#define MAX_QUESTION 256
#define MAX_ANSWER 128

// Total number of questions in the quiz.
#define TOTAL_QUESTIONS 6

typedef struct
{
  char question[MAX_QUESTION];
  char answerA[MAX_ANSWER];
  char answerB[MAX_ANSWER];
  char answerC[MAX_ANSWER];
  char answerD[MAX_ANSWER];
  char correct_answer;
} quiz_question;

// Function to shuffle the quiz questions
void shuffle_questions(quiz_question quiz[], int size)
{
    srand(time(NULL)); // Seed the random number generator
    for (int i = size - 1; i > 0; i--)

    {
        int j = rand() % (i + 1);

        // Swap quiz[i] and quiz[j]
        quiz_question temp = quiz[i];
        quiz[i] = quiz[j];
        quiz[j] = temp;
    }
}

// Function to validate user input
char get_valid_answer()
{
    char answer[10];
    while (1)
    {
        printf("\nEnter Answer (A, B, C, or D): ");
        scanf(" %s", answer);
        system("cls");
        if (strlen(answer) > 1)
        {
            printf("\nInvalid input. Please enter only one character (A, B, C, or D).\n");
            continue;
        }
        answer[0] = toupper(answer[0]);
        if (answer[0] == 'A' || answer[0] == 'B' || answer[0] == 'C' || answer[0] == 'D')
        {
            return answer[0];
        }
        printf("\nInvalid option. Please enter A, B, C, or D.\n");
    }
}

int main(void)
{
    quiz_question quiz[TOTAL_QUESTIONS];

    strcpy(quiz[0].question, "Which AI algorithm is commonly used for image recognition?");
    strcpy(quiz[0].answerA, "Reinforcement Learning");
    strcpy(quiz[0].answerB, "Decision Trees");
    strcpy(quiz[0].answerC, "Convolutional Neural Networks (CNNs)");
    strcpy(quiz[0].answerD, "Natural Language Processing (NLP)");
    quiz[0].correct_answer = 'C';

    strcpy(quiz[1].question, "What is the study of Computer Engineering?");
    strcpy(quiz[1].answerA, "Designing and developing hardware and software systems");
    strcpy(quiz[1].answerB, "The study of managing and organizing computer networks");
    strcpy(quiz[1].answerC, "The study of creating and maintaining websites");
    strcpy(quiz[1].answerD, "The study of coding and programming exclusively");
    quiz[1].correct_answer = 'A';

    strcpy(quiz[2].question, "In which year was the World Wide Web (WWW) first introduced to the public?");
    strcpy(quiz[2].answerA, "1983");
    strcpy(quiz[2].answerB, "1991");
    strcpy(quiz[2].answerC, "2000");
    strcpy(quiz[2].answerD, "1995");
    quiz[2].correct_answer = 'B';

    strcpy(quiz[3].question, "Which country is home to the largest data center in the world?");
    strcpy(quiz[3].answerA, "United States");
    strcpy(quiz[3].answerB, "China");
    strcpy(quiz[3].answerC, "Finland");
    strcpy(quiz[3].answerD, "Norway");
    quiz[3].correct_answer = 'B';

    strcpy(quiz[4].question, "How can we check if x does not equal y in C?");
    strcpy(quiz[4].answerA, "x <> y");
    strcpy(quiz[4].answerB, "x != y");
    strcpy(quiz[4].answerC, "x === y");
    strcpy(quiz[4].answerD, "x DNE y");
    quiz[4].correct_answer = 'B';

    strcpy(quiz[5].question, "Identify the even number in the sequence: 3, 5, 7, 9, 11, ?");
    strcpy(quiz[5].answerA, "12");
    strcpy(quiz[5].answerB, "13");
    strcpy(quiz[5].answerC, "14");
    strcpy(quiz[5].answerD, "15");
    quiz[5].correct_answer = 'B';

    // Shuffle questions
    shuffle_questions(quiz, TOTAL_QUESTIONS);

    double total_correct = 0;
    char answer;

    for (int i = 0; i < TOTAL_QUESTIONS; i++)
    {
        printf("Question %d: %s\n\n", (i + 1), quiz[i].question);
        printf("A) %s\n", quiz[i].answerA);
        printf("B) %s\n", quiz[i].answerB);
        printf("C) %s\n", quiz[i].answerC);
        printf("D) %s\n", quiz[i].answerD);

        answer = get_valid_answer();

        if (answer == quiz[i].correct_answer)
    {
            total_correct++;
            printf("\nCorrect Answer!\n");
        }
        else
        {
            printf("\nIncorrect Answer!\n");
            printf("The correct answer was %c.\n", quiz[i].correct_answer);
        }

        printf("\n\n");
    }

    printf("%d/%d questions answered correctly", (int)total_correct, TOTAL_QUESTIONS);
    printf(" (%.2f%%)\n\n", (total_correct / TOTAL_QUESTIONS) * 100);

    return 0;
}

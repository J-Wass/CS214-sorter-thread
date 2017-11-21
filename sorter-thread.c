#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include "sorter-thread.h"
#include "mergesort.c"
#include "stack.h"

//RUN WITH VALGRIND PLS

int * threadCount;
int * sortInt;

int main(int argc, char ** argv){
  sortInt = (int *)malloc(sizeof(int));
  threadCount = (int *)malloc(sizeof(int));
  if(argc < 2){
    fprintf(stderr, "Too few arguments. Usage is ./sorter -c [sortcol] -d [in directory] -o [out directory]");
    return 0;
  }
  if(strcmp(argv[1],"-c") != 0){
    fprintf(stderr, "Expecting -c flag. Usage is './sorter -c [sortcol] -d [in directory] -o [out directory]'");
    return 0;
  }

  //parse sortbycol to an int for sorting
  char * sortByCol = argv[2];
  int sortInt = 0;
  if(strcmp(sortByCol,  "color")==0) sortInt=0;
  else if(strcmp(sortByCol, "director_name")==0) sortInt=1;
  else if(strcmp(sortByCol, "num_critic_for_reviews")==0) sortInt=2;
  else if(strcmp(sortByCol, "duration")==0) sortInt=3;
  else if(strcmp(sortByCol, "director_facebook_likes")==0) sortInt=4;
  else if(strcmp(sortByCol, "actor_3_facebook_likes")==0) sortInt=5;
  else if(strcmp(sortByCol, "actor_2_name")==0) sortInt=6;
  else if(strcmp(sortByCol, "actor_1_facebook_likes")==0) sortInt=7;
  else if(strcmp(sortByCol, "gross")==0) sortInt=8;
  else if(strcmp(sortByCol, "genres")==0) sortInt=9;
  else if(strcmp(sortByCol, "actor_1_name")==0) sortInt=10;
  else if(strcmp(sortByCol, "movie_title")==0) sortInt=11;
  else if(strcmp(sortByCol, "num_voted_users")==0) sortInt=12;
  else if(strcmp(sortByCol, "cast_total_facebook_likes")==0) sortInt=13;
  else if(strcmp(sortByCol, "actor_3_name")==0) sortInt=14;
  else if(strcmp(sortByCol, "facenumber_in_poster")==0) sortInt=15;
  else if(strcmp(sortByCol, "plot_keywords")==0) sortInt=16;
  else if(strcmp(sortByCol, "movie_imdb_link")==0) sortInt=17;
  else if(strcmp(sortByCol, "num_user_for_reviews")==0) sortInt=18;
  else if(strcmp(sortByCol, "language")==0) sortInt=19;
  else if(strcmp(sortByCol, "country")==0) sortInt=20;
  else if(strcmp(sortByCol, "content_rating")==0) sortInt=21;
  else if(strcmp(sortByCol, "budget")==0) sortInt=22;
  else if(strcmp(sortByCol, "title_year")==0) sortInt=23;
  else if(strcmp(sortByCol, "actor_2_facebook_likes")==0) sortInt=24;
  else if(strcmp(sortByCol, "imdb_score")==0) sortInt=25;
  else if(strcmp(sortByCol, "aspect_ratio")==0) sortInt=26;
  else if(strcmp(sortByCol, "movie_facebook_likes")==0) sortInt=27;
  else{
    fprintf(stderr, "Please use a valid column name!\n");
    return 0;
  }
  //load input and output directory to current working directory
  char inDir[1024];
  char outDir[1024];
  if (getcwd(inDir, sizeof(inDir)) == NULL)
  {
    fprintf(stderr, "Could not read current working directory.");
    return 0;
  }
  strcpy(outDir, inDir);
  //has -o or -d flags
  if(argc >= 4){
    // ./sorter -c [col] -d [dir]
    if(strcmp(argv[3],"-d") == 0){
      strcpy(inDir, argv[4]);
      strcpy(outDir, inDir);
      // ./sorter -c [col] -d [dir] -o [dir]
      if(argc == 7){
        if(strcmp(argv[5],"-o") == 0){
          strcpy(outDir, argv[6]);
        }
        else{
          fprintf(stderr, "Expecting -o flag. Usage is './sorter -c [sortcol] -d [in directory] -o [out directory]'");
          return 0;
        }
      }
    }
    // ./sorter -c [col] -o [dir]
    else if(strcmp(argv[3],"-o") == 0)
    {
      strcpy(outDir, argv[4]);
    }
    else{
      fprintf(stderr, "Expecting -d or -o flag. Usage is './sorter -c [sortcol] -d [in directory] -o [out directory]'");
      return 0;
    }
  }
  DIR * inputDir = opendir (inDir);
  DIR * outputDir = opendir (outDir);
  if (inputDir == NULL) {
      fprintf(stderr,"Malformed input directory %s. Please make sure the directory spelling is correct before trying again.\n",
       inDir);
      return 0;
  }
  if (outputDir == NULL) {
      fprintf(stderr,"Malformed output directory %s. Please make sure the directory spelling is correct before trying again.\n",
       outDir);
      return 0;
  }
  printf("Initial TID: %ld\n", (unsigned long int)pthread_self());
  printf("TIDs of all child thread: ");
  fflush(stdout);
  *threadCount = -1;
  sortCSVs(inputDir, inDir, outputDir, outDir, sortByCol, 1, sortInt);
  printf("\nTotal number of threads: %d\n", *threadCount + 1);
  closedir(inputDir);
  closedir(outputDir);
  return 0;
}

void sortCSVs(DIR * inputDir, char * inDir, DIR * outputDir, char * outDir, char* sortName, short mainCall, int sortInt){
  struct dirent* inFile;
  char * isSorted;
  pthread_t * threads = (pthread_t *)malloc(sizeof(pthread_t) * 256);
  while((inFile = readdir(inputDir)) != NULL){
    isSorted = strstr(inFile->d_name, "-sorted-");
    if((strcmp(inFile->d_name, ".") == 0 || strcmp(inFile->d_name, "..") == 0) && inFile->d_type == 4){
      continue; //skip directory . and ..
    }
    if(isSorted){ //contains -sorted- or is . or is ..
    	continue; //find next file
    }
    char * name = inFile->d_name;
    int l = strlen(name);
    //REGULAR FILE
    if(inFile->d_type == 8 && name[l-4] == '.' && name[l-3] == 'c' && name[l-2] == 's' && name[l-1] == 'v'){
      char * path = (char *)malloc(sizeof(char)*(strlen(inDir) + 2 + strlen(name)));
      strcpy(path, inDir);
      strcat(path, "/");
      strcat(path, name);
      strcat(path, "\0");
      pthread_t thr;
      pthread_create (&thr, NULL, FileSortHandler, (void *)path);
      ++(*threadCount);
      threads[*threadCount] = thr;
      //break;//REMOVE AFTER TESTING
    }
    //DIRECTORY
    if(inFile->d_type == 4){
      char newDir[1 + strlen(inDir) + strlen(name)];
      strcpy(newDir, inDir);
      strcat(newDir, "/");
      strcat(newDir, name);
      DIR * open = opendir(newDir);
      sortCSVs(open, newDir, outputDir, outDir, sortName, 0, sortInt);
      closedir(open);
    }
  }
  //only run if called from main()
  if(mainCall == 1){
    int counter = *threadCount;
    Record * linkedlist = NULL;
    while(counter >= 0){
      Record * head;
      pthread_join(threads[counter--], (void *)&head);
      if(linkedlist == NULL){
        linkedlist = head;
      }
      else{
        Record * temp = linkedlist->next;
        linkedlist->next = head->next;
        head->next = temp;
      }
    }
    Record * tempH = linkedlist;
    linkedlist = linkedlist->next;
    tempH->next = NULL;
    Record * sortedList = *mergesort(&linkedlist, sortInt);
    while(sortedList != NULL){
      printf("%s\n", sortedList->movie_title);
      sortedList = sortedList->next;
    }
  }
}

void* FileSortHandler(void * filename){
  printf("%ld, ",(unsigned long int)pthread_self());
  fflush(stdout);
  FILE * sortFile = fopen((char *)filename, "r");
  char * line = NULL;
  size_t nbytes = 0 * sizeof(char);
  Record * prevRec = NULL;
  Record * head = NULL;
  Record * last;
  getline(&line, &nbytes, sortFile); //skip over first row (just the table headers)
  //eat sortFile line by line
  while (getline(&line, &nbytes, sortFile) != -1) {
    head = (Record *)malloc(sizeof(Record));
    int start = 0;
    int end = 0;
    char lookAhead = line[end];
    int colId = 0;
    short inString = 0;
    while((lookAhead = line[end]) != '\n'){
        if(lookAhead == '"'){
        inString = inString == 0 ? 1 : 0; //keep track if we are inside of quotes
      }
      else{ //normal char
        if(lookAhead == ',' && inString == 0){ //token found!
          char * token = (char *)malloc(sizeof(char));
          token[0] = '\0';
          if(end != start){ //if end == start, this is an empty entry
            int tempEnd = end - 1;
            if(line[start] == '"' && line[end-1] == '"'){ //trim quotes
              tempEnd--;
              start++;
            }
            tempEnd++;//move past last valid character
            //trim whitespace
            while(isspace(line[tempEnd-1])){
              tempEnd--;
            }
            while(isspace(line[start])){
              start++;
            }
            if(line[tempEnd - 1] == ' '){
              line[tempEnd - 1] = '\0';
            }
            else{
              line[tempEnd] = '\0';
            }
            token = (char *)realloc(token, sizeof(char) * (tempEnd-start+1));
            memcpy(token, line + start, tempEnd - start+1);
          }
          switch(colId){
            case 0:
              head->color = token;
              break;
            case 1:
              head->director_name = token;
              break;
            case 2:
              head->num_critic_for_reviews = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 3:
              head->duration = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 4:
              head->director_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 5:
              head->actor_3_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 6:
              head->actor_2_name = token;
              break;
            case 7:
              head->actor_1_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 8:
              head->gross = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 9:
              head->genres = token;
              break;
            case 10:
              head->actor_1_name = token;
              break;
            case 11:
              head->movie_title = token;
              break;
            case 12:
              head->num_voted_users = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 13:
              head->cast_total_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 14:
              head->actor_3_name = token;
              break;
            case 15:
              head->facenumber_in_poster = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 16:
              head->plot_keywords = token;
              break;
            case 17:
              head->movie_imdb_link = token;
              break;
            case 18:
              head->num_user_for_reviews = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 19:
              head->language = token;
              break;
            case 20:
              head->country = token;
              break;
            case 21:
              head->content_rating = token;
              break;
            case 22:
              head->budget = token[0] == '\0' ? -1 :atol(token);
              break;
            case 23:
              head->title_year = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 24:
              head->actor_2_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 25:
              head->imdb_score = token[0] == '\0' ? -1 : atof(token);
              break;
            case 26:
              head->aspect_ratio = token[0] == '\0' ? -1 : atof(token);
              break;
            case 27:
              head->movie_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            default:
              break;
          }
          colId++;
          start = ++end;
          continue;
        }
      }
      end++;
    }
    //add final column
    char * token = (char *)malloc(sizeof(char) * (end-start));
    int tempEnd = end;
    while(isspace(line[tempEnd])){
      tempEnd--;
    }
    while(isspace(line[start])){
      start++;
    }
    memcpy(token, line + start, tempEnd - start + 1);
    head->movie_facebook_likes = token[0] == '\0' ? -1 : atoi(token);

    //create a new struct
    if(prevRec == NULL){
      last = head;
    }
    head->next = prevRec;
    prevRec = head;
  }
  last->next = head; //complete circular linked list
  fclose(sortFile);
  free(filename);
  pthread_exit(head);
  return NULL;
}

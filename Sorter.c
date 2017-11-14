#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include "Sorter.h"
#include "mergesort.c"

//for testing a specific file
/*int main(void){
  FILE * file = fopen("movie_metadata.csv", "r");
  char * filename = "sort_movies.csv";
  sortFile(15, NULL, file, filename);
  fclose(file);
  return 0;
}*/
static int *processCount;

int main(int argc, char ** argv){
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
  if(strcmp(sortByCol,  "color")==0)sortInt=0;
  else if(strcmp(sortByCol, "director_name")==0)sortInt=1;
  else if(strcmp(sortByCol, "num_critic_for_reviews")==0)sortInt=2;
  else if(strcmp(sortByCol, "duration")==0)sortInt=3;
  else if(strcmp(sortByCol, "director_facebook_likes")==0)sortInt=4;
  else if(strcmp(sortByCol, "actor_3_facebook_likes")==0)sortInt=5;
  else if(strcmp(sortByCol, "actor_2_name")==0)sortInt=6;
  else if(strcmp(sortByCol, "actor_1_facebook_likes")==0)sortInt=7;
  else if(strcmp(sortByCol, "gross")==0)sortInt=8;
  else if(strcmp(sortByCol, "genres")==0)sortInt=9;
  else if(strcmp(sortByCol, "actor_1_name")==0)sortInt=10;
  else if(strcmp(sortByCol, "movie_title")==0)sortInt=11;
  else if(strcmp(sortByCol, "num_voted_users")==0)sortInt=12;
  else if(strcmp(sortByCol, "cast_total_facebook_likes")==0)sortInt=13;
  else if(strcmp(sortByCol, "actor_3_name")==0)sortInt=14;
  else if(strcmp(sortByCol, "facenumber_in_poster")==0)sortInt=15;
  else if(strcmp(sortByCol, "plot_keywords")==0)sortInt=16;
  else if(strcmp(sortByCol, "movie_imdb_link")==0)sortInt=17;
  else if(strcmp(sortByCol, "num_user_for_reviews")==0)sortInt=18;
  else if(strcmp(sortByCol, "language")==0)sortInt=19;
  else if(strcmp(sortByCol, "country")==0)sortInt=20;
  else if(strcmp(sortByCol, "content_rating")==0)sortInt=21;
  else if(strcmp(sortByCol, "budget")==0)sortInt=22;
  else if(strcmp(sortByCol, "title_year")==0)sortInt=23;
  else if(strcmp(sortByCol, "actor_2_facebook_likes")==0)sortInt=24;
  else if(strcmp(sortByCol, "imdb_score")==0)sortInt=25;
  else if(strcmp(sortByCol, "aspect_ratio")==0)sortInt=26;
  else if(strcmp(sortByCol, "movie_facebook_likes")==0)sortInt=27;
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
  int ppid = getpid();
  printf("Initial PID: %d\n", ppid);
  printf("PIDS of all child processes: ");
  fflush(stdout);
  processCount = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  int initial_proc = fork();
  if(initial_proc == 0){
    sortCSVs(inputDir, inDir, outputDir, outDir, sortInt, sortByCol);
  }
  else{
    int status;
    waitpid(initial_proc, &status, 0);
    printf("\nTotal number of processes: %d\n", *processCount + 1);
  }
  closedir(inputDir);
  closedir(outputDir);
  if(getpid() == ppid){
    puts("");
  }
  return 0;
}

void sortCSVs(DIR * inputDir, char * inDir, DIR * outputDir, char * outDir,  int sortByCol, char* sortName){
  struct dirent* inFile;
  pid_t child_pid;
  char * isSorted;
  while((inFile = readdir(inputDir)) != NULL){
    isSorted = strstr(inFile->d_name, "-sorted-");
    if((strcmp(inFile->d_name, ".") == 0 || strcmp(inFile->d_name, "..") == 0) && inFile->d_type == 4){
      continue; //skip directory . and ..
    }
    if(isSorted){ //contains -sorted- or is . or is ..
    	continue; //find next file
    }
    child_pid = fork();
    if(child_pid == 0){
    	continue; //child gets next file, parent continues
    }
    *processCount = (*processCount)+1;
    char * name = inFile->d_name;
    int l = strlen(name);
    int pid = getpid();
    printf("%d, ", pid);
    fflush(stdout);
    //REGULAR FILE
    if(inFile->d_type == 8 && name[l-4] == '.' && name[l-3] == 'c' && name[l-2] == 's' && name[l-1] == 'v'){
      char path[strlen(inDir) + 1 + strlen(name)];
      strcpy(path, inDir);
      strcat(path, "/");
      strcat(path, name);
      FILE * readFile = fopen(path, "r");
      sortFile(sortByCol, outDir, readFile, name, sortName);
      fclose(readFile);
    }
    //DIRECTORY
    if(inFile->d_type == 4){
      char newDir[1 + strlen(inDir) + strlen(name)];
      strcpy(newDir, inDir);
      strcat(newDir, "/");
      strcat(newDir, name);
      DIR * open = opendir(newDir);
      //create fork, make child sort the following directory
      int newPid = fork();
      if(newPid == 0){
        sortCSVs(open, newDir, outputDir, outDir, sortByCol, sortName);
      }
      //parent waits for child to iterate entire directory before continuing
      if(newPid != 0){
        int status;
        waitpid(newPid, &status, 0);
      }
    }
    int status;
    waitpid(child_pid, &status, 0);
    exit(0);
  }
  exit(0);
}

void sortFile(int sortByCol, char * outDirString, FILE * sortFile, char * filename, char * sortName){
  char * line = NULL;
  size_t nbytes = 0 * sizeof(char);
  Record * prevRec = NULL;
  Record * head = NULL;
  getline(&line, &nbytes, sortFile); //skip over first row (just the table headers)
  if(strstr(line,"color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes") == NULL)
  {
  		return;
  }//not correctly formatted


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
    head->next = prevRec;
    prevRec = head;
  }

  //sort the linked list based off of sort column
  Record ** Shead = mergesort(&head, sortByCol);
  Record * sortedHead = *Shead;
  int l = strlen(filename);
  char newFile[(l-4) + 13 + strlen(outDirString) + strlen(sortName)];//13 is for -sorted- + .csv + new slash
  strcpy(newFile, outDirString);
  strcat(newFile, "/");
  strncat(newFile,filename,l - 4);//l-4 to trim the .csv extension
  strcat(newFile,"-sorted-");
  strcat(newFile,sortName);
  strcat(newFile,".csv");
  //printf("%d: WRITING %s\n", getpid(), newFile);
  FILE * writeFile = fopen(newFile, "w");

  //print CSV header to file
  fprintf(writeFile,"color,director_name,num_critic_for_reviews,duration,director_facebook_likes,"
  "actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,"
  "movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,"
  "plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,"
  "budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");

  while(sortedHead != NULL){
    Record * r = sortedHead;
    char numCritic[50] = "";
    char duration[50] = "";
    char directLikes[50] = "";
    char actor3Likes[50] = "";
    char actor1Likes[50] = "";
    char gross[50] = "";
    char numVoted[50] = "";
    char castLikes[50] = "";
    char faceNumber[50] = "";
    char numReviews[50] = "";
    char budget[50] = "";
    char actor2Likes[50] = "";
    char titleYear[50] = "";
    char imdbScore[50] = "";
    char aspectRatio[50] = "";
    char movieLikes[50] = "";

    if(r->num_critic_for_reviews != -1){
        snprintf(numCritic, 5000, "%d",r->num_critic_for_reviews);
    }
    if(r->duration != -1){
        snprintf(duration, 5000, "%d",r->duration);
    }
    if(r->director_facebook_likes != -1){
        snprintf(directLikes, 5000, "%d",r->director_facebook_likes);
    }
    if(r->actor_3_facebook_likes != -1){
        snprintf(actor3Likes, 5000, "%d",r->actor_3_facebook_likes);
    }
    if(r->actor_1_facebook_likes != -1){
        snprintf(actor1Likes, 5000, "%d",r->actor_1_facebook_likes);
    }
    if(r->gross != -1){
        snprintf(gross, 5000, "%d",r->gross);
    }
    if(r->num_voted_users != -1){
        snprintf(numVoted, 5000, "%d",r->num_voted_users);
    }
    if(r->cast_total_facebook_likes != -1){
        snprintf(castLikes, 5000, "%d",r->cast_total_facebook_likes);
    }
    if(r->facenumber_in_poster != -1){
        snprintf(faceNumber, 5000, "%d",r->facenumber_in_poster);
    }
    if(r->num_critic_for_reviews != -1){
        snprintf(numReviews, 5000, "%d",r->num_critic_for_reviews);
    }
    if(r->budget != -1){
        snprintf(budget, 5000, "%li",r->budget);
    }
    if(r->actor_2_facebook_likes != -1){
        snprintf(actor2Likes, 5000, "%d",r->actor_2_facebook_likes);
    }
    if(r->title_year != -1){
        snprintf(titleYear, 5000, "%d",r->title_year);
    }
    if(r->imdb_score != -1){
        snprintf(imdbScore, 5000, "%f",r->imdb_score);
    }
    if(r->aspect_ratio != -1){
        snprintf(aspectRatio, 5000, "%f",r->aspect_ratio);
    }
    if(r->movie_facebook_likes != -1){
        snprintf(movieLikes, 5000, "%d",r->movie_facebook_likes);
    }

    if(strchr(r->movie_title, ',') == NULL){ //no commas in this movie title
      fprintf(writeFile,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
            r->color, r->director_name, numCritic, duration,
            directLikes, actor3Likes, r->actor_2_name,
            actor1Likes, gross, r->genres, r->actor_1_name,
            r->movie_title, numVoted, castLikes,
            r->actor_3_name, faceNumber, r->plot_keywords, r->movie_imdb_link,
            numReviews,r->language, r->country, r->content_rating,
            budget, titleYear, actor2Likes, imdbScore,
            aspectRatio, movieLikes);
    }
    else{ //put quotes around the movie title
      fprintf(writeFile,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,\"%s\",%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
              r->color, r->director_name, numCritic, duration,
              directLikes, actor3Likes, r->actor_2_name,
              actor1Likes, gross, r->genres, r->actor_1_name,
              r->movie_title, numVoted, castLikes,
              r->actor_3_name, faceNumber, r->plot_keywords, r->movie_imdb_link,
              numReviews,r->language, r->country, r->content_rating,
              budget, titleYear, actor2Likes, imdbScore,
              aspectRatio, movieLikes);
    }
    Record * temp = sortedHead;
    sortedHead = sortedHead->next;
    free(temp);
  }
  fclose(writeFile);
  return;
}

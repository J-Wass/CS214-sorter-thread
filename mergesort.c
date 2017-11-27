int * sortingInt;
int
count(Record ** head)
{//count how many things are in the list
	int c=0;
	while(*head != NULL){
		if(c < 100){
			//printf("%s\n",(**head).genres);
		}
		head = &(**head).next;
		++c;
	}
	//printf("%d\n",c);
	return c;

}

Record *
split(Record ** head, int count)
{// Count should be the number of elemnts in the list returns a pointer to first node of second half.
	if( count % 2 == 0){
	--count;
	}
	if(count == 3){
	Record ** temp = &((*head)->next);
	Record * secondhead = (*temp)->next;
	(*temp)->next = NULL;
	return secondhead;
	}
	int iter; Record ** temp = head;
	for(iter = count/2; iter > 0; iter --){
	temp = &((*temp)->next);
	}
	Record * secondhead = (*temp)->next;
	(**temp).next = NULL;
	return secondhead;

}

Record * 
merge(Record ** head, Record** secondHead, int sortBycol)
{
  if(!(*head)){
          return *secondHead;
        }
    if(!(*secondHead)){
        return *head;
      }    
    Record *returnHead;//begining of list
    Record *returnTop;//pointer to last non null node in list
    Record *HEAD = *head;
    Record *sHEAD = *secondHead;
    int count = 0;
    switch(sortBycol){
      case 0://char* color;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->color,sHEAD->color)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 1://char* director_name;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->director_name,sHEAD->director_name)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 2://int num_critic_for_reviews;
        while(HEAD && sHEAD){
          if((HEAD ->num_critic_for_reviews) <= (sHEAD->num_critic_for_reviews)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 3://int duration;
       while(HEAD && sHEAD){
          if((HEAD ->duration) <= (sHEAD->duration)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 4://int director_facebook_likes;
        while(HEAD && sHEAD){
          if((HEAD ->director_facebook_likes) <= (sHEAD->director_facebook_likes)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 5://int actor_3_facebook_likes;
        while(HEAD && sHEAD){
          if((HEAD ->actor_3_facebook_likes) <= (sHEAD->actor_3_facebook_likes)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 6://char * actor_2_name;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->actor_2_name,sHEAD->actor_2_name)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 7:// int actor_1_facebook_likes;
        while(HEAD && sHEAD){
          if((HEAD ->actor_1_facebook_likes) <= (sHEAD->actor_1_facebook_likes)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 8://int gross;
        while(HEAD && sHEAD){
          if((HEAD -> gross) <= (sHEAD->gross)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 9://char * genres;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->genres,sHEAD->genres)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 10://char * actor_1_name;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->actor_1_name,sHEAD->actor_1_name)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 11://char * movie_title;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->movie_title,sHEAD->movie_title)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 12://int num_voted_users;
        while(HEAD && sHEAD){
          if((HEAD ->num_voted_users) <= (sHEAD->num_voted_users)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 13://int cast_total_facebook_likes;
        while(HEAD && sHEAD){
          if((HEAD ->cast_total_facebook_likes) <= (sHEAD->cast_total_facebook_likes)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 14://char * actor_3_name;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->actor_3_name,sHEAD->actor_3_name)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 15://int facenumber_in_poster;
        while(HEAD && sHEAD){
          if((HEAD ->facenumber_in_poster) <= (sHEAD->facenumber_in_poster)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 16://char * plot_keywords;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->plot_keywords,sHEAD->plot_keywords)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 17://char * movie_imdb_link;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->movie_imdb_link,sHEAD->movie_imdb_link)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 18://int num_user_for_reviews;
        while(HEAD && sHEAD){
          if((HEAD ->num_user_for_reviews) <= (sHEAD->num_user_for_reviews)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 19://char * language;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->language,sHEAD->language)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 20://char * country;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->country,sHEAD->country)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 21://char * content_rating;
        while(HEAD && sHEAD){
          if(strcmp(HEAD->content_rating,sHEAD->content_rating)<=0){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 22://long budget;
        while(HEAD && sHEAD){
          if((HEAD ->budget) <= (sHEAD->budget)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 23://int title_year;
        while(HEAD && sHEAD){
          if((HEAD ->title_year) <= (sHEAD->title_year)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 24://int actor_2_facebook_likes;
       while(HEAD && sHEAD){
          if((HEAD ->actor_2_facebook_likes) <= (sHEAD->actor_2_facebook_likes)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 25://float imdb_score;
        while(HEAD && sHEAD){
          if((HEAD ->imdb_score) <= (sHEAD->imdb_score)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 26://float aspect_ratio;
        while(HEAD && sHEAD){
          if((HEAD ->aspect_ratio) <= (sHEAD->aspect_ratio)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
      case 27: //int movie_facebook_likes;
        while(HEAD && sHEAD){
          if((HEAD ->movie_facebook_likes) <= (sHEAD->movie_facebook_likes)){
            if(count == 0){
              ++count;
              returnTop = HEAD;
              returnHead = HEAD;
            
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
           else{
            returnTop->next = HEAD;
            if(HEAD->next){
              HEAD = HEAD->next;
              returnTop=returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
            returnTop->next = sHEAD;
            return returnHead;
            }
          }
        }
        else{
          if(count == 0){
            ++count;
            returnTop = sHEAD;
            returnHead = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop->next = NULL;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
          else{
            returnTop ->next = sHEAD;
            if(sHEAD->next){
              sHEAD = sHEAD->next;
              returnTop = returnTop->next;
              returnTop ->next = NULL;
              continue;
            }
            else{
              returnTop->next = HEAD;
              return returnHead;
            }
          }
        }
      }
    }
    return returnHead; 
}


/*
Record **
merge(Record ** head, Record ** secondHead, int sortBycol)
{//merge the two lists. Based on sort By col. Sort by col is a zer indexed integer that gives me which column in the struct we are sorting by.
	//printf("%s\n",(**head).genres);
      //printf("H1, %s\nH2 %s\n",(**head).movie_title,(**secondHead).movie_title);
      if(!(*head)){
      //puts("here1");
          return secondHead;
        }
      if(!(*secondHead)){
        //puts("here2");
        return head;
      }
      int s1 = 0; //if both head,single sized we will set this to 1.
      if(!((*head)->next)){
      s1 = 1;
      }int s2 = 0;
      if(!((*secondHead)->next)){
      s2 = 1;
      }

	  switch(sortBycol)
  {
		case 0: //char* color;
      if(strcmp(((*head)->color),((*secondHead)-> color))<=0){
           if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
            if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 1: //char* director_name;
      if(strcmp(((*head)->director_name),((*secondHead)-> director_name))<=0){
               if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
            if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 2: //int num_critic_for_reviews;
      if(((*head)->num_critic_for_reviews) <= (((*secondHead)-> num_critic_for_reviews))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
      if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 3: //int duration;
       if(((*head)->duration) <= (((*secondHead)-> duration))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 4: //int director_facebook_likes;
       if(((*head)->director_facebook_likes) <= (((*secondHead)->director_facebook_likes))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 5: //int actor_3_facebook_likes;
       if(((*head)->actor_3_facebook_likes) <= (((*secondHead)-> actor_3_facebook_likes))){
            if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 6: //char * actor_2_name;
      if(strcmp(((*head)->actor_2_name),((*secondHead)-> actor_2_name))<=0){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 7: //int actor_1_facebook_likes;
       if(((*head)->actor_1_facebook_likes) <= ((*secondHead)-> actor_1_facebook_likes)){
            if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 8: //int gross;
       if(((*head)->gross) <= (((*secondHead)-> gross))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 9: //char * genres;
      if(strcmp(((*head)->genres),((*secondHead)-> genres))<0){
                if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 10: //char * actor_1_name;
      if(strcmp(((*head)->actor_1_name),((*secondHead)-> actor_1_name))<=0){
                if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 11: //char * movie_title;
  	//puts("heree");
      if(strcmp(((*head)->movie_title),((*secondHead)-> movie_title))<=0){
            if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 12: //int num_voted_users;
       if(((*head)->num_voted_users) <= (((*secondHead)-> num_voted_users))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 13: //int cast_total_facebook_likes;
       if(((*head)->cast_total_facebook_likes) <= (((*secondHead)->cast_total_facebook_likes))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 14: //char * actor_3_name;
      if(strcmp(((*head)->actor_3_name),((*secondHead)-> actor_3_name))<=0){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 15: //int facenumber_in_poster;
       if(((*head)->facenumber_in_poster) <= (((*secondHead)-> facenumber_in_poster))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 16: //char * plot_keywords;
      if(strcmp(((*head)->plot_keywords),((*secondHead)->plot_keywords))<=0){
               if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 17: //char * movie_imdb_link;
       if(strcmp(((*head)->movie_imdb_link),((*secondHead)->movie_imdb_link))<=0){
               if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 18: //int num_user_for_reviews;
        if(((*head)->num_user_for_reviews) <= (((*secondHead)-> num_user_for_reviews))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 19: //char * language;
       if(strcmp(((*head)->language),((*secondHead)->language))<=0){
                if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 20: //char * country;
       if(strcmp(((*head)->country),((*secondHead)->country))<=0){
               if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 21: //char * content_rating;
       if(strcmp(((*head)->content_rating),((*head)->next)->content_rating)<=0){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 22: //int budget;
       if(((*head)->budget) <= (((*secondHead)-> budget))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 23: //int title_year;
       if(((*head)->title_year) <= (((*secondHead)->title_year))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 24: //int actor_2_facebook_likes;
       if(((*head)->actor_2_facebook_likes) <= (((*secondHead)-> actor_2_facebook_likes))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 25: //float imdb_score;
       if(((*head)->imdb_score) <= (((*secondHead)-> imdb_score))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 26: //float aspect_ratio;
       if(((*head)->aspect_ratio) <= (((*secondHead)-> aspect_ratio))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 27: //int movie_facebook_likes;
       if(((*head)->movie_facebook_likes) <= (((*secondHead)-> movie_facebook_likes))){
            if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
		if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
		default:
			return head;
  }
}
*/

void*
t_mergesort(void* arg){//basically just calls mergesort from a void*
  return (void*) mergesort((Record**)arg);
}



Record **
mergesort(Record** head)
 {//mergesort on head done by which column. COlumn is currently a string but we may swithc it to a int.
	 int size = count(head);
	 int sortByCol = *sortingInt;

  if(size > 2){
    Record * secondHead; Record * fhead;
    secondHead = split(head,size);
    Record ** secondHalf = &secondHead;
    secondHead = *mergesort(secondHalf); //create a new thread here
    fhead = *mergesort(head);
    *head = fhead;
    *secondHalf  = secondHead;
    *head = merge(head,secondHalf,sortByCol);
    return head;
  }
  if((*head) -> next == NULL){//only 1 element
    return head;
  }
  Record * temp;
  switch(sortByCol){
    case 0: //char* color;
        if(strcmp((*head)->color,((*head)->next)-> color)<=0){
         return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 1: //char* director_name;
        if(strcmp((*head)->director_name,((*head)->next)-> director_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 2: //int num_critic_for_reviews;
        if(((*head)->num_critic_for_reviews) <= (((*head)->next)-> num_critic_for_reviews)){
                   return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 3: //int duration;
        if(((*head)->duration) <= (((*head)->next)-> duration)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 4: //int director_facebook_likes;
        if(((*head)->director_facebook_likes) <= (((*head)->next)->director_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 5: //int actor_3_facebook_likes;
        if(((*head)->actor_3_facebook_likes) <= (((*head)->next)-> actor_3_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 6: //char * actor_2_name;
        if(strcmp((*head)->actor_2_name,((*head)->next)-> actor_2_name)<=0){
         return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 7: //int actor_1_facebook_likes;
        if(((*head)->actor_1_facebook_likes) <= (((*head)->next)->actor_1_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 8: //int gross;
        if(((*head)->gross) <= (((*head)->next)-> gross)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 9: //char * genres;
        if(strcmp((*head)->genres,((*head)->next)->genres)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 10: //char * actor_1_name;
        if(strcmp(((*head)->actor_1_name),((*head)->next)-> actor_1_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 11: //char * movie_title;
        if(strcmp((*head)->movie_title,((*head)->next)->movie_title)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 12: //int num_voted_users;
        if(((*head)->num_voted_users) <= (((*head)->next)-> num_voted_users)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 13: //int cast_total_facebook_likes;
        if(((*head)->cast_total_facebook_likes) <= (((*head)->next)-> cast_total_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 14: //char * actor_3_name;
        if(strcmp((*head)->actor_3_name,((*head)->next)-> actor_3_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 15: //int facenumber_in_poster;
        if(((*head)->facenumber_in_poster) <= (((*head)->next)-> facenumber_in_poster)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 16: //char * plot_keywords;
        if(strcmp((*head)->plot_keywords,((*head)->next)-> plot_keywords)<=0){
          return head;
          }
          temp = (*head)->next;
          temp->next = *head;
          (*head)->next = NULL;
          *head = temp;
          return head;
      case 17: //char * movie_imdb_link;
        if(strcmp((*head)->movie_imdb_link,((*head)->next)-> movie_imdb_link)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 18: //int num_user_for_reviews;
        if(((*head)->num_user_for_reviews) <= (((*head)->next)-> num_user_for_reviews)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 19: //char * language;
        if(strcmp((*head)->language,((*head)->next)-> language)<=0){
          return head;
          }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 20: //char * country;
        if(strcmp((*head)->country,((*head)->next)-> country)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 21: //char * content_rating;
        if(strcmp((*head)->content_rating,((*head)->next)-> content_rating)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 22: //int budget;
        if(((*head)->budget) <= (((*head)->next)-> budget)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 23: //int title_year;
        if(((*head)->title_year) <= (((*head)->next)-> title_year)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 24: //int actor_2_facebook_likes;
        if(((*head)->actor_2_facebook_likes) <= (((*head)->next)-> actor_2_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 25: //float imdb_score;
        if(((*head)->imdb_score) <= (((*head)->next)-> imdb_score)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 26: //float aspect_ratio;
        if(((*head)->aspect_ratio) <= (((*head)->next)-> aspect_ratio)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
      case 27: //int movie_facebook_likes;
        if(((*head)->movie_facebook_likes) <= (((*head)->next)-> movie_facebook_likes)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  }
    return head;


}



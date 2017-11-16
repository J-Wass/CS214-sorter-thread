typedef struct stack {
  int count;
  Record ** movie_records;
  pthread_mutex_t mutex;
} SortedRecords;

SortedRecords* stack_create(int capacity) {
  SortedRecords *result = malloc(sizeof(SortedRecords));
  result->count = 0;
  result->movie_records = malloc(sizeof(Record *) * capacity);
  pthread_mutex_init(&result->mutex, NULL);
  return result;
}

void push(SortedRecords *s, Record * movie) {
  pthread_mutex_lock(&s->mutex);
  s->movie_records[(s->count)++] = movie;
  pthread_mutex_unlock(&s->mutex); }

Record * pop(SortedRecords *s) {
  pthread_mutex_lock(&s->mutex);
  Record * r = s->movie_records[--(s->count)];
  pthread_mutex_unlock(&s->mutex);
  return r;
}

int is_empty(SortedRecords *s) {
  pthread_mutex_lock(&s->mutex);
  int result = s->count == 0;
  pthread_mutex_unlock(&s->mutex);
  return result;
}

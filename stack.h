pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
typedef struct stack {
  int count;
  Record ** movie_records;
} SortedRecords;

SortedRecords* stack_create(int capacity) {
  SortedRecords *result = malloc(sizeof(SortedRecords));
  result->count = 0;
  result->movie_records = malloc(sizeof(Record *) * capacity);
  return result;
}

void push(SortedRecords *s, Record * movie) {
  pthread_mutex_lock(mutex);
  s->values[(s->count)++] = v;
  pthread_mutex_unlock(mutex); }

double pop(SortedRecords *s) {
  pthread_mutex_lock(mutex);
  double v = s->values[--(s->count)];
  pthread_mutex_unlock(mutex);
  return v;
}

int is_empty(SortedRecords *s) {
  pthread_mutex_lock(mutex);
  int result = s->count == 0;
  pthread_mutex_unlock(mutex);
  return result;
}

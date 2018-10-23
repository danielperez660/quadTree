typedef struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
} Node;

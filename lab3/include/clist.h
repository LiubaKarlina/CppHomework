typedef struct intrusive_node node_s;
typedef struct intrusive_list list_s;
typedef struct position_node pos_node_s;

struct intrusive_node{
  struct intrusive_node *next;
  struct intrusive_node *prev;
};

struct intrusive_list{
  node_s head;
};

struct position_node{
  int x, y;
  node_s node;
};

void init_list(list_s *L);
void add_node(list_s *L, node_s *N);
void remove_node(list_s *L, node_s *N);
int get_length(list_s *L);

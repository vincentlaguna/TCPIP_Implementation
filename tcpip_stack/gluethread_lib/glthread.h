#ifndef             __GLUETHREAD_LIB_H__
#define             __GLUETHREAD_LIB_H__

#define             IS_GLTHREAD_LIST_EMPTY(glthreadptr)           \
                    ((glthreadptr)->right == 0 && (glthreadptr)->left == 0)

typedef struct      _glthread
{
  struct _glthread  *pLeft;
  struct _glthread  *pRight;
}                   glthread_t;

void glthread_add_next(glthread_t *base_glthread, glthread_t *new_glthread);

void glthread_add_before(glthread_t *base_glthread, glthread_t *new_glthread);

void remove_glthread(glthread_t *glthread);

void init_glthread(glthread_t *glthread);


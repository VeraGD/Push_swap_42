#include "../../push_swap.h"

/* int    *array_calculate_pair_cheap(int topb)
{
    int mitad;
    int index_mitad;
    int *num;
    int i;

    mitad = (topb + 1) / 2;
    index_mitad = mitad - 1;
    num = (int *)malloc((topb + 1) * sizeof(int));
    while (index_mitad >= 0)
    {
        num[index_mitad] = index_mitad + 1;
        index_mitad--;
    }
    index_mitad = mitad;
    i = mitad - 1;
    while (index_mitad <= topb)
    {
        num[index_mitad] = i;
        i--;
        index_mitad++;
    }
    return (num);
}

int    *array_calculate_odd_cheap(int topb)
{
    int mitad;
    int index_mitad;
    int *num;
    int i;

    mitad = (topb + 1) / 2;
    index_mitad = mitad - 1;
    num = (int *)malloc((topb + 1) * sizeof(int));
    while (index_mitad >= 0)
    {
        num[index_mitad] = index_mitad + 1;
        index_mitad--;
    }
    index_mitad = mitad;
    num[index_mitad] = index_mitad;
    
    i = mitad - 1;
    index_mitad = index_mitad + 1;
    while (index_mitad <= topb)
    {
        num[index_mitad] = i;
        i--;
        index_mitad++;
    }
    return (num);
} */

static int    array_calculate_cheap(int topb, int index)
{
    int mitad;
    int index_mitad;
    int num;

    if (topb == 0)
        index_mitad = 0;
    else
    {
        mitad = (topb + 1) / 2;
        index_mitad = mitad - 1;
    }
    if (index <= index_mitad)
    {
      num = index + 1;
    }
    else
    {
      num = topb - index;
    }
    return (num);
}

/* static int    calculate_cheap_min(int i, t_stack *t)
{
    int     *op_a;
    int     *op_b;
    int     sizea;
    int res;
    int num;

    sizea = t->topa + 1;
    res = 0;
    op_a = NULL;
    op_b = NULL;
    free(op_a);
    free(op_b);
    if (sizea %  2 == 0)
        op_a = array_calculate_pair_cheap(t->topa);
    else
        op_a = array_calculate_odd_cheap(t->topa);
    if ((t->topb + 1) %  2 == 0)
      op_b = array_calculate_pair_cheap(t->topb);
    else
      op_b = array_calculate_odd_cheap(t->topb);
    num = op_a[i] + op_b[t->target[i]] + 1;
    return (num);
} */

static int    calculate_cheap_min(int i, t_stack *t)
{
    int     op_a;
    int     op_b;
    int num;

    op_a = array_calculate_cheap(t->topa, i);
    op_b = array_calculate_cheap(t->topb, (int)t->target[i]);
    num = op_a + op_b + 1;
    return (num);
}

t_stack *calculate_target_min_all(t_stack *t)
{
  int i;
  //int *res;
  int topb;

  topb = t->topb;
  i = 0;
  //res = (int *)malloc((t->topa) * sizeof(int));
  while (i < t->topa)
  {
    t->cheap[i] = calculate_cheap_min(i, t);
    i++;
  }
  //t->cheap = res;
  return (t);
}
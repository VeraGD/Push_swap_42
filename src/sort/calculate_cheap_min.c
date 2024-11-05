#include "../../push_swap.h"

int    *array_calculate_pair_cheap(int topb)
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
}

static int    calculate_cheap_min(int i, t_stack *t)
{
    int     *op_a;
    int     *op_b;
    int     sizea;
    int topb;
    int num;

    sizea = t->topa + 1;
    topb = t->topb;
    if (sizea %  2 == 0)
        op_a = array_calculate_pair_cheap(t->topa);
    else
        op_a = array_calculate_odd_cheap(t->topa);
    if ((topb + 1) %  2 == 0)
      op_b = array_calculate_pair_cheap(topb);
    else
    {
      op_b = array_calculate_odd_cheap(topb);
    }
    num = op_a[i];
    num += op_b[t->target[i]];
    return (num + 1);
}

t_stack *calculate_target_min_all(t_stack *t)
{
  int sizea;
  int i;
  int *res;
  int topb;

  sizea = t->topa + 1;
  topb = t->topb;
  i = 0;
  res = (int *)malloc((sizea - 1) * sizeof(int));
  while (i < sizea)
  {
    res[i] = calculate_cheap_min(i, t);
    i++;
  }
  t->cheap = res;
  return (t);
}